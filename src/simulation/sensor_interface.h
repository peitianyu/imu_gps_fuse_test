#ifndef __SENSOR_INTERFACE_H__
#define __SENSOR_INTERFACE_H__

#include "common/gps/gps.h"
#include "common/imu/imu.h"


namespace simulation
{

void RegisterGpsCallback(void(*cb)(const Gps&));

void RegisterImuCallback(void(*cb)(const Imu&));

} // namespace simulation

#endif // __SENSOR_INTERFACE_H__