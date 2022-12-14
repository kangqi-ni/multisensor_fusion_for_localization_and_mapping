#include "multisensor_localization/matching/back_end/sliding_window.hpp"

#include <Eigen/Dense>
#include <pcl/io/pcd_io.h>
#include "glog/logging.h"

#include "multisensor_localization/global_definition/global_definition.h"
#include "multisensor_localization/tools/file_manager.hpp"

namespace multisensor_localization {

SlidingWindow::SlidingWindow() {
    InitWithConfig();
}

bool SlidingWindow::InitWithConfig() {
    // load lio localization backend config file
    std::string config_file_path = WORK_SPACE_PATH + "/config/matching/sliding_window.yaml";
    YAML::Node config_node = YAML::LoadFile(config_file_path);

    std::cout << "-----------------LIO Localization Backend Init-------------------" << std::endl;

    // estimation output path
    InitDataPath(config_node);
    // key frame selection config
    InitKeyFrameSelection(config_node);
    // sliding window config
    InitSlidingWindow(config_node);
    // IMU pre-integration config
    InitIMUPreIntegrator(config_node);

    return true;
}

bool SlidingWindow::InitDataPath(const YAML::Node& config_node) {
    std::string data_path = config_node["data_path"].as<std::string>();
    if (data_path == "./") {
        data_path = WORK_SPACE_PATH;
    }

    if (!FileManager::CreateDirectory(data_path + "/slam_data"))
        return false;

    trajectory_path_ = data_path + "/slam_data/trajectory";
    if (!FileManager::InitDirectory(trajectory_path_, "Estimated Trajectory"))
        return false;

    return true;
}


bool SlidingWindow::InitKeyFrameSelection(const YAML::Node& config_node) {
    key_frame_config_.max_distance = config_node["key_frame"]["max_distance"].as<float>();
    key_frame_config_.max_interval = config_node["key_frame"]["max_interval"].as<float>();

    return true;
}

bool SlidingWindow::InitSlidingWindow(const YAML::Node& config_node) {
    // init sliding window
    const int sliding_window_size = config_node["sliding_window_size"].as<int>();
    sliding_window_ptr_ = std::make_shared<CeresSlidingWindow>(sliding_window_size);

    // select measurements
    measurement_config_.source.map_matching = config_node["measurements"]["map_matching"].as<bool>();
    measurement_config_.source.imu_pre_integration = config_node["measurements"]["imu_pre_integration"].as<bool>();

    // get pose measurement noises
    measurement_config_.noise.lidar_odometry.resize(6);
    measurement_config_.noise.map_matching.resize(6);
    for (int i = 0; i < 6; ++i) {
        measurement_config_.noise.lidar_odometry(i) =
            config_node["lidar_odometry"]["noise"][i].as<double>();
        measurement_config_.noise.map_matching(i) =
            config_node["map_matching"]["noise"][i].as<double>();
    }

    // get position measurement noises
    measurement_config_.noise.gnss_position.resize(3);
    for (int i = 0; i < 3; i++) {
        measurement_config_.noise.gnss_position(i) =
            config_node["gnss_position"]["noise"][i].as<double>();
    }

    return true;
}

bool SlidingWindow::InitIMUPreIntegrator(const YAML::Node& config_node) {
    imu_pre_integrator_ptr_ = nullptr;
    
    if (measurement_config_.source.imu_pre_integration) {
        imu_pre_integrator_ptr_ = std::make_shared<IMUPreIntegrator>(config_node["imu_pre_integration"]);
    }

    return true;
}

bool SlidingWindow::UpdateIMUPreIntegration(const IMUData &imu_data) {
    if (!measurement_config_.source.imu_pre_integration || nullptr == imu_pre_integrator_ptr_)
        return false;
    
    if (!imu_pre_integrator_ptr_->IsInited() ||
        imu_pre_integrator_ptr_->Update(imu_data)) {
        return true;
    }

    return false;
}

bool SlidingWindow::Update(
    const PoseData &laser_odom,
    const PoseData &map_matching_odom,
    const IMUData &imu_data, 
    const PoseData& gnss_pose) {
    ResetParam();

    if (CheckNewKeyFrame(laser_odom, map_matching_odom, imu_data, gnss_pose)) {
        Update();
        CheckOptimized();
    }

    return true;
}

bool SlidingWindow::HasNewKeyFrame() {
    return has_new_key_frame_;
}

bool SlidingWindow::HasNewOptimized() {
    return has_new_optimized_;
}

void SlidingWindow::GetLatestKeyFrame(KeyFrame& key_frame) {
    key_frame = current_key_frame_;
}

void SlidingWindow::GetLatestKeyGNSS(KeyFrame& key_frame) {
    key_frame = current_key_gnss_;
}

void SlidingWindow::GetLatestOptimizedOdometry(KeyFrame& key_frame) {
    sliding_window_ptr_->GetLatestOptimizedKeyFrame(key_frame);
}

void SlidingWindow::GetOptimizedKeyFrames(std::deque<KeyFrame>& key_frames_deque) {
    key_frames_deque.clear();
    
    // load optimized key frames
    sliding_window_ptr_->GetOptimizedKeyFrames(key_frames_.optimized);
    
    key_frames_deque.insert(
        key_frames_deque.end(), 
        key_frames_.optimized.begin(), key_frames_.optimized.end()
    );
}

bool SlidingWindow::SavePose(std::ofstream& ofs, const Eigen::Matrix4f& pose) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            ofs << pose(i, j);
            
            if (i == 2 && j == 3) {
                ofs << std::endl;
            } else {
                ofs << " ";
            }
        }
    }

    return true;
}

bool SlidingWindow::SaveOptimizedTrajectory() {
    static Eigen::Matrix4f current_pose = Eigen::Matrix4f::Identity();

    if ( sliding_window_ptr_->GetNumParamBlocks() == 0 )
        return false;

    // create output trajectory files
    std::ofstream laser_odom_ofs, optimized_ofs, ground_truth_ofs;
    if (!FileManager::CreateFile(laser_odom_ofs, trajectory_path_ + "/laser_odom.txt") ||
        !FileManager::CreateFile(optimized_ofs, trajectory_path_ + "/optimized.txt") ||
        !FileManager::CreateFile(ground_truth_ofs, trajectory_path_ + "/ground_truth.txt")  ) {
        return false;
    }

    // load optimized key frames
    sliding_window_ptr_->GetOptimizedKeyFrames(key_frames_.optimized);

    // write 
    //     a. lidar odometry estimation
    //     b. sliding window optimized odometry estimation
    //     c. IMU/GNSS position reference
    // as trajectories for evo evaluation
    for (size_t i = 0; i < key_frames_.optimized.size(); ++i) {
        // lidar odometry
        current_pose = key_frames_.lidar.at(i).pose;
        current_pose(2, 3) = 0.0f;
        SavePose(laser_odom_ofs, current_pose);
        // sliding window optimized odometry
        current_pose = key_frames_.optimized.at(i).pose;
        current_pose(2, 3) = 0.0f;
        SavePose(optimized_ofs, current_pose);
        // IMU/GNSS position reference as ground truth
        current_pose = key_frames_.reference.at(i).pose;
        current_pose(2, 3) = 0.0f;
        SavePose(ground_truth_ofs, current_pose);
    }

    return true;
}

void SlidingWindow::ResetParam() {
    has_new_key_frame_ = false;
    has_new_optimized_ = false;
}

bool SlidingWindow::CheckNewKeyFrame( 
    const PoseData &laser_odom, 
    const PoseData &map_matching_odom,
    const IMUData &imu_data,
    const PoseData &gnss_odom) {
    static KeyFrame last_key_frame;

    // key frame selection for sliding window 
    if (key_frames_.lidar.empty()) {
        // init IMU pre-integrator
        if (imu_pre_integrator_ptr_) {
            imu_pre_integrator_ptr_->Init(imu_data);
        }

        has_new_key_frame_ = true;
    } 
    else if (
        // spatial: distance threshold
        (laser_odom.pose.block<3,1>(0, 3) - 
         last_key_frame.pose.block<3,1>(0, 3) 
        ).lpNorm<1>() > key_frame_config_.max_distance || 
        // temporal: time difference threshold
        (laser_odom.time - last_key_frame.time) > key_frame_config_.max_interval) { 
        // finish current IMU pre-integration
        if (imu_pre_integrator_ptr_) {
            imu_pre_integrator_ptr_->Reset(imu_data, imu_pre_integration_); 
        }
    
        has_new_key_frame_ = true;
    } 
    else {
        has_new_key_frame_ = false;
    }

    if (has_new_key_frame_) {
        // create key frame for lidar odometry, relative pose measurement
        current_key_frame_.time = laser_odom.time;
        current_key_frame_.index = key_frames_.lidar.size();
        current_key_frame_.pose = laser_odom.pose;
        current_key_frame_.vel.v = gnss_odom.vel.v;
        current_key_frame_.vel.w = gnss_odom.vel.w;

        current_map_matching_pose_ = map_matching_odom;

        // create key frame for GNSS measurement, full LIO state
        current_key_gnss_.time = current_key_frame_.time;
        current_key_gnss_.index = current_key_frame_.index;
        current_key_gnss_.pose = gnss_odom.pose;
        current_key_gnss_.vel.v = gnss_odom.vel.v;
        current_key_gnss_.vel.w = gnss_odom.vel.w;

        // add to cache for later evo evaluation
        key_frames_.lidar.push_back(current_key_frame_);
        key_frames_.reference.push_back(current_key_gnss_);

        // save for next key frame selection
        last_key_frame = current_key_frame_;
    }

    return has_new_key_frame_;
}

bool SlidingWindow::Update() {
    static KeyFrame last_key_frame_ = current_key_frame_;

    // add node for new key frame pose
    if (sliding_window_ptr_->GetNumParamBlocks() == 0) {
        // add init key frame with fixed pose
        sliding_window_ptr_->AddPRVAGParam(current_key_frame_, true);
    } 
    else {
        // add current key frame
        sliding_window_ptr_->AddPRVAGParam(current_key_frame_, false);
    }

    // get number of vertices
    const int N = sliding_window_ptr_->GetNumParamBlocks();
    // get currrent param block ID
    const int param_index_j = N - 1;

    // add unary constraints: map matching / GNSS pose
    if (N > 0 && measurement_config_.source.map_matching) {
        // get prior pose measurement
        Eigen::Matrix4d prior_pose = current_map_matching_pose_.pose.cast<double>();

        // add constraint GNSS pose
        sliding_window_ptr_->AddPRVAGMapMatchingPoseFactor(
            param_index_j, 
            prior_pose, measurement_config_.noise.map_matching
        );
    }

    // add binary constraints: lidar frontend, IMU pre-integration
    if (N > 1) {
        // get previous param block ID
        const int param_index_i = N - 2;

        // get relative pose measurement T_last_current
        Eigen::Matrix4d relative_pose = (last_key_frame_.pose.inverse() * current_key_frame_.pose).cast<double>();
        // add constraint for lidar frontend / loop closure detection
        sliding_window_ptr_->AddPRVAGRelativePoseFactor(
            param_index_i, param_index_j, 
            relative_pose, measurement_config_.noise.lidar_odometry
        );

        if (measurement_config_.source.imu_pre_integration) {
            // add constraint for IMU pre-integraion
            sliding_window_ptr_->AddPRVAGIMUPreIntegrationFactor(
                param_index_i, param_index_j,
                imu_pre_integration_
            );
        }
    }

    // move forward
    last_key_frame_ = current_key_frame_;

    return true;
}

bool SlidingWindow::CheckOptimized() {    
    if (sliding_window_ptr_->Optimize()) {
        has_new_optimized_ = true;

        return true;
    }
    
    return false;
}

} // namespace multisensor_localization