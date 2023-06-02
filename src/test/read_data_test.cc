#include "core/tt_test.h"
#include "simulation/read_data.h"
#include "common/gps/gps.h"
#include "common/imu/imu.h"
#include "simulation/sensor_interface.h"

void GpsCallback(const Gps& gps)
{
    std::cout << "GpsCallback: " << gps.time_stamp << " " << gps.lla.transpose() << " " << gps.cov.diagonal().transpose() << std::endl;
}

void ImuCallback(const Imu& imu)
{
    std::cout << "ImuCallback: " << imu.time_stamp << " " << imu.acc.transpose() << " " << imu.gyro.transpose() << std::endl;
}

// JUST_RUN_TEST(read_data, test) 
TEST(read_data, test) 
{
    // 注册
    simulation::RegisterGpsCallback(GpsCallback);
    simulation::RegisterImuCallback(ImuCallback);

    std::string data_path = "/mnt/d/file_ws/Learning/slam/imu_gps_fuse_test/dataset/imu_gps_data.txt";
    simulation::ReadData(data_path);
    simulation::ReadData(data_path);
    simulation::ReadData(data_path);
}
