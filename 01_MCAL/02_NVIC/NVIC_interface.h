#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
void MNVIC_vEnableINT(u8 Copy_u8IntNUM);
void MNVIC_vDisableINT(u8 Copy_u8IntNUM);
void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM);
void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM);
void MNVIC_vSerGroupSubGroupPriority(u8 Copy_u8IntNUM);










#endif
