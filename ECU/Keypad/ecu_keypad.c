/**
 * @file    ecu_keypad.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Source file for the Keypad driver.
 * @version 0.1
 * @date    2025-08-31
 */

#include "ecu_keypad.h"

/**
 * 
 * @param keypad
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t* keypad , const uint8 keypad_chars[KEYPAD_ROW][KEYPAD_COL])
{
    Std_ReturnType state=E_OK;
    if(keypad==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        for(uint8 row_counter=0;row_counter<KEYPAD_ROW;row_counter++)
        {
            state &= gpio_pin_direction_initialize(&(keypad->Keypad_row_pins[row_counter]));
            for(uint8 col_counter=0;col_counter<KEYPAD_COL;col_counter++)
            {
                if(row_counter==0)
                state &= gpio_pin_direction_initialize(&(keypad->Keypad_col_pins[col_counter]));
                local_keypad_chars[row_counter][col_counter]=((keypad_chars[row_counter][col_counter]));
            }
        }
    }
    return state;
}

/**
 * 
 * @param keypad
 * @param chr
 * @return 
 */
Std_ReturnType keypad_get_char(const keypad_t* keypad , uint8* chr)
{
    Std_ReturnType state=E_OK;
    if((keypad==NULL) || (chr==NULL))
    {
        state=E_NOT_OK;
    }
    else
    {
        uint8 logic;
        for(uint8 row_counter=0;row_counter<KEYPAD_ROW;row_counter++)
        {
            state &= gpio_pin_write_logic(&(keypad->Keypad_row_pins[row_counter]),GPIO_HIGH);
            for(uint8 col_counter=0;col_counter<KEYPAD_COL;col_counter++)
            {
                state &= gpio_pin_read_logic(&(keypad->Keypad_col_pins[col_counter]),&logic);
                if(logic==GPIO_HIGH)
                {
                    *chr=local_keypad_chars[row_counter][col_counter];
                    break;
                }
            }
            for(uint8 row_counter_in=0;row_counter_in<KEYPAD_ROW;row_counter_in++)
            {
                state &= gpio_pin_write_logic(&(keypad->Keypad_row_pins[row_counter_in]),GPIO_LOW);
            }
        }
    }
    return state;
}