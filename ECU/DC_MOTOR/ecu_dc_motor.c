/* 
 * File:   ecu_dc_motor.c
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 25 ????, 2024, 04:22 ?
 */

#include "ecu_dc_motor.h"

/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t* dc_motor)
{
    Std_ReturnType state=E_OK;
    if(dc_motor==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t dc_motor_pin1={.port=dc_motor->portIN1,.pin=dc_motor->pin1,.direction=GPIO_OUTPUT};
        pin_config_t dc_motor_pin2={.port=dc_motor->portIN2,.pin=dc_motor->pin2,.direction=GPIO_OUTPUT};
        gpio_pin_direction_initialize(&dc_motor_pin1);
        gpio_pin_direction_initialize(&dc_motor_pin2);
    }
    return state;
}

/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t* dc_motor)
{
    Std_ReturnType state=E_OK;
    if(dc_motor==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t dc_motor_pin1={.port=dc_motor->portIN1,.pin=dc_motor->pin1,.direction=GPIO_OUTPUT};
        pin_config_t dc_motor_pin2={.port=dc_motor->portIN2,.pin=dc_motor->pin2,.direction=GPIO_OUTPUT};
        gpio_pin_write_logic(&dc_motor_pin1,GPIO_HIGH);
        gpio_pin_write_logic(&dc_motor_pin2,GPIO_LOW);
    }
    return state;
}

/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t* dc_motor)
{
    Std_ReturnType state=E_OK;
    if(dc_motor==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t dc_motor_pin1={.port=dc_motor->portIN1,.pin=dc_motor->pin1,.direction=GPIO_OUTPUT};
        pin_config_t dc_motor_pin2={.port=dc_motor->portIN2,.pin=dc_motor->pin2,.direction=GPIO_OUTPUT};
        gpio_pin_write_logic(&dc_motor_pin1,GPIO_LOW);
        gpio_pin_write_logic(&dc_motor_pin2,GPIO_HIGH);
    }
    return state;
}