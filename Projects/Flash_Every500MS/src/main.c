#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "SSD/SSD_interface.h"
#include "LED/LED_interface.h"
#include "SW/SW_interface.h"
// #include "avr/io.h"
int main()
{

  while (1)
  {
    
    LED_u8PortTurnOn(DIO_PORTB,LED_U8SOURCE);
    _delay_ms(500);
    LED_u8PortTurnOff(DIO_PORTB,LED_U8SOURCE);
    _delay_ms(500);
  }

  return 0;
}