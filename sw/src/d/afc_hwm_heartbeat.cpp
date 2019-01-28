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
#include <Chimera/gpio.hpp>
#include <Chimera/threading.hpp>

/* Module Includes */
#include <src/d/afc_hwm_heartbeat.hpp>

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
void afc_hwm_heartbeatThread(void *argument)
{
    // TODO: This pin mapping is temporary for the SMT32F767ZI Nucleo dev board
    GPIOClass redLed;
    redLed.init(Port::PORTB, 14);
    redLed.setMode(Drive::OUTPUT_PUSH_PULL, false);
    redLed.setState(State::LOW);

    signalThreadSetupComplete();

    for (;;)
    {
        redLed.setState(State::HIGH);
        delayMilliseconds(hwm_heartbeat_period_on_mS);

        redLed.setState(State::LOW);
        delayMilliseconds(hwm_heartbeat_period_off_mS);
    }
}
