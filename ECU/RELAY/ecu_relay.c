/**
 * @file    ecu_relay.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Source file for the Relay driver.
 * @version 0.1
 * @date    2025-08-31
 */


#include "ecu_relay.h"

/**
 * 
 * @param Relay
 * @return 
 */
Std_ReturnType Relay_initialize(const Relay_t* Relay)
{
    Std_ReturnType state=E_OK;
    if(Relay==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t relay={.port=Relay->port,.pin=Relay->pin,.logic=GPIO_OUTPUT};
        gpio_pin_direction_initialize(&relay);
    }
}

/**
 * 
 * @param Relay
 * @return 
 */
Std_ReturnType Relay_turn_on(const Relay_t* Relay)
{
    Std_ReturnType state=E_OK;
    if(Relay==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t relay={.port=Relay->port,.pin=Relay->pin};
        gpio_pin_write_logic(&relay,GPIO_HIGH);
    }
}

/**
 * 
 * @param Relay
 * @return 
 */
Std_ReturnType Relay_turn_off(const Relay_t* Relay)
{
    Std_ReturnType state=E_OK;
    if(Relay==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t relay={.port=Relay->port,.pin=Relay->pin};
        gpio_pin_write_logic(&relay,GPIO_LOW);
    }
}

/**
 * 
 * @param Relay
 * @return 
 */
Std_ReturnType Relay_toggle(const Relay_t* Relay)
{
    Std_ReturnType state=E_OK;
    if(Relay==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t relay={.port=Relay->port,.pin=Relay->pin};
        gpio_pin_toggle_logic(&relay);
    }
}