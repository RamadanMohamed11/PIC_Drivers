/**
 * @file    hal_gpio.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the GPIO driver.
 * @version 0.1
 * @date    2025-08-31
 */



#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

#include "../pic18.h"
#include "../std_types.h"
#include "../device_config.h"

#define HWREG8(_X) (*((volatile uint8*)_X))

    /*____PORTA____*/
#define LATA_REG (HWREG8(0xF89))
#define PORTA_REG (HWREG8(0xF80))
#define TRISA_REG (HWREG8(0xF92))
    /*____PORTB____*/
#define LATB_REG (HWREG8(0xF8A))
#define PORTB_REG (HWREG8(0xF81))
#define TRISB_REG (HWREG8(0xF93))
    /*____PORTC____*/
#define LATC_REG (HWREG8(0xF8B))
#define PORTC_REG (HWREG8(0xF82))
#define TRISC_REG (HWREG8(0xF94))
    /*____PORTD____*/
#define LATD_REG (HWREG8(0xF8C))
#define PORTD_REG (HWREG8(0xF83))
#define TRISD_REG (HWREG8(0xF95))
    /*____PORTE____*/
#define LATE_REG (HWREG8(0xF8D))
#define PORTE_REG (HWREG8(0xF84))
#define TRISE_REG (HWREG8(0xF96))

volatile uint8* tris_regesters[]={&TRISA_REG,&TRISB_REG,&TRISC_REG,&TRISD_REG,&TRISE_REG};
volatile uint8* lat_regesters[]={&LATA_REG,&LATB_REG,&LATC_REG,&LATD_REG,&LATE_REG};
volatile uint8* port_regesters[]={&PORTA_REG,&PORTB_REG,&PORTC_REG,&PORTD_REG,&PORTE_REG};

#define BIT_MASK 1

#define SET_BIT(REG,BIT_POS) (REG |= (BIT_MASK<<BIT_POS))
#define CLEAR_BIT(REG,BIT_POS) (REG &= ~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS) (REG ^= (BIT_MASK<<BIT_POS))
#define READ_BIT(REG,BIT_POS) ((REG >> BIT_POS) & BIT_MASK)

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum
{
    GPIO_OUTPUT,
    GPIO_INPUT
}direction_t;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum
{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct
{
    uint8 port : 3; /* @ref port_index_t */
    uint8 pin : 3;  /* @ref pin_index_t */
    uint8 direction : 1;    /* @ref direction_t */
    uint8 logic : 1;    /* @ref logic_t */
}pin_config_t;

Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config , uint8* direction);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config , uint8 logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config , uint8* logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);

Std_ReturnType gpio_port_direction_initialize(port_index_t _port , uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t _port , uint8* direction);
Std_ReturnType gpio_port_write_logic(port_index_t _port , uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t _port , uint8* logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t _port);

#endif	/* HAL_GPIO_H */

