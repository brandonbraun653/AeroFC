/********************************************************************************
 *   File Name:
 *       afc_watchdog.hpp
 *
 *   Description:
 *       Provides definitions for the hardware watchdog interface
 *
 *   2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef AFC_WATCHDOG_HPP
#define AFC_WATCHDOG_HPP

/* C++ Includes */
#include <cstdint>


static constexpr uint32_t hwm_wd_hi_res_kick_mS    = 25;
static constexpr uint32_t hwm_wd_hi_res_timeout_mS = 30;

static constexpr uint32_t hwm_wd_lo_res_kick_mS    = 50;
static constexpr uint32_t hwm_wd_lo_res_timeout_mS = 1000;

/**
 *   A FreeRTOS thread that will kick the low resolution watchdog, assuming
 *   the Chimera HW supports it. Otherwise it does nothing.
 *
 *   @note   The thread shall kick the dog every hwm_wd_lo_res_kick_mS
 *
 *   @param[in]  argument    Not used
 *   @return void
 */
void afc_hwm_independentWatchdogThread( void *argument );


#endif /* !AFC_WATCHDOG_HPP */
