/* 
 * File:   ecu_button.h
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 25 ????, 2024, 02:37 ?
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

