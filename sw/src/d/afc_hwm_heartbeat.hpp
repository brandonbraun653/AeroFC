/********************************************************************************
*   File Name:
*       afc_hwm_heartbeat.hpp
*
*   Description:
*       Definition of the heartbeat interface. Got to have those blinky LEDs!
*
*   2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

#pragma once
#ifndef AFC_HWM_HEARTBEAT_HPP
#define AFC_HWM_HEARTBEAT_HPP

/* C++ Includes */
#include <cstdint>

static constexpr uint32_t hwm_heartbeat_period_on_mS = 150;
static constexpr uint32_t hwm_heartbeat_period_off_mS = 850;

/**
*   A FreeRTOS thread that will pulse the heartbeat led so the user knows
*   the system is up and running. Plus, who doesn't love LEDs?
*
*   @param[in]  argument    Not used
*   @return void
*/
void afc_hwm_heartbeatThread(void *argument);

#endif
