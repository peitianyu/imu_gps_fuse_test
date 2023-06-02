#include "core/tt_test.h"
#include "core/tt_log.h"
#include "simulation/read_data.h"
#include "simulation/sensor_interface.h"
#include "common/location/imu_gps_localizer.h"
#include <fstream>

class ImuGpsFuse
{
public:
    ImuGpsFuse(const std::string& data_path) : data_path_(data_path){
        simulation::RegisterGpsCallback(GpsProcess);
        simulation::RegisterImuCallback(ImuProcess);
    }

    void Run(){
        std::ofstream log_file;
        log_file.open("/mnt/d/file_ws/Learning/slam/imu_gps_fuse_test/log/imu_gps_fuse.log");

        while(1){
            simulation::ReadData(data_path_);
            LOG_FILE(log_file, imu_gps_localizer_->GetFuseState().position.transpose()) << std::endl;
        }

        log_file.close();
    }
private:
    static void GpsProcess(const Gps& gps)
    {
        imu_gps_localizer_->GpsUpdate(gps);
    }

    static void ImuProcess(const Imu &imu)
    {
        if(!imu_gps_localizer_->ImuPredict(imu))
            return;
    }
private:
    std::string data_path_;
    static std::unique_ptr<ImuGpsLocalizer> imu_gps_localizer_;
};

std::unique_ptr<ImuGpsLocalizer> ImuGpsFuse::imu_gps_localizer_ = 
                std::make_unique<ImuGpsLocalizer>(Eigen::Vector3d::Zero(), 
                ImuPreintegrator::Option(1e-2, 1e-4, 1e-6, 1e-8, Eigen::Vector3d(0., 0., -9.81007)));




// JUST_RUN_TEST(imu_gps_location, test) 
TEST(imu_gps_location, test) 
{
    std::string data_path = "/mnt/d/file_ws/Learning/slam/imu_gps_fuse_test/dataset/imu_gps_data.txt";
    static ImuGpsFuse imu_gps_fuse(data_path);
    imu_gps_fuse.Run();
}