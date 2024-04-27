/* 
 * File:   ecu_led.c
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 16 ????, 2024, 02:17 ?
 */

#include "ecu_led.h"

/**
 * 
 * @param LED
 * @return 
 */
Std_ReturnType led_initialize(const led_t* LED)
{
    Std_ReturnType state=E_OK;
    if(LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t led={.port=LED->port,.pin=LED->pin,.direction=GPIO_OUTPUT,.logic=LED->state};
        gpio_pin_direction_initialize(&led);
    }
    return state;
}

/**
 * 
 * @param LED
 * @return 
 */
Std_ReturnType led_turn_on(const led_t* LED)
{
    Std_ReturnType state=E_OK;
    if(LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t led={.port=LED->port,.pin=LED->pin,.direction=GPIO_OUTPUT,.logic=LED->state};
        gpio_pin_write_logic(&led,GPIO_HIGH);
    }
    return state;
}

/**
 * 
 * @param LED
 * @return 
 */
Std_ReturnType led_turn_off(const led_t* LED)
{
    Std_ReturnType state=E_OK;
    if(LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t led={.port=LED->port,.pin=LED->pin,.direction=GPIO_OUTPUT,.logic=LED->state};
        gpio_pin_write_logic(&led,GPIO_LOW);
    }
    return state;
}

/**
 * 
 * @param LED
 * @return 
 */
Std_ReturnType led_toggle(const led_t* LED)
{
    Std_ReturnType state=E_OK;
    if(LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t led={.port=LED->port,.pin=LED->pin,.direction=GPIO_OUTPUT,.logic=LED->state};
        gpio_pin_toggle_logic(&led);
    }
    return state;
}

/**
 * 
 * @param LEDs
 * @return 
 */
Std_ReturnType led_port_initialize(const leds_in_port_t* LEDs)
{
    Std_ReturnType state=E_OK;
    if(LEDs==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        gpio_port_direction_initialize(LEDs->port,0x00);
        gpio_port_write_logic(LEDs->port,LEDs->state);
    }
    return state;
}

/**
 * 
 * @param LEDs
 * @return 
 */
Std_ReturnType led_port_write(const leds_in_port_t* LEDs,const uint8* val)
{
    Std_ReturnType state=E_OK;
    if(LEDs==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        gpio_port_write_logic(LEDs->port,*val);
    }
    return state;
}