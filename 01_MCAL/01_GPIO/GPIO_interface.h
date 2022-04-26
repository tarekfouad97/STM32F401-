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
*                                     MACRO TO DEFINE AF                                                *
*********************************************************************************************************/
#define ALTFN_0                  (0b0000)      /*!< ALTF  --> 0  */
#define ALTFN_1                  (0b0001)      /*!< ALTF  --> 1  */
#define ALTFN_2                  (0b0010)      /*!< ALTF  --> 2  */
#define ALTFN_3                  (0b0011)      /*!< ALTF  --> 3  */
#define ALTFN_4                  (0b0100)      /*!< ALTF  --> 4  */
#define ALTFN_5                  (0b0101)      /*!< ALTF  --> 5  */
#define ALTFN_6                  (0b0110)      /*!< ALTF  --> 6  */
#define ALTFN_7                  (0b0111)      /*!< ALTF  --> 7  */
#define ALTFN_8                  (0b1000)      /*!< ALTF  --> 8  */
#define ALTFN_9                  (0b1001)      /*!< ALTF  --> 9  */
#define ALTFN_10                 (0b1010)      /*!< ALTF  --> 10 */
#define ALTFN_11                 (0b1011)      /*!< ALTF  --> 11 */
#define ALTFN_12                 (0b1100)      /*!< ALTF  --> 12 */
#define ALTFN_13                 (0b1101)      /*!< ALTF  --> 13 */
#define ALTFN_14                 (0b1110)      /*!< ALTF  --> 14 */
#define ALTFN_15                 (0b1111)      /*!< ALTF  --> 15 */
/********************************************************************************************************
*                                   FUNCTION PROTOTYPE                                                  *
*********************************************************************************************************/
void MGPIO_vSetMode(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8Mode);
void MGPIO_vPinOutSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PinOutSpeed);
void MGPIO_vPinOutType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8OutputType);
void MGPIO_vPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PullType);
u8   MGPIO_U8ReadData(u8 Copy_u8PortName, u8 Copy_u8PinNum);
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);
void MGPIO_vPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum);
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF );

#endif /* GPIO_INTERFACE_H */
