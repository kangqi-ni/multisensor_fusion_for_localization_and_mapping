#ifndef MULTISENSOR_MAPPING_MODELS_GRAPH_OPTIMIZER_G2O_G2O_GRAPH_OPTIMIZER_HPP_
#define MULTISENSOR_MAPPING_MODELS_GRAPH_OPTIMIZER_G2O_G2O_GRAPH_OPTIMIZER_HPP_

#include <g2o/stuff/macros.h>
#include <g2o/core/factory.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/linear_solver.h>
#include <g2o/core/sparse_optimizer.h>
#include <g2o/core/robust_kernel_factory.h>
#include <g2o/core/optimization_algorithm_factory.h>
#include <g2o/solvers/pcg/linear_solver_pcg.h>
#include <g2o/types/slam3d/types_slam3d.h>
#include <g2o/types/slam3d/edge_se3_pointxyz.h>
#include <g2o/types/slam3d_addons/types_slam3d_addons.h>

#include "multisensor_mapping/models/graph_optimizer/g2o/vertex/vertex_prvag.hpp"

#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_prvag_relative_pose.hpp"
#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_prvag_prior_pos.hpp"
#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_prvag_imu_pre_integration.hpp"
#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_prvag_odo_pre_integration.hpp"
#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_se3_priorxyz.hpp"
#include "multisensor_mapping/models/graph_optimizer/g2o/edge/edge_se3_priorquat.hpp"

#include "multisensor_mapping/models/graph_optimizer/interface_graph_optimizer.hpp"

namespace g2o {
  class VertexSE3;
  class VertexPlane;
  class VertexPointXYZ;
  class EdgeSE3;
  class EdgeSE3Plane;
  class EdgeSE3PointXYZ;
  class EdgeSE3PriorXY;
  class EdgeSE3PriorXYZ;
  class EdgeSE3PriorVec;
  class EdgeSE3PriorQuat;
  class RobustKernelFactory;
} // namespace g2o

G2O_USE_TYPE_GROUP(slam3d);

G2O_USE_OPTIMIZATION_LIBRARY(pcg)
G2O_USE_OPTIMIZATION_LIBRARY(cholmod)
G2O_USE_OPTIMIZATION_LIBRARY(csparse)

// namespace g2o {
// G2O_REGISTER_TYPE(EDGE_SE3_PRIORXYZ, EdgeSE3PriorXYZ)
// G2O_REGISTER_TYPE(EDGE_SE3_PRIORQUAT, EdgeSE3PriorQuat)
// } // namespace g2o

namespace multisensor_mapping {
  
class G2oGraphOptimizer: public InterfaceGraphOptimizer {
public:
    G2oGraphOptimizer(const std::string &solver_type = "lm_var");

    bool Optimize() override;

    int GetNodeNum() override;

    void SetEdgeRobustKernel(std::string robust_kernel_name, double robust_kernel_size) override;

    bool GetOptimizedPose(std::deque<Eigen::Matrix4f>& optimized_pose) override;
    void AddSe3Node(
      const Eigen::Isometry3d &pose, const bool need_fix
    ) override;
    void AddSe3Edge(
      const int vertex_index1, const int vertex_index2,
      const Eigen::Isometry3d &relative_pose, const Eigen::VectorXd &noise
    ) override;
    void AddSe3PriorXYZEdge(
      const int se3_vertex_index,
      const Eigen::Vector3d &xyz, const Eigen::VectorXd &noise
    ) override;
    void AddSe3PriorQuaternionEdge(
      const int se3_vertex_index,
      const Eigen::Quaterniond &quat, const Eigen::VectorXd &noise
    ) override;

    /**
     * @brief  get optimized LIO key frame state estimation
     * @param  optimized_key_frames, output optimized LIO key frames
     * @return true if success false otherwise
     */
    bool GetOptimizedKeyFrame(std::deque<KeyFrame> &optimized_key_frames) override;
    /**
     * @brief  add vertex for LIO key frame
     * @param  lio_key_frame, LIO key frame with (pos, ori, vel, b_a and b_g)
     * @param  need_fix, shall the vertex be fixed to eliminate trajectory estimation ambiguity
     * @return true if success false otherwise
     */
    void AddPRVAGNode(
      const KeyFrame &lio_key_frame, const bool need_fix
    ) override;
    /**
     * @brief  add edge for relative pose constraint from lidar frontend / loop closure detection
     * @param  vertex_index_i, vertex ID of previous key frame
     * @param  vertex_index_j, vertex ID of current key frame
     * @param  relative_pose, relative pose measurement
     * @param  noise, relative pose measurement noise
     * @return void
     */
    void AddPRVAGRelativePoseEdge(
      const int vertex_index_i, const int vertex_index_j,
      const Eigen::Matrix4d &relative_pose, const Eigen::VectorXd &noise
    ) override;
    /**
     * @brief  add edge for prior position constraint from GNSS measurement
     * @param  vertex_index, vertex ID of current key frame
     * @param  pos, prior position measurement
     * @param  noise, prior position measurement noise
     * @return void
     */
    void AddPRVAGPriorPosEdge(
      const int vertex_index,
      const Eigen::Vector3d &pos, const Eigen::Vector3d &noise
    ) override;
    /**
     * @brief  add edge for IMU pre-integration constraint from IMU measurement
     * @param  vertex_index_i, vertex ID of previous key frame
     * @param  vertex_index_j, vertex ID of current key frame
     * @param  imu_pre_integration, IMU pre-integration measurement
     * @return void
     */
    void AddPRVAGIMUPreIntegrationEdge(
      const int vertex_index_i, const int vertex_index_j,
      const IMUPreIntegrator::IMUPreIntegration &imu_pre_integration
    ) override;
    /**
     * @brief  add edge for odometer pre-integration constraint from odometer measurement
     * @param  vertex_index_i, vertex ID of previous key frame
     * @param  vertex_index_j, vertex ID of current key frame
     * @param  odo_pre_integration, odometer pre-integration measurement
     * @return void
     */
    void AddPRVAGOdoPreIntegrationEdge(
      const int vertex_index_i, const int vertex_index_j,
      const OdoPreIntegrator::OdoPreIntegration &odo_pre_integration
    ) override;
    
private:
    void ShowIMUPreIntegrationResidual(
      const int vertex_index_i, const int vertex_index_j,
      const IMUPreIntegrator::IMUPreIntegration &imu_pre_integration
    );

    Eigen::MatrixXd CalculateSe3EdgeInformationMatrix(Eigen::VectorXd noise);
    Eigen::MatrixXd CalculateSe3PriorQuaternionEdgeInformationMatrix(Eigen::VectorXd noise);
    Eigen::MatrixXd CalculateDiagMatrix(Eigen::VectorXd noise);

    void AddRobustKernel(g2o::OptimizableGraph::Edge *edge, const std::string &kernel_type, double kernel_size);

private:
    g2o::RobustKernelFactory *robust_kernel_factory_;
    std::unique_ptr<g2o::SparseOptimizer> graph_ptr_;

    std::string robust_kernel_name_;
    double robust_kernel_size_;
    bool need_robust_kernel_ = false;
};
} // namespace multisensor_mapping
#endif