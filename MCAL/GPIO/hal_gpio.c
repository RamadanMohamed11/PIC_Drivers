/**
 * @file    hal_gpio.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Source file for the GPIO driver.
 * @version 0.1
 * @date    2025-08-31
 */

#include "hal_gpio.h"
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config)
{
    Std_ReturnType state=E_OK;
    if(_pin_config==NULL)
        state=E_NOT_OK;
    else
    {
        switch(_pin_config->direction)
        {
            case GPIO_OUTPUT:
                CLEAR_BIT(*tris_regesters[_pin_config->port],_pin_config->pin);
                switch(_pin_config->logic)
                {
                    case GPIO_HIGH:
                        SET_BIT(*lat_regesters[_pin_config->port],_pin_config->pin);
                        break;
                    case GPIO_LOW:
                        CLEAR_BIT(*lat_regesters[_pin_config->port],_pin_config->pin);
                        break;
                }
                break;
            case GPIO_INPUT:
                SET_BIT(*tris_regesters[_pin_config->port],_pin_config->pin);
                break;
            default:
                state=E_NOT_OK;
        }
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config , uint8* direction)
{
    Std_ReturnType state=E_OK;
    if(_pin_config==NULL || direction==NULL)
        state=E_NOT_OK;
    else
    {
        *direction=READ_BIT(*tris_regesters[_pin_config->port],_pin_config->pin);
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config , uint8 logic)
{
    Std_ReturnType state=E_OK;
    if(_pin_config==NULL)
        state=E_NOT_OK;
    else
    {
        switch(logic)
        {
            case GPIO_HIGH:
                SET_BIT(*lat_regesters[_pin_config->port],_pin_config->pin);
                break;
            case GPIO_LOW:
                CLEAR_BIT(*lat_regesters[_pin_config->port],_pin_config->pin);
                break;
            default:
                state=E_NOT_OK;
        }
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config , uint8* logic)
{
    Std_ReturnType state=E_OK;
    if(_pin_config==NULL || logic==NULL)
        state=E_NOT_OK;
    else
    {
        *logic=READ_BIT(*port_regesters[_pin_config->port],_pin_config->pin);
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config)
{
    Std_ReturnType state=E_OK;
    if(_pin_config==NULL)
        state=E_NOT_OK;
    else
    {
        TOGGLE_BIT(*lat_regesters[_pin_config->port],_pin_config->pin);
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_port_direction_initialize( port_index_t _port, uint8 direction)
{
    Std_ReturnType state=E_OK;
    *tris_regesters[_port]=direction;
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_port_get_direction_status( port_index_t _port , uint8* direction)
{
    Std_ReturnType state=E_OK;
    if(direction==NULL)
        state=E_NOT_OK;
    else
    {
        *direction=*tris_regesters[_port];
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_port_write_logic(port_index_t _port , uint8 logic)
{
    Std_ReturnType state=E_OK;
    *lat_regesters[_port]=logic;
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_port_read_logic( port_index_t _port , uint8* logic)
{
    Std_ReturnType state=E_OK;
    if(logic==NULL)
        state=E_NOT_OK;
    else
    {
        *logic=*port_regesters[_port];
    }
    return state;
}

/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_port_toggle_logic( port_index_t _port)
{
    Std_ReturnType state=E_OK;
    *lat_regesters[_port]^=0xff;
    return state;
}