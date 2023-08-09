/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    SW_INTERFACE           ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_U8PULL_UP 0
#define SW_U8PULL_DOWN 1
#define SW_U8INTERNAL_PULL_UP 2

#define SW_U8SELF_LOCKING 2
#define SW_U8NOT_SELF_LOCKING 4

#define SW_PRESSED 1
#define SW_NOT_PRESSED 0

typedef struct
{
    u8 Copy_u8Port;
    u8 Copy_u8Pin;
    u8 Copy_u8ConnType;
    u8 Copy_u8LockState;
} SW_T;

/*************************************************************/
/**    Description :  returnning switch state               **/
/**    Return      :  SW_PRESSED    or   SW_NOT_PRESSED     **/
/**    Parameters  :  Takeing SW_T info struct              **/
/*************************************************************/
u8 SW_u8StatePressed(SW_T *SW_struckt, u8 *Copy_pu8Value);

#endif