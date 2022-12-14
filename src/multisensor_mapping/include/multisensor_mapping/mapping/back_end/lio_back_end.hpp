#ifndef MULTISENSOR_MAPPING_MAPPING_BACK_END_LIO_BACK_END_HPP_
#define MULTISENSOR_MAPPING_MAPPING_BACK_END_LIO_BACK_END_HPP_

#include <string>
#include <deque>
#include <yaml-cpp/yaml.h>
#include <fstream>

#include "multisensor_mapping/sensor_data/cloud_data.hpp"
#include "multisensor_mapping/sensor_data/pose_data.hpp"
#include "multisensor_mapping/sensor_data/key_frame.hpp"
#include "multisensor_mapping/sensor_data/loop_pose.hpp"
#include "multisensor_mapping/sensor_data/imu_data.hpp"
#include "multisensor_mapping/sensor_data/velocity_data.hpp"

#include "multisensor_mapping/models/pre_integrator/imu_pre_integrator.hpp"
#include "multisensor_mapping/models/pre_integrator/odo_pre_integrator.hpp"

#include "multisensor_mapping/models/graph_optimizer/g2o/g2o_graph_optimizer.hpp"

namespace multisensor_mapping {

class LIOBackEnd {
  public:
    LIOBackEnd();

    bool InsertLoopPose(const LoopPose& loop_pose);
    bool UpdateIMUPreIntegration(const IMUData &imu_data);
    bool UpdateOdoPreIntegration(const VelocityData &velocity_data);
    
    bool Update(
      const CloudData& cloud_data, 
      const PoseData& laser_odom, 
      const PoseData& gnss_pose,
      const IMUData &imu_data
    );

    bool ForceOptimize();
    bool SaveOptimizedPose();

    void GetOptimizedKeyFrames(std::deque<KeyFrame>& key_frames_deque);
    bool HasNewKeyFrame();
    bool HasNewOptimized();
    void GetLatestKeyScan(CloudData& key_scan);
    void GetLatestKeyFrame(KeyFrame& key_frame);
    void GetLatestKeyGNSS(KeyFrame& key_frame);

  private:
    bool InitWithConfig();

    bool InitDataPath(const YAML::Node& config_node);
    bool InitParam(const YAML::Node& config_node);
    bool InitGraphOptimizer(const YAML::Node& config_node);
    bool InitIMUPreIntegrator(const YAML::Node& config_node);
    bool InitOdoPreIntegrator(const YAML::Node& config_node);

    void ResetParam();
    bool SavePose(std::ofstream& ofs, const Eigen::Matrix4f& pose);
    
    bool CheckNewKeyFrame(
      const CloudData& cloud_data, 
      const PoseData& laser_odom, 
      const PoseData& gnss_pose,
      const IMUData &imu_data
    );
    
    bool AddNodeAndEdge(const PoseData& gnss_data);

    bool CheckOptimized();
    void ShowIMUPreIntegrationResidual(
      const PoseData &last_gnss_pose, const PoseData& curr_gnss_pose,
      const IMUPreIntegrator::IMUPreIntegration &imu_pre_integration
    );

  private:
    // data path
    std::string key_frames_path_ = "";
    std::string scan_context_path_ = "";
    std::string trajectory_path_ = "";

    // data writer
    std::ofstream ground_truth_ofs_;
    std::ofstream laser_odom_ofs_;
    std::ofstream optimized_pose_ofs_;

    float key_frame_distance_ = 2.0;

    bool has_new_key_frame_ = false;
    bool has_new_optimized_ = false;

    CloudData current_key_scan_;
    KeyFrame current_key_frame_;
    KeyFrame current_key_gnss_;
    std::deque<KeyFrame> key_frames_deque_;
    std::deque<KeyFrame> key_gnss_deque_;
    std::deque<KeyFrame> optimized_key_frames_;

    // pre-integrator
    std::shared_ptr<IMUPreIntegrator> imu_pre_integrator_ptr_;
    IMUPreIntegrator::IMUPreIntegration imu_pre_integration_;
    std::shared_ptr<OdoPreIntegrator> odo_pre_integrator_ptr_;
    OdoPreIntegrator::OdoPreIntegration odo_pre_integration_;
    
    // optimizer
    std::shared_ptr<InterfaceGraphOptimizer> graph_optimizer_ptr_;

    // optimizer configuration
    struct GraphOptimizerConfig {
        GraphOptimizerConfig() {
          odom_edge_noise.resize(6);
          close_loop_noise.resize(6);
          gnss_noise.resize(3);
        }

        bool use_gnss = true;
        bool use_loop_close = false;
        bool use_imu_pre_integration = false;
        bool use_odo_pre_integration = false;

        struct {
          int key_frame = 50;
          int loop_closure = 10;
        } optimization_step_size;

        Eigen::VectorXd odom_edge_noise;
        Eigen::VectorXd close_loop_noise;
        Eigen::VectorXd gnss_noise;
    };
    GraphOptimizerConfig graph_optimizer_config_;

    // counter to count key frames and loop closures for optimizer
    struct {
      int key_frame = 0;
      int loop_closure = 0;

      bool HasEnoughKeyFrames(const int num_key_frames_thresh) {
        if (key_frame >= num_key_frames_thresh) {
          key_frame = 0;
          return true;
        }

        return false;
      }

      bool HasEnoughLoopClosures(const int num_loop_closures_thresh) {
        if (loop_closure >= num_loop_closures_thresh) {
          loop_closure = 0;
          return true;
        }

        return false;
      }

    } counter_;
};

} // namespace multisensor_mapping

#endif // MULTISENSOR_MAPPING_MAPPING_BACK_END_LIO_BACK_END_HPP_