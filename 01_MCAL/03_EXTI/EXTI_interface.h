#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void MEXTI_vInit(void);
void MEXTI_vSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode);
void MEXTI_vEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_vDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_vSWTrigger(u8 Copy_u8EXTILine);
void MEXTI_vSetCallBack(void (*ptr) (void));

#endif