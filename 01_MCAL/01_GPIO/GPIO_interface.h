#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPE.h"


/******************************************
*         MACRO TO DEFINE GPIO PORTS      *
*******************************************/
#define GPIOA_PORT                       0U
#define GPIOB_PORT                       1U
#define GPIOC_PORT                       2U
#define GPIOD_PORT                       3U
#define GPIOE_PORT                       4U
#define GPIOH_PORT                       5U
/******************************************
*         MACRO TO DEFINE GPIO PINS       *
*******************************************/
#define _PIN_0                           0U
#define _PIN_1                           1U
#define _PIN_2                           2U
#define _PIN_3                           3U
#define _PIN_4                           4U
#define _PIN_5                           5U
#define _PIN_6                           6U
#define _PIN_7                           7U
#define _PIN_8                           8U
#define _PIN_9                           9U
#define _PIN_10                         10U
#define _PIN_11                         11U
#define _PIN_12                         12U
#define _PIN_13                         13U
#define _PIN_14                         14U
#define _PIN_15                         15U
/******************************************
*           MACRO TO DEFINE MODE          *
*******************************************/
#define _MODE_INPUT                  (0b00)
#define _MODE_OUTPUT                 (0b01)
#define _MODE_ALTF                   (0b10)
#define _MODE_ANALOG                 (0b11)
/******************************************
*           MACRO TO DEFINE SPEED         *
*******************************************/
#define _OUTPUT_SPEED_LOW            (0b00)
#define _OUTPUT_SPEED_MEDIUM         (0b01)
#define _OUTPUT_SPEED_HIGH           (0b10)
#define _OUTPUT_SPEED_VERY_HIGH      (0b11)
/******************************************
*       MACRO TO DEFINE OUTPUT TYPE       *
*******************************************/
/********************************************************************************************************
*                                   MACRO TO DEFINE PULL TYPE                                            *
*********************************************************************************************************/
#define _OUTPUT_TYPE_PUSH_PULL         (0U)
#define _OUTPUT_TYPE_OPEN_DRAIN        (1U)
/********************************************************************************************************
*                                   MACRO TO DEFINE PULL TYPE                                            *
*********************************************************************************************************/
#define _PULL_OFF                    (0b00)  
#define _PULL_UP                     (0b01)  
#define _PULL_DOWEN                  (0b10)  
/********************************************************************************************************
*                                   FUNCTION PROTOTYPE                                                  *
*********************************************************************************************************/
void MGPIO_vSetMode(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8Mode);
void MGPIO_vPinOutSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PinOutSpeed);
void MGPIO_vPinOutType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8OutputType);
void MGPIO_vPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PullType);
u8   MGPIO_U8ReadData(u8 Copy_u8PortName, u8 Copy_u8PinNum);
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);



#endif /* GPIO_INTERFACE_H */
