/********************************************************************************
 *   File Name:
 *      sim_debug_test.hpp
 *
 *   Description:
 *       Provides several functions or threads to validate that the sim is working
 *
 *   2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef AFC_SIM_DEBUG_TEST_HPP
#define AFC_SIM_DEBUG_TEST_HPP

namespace Simulator
{
  /**
   *  A simple thread that periodically prints hello world to the command line
   *  plus whatever the current tick is.
   *
   *  @param[in]  argument    Default argument required for FreeRTOS threads. Not used.
   *  @return void
   */
  void print_hello_world( void *argument );
}    // namespace Simulator

#endif /* AFC_SIM_DEBUG_TEST_HPP */