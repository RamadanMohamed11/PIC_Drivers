/**
 * @file    ecu_relay.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the Relay driver.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

#include "../../MCAL/GPIO/hal_gpio.h"

typedef enum
{
    Relay_ON,
    Relay_Off
}Relay_state_t;

typedef struct
{
    uint8 port : 3;
    uint8 pin : 3;
}Relay_t;

Std_ReturnType Relay_initialize(const Relay_t* Relay);
Std_ReturnType Relay_turn_on(const Relay_t* Relay);
Std_ReturnType Relay_turn_off(const Relay_t* Relay);

#endif	/* ECU_RELAY_H */

