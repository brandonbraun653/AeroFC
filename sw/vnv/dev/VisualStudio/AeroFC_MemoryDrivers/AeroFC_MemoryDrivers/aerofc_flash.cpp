/********************************************************************************
*   File Name:
*       aerofc_flash.cpp
*
*   Description:
*       Implements threads used in testing out the Reliance Edge FS integration
*       with the Chimera based memory drivers.
*
*   2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

/* Module Includes */
#include "aerofc_flash.hpp"

/* C++ Includes */

/* Chimera Includes */
#include <Chimera/spi.hpp>
#include <Chimera/threading.hpp>

/* Driver Includes */
#include <at45db081.hpp>


using namespace Chimera;
using namespace Chimera::Threading;


void simpleREDFS_WriteRead(void *argument)
{


    signalThreadSetupComplete();

    for (;;)
    {


        delayMilliseconds(100);
    }
}
