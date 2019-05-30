/********************************************************************************
 *  File Name:
 *    afc_imu.hpp
 *
 *  Description:
 *    
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once 
#ifndef AFC_IMU_HPP
#define AFC_IMU_HPP

/* Chimera Includes */
#include <Chimera/types/common_types.hpp>

namespace AeroFC::IMU
{
  /**
   *  Initializes the IMU driver resources 
   */
  Chimera::Status_t initDriver();
  
  //Create an interface to the type of object that AFC expects for an IMU device.
  //Create a second class that actually manages the object and can be called for real code.
}

#endif /* !AFC_IMU_HPP */