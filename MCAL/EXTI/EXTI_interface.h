/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    EXTI_INTERFACE         ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

// typedef union
// {
//     u8 Allbits;
//     struct
//     {
//         u8 ISC0 : 2;
//         u8 ISC1 : 2
//     };

// } EXTI_MCUCR_t;
// volatile EXTI_MCUCR_t EXTI_MCUCR = (volatile EXTI_MCUCR_t)(0x55);

#define  EXTI_INT_LOGIC_LOW 0
#define  EXTI_INT_LOGIC_HIGH 1
#define  EXTI_INT_FALLING_EDGE 2
#define  EXTI_INT_RISING_EDGE 3

#define EXTI_INT2_FALLING_EDGE 2
#define EXTI_INT2_RISING_EDGE 3

/*************************************************************/
/**    Description :    Changing Interrupt mode             **/
/**    Return      :    ErrorState                          **/
/**    Parameters  :    interrupt                           **/
/**    Options     :                                        **/
/**             Options:                                    **/
/**                 1-EXTI_INT_LOGIC_LOW                    **/
/**                 2-EXTI_INT_LOGIC_HIGH                   **/
/**                 3-EXTI_INT_FALLING_EDGE                 **/
/**                 4-EXTI_INT_RISING_EDGE                  **/
/*************************************************************/
u8 EXTI_u8INT0_Mode(u8 Copy_u8INT0Mode);
u8 EXTI_u8INT1_Mode(u8 Copy_u8INT1Mode);
u8 EXTI_u8INT2_Mode(u8 Copy_u8INT1Mode);

/*************************************************************/
/**    Description :    Enable and Disable interuppt        **/
/**    Return      :    void                                **/
/**    Parameters  :    void                                **/
/*************************************************************/
void EXTI_voidINT0_Enable(void);
void EXTI_voidINT1_Enable(void);
void EXTI_voidINT2_Enable(void);

void EXTI_voidINT0_Disable(void);
void EXTI_voidINT1_Disable(void);
void EXTI_voidINT2_Disable(void);

/*************************************************************/
/**    Description :    Callback ISR function               **/
/**    Return      :    void                                **/
/**    Parameters  :    pointer to function                 **/
/*************************************************************/
void EXTI_voidINT0_SetCallbackFunc(void (*Copy_pvInt0Func) (void));
void EXTI_voidINT1_SetCallbackFunc(void (*Copy_pvInt1Func) (void));
void EXTI_voidINT2_SetCallbackFunc(void (*Copy_pvInt2Func) (void));

#endif