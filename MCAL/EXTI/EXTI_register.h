/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    EXTI_REGISTER          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define EXTI_MCUCR *((volatile u8 *)0x55)
#define EXTI_MCUCR_ISC00 0
#define EXTI_MCUCR_ISC01 1
#define EXTI_MCUCR_ISC10 2
#define EXTI_MCUCR_ISC11 3

#define EXTI_MCUCSR *((volatile u8 *)0x54)
#define EXTI_MCUCR_ISC2 6

#define EXTI_GICR *((volatile u8 *)0x5B)
#define EXTI_GICR_INT0 6
#define EXTI_GICR_INT1 7
#define EXTI_GICR_INT2 5

#endif