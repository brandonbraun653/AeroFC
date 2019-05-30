/********************************************************************************
*  File Name:
*    afc_sim_entry.cpp
*
*  Description:
*    Simulator entry point for the AeroFC project
*
*  2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

/* Chimera Includes */
#include <Chimera/threading.hpp>

/* Simulator Includes */
#include <sim/sim_debug_test.hpp>

int main()
{
  using namespace Chimera::Threading;

  addThread( Simulator::print_hello_world, "helloWorld", 200, NULL, 2, NULL );

  /* Should never return from here */
  startScheduler();

  while(1){}
}