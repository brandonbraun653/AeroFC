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
#include <Chimera/modules/memory/red_driver.hpp>

/* Driver Includes */
#include <at45db081.hpp>


using namespace Chimera;
using namespace Chimera::Threading;

using namespace Chimera::SPI;


void simpleREDFS_WriteRead(void *argument)
{
  Setup setup;

  setup.clockFrequency = 1000000;
  setup.bitOrder       = BitOrder::MSB_FIRST;
  setup.clockMode      = ClockMode::MODE0;
  setup.dataSize       = DataSize::SZ_8BIT;
  setup.mode           = Mode::MASTER;

  setup.CS.pin   = 4;
  setup.CS.port  = GPIO::Port::PORTA;
  setup.CS.mode  = GPIO::Drive::OUTPUT_PUSH_PULL;
  setup.CS.state = GPIO::State::HIGH;


  auto spi = std::make_shared<SPIClass>(1);
  spi->init( setup );
  spi->setChipSelectControlMode( ChipSelectMode::MANUAL );


  auto flash = std::make_shared<Adesto::NORFlash::AT45>( Adesto::FlashChip::AT45DB081E, spi );
  flash->initialize( 1000000 );

  Chimera::Modules::Memory::BlockDevice_sPtr blockDev = flash;
  Red::RedFSPosix fs;

  signalThreadSetupComplete();

  auto ret_code = fs.init( blockDev, "VOL0:" );

  ret_code = fs.mount();


  ret_code = fs.unmount();
  fs.deInitBlockDevice();

  ret_code = fs.deInitFileSystem();

  printf( "Return code %d\r\n", ( int )ret_code );

  for ( ;; )
  {
    delayMilliseconds( 100 );
    }
}
