/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    GIE_PROGRAM            ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "GIE/GIE_register.h"
#include "GIE/GIE_private.h"
#include "GIE/GIE_config.h"
#include "GIE/GIE_interface.h"

void GIE_voidEnable(void)
{
    /*settiing Global interrupt pin*/
    SET_BIT(GIE_SREG, GIE_SREG_I);
}

void GIE_voidDisable(void)
{
    /*clearing Global interrupt pin*/
    CLR_BIT(GIE_SREG, GIE_SREG_I);
}
