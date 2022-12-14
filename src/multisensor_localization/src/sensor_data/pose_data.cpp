#include "multisensor_localization/sensor_data/pose_data.hpp"

namespace multisensor_localization {

Eigen::Quaternionf PoseData::GetQuaternion() {
    Eigen::Quaternionf q;
    q = pose.block<3,3>(0,0);
    return q;
}

void PoseData::GetVelocityData(VelocityData &velocity_data) const {
    velocity_data.time = time;

    velocity_data.linear_velocity.x = vel.v.x();
    velocity_data.linear_velocity.y = vel.v.y();
    velocity_data.linear_velocity.z = vel.v.z();

    velocity_data.angular_velocity.x = vel.w.x();
    velocity_data.angular_velocity.y = vel.w.y();
    velocity_data.angular_velocity.z = vel.w.z();
}

}