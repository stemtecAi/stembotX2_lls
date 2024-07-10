//Copyright (c) STEMTEC AI and Robotics Private Limited, India


#ifndef MOTOR_H
#define MOTOR_H

#include "default_motor.h"

//This script allows the robot's LLS Motor driver to be upgraded or changed to a different one with different interface.
#ifdef USE_GENERIC_1_IN_MOTOR_DRIVER
    #define Motor Generic1
#endif

#endif