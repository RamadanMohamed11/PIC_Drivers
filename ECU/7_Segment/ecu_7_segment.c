/* 
 * File:   ecu_7_segment.c
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 25 ????, 2024, 04:20 ?
 */

#include "ecu_7_segment.h"

/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType segment_initialize(const segment_t* segment)
{
    Std_ReturnType state=E_OK;
    if(segment==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t seg[]={{.port=segment->segment_pins[0].port,.pin=segment->segment_pins[0].pin,.direction=GPIO_OUTPUT}
                            ,{.port=segment->segment_pins[1].port,.pin=segment->segment_pins[1].pin,.direction=GPIO_OUTPUT}
                            ,{.port=segment->segment_pins[2].port,.pin=segment->segment_pins[2].pin,.direction=GPIO_OUTPUT}
                            ,{.port=segment->segment_pins[3].port,.pin=segment->segment_pins[3].pin,.direction=GPIO_OUTPUT}};
        for(int i=0;i<4;i++)
        {
            gpio_pin_direction_initialize(&seg[i]);
        }
        segment_write(segment,0);
    }
    return state;
}

/**
 * 
 * @param segment
 * @param number
 * @return 
 */
Std_ReturnType segment_write(const segment_t* segment,uint8 number)
{
    Std_ReturnType state=E_OK;
    if(segment==NULL || number>9 || number<0)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t seg[]={{.port=segment->segment_pins[0].port,.pin=segment->segment_pins[0].pin}
                            ,{.port=segment->segment_pins[1].port,.pin=segment->segment_pins[1].pin}
                            ,{.port=segment->segment_pins[2].port,.pin=segment->segment_pins[2].pin}
                            ,{.port=segment->segment_pins[3].port,.pin=segment->segment_pins[3].pin}};
        for(int i=0;i<4;i++)
        {
            gpio_pin_write_logic(&seg[i],number & 1);
            number>>=1;
        }
    }
    return state;
}

/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType segment_multi_initialize(const segment_multi_pin_t* segment)
{
    Std_ReturnType state=E_OK;
    if(segment==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t seg={.port=segment->port,.pin=segment->pin,.direction=GPIO_OUTPUT};
        gpio_pin_direction_initialize(&seg);
    }
    return state;
}

/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType segment_multi_enable(const segment_multi_pin_t* segment)
{
   Std_ReturnType state=E_OK;
    if(segment==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t seg={.port=segment->port,.pin=segment->pin};
        gpio_pin_write_logic(&seg,GPIO_LOW);
    }
    return state; 
}

/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType segment_multi_disable(const segment_multi_pin_t* segment)
{
    Std_ReturnType state=E_OK;
    if(segment==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t seg={.port=segment->port,.pin=segment->pin};
        gpio_pin_write_logic(&seg,GPIO_HIGH);
    }
    return state;
}