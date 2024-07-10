//Copyright (c) STEMTEC AI and Robtics Private Limited, India


#ifndef IMU_CONFIG_H
#define IMU_CONFIG_H

#include "default_imu.h"

//in Future we may migrate to BOSCH IMU
#ifdef USE_MPU9250_IMU
    #define IMU MPU9250IMU
#endif

#endif
