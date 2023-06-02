#include "core/tt_test.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

JUST_RUN_TEST(show_fused_pose, test)
TEST(show_fused_pose, test)
{
    std::ifstream ifs("/mnt/d/file_ws/Learning/slam/imu_gps_fuse_test/log/imu_gps_fuse.log");
    

    std::string line;
    std::vector<std::vector<double>> poses;
    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        std::vector<double> pose;
        double data;
        while (iss >> data)
            pose.push_back(data);
        
        poses.push_back(pose);
    }

    std::cout << "poses.size(): " << poses.size() << std::endl;

    cv::Mat img(1000, 1000, CV_8UC3, cv::Scalar(255, 255, 255));
    for (uint i = 0; i < poses.size(); ++i) {
        cv::Point2d pt(poses[i][0]*0.5 + 500, -poses[i][1]*0.5 + 500);
        cv::circle(img, pt, 1, cv::Scalar(0, 0, 0), -1);
    }

    cv::imshow("img", img);
    cv::waitKey(0);
}