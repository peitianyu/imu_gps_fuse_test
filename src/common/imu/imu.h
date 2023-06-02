#ifndef __IMU_H__
#define __IMU_H__

#include <Eigen/Core>
#include <memory>

struct Imu
{
    double time_stamp;

    Eigen::Vector3d acc;
    Eigen::Vector3d gyro;
};

using ImuPtr = std::shared_ptr<Imu>;

#endif // __IMU_H__