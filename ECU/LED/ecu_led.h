/**
 * @file    ecu_led.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the LED driver.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

#include "../../MCAL/GPIO/hal_gpio.h"

typedef enum
{
    LED_OFF,
    LED_ON
}led_stutes;

typedef struct
{
    uint8 port : 3;
    uint8 pin : 3;
    uint8 state : 1;
}led_t;

typedef struct
{
    uint8 port : 3;
    uint8 state : 1;
}leds_in_port_t;

Std_ReturnType led_initialize(const led_t* LED);
Std_ReturnType led_turn_on(const led_t* LED);
Std_ReturnType led_turn_off(const led_t* LED);
Std_ReturnType led_toggle(const led_t* LED);

Std_ReturnType led_port_initialize(const leds_in_port_t* LEDs);
Std_ReturnType led_port_write(const leds_in_port_t* LEDs,const uint8* val);

#endif	/* ECU_LED_H */

