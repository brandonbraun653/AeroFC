/********************************************************************************
*   File Name:
*       main.cpp
*
*   Description:
*       Sets up the environment for testing the primary memory drivers used on
*       the AeroFC platform. Currently this is an SD Card and
*
*   2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

/* Chimera Includes */
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

/* Project Includes */
#include <a/afc_watchdog.hpp>
#include <d/afc_hwm_heartbeat.hpp>

using namespace Chimera::Threading;

int main(void)
{
    ChimeraInit();

    addThread(afc_hwm_independentWatchdogThread, "wd", 300, NULL, 2, NULL);
    addThread(afc_hwm_heartbeatThread, "hb", 100, NULL, 2, NULL);

    startScheduler();

	for (;;)
	{
	}
}
