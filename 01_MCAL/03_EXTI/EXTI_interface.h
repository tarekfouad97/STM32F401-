#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define _RAISE_STATE      1U
#define _FALL_STATE       2U
#define _ON_CHANGE_STATE  3U

#define _EXTI_PORTA 0000
#define _EXTI_PORTB 0001
#define _EXTI_PORTC 0010
#define _EXTI_PORTD 0011
#define _EXTI_PORTE 0100
#define _EXTI_PORTH 0111

#define _EXTI_LINE_0                 0U
#define _EXTI_LINE_1                 1U
#define _EXTI_LINE_2                 2U
#define _EXTI_LINE_3                 3U
#define _EXTI_LINE_4                 4U
#define _EXTI_LINE_5                 5U
#define _EXTI_LINE_6                 6U
#define _EXTI_LINE_7                 7U
#define _EXTI_LINE_8                 8U
#define _EXTI_LINE_9                 9U
#define _EXTI_LINE_10                10U
#define _EXTI_LINE_11                11U
#define _EXTI_LINE_12                12U
#define _EXTI_LINE_13                13U
#define _EXTI_LINE_14                14U
#define _EXTI_LINE_15                15U

u8 MEXTI_u8GetPending(u8 Copy_u8EXTILine);
void MEXTI_vSWTrigger(u8 Copy_u8EXTILine);
void MEXTI_vDisableLine(u8 Copy_u8EXTILine);
void MEXTI_vEnableLine(u8 Copy_u8EXTILine);
/*
_RAISE_STATE
_FALL_STATE
_ON_CHANGE_STATE
*/
void MEXTI_vEventType(u8 Copy_u8Type,u8 Copy_u8EXTILine);

 /*_EXTI_PORTA
 _EXTI_PORTB
 _EXTI_PORTC
 _EXTI_PORTD
 _EXTI_PORTE
 _EXTI_PORTH*/
void MEXTI_vSelectPort(u8 Copy_u8EXTILine,u8 Copy_u8PortID);
#endif
