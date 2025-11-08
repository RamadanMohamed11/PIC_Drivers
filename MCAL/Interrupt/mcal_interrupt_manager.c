/**
 * @file    mcal_interrupt_manager.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Interrupt manager implementation (dispatcher/shared handlers).
 * @version 0.1
 * @date    2025-11-1
 */

#include "mcal_interrupt_manager.h"
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE

void __interrupt() interruptManagerHighPriority(void)
{
    // High priority interrupt handling logic would go here
}

void __interrupt(low_priority) interruptManagerLowPriority(void)
{
    // Low priority interrupt handling logic would go here
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
}

#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */