#ifndef MULTISENSOR_LOCALIZATION_SUBSCRIBER_KEY_FRAMES_SUBSCRIBER_HPP_
#define MULTISENSOR_LOCALIZATION_SUBSCRIBER_KEY_FRAMES_SUBSCRIBER_HPP_

#include <deque>
#include <mutex>
#include <thread>

#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

#include "multisensor_localization/sensor_data/key_frame.hpp"

namespace multisensor_localization {
class KeyFramesSubscriber {
  public:
    KeyFramesSubscriber(ros::NodeHandle& nh, std::string topic_name, size_t buff_size);
    KeyFramesSubscriber() = default;
    void ParseData(std::deque<KeyFrame>& deque_key_frames);

  private:
    void msg_callback(const nav_msgs::Path::ConstPtr& key_frames_msg_ptr);

  private:
    ros::NodeHandle nh_;
    ros::Subscriber subscriber_;
    std::deque<KeyFrame> new_key_frames_;

    std::mutex buff_mutex_; 
};
}
#endif