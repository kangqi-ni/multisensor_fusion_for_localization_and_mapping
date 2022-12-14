#ifndef MULTISENSOR_MAPPING_MAPPING_FRONT_END_FRONT_END_HPP_
#define MULTISENSOR_MAPPING_MAPPING_FRONT_END_FRONT_END_HPP_

#include <deque>
#include <Eigen/Dense>
#include <yaml-cpp/yaml.h>

#include "multisensor_mapping/sensor_data/cloud_data.hpp"
#include "multisensor_mapping/models/registration/registration_interface.hpp"
#include "multisensor_mapping/models/cloud_filter/cloud_filter_interface.hpp"

namespace multisensor_mapping {
class FrontEnd {
  public:
    // frame
    struct Frame { 
        Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();
        CloudData cloud_data;
    };

  public:
    FrontEnd();

    bool Update(const CloudData& cloud_data, Eigen::Matrix4f& cloud_pose);
    bool SetInitPose(const Eigen::Matrix4f& init_pose);

  private:
    bool InitWithConfig();
    bool InitParam(const YAML::Node& config_node);
    bool InitRegistration(std::shared_ptr<RegistrationInterface>& registration_ptr, const YAML::Node& config_node);
    bool InitFilter(std::string filter_user, std::shared_ptr<CloudFilterInterface>& filter_ptr, const YAML::Node& config_node);
    bool UpdateWithNewFrame(const Frame& new_key_frame);

  private:
    std::string data_path_ = "";

    // scan filter:
    std::shared_ptr<CloudFilterInterface> frame_filter_ptr_;
    // local map filter:
    std::shared_ptr<CloudFilterInterface> local_map_filter_ptr_;
    // point cloud registrator:
    std::shared_ptr<RegistrationInterface> registration_ptr_; 

    std::deque<Frame> local_map_frames_;

    CloudData::CLOUD_PTR local_map_ptr_;
    Frame current_frame_;

    Eigen::Matrix4f init_pose_ = Eigen::Matrix4f::Identity();

    float key_frame_distance_ = 2.0;
    int local_frame_num_ = 20;
};
}

#endif