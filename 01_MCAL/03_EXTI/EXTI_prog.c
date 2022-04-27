 #include "STD_TYPE.h"
 #include "BIT_MATH.h"

 #include "EXTI_interface.h"
 #include "EXTI_private.h"
 #include "EXTI_config.h"

static void (*EXTI0_CallBack)(void);
static void (*EXTI1_CallBack)(void);
static void (*EXTI2_CallBack)(void);

void MEXTI_vEnableLine(u8 Copy_u8EXTILine){
    SET_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_vDisableLine(u8 Copy_u8EXTILine){
    CLR_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_vSWTrigger(u8 Copy_u8EXTILine){
    SET_BIT(MEXTI->SWIER,Copy_u8EXTILine);
}
u8 MEXTI_u8GetPending(u8 Copy_u8EXTILine){
    u8 local_u8Pendingstate;
    local_u8Pendingstate = GET_BIT(MEXTI->PR,Copy_u8EXTILine);
    return local_u8Pendingstate;
}
/*
_RAISE_STATE    
_FALL_STATE     
_ON_CHANGE_STATE
*/
void MEXTI_vEventType(u8 Copy_u8Type,u8 Copy_u8EXTILine){
    switch (Copy_u8EXTILine){
        case _RAISE_STATE    :    
        SET_BIT(MEXTI->RTSR,Copy_u8EXTILine);
        CLR_BIT(MEXTI->FTSR,Copy_u8EXTILine);
        break;
        case _FALL_STATE     :    
        SET_BIT(MEXTI->FTSR,Copy_u8EXTILine);
        CLR_BIT(MEXTI->RTSR,Copy_u8EXTILine);
        break;
        case _ON_CHANGE_STATE:    
        SET_BIT(MEXTI->FTSR,Copy_u8EXTILine);
        SET_BIT(MEXTI->RTSR,Copy_u8EXTILine);
        break;
    }
}

 /*_EXTI_PORTA 
 _EXTI_PORTB 
 _EXTI_PORTC 
 _EXTI_PORTD 
 _EXTI_PORTE 
 _EXTI_PORTH*/ 
void MEXTI_vSelectPort(u8 Copy_u8EXTILine,u8 Copy_u8PortID){
    if (Copy_u8EXTILine<=3U){

            MSYSCFG->EXTICR1 &= ~ (0b1111<< (4U*Copy_u8EXTILine));
            MSYSCFG->EXTICR1 |= (Copy_u8PortID <<(4U*Copy_u8EXTILine));
    }
    else if (Copy_u8EXTILine<=7){
            Copy_u8EXTILine -=4;    
            MSYSCFG->EXTICR2 &= ~ (0b1111<< (4U*Copy_u8EXTILine));
            MSYSCFG->EXTICR2 |= (Copy_u8PortID <<(4U*Copy_u8EXTILine));
    }
    else if (Copy_u8EXTILine<=11){
            Copy_u8EXTILine -=8; 
            MSYSCFG->EXTICR3 &= ~ (0b1111<< (4U*Copy_u8EXTILine));
            MSYSCFG->EXTICR3 |= (Copy_u8PortID <<(4U*Copy_u8EXTILine));
    }
    else if (Copy_u8EXTILine<=15){
            Copy_u8EXTILine -=12; 
            MSYSCFG->EXTICR4 &= ~ (0b1111        << (4U*Copy_u8EXTILine));
            MSYSCFG->EXTICR4 |=   (Copy_u8PortID << (4U*Copy_u8EXTILine));
    }
    else{
        /*ERROR*/
    }
}

void EXTI0_VSetCallBack(void (*ptr) (void)){
    EXTI0_CallBack= ptr;
}

void EXTI1_VSetCallBack(void (*ptr) (void)){
    EXTI1_CallBack= ptr;
}

void EXTI2_VSetCallBack(void (*ptr) (void)){
    EXTI2_CallBack= ptr;
}

void EXTI0_IRQHandler(void){
    EXTI0_CallBack();
    SET_BIT(MEXTI->PR,0);
}


void EXTI1_IRQHandler(void){
    EXTI1_CallBack();
    SET_BIT(MEXTI->PR,1);
}
void EXTI2_IRQHandler(void){
    EXTI2_CallBack();
    SET_BIT(MEXTI->PR,2);
}
