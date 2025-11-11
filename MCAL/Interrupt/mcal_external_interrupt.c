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

static Std_ReturnType EXT_RBx_PIN_Init(const ext_RBx_config_t* ext_INTx);
static Std_ReturnType EXT_RBx_Enable(const ext_RBx_config_t* ext_INTx);
static Std_ReturnType EXT_RBx_Disable(const ext_RBx_config_t* ext_INTx);
static Std_ReturnType EXT_RBx_edge_Init(const ext_RBx_config_t* ext_INTx);
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_RBx_priority_Init(const ext_RBx_config_t* ext_INTx);
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */


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
        state &= EXT_INTx_priority_Init(ext_INTx);
        #endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

        // Interrupt Callback function assignment would go here
        state &= Interrupt_INTx_SetInterruptHandler(ext_INTx);
        // Enable interrupt
        state &= EXT_INTx_Enable(ext_INTx);
    }
    return state;
}

Std_ReturnType EXT_RBx_Init(const ext_RBx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {

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
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE();
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE();
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
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
                state &= INT0_SetInterruptHandler(ext_INTx->int_handler);
                break;
            case EXT_INT2:
                state &= INT0_SetInterruptHandler(ext_INTx->int_handler);
                break;
            default:
                state = E_NOT_OK;
                break;
        }
    }
    return state;
}