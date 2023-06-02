#include "core/tt_test.h"
#include "core/tt_log.h"

#include<fstream>

// JUST_RUN_TEST(log, test)
TEST(log, test)
{
    std::string log_path = "/mnt/d/file_ws/Learning/slam/imu_gps_fuse_test/log/log_test.log";
    std::ofstream log_file;
    log_file.open(log_path);

    LOG("log_file: ", 1, 2.0, "hello") << std::endl;
    log_file << "log_file: " << 1 << " " << 2.0 << " " << "hello" << std::endl;
    LOG_FILE(log_file, "log_file: ", 1, 2.0, "hello");
}