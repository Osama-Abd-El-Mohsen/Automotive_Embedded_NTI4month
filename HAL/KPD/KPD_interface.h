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

/*init Keypad pins directions and init values*/
void KPD_u8iniit();

/*return pressed value with pointers*/
void KPD_u8ReturnPressed(u8 *Copy_pu8Value);

#endif