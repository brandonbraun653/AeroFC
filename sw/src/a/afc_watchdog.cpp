/********************************************************************************
 *   File Name:
 *       afc_watchdog.cpp
 *
 *   Description:
 *       Implements the hardware watchdog interface
 *
 *   2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

/* Chimera Includes */
#include <Chimera/threading.hpp>
#include <Chimera/watchdog.hpp>

/* Module Includes */
#include <a/afc_watchdog.hpp>

using namespace Chimera;
using namespace Chimera::Threading;

/**
 *   A FreeRTOS thread that will kick the low resolution watchdog, assuming
 *   the Chimera HW supports it. Otherwise it does nothing.
 *
 *   @note   The thread shall kick the dog every hwm_wd_lo_res_kick_mS
 *
 *   @param[in]  argument    Not used
 *   @return void
 */
void afc_hwm_independentWatchdogThread( void *argument )
{
  Chimera::Watchdog::WatchdogClass dog;
  signalSetupComplete();


  dog.initialize( hwm_wd_lo_res_timeout_mS );
  dog.start();

  for ( ;; )
  {
    dog.kick();
    delayMilliseconds( hwm_wd_lo_res_kick_mS );
  }
}
