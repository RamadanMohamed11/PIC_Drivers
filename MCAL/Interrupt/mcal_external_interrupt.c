/**
 * @file    mcal_external_interrupt.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   External interrupt source implementation file.
 * @version 0.1
 * @date    2025-11-1
 */

#include "mcal_external_interrupt.h"

static void (*INT0_InterruptHandler) (void) = NULL;
static void (*INT1_InterruptHandler) (void) = NULL;
static void (*INT2_InterruptHandler) (void) = NULL;

static void (*RB4_InterruptHandler_HIGH) (void) = NULL;
static void (*RB4_InterruptHandler_LOW) (void) = NULL;
static void (*RB5_InterruptHandler_HIGH) (void) = NULL;
static void (*RB5_InterruptHandler_LOW) (void) = NULL;
static void (*RB6_InterruptHandler_HIGH) (void) = NULL;
static void (*RB6_InterruptHandler_LOW) (void) = NULL;
static void (*RB7_InterruptHandler_HIGH) (void) = NULL;
static void (*RB7_InterruptHandler_LOW) (void) = NULL;

static Std_ReturnType EXT_INTx_PIN_Init(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Enable(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Disable(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_edge_Init(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Clear_Flag(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Set_Callback(const ext_INTx_config_t* ext_INTx);
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_INTx_priority_Init(const ext_INTx_config_t* ext_INTx);
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
static Std_ReturnType INT0_SetInterruptHandler(const void (*handler)(void));
static Std_ReturnType INT1_SetInterruptHandler(const void (*handler)(void));
static Std_ReturnType INT2_SetInterruptHandler(const void (*handler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const ext_INTx_config_t* ext_INTx);

static Std_ReturnType EXT_RBx_PIN_Init(const ext_RBx_config_t* ext_RBx);
static Std_ReturnType EXT_RBx_Enable(const ext_RBx_config_t* ext_RBx);
static Std_ReturnType EXT_RBx_Disable(const ext_RBx_config_t* ext_RBx);
// static Std_ReturnType EXT_RBx_edge_Init(const ext_RBx_config_t* ext_RBx);
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_RBx_priority_Init(const ext_RBx_config_t* ext_RBx);
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
static Std_ReturnType RB4_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void));
static Std_ReturnType RB5_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void));
static Std_ReturnType RB6_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void));
static Std_ReturnType RB7_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void));
static Std_ReturnType Interrupt_RBx_SetInterruptHandler(const ext_RBx_config_t* ext_RBx);


Std_ReturnType EXT_INTx_Init(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        // Disable interrupt during configuration
        state &= EXT_INTx_Disable(ext_INTx);
        // Clear interrupt flag
        state &= EXT_INTx_Clear_Flag(ext_INTx);
        // Initialize pin direction
        state &= EXT_INTx_PIN_Init(ext_INTx);
        // Initialize interrupt edge
        state &= EXT_INTx_edge_Init(ext_INTx);
        // Initialize interrupt priority
        #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
        INTERRUPT_INTERRUPT_PRIORITY_ENABLE();
        if(ext_INTx->int_source!=EXT_INT0)
        {
            // INT0 is always high priority
            state &= EXT_INTx_priority_Init(ext_INTx);
        }
        #else
        INTERRUPT_INTERRUPT_PRIORITY_DISABLE();
        #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

        // Interrupt Callback function assignment would go here
        state &= Interrupt_INTx_SetInterruptHandler(ext_INTx);
        // Enable interrupt
        state &= EXT_INTx_Enable(ext_INTx);
    }
    return state;
}

Std_ReturnType EXT_RBx_Init(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        // Disable interrupt during configuration
        state &= EXT_RBx_Disable(ext_RBx);
        // Clear interrupt flag
        EXT_RBx_INTERRUPT_FLAG_CLEAR();
        // Initialize pin direction
        state &= EXT_RBx_PIN_Init(ext_RBx);
        // Initialize interrupt priority
        #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
        INTERRUPT_INTERRUPT_PRIORITY_ENABLE();
        state &= EXT_RBx_priority_Init(ext_RBx);
        #else
        INTERRUPT_INTERRUPT_PRIORITY_DISABLE();
        #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
        // Interrupt Callback function assignment would go here
        state &= Interrupt_RBx_SetInterruptHandler(ext_RBx);
        // Enable interrupt
        state &= EXT_RBx_Enable(ext_RBx);
    }
    return state;
}

void INT0_ISR(void)
{
    EXT_INT0_INTERRUPT_FLAG_CLEAR();
    if(INT0_InterruptHandler != NULL)
    {
        INT0_InterruptHandler();
    }
}

void INT1_ISR(void)
{
    EXT_INT1_INTERRUPT_FLAG_CLEAR();
    if(INT1_InterruptHandler != NULL)
    {
        INT1_InterruptHandler();
    }
}

void INT2_ISR(void)
{
    EXT_INT2_INTERRUPT_FLAG_CLEAR();
    if(INT2_InterruptHandler != NULL)
    {
        INT2_InterruptHandler();
    }
}

void RB4_ISR(uint8 edge)
{
    EXT_RBx_INTERRUPT_FLAG_CLEAR();
    if(edge==RISING_EDGE)
    {
        if(RB4_InterruptHandler_HIGH != NULL)
        {
            RB4_InterruptHandler_HIGH();
        }
    }
    else
    {
        if(RB4_InterruptHandler_LOW != NULL)
        {
            RB4_InterruptHandler_LOW();
        }
    }
}

void RB5_ISR(uint8 edge)
{
    EXT_RBx_INTERRUPT_FLAG_CLEAR();
    if(edge==RISING_EDGE)
    {
        if(RB5_InterruptHandler_HIGH != NULL)
        {
            RB5_InterruptHandler_HIGH();
        }
    }
    else
    {
        if(RB5_InterruptHandler_LOW != NULL)
        {
            RB5_InterruptHandler_LOW();
        }
    }
}
void RB6_ISR(uint8 edge)
{
    EXT_RBx_INTERRUPT_FLAG_CLEAR();
    if(edge==RISING_EDGE)
    {
        if(RB6_InterruptHandler_HIGH != NULL)
        {
            RB6_InterruptHandler_HIGH();
        }
    }
    else
    {
        if(RB6_InterruptHandler_LOW != NULL)
        {
            RB6_InterruptHandler_LOW();
        }
    }
}
void RB7_ISR(uint8 edge)
{
    EXT_RBx_INTERRUPT_FLAG_CLEAR();
    if(edge==RISING_EDGE)
    {
        if(RB7_InterruptHandler_HIGH != NULL)
        {
            RB7_InterruptHandler_HIGH();
        }
    }
    else
    {
        if(RB7_InterruptHandler_LOW != NULL)
        {
            RB7_InterruptHandler_LOW();
        }
    }
}

static Std_ReturnType EXT_INTx_PIN_Init(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        state &= gpio_pin_direction_initialize(&ext_INTx->pin_config);
    }
    return state;
}

static Std_ReturnType EXT_INTx_Enable(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_ENABLE();
                #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
                INTERRUPT_GLOBAL_HIGH_ENABLE();
                #else
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE();
                #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
                if(ext_INTx->priority==HIGH_PRIORITY)
                {
                    INTERRUPT_GLOBAL_HIGH_ENABLE();
                }
                else
                {
                    INTERRUPT_GLOBAL_LOW_ENABLE();
                }
                #else
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE();
                #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
                if(ext_INTx->priority==HIGH_PRIORITY)
                {
                    INTERRUPT_GLOBAL_HIGH_ENABLE();
                }
                else
                {
                    INTERRUPT_GLOBAL_LOW_ENABLE();
                }
                #else
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
                break;
            default:
                state=E_NOT_OK;
                break;
        }
    }
    return state;
}

static Std_ReturnType EXT_INTx_Disable(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_DISABLE();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_DISABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_DISABLE();
                break;
            default:
                state=E_NOT_OK;
                break;
        }
    }
    return state;
}

static Std_ReturnType EXT_INTx_edge_Init(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                if(ext_INTx->int_edge==RISING_EDGE)
                {
                    EXT_INT0_RISING_EDGE_SET();
                }
                else
                {
                    EXT_INT0_FALLING_EDGE_SET();
                }
                break;
            case EXT_INT1:
                if(ext_INTx->int_edge==RISING_EDGE)
                {
                    EXT_INT1_RISING_EDGE_SET();
                }
                else
                {
                    EXT_INT1_FALLING_EDGE_SET();
                }
                break;
            case EXT_INT2:
                if(ext_INTx->int_edge==RISING_EDGE)
                {
                    EXT_INT2_RISING_EDGE_SET();
                }
                else
                {
                    EXT_INT2_FALLING_EDGE_SET();
                }
                break;
            default:
                state=E_NOT_OK;
                break;
        }
    }
    return state;
}

static Std_ReturnType EXT_INTx_Clear_Flag(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                EXT_INT0_INTERRUPT_FLAG_CLEAR();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_FLAG_CLEAR();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_FLAG_CLEAR();
                break;
            default:
                state=E_NOT_OK;
                break;
        }
    }
    return state;
}

#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_INTx_priority_Init(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                state = E_NOT_OK; /* EXT_INT0 does not support priority configuration */
                break;
            case EXT_INT1:
                if(ext_INTx->priority==HIGH_PRIORITY)
                {
                    EXT_INT1_HIGH_PRIORITY_SET();
                }
                else
                {
                    EXT_INT1_LOW_PRIORITY_SET();
                }
                break;
            case EXT_INT2:
                if(ext_INTx->priority==HIGH_PRIORITY)
                {
                    EXT_INT2_HIGH_PRIORITY_SET();
                }
                else
                {
                    EXT_INT2_LOW_PRIORITY_SET();
                }
                break;
            default:
                state=E_NOT_OK;
                break;
        }
    }
    return state;
}
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

static Std_ReturnType INT0_SetInterruptHandler(const void (*handler)(void))
{
    Std_ReturnType state=E_OK;
    if(handler==NULL)
        state=E_NOT_OK;
    else
    {
        INT0_InterruptHandler=handler;
    }
    return state;
}

static Std_ReturnType INT1_SetInterruptHandler(const void (*handler)(void))
{
    Std_ReturnType state=E_OK;
    if(handler==NULL)
        state=E_NOT_OK;
    else
    {
        INT1_InterruptHandler=handler;
    }
    return state;
}
static Std_ReturnType INT2_SetInterruptHandler(const void (*handler)(void))
{
    Std_ReturnType state=E_OK;
    if(handler==NULL)
        state=E_NOT_OK;
    else
    {
        INT2_InterruptHandler=handler;
    }
    return state;
}

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_INTx->int_source)
        {
            case EXT_INT0:
                state &= INT0_SetInterruptHandler(ext_INTx->int_handler);
                break;
            case EXT_INT1:
                state &= INT1_SetInterruptHandler(ext_INTx->int_handler);
                break;
            case EXT_INT2:
                state &= INT2_SetInterruptHandler(ext_INTx->int_handler);
                break;
            default:
                state = E_NOT_OK;
                break;
        }
    }
    return state;
}

static Std_ReturnType EXT_RBx_Disable(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        EXT_RBx_INTERRUPT_DISABLE();
    }
    return state;
}

static Std_ReturnType EXT_RBx_PIN_Init(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        state &= gpio_pin_direction_initialize(&ext_RBx->pin_config);
    }
    return state;
}

static Std_ReturnType EXT_RBx_Enable(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        EXT_RBx_INTERRUPT_ENABLE();
        #if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
        if(ext_RBx->priority==HIGH_PRIORITY)
        {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
        }
        else
        {
            INTERRUPT_GLOBAL_LOW_ENABLE();
        }
        #else
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */
    }
}

#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_RBx_priority_Init(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        if(ext_RBx->priority==HIGH_PRIORITY)
        {
            EXT_RBx_HIGH_PRIORITY_SET();
        }
        else
        {
            EXT_RBx_LOW_PRIORITY_SET();
        }
    }
    return state;
}
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

static Std_ReturnType RB4_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void))
{
    Std_ReturnType state=E_OK;
    if(handler_high==NULL || handler_low==NULL)
        state=E_NOT_OK;
    else
    {
        RB4_InterruptHandler_HIGH=handler_high;
        RB4_InterruptHandler_LOW=handler_low;
    }
    return state;
}

static Std_ReturnType RB5_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void))
{
    Std_ReturnType state=E_OK;
    if(handler_high==NULL || handler_low==NULL)
        state=E_NOT_OK;
    else
    {
        RB5_InterruptHandler_HIGH=handler_high;
        RB5_InterruptHandler_LOW=handler_low;
    }
    return state;
}

static Std_ReturnType RB6_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void))
{
    Std_ReturnType state=E_OK;
    if(handler_high==NULL || handler_low==NULL)
        state=E_NOT_OK;
    else
    {
        RB6_InterruptHandler_HIGH=handler_high;
        RB6_InterruptHandler_LOW=handler_low;
    }
    return state;
}
static Std_ReturnType RB7_SetInterruptHandler(const void (*handler_high)(void), const void (*handler_low )(void))
{
    Std_ReturnType state=E_OK;
    if(handler_high==NULL || handler_low==NULL)
        state=E_NOT_OK;
    else
    {
        RB7_InterruptHandler_HIGH=handler_high;
        RB7_InterruptHandler_LOW=handler_low;
    }
    return state;
}

static Std_ReturnType Interrupt_RBx_SetInterruptHandler(const ext_RBx_config_t* ext_RBx)
{
    Std_ReturnType state=E_OK;
    if(ext_RBx==NULL)
        state=E_NOT_OK;
    else
    {
        switch(ext_RBx->pin_config.pin)
        {
            case PIN4:
                state &= RB4_SetInterruptHandler(ext_RBx->int_handler_high, ext_RBx->int_handler_low);
                break;
            case PIN5:
                state &= RB5_SetInterruptHandler(ext_RBx->int_handler_high, ext_RBx->int_handler_low);
                break;
            case PIN6:
                state &= RB6_SetInterruptHandler(ext_RBx->int_handler_high, ext_RBx->int_handler_low);
                break;
            case PIN7:
                state &= RB7_SetInterruptHandler(ext_RBx->int_handler_high, ext_RBx->int_handler_low);
                break;
            default:
                state = E_NOT_OK;
                break;
        }
    }
    return state;
}