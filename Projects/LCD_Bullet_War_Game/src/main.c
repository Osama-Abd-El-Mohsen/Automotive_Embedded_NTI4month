#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "LCD/LCD_interface.h"
#include "EXTI/EXTI_interface.h"
#include "GIE/GIE_interface.h"
#include "SW/SW_interface.h"
#include "util/delay.h"
#include "assits.h"

/*Declration variabls*/
u8 INT0_CursorCounter = ZERO;
u8 INT1_CursorCounter = ZERO;
u8 Local_u8temp0CursorPos = ZERO;
u8 Local_u8temp1CursorPos = ZERO;
u8 Local_sw1State;
u8 Local_sw2State;

u8 Local_u8BulletRow0 = DEAFULT_VALUE;
u8 Local_u8BulletRow1 = DEAFULT_VALUE;
u8 Local_u8BulletCol0 = DEAFULT_VALUE;
u8 Local_u8BulletCol1 = DEAFULT_VALUE;

u8 Local_u8WinState = NO_WINNER;

/*Declration 2 switchs information struct */
SW_T sw2 = {
    DIO_PORTD,
    DIO_PIN4,
    SW_U8INTERNAL_PULL_UP};
SW_T sw1 = {
    DIO_PORTD,
    DIO_PIN5,
    SW_U8INTERNAL_PULL_UP};

void main(void)
{
  /*setting int pin as input*/
  DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
  DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);

  /*setting int pin as internal interuupt*/
  DIO_u8SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);
  DIO_u8SetPinValue(DIO_PORTD, DIO_PIN3, DIO_PIN_HIGH);

  /*Init LCD and sending welcome msg*/
  LCD_voidINIT();
  LCD_u8SendString(FIRST_ROW, FIRST_COL, "Welcome To The..Bullet game");
  _delay_ms(MSG_DELAY);
  LCD_voidClear();

  /*init INT0,INT1*/
  EXTI_u8INT0_Mode(EXTI_INT_FALLING_EDGE);
  EXTI_u8INT1_Mode(EXTI_INT_FALLING_EDGE);

  /*Enable Global Interrupt pin*/
  GIE_voidEnable();

  /*Enable INT0,INT1 pin*/
  EXTI_voidINT0_Enable();
  EXTI_voidINT1_Enable();

  /*Setting Callback Function*/
  EXTI_voidINT0_SetCallbackFunc(INT0_ISR);
  EXTI_voidINT1_SetCallbackFunc(INT1_ISR);

  while (ONE)
  {
    Game_init();
    while (Local_u8WinState == NO_WINNER)
    {
      /*Getting Switches readings*/
      SW_u8StatePressed(&sw1, &Local_sw1State);
      SW_u8StatePressed(&sw2, &Local_sw2State);

      if (Local_sw1State == SW_PRESSED)
      {
        Local_u8BulletRow0 = INT0_CursorCounter;
        Local_u8BulletRow1 = INT1_CursorCounter;
        for (LoopCounter0 = FIRST_COL + ONE; LoopCounter0 < LAST_COL + ONE; LoopCounter0++)
        {
          if (LoopCounter0 == ONE)
          {
            LoopCounter0 = ONE;
          }
          else
          {
            LCD_u8SendString(Local_u8BulletRow0, LoopCounter0 - ONE, " ");
          }
          Local_u8BulletCol0 = ZERO + LoopCounter0;
          LCD_voidWriteSpechialChar(Left_Bullet, THIRD_SPECHIAL_CHAR, Local_u8BulletRow0, Local_u8BulletCol0);

          _delay_ms(BULLET_ANIMATION_DELAY);

          if (LoopCounter0 == LAST_COL)
          {
            LCD_voidGoToRow_Col(Local_u8BulletRow0, Local_u8BulletCol0);
            LCD_voidSendData(' ');
          }
        }
      }

      if (Local_sw2State == SW_PRESSED)
      {
        Local_u8BulletRow0 = INT0_CursorCounter;
        Local_u8BulletRow1 = INT1_CursorCounter;
        for (LoopCounter1 = LAST_COL; LoopCounter1 > FIRST_COL; LoopCounter1--)
        {
          if (LoopCounter1 == LAST_COL)
          {
            LoopCounter1 = LoopCounter1;
          }
          else
          {
            LCD_u8SendString(INT1_CursorCounter, LoopCounter1, " ");
          }
          Local_u8BulletCol1 = LoopCounter1 - ONE;

          LCD_voidWriteSpechialChar(Right_Bullet, THIRD_SPECHIAL_CHAR, Local_u8BulletRow1, Local_u8BulletCol1);

          _delay_ms(BULLET_ANIMATION_DELAY);

          if (LoopCounter0 == FIRST_COL + 1)
          {
            LCD_voidGoToRow_Col(Local_u8BulletRow1, Local_u8BulletCol1);
            LCD_voidSendData(' ');
          }
        }
      }

      if ((Local_u8BulletRow0 == INT1_CursorCounter) && (Local_u8BulletCol0 == LAST_COL))
      {
        LCD_voidClear();
        LCD_u8SendString(FIRST_ROW, LAST_ROW, "Player 1 Win");
        Local_u8WinState = WINNER;
        _delay_ms(WIN_DELAY);
      }

      else if ((Local_u8BulletRow1 == INT0_CursorCounter) && (Local_u8BulletCol1 == FIRST_COL))
      {
        LCD_voidClear();
        LCD_u8SendString(FIRST_ROW, LAST_ROW, "Player 2 Win");
        Local_u8WinState = WINNER;
        _delay_ms(WIN_DELAY);
      }
      Local_u8BulletCol0 = DEAFULT_VALUE;
      Local_u8BulletCol1 = DEAFULT_VALUE;
    }
    LCD_voidClear();
  }
}

/*inint game clearing variabls and sending welcome msg*/
void Game_init(void)
{
  /*Loading effect and init position of paddles*/
  Loading_Effect();
  LCD_voidClear();
  LCD_voidWriteSpechialChar(Paddle, FIRST_SPECHIAL_CHAR, FIRST_ROW, FIRST_COL);
  LCD_u8SendString(LAST_ROW, FIRST_COL, "P1");
  LCD_voidWriteSpechialChar(Paddle, SECOND_SPECHIAL_CHAR, FIRST_ROW, LAST_COL);
  LCD_u8SendString(LAST_ROW, LAST_COL - ONE, "P2");
  _delay_ms(MSG_DELAY);
  LCD_u8SendString(LAST_ROW, LAST_COL - ONE, "  ");
  LCD_u8SendString(LAST_ROW, FIRST_COL, "  ");

  /*clearing init variabls*/
  Local_u8WinState = NO_WINNER;
  LCD_voidGoToRow_Col(Local_u8BulletRow0, Local_u8BulletCol0);
  LCD_voidSendData(' ');
  LCD_voidGoToRow_Col(Local_u8BulletRow1, Local_u8BulletCol1);
  LCD_voidSendData(' ');
  INT0_CursorCounter = ZERO;
  INT1_CursorCounter = ZERO;
  Local_u8temp0CursorPos = ZERO;
  Local_u8temp1CursorPos = ZERO;
}
/*Loading Effect Function*/
void Loading_Effect(void)
{
  u8 Local_u8ColCounter = FIRST_COL;
  LCD_u8SendString(FIRST_ROW, FIRST_COL, "Loading ");

  for (u8 i = FIRST_ROW; i < LAST_COL + ONE; i++)
  {
    LCD_u8SendString(LAST_ROW, Local_u8ColCounter, "/");
    _delay_ms(LOADING_ANIMATION);
    LCD_voidGoToRow_Col(LAST_ROW, Local_u8ColCounter);
    LCD_u8SendString(LAST_ROW, Local_u8ColCounter, ".");
    _delay_ms(LOADING_ANIMATION);
    Local_u8ColCounter++;
  }
}

/*Interrupt 0 ISR Function*/
void INT0_ISR(void)
{
  Local_u8temp0CursorPos = INT0_CursorCounter;
  INT0_CursorCounter++;
  if (INT0_CursorCounter == TWO)
  {
    INT0_CursorCounter = FIRST_ROW;
  }
  LCD_u8SendString(Local_u8temp0CursorPos, FIRST_COL, "  ");
  LCD_u8SendString(INT0_CursorCounter, FIRST_COL, "  ");

  LCD_voidWriteSpechialChar(Paddle, FIRST_SPECHIAL_CHAR, INT0_CursorCounter, FIRST_COL);
}

/*Interrupt 1 ISR Function*/
void INT1_ISR(void)
{
  Local_u8temp1CursorPos = INT1_CursorCounter;
  INT1_CursorCounter++;
  if (INT1_CursorCounter == TWO)
  {
    INT1_CursorCounter = FIRST_ROW;
  }
  LCD_u8SendString(Local_u8temp1CursorPos, LAST_COL - ONE, "  ");
  LCD_u8SendString(INT1_CursorCounter, LAST_COL - ONE, "  ");

  LCD_voidWriteSpechialChar(Paddle, SECOND_SPECHIAL_CHAR, INT1_CursorCounter, LAST_COL);
}
