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
void INT1_Function(void);
void INT2_Function(void);

void RB4_HIGH_Function(void);
void RB4_LOW_Function(void);
void RB5_HIGH_Function(void);
void RB5_LOW_Function(void);
void RB6_HIGH_Function(void);
void RB6_LOW_Function(void);
void RB7_HIGH_Function(void);
void RB7_LOW_Function(void);

led_t led1={.port=PORTA_INDEX,.pin=PIN0, .state=LED_OFF};
led_t led2={.port=PORTA_INDEX,.pin=PIN1, .state=LED_OFF};
led_t led3={.port=PORTA_INDEX,.pin=PIN2, .state=LED_OFF};
led_t led4={.port=PORTA_INDEX,.pin=PIN3, .state=LED_OFF};

ext_INTx_config_t ext_INT0_config={
    .int_source=EXT_INT0,
    .int_edge=RISING_EDGE,
    .int_handler=INT0_Function,
    .priority=HIGH_PRIORITY,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN0,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};
ext_INTx_config_t ext_INT1_config={
    .int_source=EXT_INT1,
    .int_edge=RISING_EDGE,
    .int_handler=INT1_Function,
    .priority=LOW_PRIORITY,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN1,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};
ext_INTx_config_t ext_INT2_config={
    .int_source=EXT_INT2,
    .int_edge=RISING_EDGE,
    .priority=HIGH_PRIORITY,
    .int_handler=INT2_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN2,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};

ext_RBx_config_t ext_RB4_config={
    .int_edge=RISING_EDGE,
    .priority=LOW_PRIORITY,
    .int_handler_high=RB4_HIGH_Function,
    .int_handler_low=RB4_LOW_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN4,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};
ext_RBx_config_t ext_RB5_config={
    .int_edge=RISING_EDGE,
    .priority=LOW_PRIORITY,
    .int_handler_high=RB5_HIGH_Function,
    .int_handler_low=RB5_LOW_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN5,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};
ext_RBx_config_t ext_RB6_config={
    .int_edge=RISING_EDGE,
    .priority=LOW_PRIORITY,
    .int_handler_high=RB6_HIGH_Function,
    .int_handler_low=RB6_LOW_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN6,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};
ext_RBx_config_t ext_RB7_config={
    .int_edge=RISING_EDGE,
    .priority=LOW_PRIORITY,
    .int_handler_high=RB7_HIGH_Function,
    .int_handler_low=RB7_LOW_Function,
    .pin_config={
        .port=PORTB_INDEX,
        .pin=PIN7,
        .direction=GPIO_INPUT,
        .logic=GPIO_LOW
    }
};


int main(void) 
{    
    application_initialize();
    EXT_INTx_Init(&ext_INT0_config);
    EXT_INTx_Init(&ext_INT1_config);
    EXT_INTx_Init(&ext_INT2_config);
   
    EXT_RBx_Init(&ext_RB4_config);
    EXT_RBx_Init(&ext_RB5_config);
    EXT_RBx_Init(&ext_RB6_config);
    EXT_RBx_Init(&ext_RB7_config);
    
    while(1)
    {

    }
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initialize(void)
{
    Std_ReturnType state = E_OK;
    // state &= lcd_4bit_initialize(&lcd_4bit);
    // state &= lcd_8bit_initialize(&lcd_8bit);
    state &= led_initialize(&led1);
    state &= led_initialize(&led2);
    state &= led_initialize(&led3);
    return state;
}

void INT0_Function(void)
{
    led_toggle(&led1);
    __delay_ms(1000);
}
void INT1_Function(void)
{
    led_toggle(&led2);
    __delay_ms(1000);
}
void INT2_Function(void)
{
    led_toggle(&led3);
    __delay_ms(1000);
}

void RB4_HIGH_Function(void)
{
    led_turn_on(&led1);
}
void RB4_LOW_Function(void)
{
    led_turn_off(&led1);
}
void RB5_HIGH_Function(void)
{
    led_turn_on(&led2);
}
void RB5_LOW_Function(void)
{
    led_turn_off(&led2);
}
void RB6_HIGH_Function(void)
{
    led_turn_on(&led3);
}
void RB6_LOW_Function(void)
{
    led_turn_off(&led3);
}
void RB7_HIGH_Function(void)
{
    led_turn_on(&led4);
}
void RB7_LOW_Function(void)
{
    led_turn_off(&led4);
}