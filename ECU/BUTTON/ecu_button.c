/* 
 * File:   ecu_button.h
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 25 ????, 2024, 02:37 ?
 */

/**
 * 
 * @param BUTTON
 * @return 
 */

#include "ecu_button.h"

Std_ReturnType button_initialize(const button_t* BUTTON)
{
    Std_ReturnType state=E_OK;
    if(BUTTON==NULL)
        state=E_NOT_OK;
    else
    {
        pin_config_t button={.port=BUTTON->port,.pin=BUTTON->pin,.direction=GPIO_INPUT};
        gpio_pin_direction_initialize(&button);
    }
    return state;
}

/**
 * 
 * @param BUTTON
 * @param state
 * @return 
 */
Std_ReturnType button_read_state(const button_t* BUTTON , button_state_t* button_state)
{
    Std_ReturnType state=E_OK;
    if(BUTTON==NULL)
        state=E_NOT_OK;
    else
    {
        pin_config_t button={.port=BUTTON->port,.pin=BUTTON->pin,.direction=GPIO_INPUT};
        gpio_pin_read_logic(&button,button_state);
        if(BUTTON->button_config==BUTTON_ACTIVE_LOW)
            *button_state=!*button_state;
    }
    return state;
}