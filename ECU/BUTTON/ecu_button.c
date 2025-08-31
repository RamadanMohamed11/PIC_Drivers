/**
 * @file    ecu_button.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Source file for the Button driver.
 * @version 0.1
 * @date    2025-08-31
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