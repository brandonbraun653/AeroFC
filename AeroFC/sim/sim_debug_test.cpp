/********************************************************************************
 *   File Name:
 *       sim_debug_test.cpp
 *
 *   Description:
 *       Provides implementations for debug testing resources for AeroFC simulator
 *
 *   2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

/* C++ Includes */
#include <iostream>

/* Chimera Includes */
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

/* AeroFC Includes */
#include <sim/sim_debug_test.hpp>

namespace Simulator
{
  void print_hello_world( void *argument )
  {
    using namespace Chimera::Threading;

    signalSetupComplete();

    static constexpr uint32_t printDelay_mS = 1000;

    while(1)
    {
      std::cout << xTaskGetTickCount() << ": Hello World!" << std::endl;
      Chimera::delayMilliseconds( printDelay_mS );
    }
  }
}    // namespace Simulator