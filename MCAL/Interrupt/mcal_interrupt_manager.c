/**
 * @file    mcal_interrupt_manager.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Interrupt manager implementation (dispatcher/shared handlers).
 * @version 0.1
 * @date    2025-11-1
 */

#include "mcal_interrupt_manager.h"
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE

uint8 RB4_FLAG = 1;
uint8 RB5_FLAG = 1;
uint8 RB6_FLAG = 1;
uint8 RB7_FLAG = 1;

void __interrupt() interruptManagerHighPriority(void)
{
    // High priority interrupt handling logic would go here
    if(INTCONbits.INT0IF && INTCONbits.INT0IE)
    {
        INT0_ISR();
    }
    else if(INTCON3bits.INT1IF && INTCON3bits.INT1IE)
    {
        INT1_ISR();
    }
    else if(INTCON3bits.INT2IF && INTCON3bits.INT2IE)
    {
        INT2_ISR();
    }
}

void __interrupt(low_priority) interruptManagerLowPriority(void)
{
    // Low priority interrupt handling logic would go here
    if(INTCON3bits.INT1IF && INTCON3bits.INT1IE)
    {
        INT1_ISR();
    }
    else if(INTCON3bits.INT2IF && INTCON3bits.INT2IE)
    {
        INT2_ISR();
    }
}

#else

void __interrupt() interruptManager(void)
{
    if(INTCONbits.INT0IF && INTCONbits.INT0IE)
    {
        INT0_ISR();
    }
    else if(INTCON3bits.INT1IF && INTCON3bits.INT1IE)
    {
        INT1_ISR();
    }
    else if(INTCON3bits.INT2IF && INTCON3bits.INT2IE)
    {
        INT2_ISR();
    }
    else if(INTCONbits.RBIF && INTCONbits.RBIE)
    {
        if(PORTBbits.RB4 == GPIO_HIGH && RB4_FLAG == 1)
        {
            RB4_FLAG = 0;
            RB4_ISR(1); // Rising edge
        }
        else
        {
            RB4_FLAG = 1;
            RB4_ISR(0); // Falling edge
        }
        if(PORTBbits.RB5 == GPIO_HIGH && RB5_FLAG == 1)
        {
            RB5_FLAG = 0;
            RB5_ISR(1); // Rising edge
        }
        else
        {
            RB5_FLAG = 1;
            RB5_ISR(0); // Falling edge
        }
        {
            RB5_FLAG = PORTBbits.RB5;
            RB5_ISR(RB5_FLAG);
        }
        if(PORTBbits.RB6 == GPIO_HIGH && RB6_FLAG == 1)
        {
            RB6_FLAG = 0;
            RB6_ISR(1); // Rising edge
        }
        else
        {
            RB6_FLAG = 1;
            RB6_ISR(0); // Falling edge
        }
        if(PORTBbits.RB7 == GPIO_HIGH && RB7_FLAG == 1)
        {
            RB7_FLAG = 0;
            RB7_ISR(1); // Rising edge
        }
        else
        {
            RB7_FLAG = 1;
            RB7_ISR(0); // Falling edge
        }
    }
}

#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */