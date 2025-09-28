/**
 * @file    application.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Main application file.
 * @version 0.1
 * @date    2025-09-01
 */

#include "application.h"

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




int main(void) 
{    
    application_initialize();
    lcd_8bit_send_string_at_position(&lcd_8bit, 1, 4, "Hello World");
    lcd_4bit_send_string_at_position(&lcd_4bit, 1, 4, "Hello World");

    lcd_8bit_send_string_at_position(&lcd_8bit, 2, 5, "Counter = ");
    lcd_4bit_send_string_at_position(&lcd_4bit, 2, 5, "Counter = ");

    sint32 counter1 = 0;
    sint32 counter2 = 0;
    while(1)
    {
        counter1++;
        counter2--;
        lcd_8bit_send_number_at_position(&lcd_8bit, 2, 15, counter1);
        lcd_4bit_send_number_at_position(&lcd_4bit, 2, 15, counter2);
        __delay_ms(50);
    }
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initialize(void)
{
    Std_ReturnType state = E_OK;
    state &= lcd_4bit_initialize(&lcd_4bit);
    state &= lcd_8bit_initialize(&lcd_8bit);
    return state;
}

