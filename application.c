/**
 * @file    application.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Main application file.
 * @version 0.1
 * @date    2025-09-01
 */

#include "application.h"

uint8 customChars[][8] = {{0x0E,0x0A,0x1B,0x11,0x11,0x11,0x1F,0x00},
                         {0x0E,0x0A,0x1B,0x11,0x11,0x1F,0x1F,0x00},
                         {0x0E,0x0A,0x1B,0x11,0x1F,0x1F,0x1F,0x00},
                         {0x0E,0x0A,0x1B,0x1F,0x1F,0x1F,0x1F,0x00},
                         {0x0E,0x0A,0x1B,0x1F,0x1F,0x1F,0x1F,0x00},
                         {0x0E,0x0A,0x1F,0x1F,0x1F,0x1F,0x1F,0x00},
                         {0x0E,0x0E,0x1F,0x1F,0x1F,0x1F,0x1F,0x00}};

lcd_4bit_t lcd_4bit={.lcd_rs_pin.port=PORTB_INDEX,.lcd_rs_pin.pin=PIN0,
                    .lcd_en_pin.port=PORTB_INDEX,.lcd_en_pin.pin=PIN1,
                    .lcd_data_pins[0].port=PORTB_INDEX,.lcd_data_pins[0].pin=PIN2,
                    .lcd_data_pins[1].port=PORTB_INDEX,.lcd_data_pins[1].pin=PIN3,
                    .lcd_data_pins[2].port=PORTB_INDEX,.lcd_data_pins[2].pin=PIN4,
                    .lcd_data_pins[3].port=PORTB_INDEX,.lcd_data_pins[3].pin=PIN5};

lcd_8bit_t lcd_8bit={.lcd_rs_pin.port=PORTC_INDEX,.lcd_rs_pin.pin=PIN0,
                    .lcd_en_pin.port=PORTC_INDEX,.lcd_en_pin.pin=PIN1,
                    .lcd_data_pins[0].port=PORTD_INDEX,.lcd_data_pins[0].pin=PIN0,
                    .lcd_data_pins[1].port=PORTD_INDEX,.lcd_data_pins[1].pin=PIN1,
                    .lcd_data_pins[2].port=PORTD_INDEX,.lcd_data_pins[2].pin=PIN2,
                    .lcd_data_pins[3].port=PORTD_INDEX,.lcd_data_pins[3].pin=PIN3,
                    .lcd_data_pins[4].port=PORTD_INDEX,.lcd_data_pins[4].pin=PIN4,
                    .lcd_data_pins[5].port=PORTD_INDEX,.lcd_data_pins[5].pin=PIN5,
                    .lcd_data_pins[6].port=PORTD_INDEX,.lcd_data_pins[6].pin=PIN6,
                    .lcd_data_pins[7].port=PORTD_INDEX,.lcd_data_pins[7].pin=PIN7};


/*
 * 
 */

void INT0_Function(void);
led_t led1={.port=PORTA_INDEX,.pin=PIN0, .state=LED_OFF};

ext_INTx_config_t ext_INT0_config={
    .int_source=EXT_INT0,
    .int_edge=RISING_EDGE,
    .int_handler=INT0_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN0,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};





int main(void) 
{    
    application_initialize();
    EXT_INTx_Init(&ext_INT0_config);
    // // lcd_8bit_send_string_at_position(&lcd_8bit, 1, 4, "Hello World");
    // // lcd_4bit_send_string_at_position(&lcd_4bit, 1, 4, "Hello World");
    // for(uint8 local_index=0; local_index<7; local_index++)
    // {
    //     lcd_8bit_send_custome_char(&lcd_8bit, 1, 1, customChars[local_index], local_index);
    //     lcd_4bit_send_custome_char(&lcd_4bit, 1, 1, customChars[local_index], local_index);
    // }

    while(1)
    {
//         for(uint8 local_index=0; local_index<7; local_index++)
//         {
// //            lcd_4bit_send_command(&lcd_4bit, LCD_CGRAM_START + 0);
// //            lcd_8bit_send_command(&lcd_8bit, LCD_CGRAM_START + 0);
//             lcd_4bit_send_char_at_position(&lcd_4bit, 4, 4, local_index);
//             lcd_8bit_send_char_at_position(&lcd_8bit, 4, 4, local_index);
//             __delay_ms(500);
//         }
    }
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initialize(void)
{
    Std_ReturnType state = E_OK;
    // state &= lcd_4bit_initialize(&lcd_4bit);
    // state &= lcd_8bit_initialize(&lcd_8bit);
    state &= led_initialize(&led1);
    return state;
}

void INT0_Function(void)
{
    led_toggle(&led1);
}