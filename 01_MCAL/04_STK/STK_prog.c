#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "STK_private.h"

#define 

void (* MSTK)
void MSTK_vInit(void){
    _MSTK->CTRL=0;
    #if _MSTK_CLK_SRC  _MSTK_CLK_AHB
    SET_BIT(MSTK->CTRL,2U);
    SET_BIT(MSTK->CTRL,1U);
    
    #elif _MSTK_CLK_SRC  _MSTK_CLK_AHB
    
    #endif
}


void MSTK_vBusyWait(u32 Copy_u32Ticks){
    /*Load Value*/
    MSTK->LOAD=Copy_u32Ticks;
    /*Start timer*/
    SET_BIT(MSTK->CTRL,0U);
    /*Wait*/
    while ((GIT_BIT(MSTK->CTRL,16U))==0U);
    /*Stop timer*/
    CLR_BIT(MSTK->CTRL,0U);
    /*Reset Values*/ 
    MSTK->LOAD=0U;
    MSTK->VAL=0U;
}

u32 MSTK_u32GetRemainingTime(void){
    u32 L_32RamingTime =0U;
    L_32RamingTime=MSTK->VAL;
    return L_32RamingTime;
}