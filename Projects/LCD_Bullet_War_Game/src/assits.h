#ifndef ASSITS_H_
#define ASSITS_H_

/*Functions Prototype*/
void Loading_Effect(void);
void INT0_ISR(void);
void INT1_ISR(void);
void Game_init(void);

/*Spechial charachters arrays*/
u8 Paddle[] = {
    0B11100,
    0B11100,
    0B11100,
    0B11100,
    0B11100,
    0B11100,
    0B11100,
    0B11100};

u8 Right_Bullet[] = {
    0B00000,
    0B00000,
    0B00111,
    0B01111,
    0B00111,
    0B00000,
    0B00000,
    0B00000};

u8 Left_Bullet[] = {
    0B00000,
    0B00000,
    0B11100,
    0B11110,
    0B11100,
    0B00000,
    0B00000,
    0B00000};

#define DEAFULT_VALUE 20

#define LEFT_BULLET_INIT_POS 1
#define RIGHT_BULLET_INIT_POS 14

#define FIRST_ROW 0
#define LAST_ROW 1

#define FIRST_COL 0
#define LAST_COL 15

#define THREE 3
#define FIVE 5
#define NINE 9

#define WINNER 1
#define NO_WINNER 0

#define MSG_DELAY 400
#define LOADING_ANIMATION 10
#define BULLET_ANIMATION_DELAY 50
#define WIN_DELAY 1000


#define FIRST_SPECHIAL_CHAR 1
#define SECOND_SPECHIAL_CHAR 2
#define THIRD_SPECHIAL_CHAR 3

u8 LoopCounter0 = LEFT_BULLET_INIT_POS;
u8 LoopCounter1 = RIGHT_BULLET_INIT_POS;
#endif