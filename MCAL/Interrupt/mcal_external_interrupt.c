/**
 * @file    mcal_external_interrupt.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   External interrupt source implementation file.
 * @version 0.1
 * @date    2025-11-1
 */

#include "mcal_external_interrupt.h"

static Std_ReturnType EXT_INTx_PIN_Init(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Enable(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Disable(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_edge_Init(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Clear_Flag(const ext_INTx_config_t* ext_INTx);
static Std_ReturnType EXT_INTx_Set_Callback(const ext_INTx_config_t* ext_INTx);
#if INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE
static Std_ReturnType EXT_INTx_priority_Init(const ext_INTx_config_t* ext_INTx);
#endif /* INTERRUPT_PRIORITY_FEATURE_ENABLE == INTERRUPT_PRIORITY_ENABLE */

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
        state &= EXT_INTx_priority_Init(ext_INTx);
        // Interrupt Callback function assignment would go here
        state &= EXT_INTx_Set_Callback(ext_INTx);
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
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_ENABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_ENABLE();
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

static Std_ReturnType EXT_INTx_Set_Callback(const ext_INTx_config_t* ext_INTx)
{
    Std_ReturnType state=E_OK;
    if(ext_INTx==NULL)
        state=E_NOT_OK;
    else
    {

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