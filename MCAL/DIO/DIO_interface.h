/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL				   ***********/
/***********    SWC    :    DIO_INTERFACE 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORT_HIGH 0XFF
#define PORT_LOW 0X00

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

#define DIO_PORT_OUTPUT 0XFF
#define DIO_PORT_INPUT  0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0
#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW  0

#define DIO_PORTA 2
#define DIO_PORTB 3
#define DIO_PORTC 4
#define DIO_PORTD 5

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/*************************************************************/
/**    Description :  Config pin and port direction         **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  Port,(pin),input or output            **/
/**    Options     :                                        **/
/**             Port Options:                               **/
/**                 1-DIO_PORTA                             **/
/**                 2-DIO_PORTB                             **/
/**                 3-DIO_PORTC                             **/
/**                 4-DIO_PORTD                             **/
/**             Pin Options:                                **/
/**                 1-DIO_PIN0                              **/
/**                 2-DIO_PIN1                              **/
/**                 3-DIO_PIN2                              **/
/**                 4-DIO_PIN3                              **/
/**                 5-DIO_PIN4                              **/
/**                 6-DIO_PIN5                              **/
/**                 7-DIO_PIN6                              **/
/**                 8-DIO_PIN7                              **/
/*************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir);
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Dir);

/*************************************************************/
/**    Description :  Config pin and port value             **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  Port,(pin),high or low                **/
/**    Options     :                                        **/
/**             Port Options:                               **/
/**                 1-DIO_PORTA                             **/
/**                 2-DIO_PORTB                             **/
/**                 3-DIO_PORTC                             **/
/**                 4-DIO_PORTD                             **/
/**             Pin Options:                                **/
/**                 1-DIO_PIN0                              **/
/**                 2-DIO_PIN1                              **/
/**                 3-DIO_PIN2                              **/
/**                 4-DIO_PIN3                              **/
/**                 5-DIO_PIN4                              **/
/**                 6-DIO_PIN5                              **/
/**                 7-DIO_PIN6                              **/
/**                 8-DIO_PIN7                              **/
/*************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val);
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Val);

/*************************************************************/
/**    Description :  Getting pin value                     **/
/**    Return      :  Errorstate , pin value in the memory  **/
/**    Parameters  :  Port,(pin),high or variable address   **/
/**    Options     :                                        **/
/**             Port Options:                               **/
/**                 1-DIO_PORTA                             **/
/**                 2-DIO_PORTB                             **/
/**                 3-DIO_PORTC                             **/
/**                 4-DIO_PORTD                             **/
/**             Pin Options:                                **/
/**                 1-DIO_PIN0                              **/
/**                 2-DIO_PIN1                              **/
/**                 3-DIO_PIN2                              **/
/**                 4-DIO_PIN3                              **/
/**                 5-DIO_PIN4                              **/
/**                 6-DIO_PIN5                              **/
/**                 7-DIO_PIN6                              **/
/**                 8-DIO_PIN7                              **/
/*************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);

#endif