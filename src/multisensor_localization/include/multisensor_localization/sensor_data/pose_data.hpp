#ifndef MULTISENSOR_LOCALIZATION_SENSOR_DATA_POSE_DATA_HPP_
#define MULTISENSOR_LOCALIZATION_SENSOR_DATA_POSE_DATA_HPP_

#include <Eigen/Dense>

#include "multisensor_localization/sensor_data/velocity_data.hpp"

namespace multisensor_localization {

class PoseData {
  public:
    double time = 0.0;
    Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();

    struct {
      Eigen::Vector3f v = Eigen::Vector3f::Zero();
      Eigen::Vector3f w = Eigen::Vector3f::Zero();
    } vel;
    
  public:
    Eigen::Quaternionf GetQuaternion();

    void GetVelocityData(VelocityData &velocity_data) const;
};

}

#endif