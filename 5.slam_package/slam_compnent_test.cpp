#include <iostream>
#include <string>
#include <Eigen/Core>
#include <pangolin/pangolin.h>
#include <unistd.h>
#include "sophus/se3.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/block_solver.h"
#include "g2o/core/optimization_algorithm_gauss_newton.h"
#include "g2o/core/optimization_algorithm_levenberg.h"
#include "g2o/solvers/csparse/linear_solver_csparse.h"
#include "g2o/solvers/dense/linear_solver_dense.h"
#include "g2o/core/factory.h"
#include "g2o/stuff/command_args.h"
#include "ceres/ceres.h"

#include <cmath>
#include <chrono>

using namespace std;
using namespace g2o;
using namespace Eigen;

namespace test_component{
    void test_start(string block_name){
      string start_output = "\n\033[32m"+ block_name + " Testing\033[0m";
      cout<<start_output<<endl;
    }
    void test_end(string block_name){
      string end_output = "\033[31m"+ block_name + " Test successfully\033[0m";
      cout<<end_output<<endl;
    }
}

namespace test_Eigen{
  string block_name = "Eigen";
  void test(){
    Eigen::Matrix<float, 2, 3> matrix_23;
    // cout<<"\n\033[32mTesting Eigen---\033[0m"<<endl;
    test_component::test_start(block_name);
    matrix_23 << 1,2,3,4,5,6;
    cout<<"matrix 2x3 from 1 to 6: \n"<<matrix_23<<endl;
    test_component::test_end(block_name);
  }
}

namespace test_Sophus{
  string block_name = "Sophus";
  void test(){
    test_component::test_start(block_name);
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    Eigen::Quaterniond q(R);
    Sophus::SO3d SO3_R(R);
    Sophus::SO3d SO3_q(q);
    cout<<"SO(3) from matrix:\n"<<SO3_R.matrix()<<endl;
    cout<<"SO(3) from matrix:\n"<<SO3_q.matrix()<<endl;
    cout<<"They are equal\n"<<endl;
    test_component::test_end(block_name);
  }
}

namespace test_opencv{
  string block_name = "Opencv";
  void test(){
    test_component::test_start(block_name);
    cv::Mat image;
    image = cv::imread("ubuntu.png");
    if(image.data == nullptr){
        cerr<<"文件"<<"ubuntu.png不存在\n"<<endl;
    }
    cv::imshow("image",image);
    cv::waitKey(0);
    test_component::test_end(block_name);
  }
}

namespace test_ceres{
  string block_name = "ceres";
  struct CURVE_FITTING_COST {
    CURVE_FITTING_COST(double x, double y) : _x(x), _y(y) {}

    // 残差的计算
    template<typename T>
    bool operator()(
      const T *const abc, // 模型参数，有3维
      T *residual) const {
      residual[0] = T(_y) - ceres::exp(abc[0] * T(_x) * T(_x) + abc[1] * T(_x) + abc[2]); // y-exp(ax^2+bx+c)
      return true;
    }
    const double _x, _y;    // x,y数据
  };

  void test(){
    test_component::test_start(block_name);
    double ar = 1.0, br = 2.0, cr = 1.0;         // 真实参数值
    double ae = 2.0, be = -1.0, ce = 5.0;        // 估计参数值
    int N = 100;                                 // 数据点
    double w_sigma = 1.0;                        // 噪声Sigma值
    double inv_sigma = 1.0 / w_sigma;
    cv::RNG rng;                                 // OpenCV随机数产生器

    vector<double> x_data, y_data;      // 数据
    for (int i = 0; i < N; i++) {
      double x = i / 100.0;
      x_data.push_back(x);
      y_data.push_back(exp(ar * x * x + br * x + cr) + rng.gaussian(w_sigma * w_sigma));
    };

    double abc[3] = {ae, be, ce};

    // 构建最小二乘问题
    ceres::Problem problem;
    for (int i = 0; i < N; i++) {
      problem.AddResidualBlock(     // 向问题中添加误差项
        // 使用自动求导，模板参数：误差类型，输出维度，输入维度，维数要与前面struct中一致
        new ceres::AutoDiffCostFunction<CURVE_FITTING_COST, 1, 3>(
          new CURVE_FITTING_COST(x_data[i], y_data[i])
        ),
        nullptr,            // 核函数，这里不使用，为空
        abc                 // 待估计参数
      );
    }

    // 配置求解器
    ceres::Solver::Options options;     // 这里有很多配置项可以填
    options.linear_solver_type = ceres::DENSE_NORMAL_CHOLESKY;  // 增量方程如何求解
    options.minimizer_progress_to_stdout = true;   // 输出到cout

    ceres::Solver::Summary summary;                // 优化信息
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    ceres::Solve(options, &problem, &summary);  // 开始优化
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "solve time cost = " << time_used.count() << " seconds. " << endl;

    // 输出结果
    cout << summary.BriefReport() << endl;
    cout << "estimated a,b,c = ";
    for (auto a:abc) cout << a << " ";
    cout << endl;
    test_component::test_end(block_name);
  }
}


namespace test_g2o{
  class CurveFittingVertex : public g2o::BaseVertex<3, Eigen::Vector3d> {
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    // 重置
    virtual void setToOriginImpl() override {
      _estimate << 0, 0, 0;
    }
    // 更新
    virtual void oplusImpl(const double *update) override {
      _estimate += Eigen::Vector3d(update);
    }
    // 存盘和读盘：留空
    virtual bool read(istream &in) {}
    virtual bool write(ostream &out) const {}
};

// 误差模型 模板参数：观测值维度，类型，连接顶点类型
  class CurveFittingEdge : public g2o::BaseUnaryEdge<1, double, CurveFittingVertex> {
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    CurveFittingEdge(double x) : BaseUnaryEdge(), _x(x) {}

    // 计算曲线模型误差
    virtual void computeError() override {
      const CurveFittingVertex *v = static_cast<const CurveFittingVertex *> (_vertices[0]);
      const Eigen::Vector3d abc = v->estimate();
      _error(0, 0) = _measurement - std::exp(abc(0, 0) * _x * _x + abc(1, 0) * _x + abc(2, 0));
    }

    // 计算雅可比矩阵
    virtual void linearizeOplus() override {
      const CurveFittingVertex *v = static_cast<const CurveFittingVertex *> (_vertices[0]);
      const Eigen::Vector3d abc = v->estimate();
      double y = exp(abc[0] * _x * _x + abc[1] * _x + abc[2]);
      _jacobianOplusXi[0] = -_x * _x * y;
      _jacobianOplusXi[1] = -_x * y;
      _jacobianOplusXi[2] = -y;
    }

    virtual bool read(istream &in) {}

    virtual bool write(ostream &out) const {}

  public:
    double _x;  // x 值， y 值为 _measurement
  };

  void test(){

    string block_name = "g2o";
    test_component::test_start(block_name);
 //
    double ar = 1.0, br = 2.0, cr = 1.0;         // 真实参数值
    double ae = 2.0, be = -1.0, ce = 5.0;        // 估计参数值
    int N = 100;                                 // 数据点
    double w_sigma = 1.0;                        // 噪声Sigma值
    double inv_sigma = 1.0 / w_sigma;
    cv::RNG rng;                                 // OpenCV随机数产生器

    vector<double> x_data, y_data;      // 数据
    for (int i = 0; i < N; i++) {
      double x = i / 100.0;
      x_data.push_back(x);
      y_data.push_back(exp(ar * x * x + br * x + cr) + rng.gaussian(w_sigma * w_sigma));
    }

    // 构建图优化，先设定g2o
    typedef g2o::BlockSolver<g2o::BlockSolverTraits<3, 1>> BlockSolverType;  // 每个误差项优化变量维度为3，误差值维度为1
    typedef g2o::LinearSolverDense<BlockSolverType::PoseMatrixType> LinearSolverType; // 线性求解器类型
    // typedef g2o::LinearSolverDense<BlockSolverType::PoseMatrixType> LinearSolverType; // 线性求解器类型
    // 梯度下降方法，可以从GN, LM, DogLeg 中选
    auto solver = new g2o::OptimizationAlgorithmGaussNewton(
      g2o::make_unique<BlockSolverType>(g2o::make_unique<LinearSolverType>()));
    
    
    g2o::SparseOptimizer optimizer;     // 图模型
    optimizer.setAlgorithm(solver);   // 设置求解器
    optimizer.setVerbose(true);       // 打开调试输出

    // 往图中增加顶点
    CurveFittingVertex *v = new CurveFittingVertex();
    v->setEstimate(Eigen::Vector3d(ae, be, ce));
    v->setId(0);
    optimizer.addVertex(v);

    // 往图中增加边
    for (int i = 0; i < N; i++) {
      CurveFittingEdge *edge = new CurveFittingEdge(x_data[i]);
      edge->setId(i);
      edge->setVertex(0, v);                // 设置连接的顶点
      edge->setMeasurement(y_data[i]);      // 观测数值
      edge->setInformation(Eigen::Matrix<double, 1, 1>::Identity() * 1 / (w_sigma * w_sigma)); // 信息矩阵：协方差矩阵之逆
      optimizer.addEdge(edge);
    }

    // 执行优化
    cout << "start optimization" << endl;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    optimizer.initializeOptimization();
    optimizer.optimize(10);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "solve time cost = " << time_used.count() << " seconds. " << endl;

    // 输出优化值
    Eigen::Vector3d abc_estimate = v->estimate();
    cout << "estimated model: " << abc_estimate.transpose() << endl;

 //
    test_component::test_end(block_name);
  }
}

namespace test_Pangolin{
  string trajectory_file = "/home/yogurtsuee/C-prog/SimpeAlg/src/slam_test/trajectory.txt";
  void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>>);

  void test(){
    string block_name = "Pangolin";
    test_component::test_start(block_name);
    vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses;
    ifstream fin(trajectory_file);
    if (!fin) {
      cout << "cannot find trajectory file at " << trajectory_file << endl;
    }

    while (!fin.eof()) {
      double time, tx, ty, tz, qx, qy, qz, qw;
      fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
      Isometry3d Twr(Quaterniond(qw, qx, qy, qz));
      Twr.pretranslate(Vector3d(tx, ty, tz));
      poses.push_back(Twr);
    }
    cout << "read total " << poses.size() << " pose entries" << endl;

    // draw trajectory in pangolin
    DrawTrajectory(poses);
    test_component::test_end(block_name);
  }

  void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses) {
    // create pangolin window and plot the trajectory
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
      pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
      pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
    );

    pangolin::View &d_cam = pangolin::CreateDisplay()
      .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f / 768.0f)
      .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false) {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      d_cam.Activate(s_cam);
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
      glLineWidth(2);
      for (size_t i = 0; i < poses.size(); i++) {
        // 画每个位姿的三个坐标轴
        Vector3d Ow = poses[i].translation();
        Vector3d Xw = poses[i] * (0.1 * Vector3d(1, 0, 0));
        Vector3d Yw = poses[i] * (0.1 * Vector3d(0, 1, 0));
        Vector3d Zw = poses[i] * (0.1 * Vector3d(0, 0, 1));
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3d(Ow[0], Ow[1], Ow[2]);
        glVertex3d(Xw[0], Xw[1], Xw[2]);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3d(Ow[0], Ow[1], Ow[2]);
        glVertex3d(Yw[0], Yw[1], Yw[2]);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3d(Ow[0], Ow[1], Ow[2]);
        glVertex3d(Zw[0], Zw[1], Zw[2]);
        glEnd();
      }
      // 画出连线
      for (size_t i = 0; i < poses.size(); i++) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        auto p1 = poses[i], p2 = poses[i + 1];
        glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
        glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
        glEnd();
      }
      pangolin::FinishFrame();
      usleep(5000);   // sleep 5 ms
  }
}
}

namespace test_pcl{
    string block_name = "Pcl";
    string left_file = "left.png";
    string right_file = "right.png";

    void showPointCloud(
    const vector<Vector4d, Eigen::aligned_allocator<Vector4d>> &pointcloud);

    void test(){
      // 内参
      double fx = 718.856, fy = 718.856, cx = 607.1928, cy = 185.2157;
      // 基线
      double b = 0.573;

      // 读取图像
      cv::Mat left = cv::imread(left_file, 0);
      cv::Mat right = cv::imread(right_file, 0);
      cv::imshow("left", left);
      cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(
          0, 96, 9, 8 * 9 * 9, 32 * 9 * 9, 1, 63, 10, 100, 32);    // 神奇的参数
      cv::Mat disparity_sgbm, disparity;
      sgbm->compute(left, right, disparity_sgbm);
      disparity_sgbm.convertTo(disparity, CV_32F, 1.0 / 16.0f);

      // 生成点云
      vector<Vector4d, Eigen::aligned_allocator<Vector4d>> pointcloud;

      // 如果你的机器慢，请把后面的v++和u++改成v+=2, u+=2 v++ u++
      for (int v = 0; v < left.rows; v++)
          for (int u = 0; u < left.cols; u++) {
              if (disparity.at<float>(v, u) <= 0.0 || disparity.at<float>(v, u) >= 96.0) continue;

              Vector4d point(0, 0, 0, left.at<uchar>(v, u) / 255.0); // 前三维为xyz,第四维为颜色

              // 根据双目模型计算 point 的位置
              double x = (u - cx) / fx;
              double y = (v - cy) / fy;
              double depth = fx * b / (disparity.at<float>(v, u));
              point[0] = x * depth;
              point[1] = y * depth;
              point[2] = depth;

              pointcloud.push_back(point);
          }

      cv::imshow("disparity", disparity / 96.0);
      cv::waitKey(0);
      // 画出点云
      showPointCloud(pointcloud);

    }

    void showPointCloud(const vector<Vector4d, Eigen::aligned_allocator<Vector4d>> &pointcloud) {
      if (pointcloud.empty()) {
          cerr << "Point cloud is empty!" << endl;
          return;
      }

      pangolin::CreateWindowAndBind("Point Cloud Viewer", 1024, 768);
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      pangolin::OpenGlRenderState s_cam(
          pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
          pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
      );

      pangolin::View &d_cam = pangolin::CreateDisplay()
          .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
          .SetHandler(new pangolin::Handler3D(s_cam));

      while (pangolin::ShouldQuit() == false) {
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          d_cam.Activate(s_cam);
          glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

          glPointSize(2);
          glBegin(GL_POINTS);
          for (auto &p: pointcloud) {
              glColor3f(p[3], p[3], p[3]);
              glVertex3d(p[0], p[1], p[2]);
          }
          glEnd();
          pangolin::FinishFrame();
          usleep(5000);   // sleep 5 ms
      }
      return;
}
}

int main(int argc, char **argv){
    // cout<<"Test slam"<<endl; 
    // test_Sophus::test();
    // test_Eigen::test(); 
    // test_opencv::test();
    // test_g2o::test();
    // test_ceres::test();
    // test_Pangolin::test();
    test_pcl::test();
    return 0;
}