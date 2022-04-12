 #include "00_LIB/00_STD_TYPE/STD_TYPE.h"
 #include "00_LIB/01_BIT_MATH/BIT_MATH.h"

 #include "02_NVIC/NVIC_private.h"
 #include "02_NVIC/NVIC_interface.h"
 #include "02_NVIC/NVIC_config.h"






void MNVIC_vEnableINT(u8 Copy_u8IntNUM)
{
    if (Copy_u8IntNUM >= 31U){
        NVIC_ISER_0 = (1U<<Copy_u8IntNUM);
    }
    else if (Copy_u8IntNUM >= 63U)
    {   
        Copy_u8IntNUM -= 32;
        NVIC_ISER_1 = (1U<<Copy_u8IntNUM);

    }   
    else if (Copy_u8IntNUM >= 85U){
        Copy_u8IntNUM -= 64;
        NVIC_ISER_2 = (1U<<Copy_u8IntNUM);
    }
    else{
        /*ERROR*/
    }    
}

void MNVIC_vDisableINT(u8 Copy_u8IntNUM){

    if (Copy_u8IntNUM >= 31U){
        NVIC_ICER_0 = (1U<<Copy_u8IntNUM);
    }
    else if (Copy_u8IntNUM >= 63U)
    {   Copy_u8IntNUM -= 32;
        NVIC_ICER_1 = (1U<<Copy_u8IntNUM);

    }
    else if (Copy_u8IntNUM >= 85U){
        Copy_u8IntNUM -= 64;
        NVIC_ICER_2 = (1U<<Copy_u8IntNUM);
    }
    else{
        /*ERROR*/
    }   
}

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM){
    if (Copy_u8IntNUM >= 31U){
        NVIC_ISPR_0 = (1U<<Copy_u8IntNUM);
    }
    else if (Copy_u8IntNUM >= 63U)
    {   Copy_u8IntNUM -= 32;
        NVIC_ISPR_1 = (1U<<Copy_u8IntNUM);

    }
    else if (Copy_u8IntNUM >= 85U){
        Copy_u8IntNUM -= 64;
        NVIC_ISPR_2 = (1U<<Copy_u8IntNUM);
    }
    else{
        /*ERROR*/
    }
}

void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM){
    if (Copy_u8IntNUM >= 31U){
        NVIC_ICPR_0 = (1U<<Copy_u8IntNUM);
    }
    else if (Copy_u8IntNUM >= 63U)
    {
        Copy_u8IntNUM -= 32;
        NVIC_ICPR_1 = (1U<<Copy_u8IntNUM);

    }
    else if (Copy_u8IntNUM >= 85U){
        Copy_u8IntNUM -= 64;
        NVIC_ICPR_2 = (1U<<Copy_u8IntNUM);
    }
    else{
        /*ERROR*/
    }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM){
    u8 L_u8ActiveFlag;
    if (Copy_u8IntNUM >= 31U){
        L_u8ActiveFlag = GET_BIT(NVIC_IABR_0,Copy_u8IntNUM);

    }
    else if (Copy_u8IntNUM >= 63U)
    {
        Copy_u8IntNUM -= 32;
        L_u8ActiveFlag = GET_BIT(NVIC_IABR_1,Copy_u8IntNUM);

    }
    else if (Copy_u8IntNUM >= 85U){
        Copy_u8IntNUM -= 64;
        L_u8ActiveFlag = GET_BIT(NVIC_IABR_2,Copy_u8IntNUM);
    }
    else{
        /*ERROR*/
    }
}



