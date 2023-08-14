#include <LIB/STD_TYPES.h>
#include <LIB/BIT_MATH.h>

#include "DIO/DIO_interface.h"
#include "SPI/SPI_interface.h"
#include "util/delay.h"

void main(void)
{
  /*setting master pin to output*/

  
  SPI_voidMasterInit();
  u8 data = 4;
  u8 counter=0;

  while (1)
  {    
    counter++;
    if (counter==2)
    {
      counter=0;
    }
    
    data = SPI_u8Transfer(counter);
  
    _delay_ms(100);
  
  }
}