#ifndef __GPS_H__
#define __GPS_H__

#include <Eigen/Core>
#include <memory>

struct Gps
{
    double time_stamp;

    Eigen::Vector3d lla; 
    Eigen::Matrix3d cov;
};
using GpsPtr = std::shared_ptr<Gps>;

#endif // __GPS_H__