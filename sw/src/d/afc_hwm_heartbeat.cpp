/********************************************************************************
 *   File Name:
 *       afc_hwm_heartbeat.cpp
 *
 *   Description:
 *       Implements the heartbeat driver
 *
 *   2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

/* Chimera Includes */
#include <Chimera/chimera.hpp>
#include <Chimera/gpio.hpp>
#include <Chimera/threading.hpp>

/* Module Includes */
#include <d/afc_hwm_heartbeat.hpp>

using namespace Chimera;
using namespace Chimera::GPIO;
using namespace Chimera::Threading;

/**
 *   A FreeRTOS thread that will pulse the heartbeat led so the user knows
 *   the system is up and running. Plus, who doesn't love LEDs?
 *
 *   @param[in]  argument    Not used
 *   @return void
 */
void afc_hwm_heartbeatThread( void *argument )
{
  // TODO: This pin mapping is temporary for the SMT32F446RE Nucleo dev board
  GPIOClass led;
  led.init( Port::PORTA, 5 );
  led.setMode( Drive::OUTPUT_PUSH_PULL, false );
  led.setState( State::LOW );

  signalSetupComplete();

  for ( ;; )
  {
    led.setState( State::HIGH );
    delayMilliseconds( hwm_heartbeat_period_on_mS );

    led.setState( State::LOW );
    delayMilliseconds( hwm_heartbeat_period_off_mS );
  }
}
