/**
 * @file    ecu_button.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the Button driver.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

#include "../../MCAL/GPIO/hal_gpio.h"

typedef enum
{
    BUTTON_RELEASED, // 0
    BUTTON_PRESSED  // 1
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}button_config_t;

typedef struct
{
    uint8 port : 3;
    uint8 pin : 3;
    button_config_t button_config;
}button_t;

Std_ReturnType button_initialize(const button_t* BUTTON);
Std_ReturnType button_read_state(const button_t* BUTTON , button_state_t* state);

#endif	/* ECU_BUTTON_H */

