/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL 				   ***********/
/***********    SWC    :    KPD_INTERFACE 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/*************************************************************/
/**    Description :   Initialization keypad                **/
/**    Return      :   void				                    **/
/**    Parameters  :   void				                    **/
/*************************************************************/
void KPD_u8iniit(void);

/*************************************************************/
/**    Description :  Initialization LCD 8 or 4 Bit         **/
/**    Return      :  return pressed value in memory        **/
/**    Parameters  :  variable address to returnValue in it **/
/*************************************************************/
void KPD_u8ReturnPressed(u8 *Copy_pu8Value);

#endif