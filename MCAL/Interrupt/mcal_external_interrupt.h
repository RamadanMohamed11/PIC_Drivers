/**
 * @file    mcal_external_interrupt.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   External interrupt source header file.
 * @version 0.1
 * @date    2025-11-1
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define MCAL_EXTERNAL_INTERRUPT_H

#include "../std_types.h"
#include "mcal_interrupt_config.h"
#include "../MCAL/GPIO/hal_gpio.h"

#define EXT_INT0_INTERRUPT_ENABLE() (INTCONbits.INT0IE = 1)
#define EXT_INT0_INTERRUPT_DISABLE() (INTCONbits.INT0IE = 0)
#define EXT_INT0_INTERRUPT_FLAG_CLEAR() (INTCONbits.INT0IF = 0)
#define EXT_INT0_RISING_EDGE_SET() (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FALLING_EDGE_SET() (INTCON2bits.INTEDG0 = 0)

#define EXT_INT1_INTERRUPT_ENABLE() (INTCON3bits.INT1IE = 1)
#define EXT_INT1_INTERRUPT_DISABLE() (INTCON3bits.INT1IE = 0)
#define EXT_INT1_INTERRUPT_FLAG_CLEAR() (INTCON3bits.INT1IF = 0)
#define EXT_INT1_RISING_EDGE_SET() (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FALLING_EDGE_SET() (INTCON2bits.INTEDG1 = 0)

#define EXT_INT2_INTERRUPT_ENABLE() (INTCON3bits.INT2IE = 1)
#define EXT_INT2_INTERRUPT_DISABLE() (INTCON3bits.INT2IE = 0)
#define EXT_INT2_INTERRUPT_FLAG_CLEAR() (INTCON3bits.INT2IF = 0)
#define EXT_INT2_RISING_EDGE_SET() (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FALLING_EDGE_SET() (INTCON2bits.INTEDG2 = 0)

#define EXT_RBx_INTERRUPT_ENABLE() (INTCONbits.RBIE = 1)
#define EXT_RBx_INTERRUPT_DISABLE() (INTCONbits.RBIE = 0)
#define EXT_RBx_INTERRUPT_FLAG_CLEAR() (INTCONbits.RBIF = 0)


#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
#define EXT_INT1_HIGH_PRIORITY_SET() (INTCON3bits.INT1IP = 1)
#define EXT_INT1_LOW_PRIORITY_SET() (INTCON3bits.INT1IP = 0 )

#define EXT_INT2_HIGH_PRIORITY_SET() (INTCON3bits.INT2IP = 1)
#define EXT_INT2_LOW_PRIORITY_SET() (INTCON3bits.INT2IP = 0 )

#define EXT_RBx_HIGH_PRIORITY_SET() (INTCON2bits.RBIP = 1)
#define EXT_RBx_LOW_PRIORITY_SET() (INTCON2bits.RBIP = 0 )
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

typedef enum
{
    EXT_INT0,
    EXT_INT1,
    EXT_INT2
}ext_INTx_source_t;

typedef enum
{
    RISING_EDGE,
    FALLING_EDGE
}ext_INTx_edge_t;

typedef struct
{
    void (*int_handler)(void);
    pin_config_t       pin_config;
    ext_INTx_source_t  int_source;
    ext_INTx_edge_t    int_edge;
    interrupt_priority_t priority;

}ext_INTx_config_t;

typedef struct
{
    void (*int_handler)(void);
    pin_config_t       pin_config;
    ext_INTx_edge_t    int_edge;
    interrupt_priority_t priority;

}ext_RBx_config_t;


Std_ReturnType EXT_INTx_Init(const ext_INTx_config_t* ext_INTx);
Std_ReturnType EXT_RBx_Init(const ext_RBx_config_t* ext_INTx);

#endif /* MCAL_EXTERNAL_INTERRUPT_H */

