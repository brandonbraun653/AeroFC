/********************************************************************************
 *  File Name:
 *    afc_mod_test_entry.cpp
 *
 *  Description:
 *    TModule test entry point for AeroFC
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include <gtest/gtest.h>

using namespace ::testing;

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  // GTEST_FLAG( filter ) = "*";
  return RUN_ALL_TESTS();
}