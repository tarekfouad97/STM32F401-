/****************************************************************
* Auther:   Tarek Fouad                                         *
* Version:  V01                                                 *
* Date :    11 April 2022                                       *
*****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPE.h"

#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"



void MRCC_vEnableClock(BusName_t BusName,u8 Copy_u8PerNum){

    switch(BusName){
        case AHB1 : SET_BIT( MRCC -> AHB1ENR , Copy_u8PerNum ); break;
        case AHB2 : SET_BIT( MRCC -> AHB2ENR , Copy_u8PerNum ); break;
        case APB1 : SET_BIT( MRCC -> APB1ENR , Copy_u8PerNum ); break;
        case APB2 : SET_BIT( MRCC -> APB2ENR , Copy_u8PerNum ); break;
        default:/*ERROR*/                                       break;
    } 
}

void MRCC_vDisableClock(BusName_t BusName,u8 Copy_u8PerNum){

    switch(BusName){
        case AHB1 : CLR_BIT( MRCC-> AHB1ENR , Copy_u8PerNum ); break;
        case AHB2 : CLR_BIT( MRCC-> AHB2ENR , Copy_u8PerNum ); break;
        case APB1 : CLR_BIT( MRCC-> APB1ENR , Copy_u8PerNum ); break;
        case APB2 : CLR_BIT( MRCC-> APB2ENR , Copy_u8PerNum ); break;
        default:/*ERROR*/                                      break;
    } 
}

void MRCC_vEnableSecuritySystem(void) {
    SET_BIT(RCC_TypeDef->CR,CSSON);
}

void MRCC_vDisableSecuritySystem(void) {

    CLR_BIT( RCC_TypeDef->CR,CSSON );
}

void MRCC_vInitSystemCLK(void){
#if     CLKSRC == HSI
    /*SET HSION BIT*/
    SET_BIT(MRCC ->CR,0U);
    /*select the system clock source*/
    CLR_BIT(MRCC ->CFGR,0U);
    CLR_BIT(MRCC ->CFGR,1U);

#elif   CLKSRC == HSE

        #if     HSE_SRC == _HSE_CRYSTAL
                /*SET HSEON BIT*/
                SET_BIT(MRCC->CR,16U);
                CLR_BIT(MRCC->CR,18U);
               /*select the system clock source*/
                CLR_BIT(MRCC->CFGR,1U);
                SET_BIT(MRCC->CFGR,0U);
        #elif   HSE_SRC == _HSE_RC
                /*SET HSEON BIT*/
                SET_BIT(MRCC->CR,16U);
                SET_BIT(MRCC->CR,18U);
                /*select the system clock source*/
                CLR_BIT(MRCC->CFGR,1U);
                SET_BIT(MRCC->CFGR,0U);
        #endif
#elif   CLKSRC == PLL
        #if PLL_SRC == _HSE_PLL
            /*HSE ON*/
            SET_BIT(MRCC->CR,16U);
            /*PLL OFF*/
            CLR_BIT(MRCC->CR,24U);
            /*PLL from HSE*/
            SET_BIT(MRCC->PLLCFGR,22U);
            /*SET PLLON BIT*/
            SET_BIT(MRCC->CR,24U);
            /*select the system clock source*/
            CLR_BIT(MRCC->CFGR,0U);
            SET_BIT(MRCC->CFGR,1U);

        #elif PLL_SRC == _HSI_PLL
            /*Enable HSI*/
            SET_BIT(MRCC ->CR,0U);
            /*Disable PLL*/
            CLR_BIT(MRCC->CR,24);
            /*PLL from HSI*/
            CLR_BIT(MRCC->CR,22U);
            /*SET PLLON BIT*/
            SET_BIT(MRCC->CR,24U);
            /*select the system clock source*/
            CLR_BIT(MRCC->CFGR,0U);
            SET_BIT(MRCC->CFGR,1U);
        #else
            /*Error*/
        #endif
    #else
        /*Error*/    
#endif
}



void MRCC_vOutMCO_1(u8 Copy_u8MC1_0SRC){

    switch(Copy_u8MC1_0SRC){
        case MCO_1_LSE : 
            SET_BIT(MRCC->CFGR,21);
            CLR_BIT(MRCC->CFGR,22);
            break;
        case MCO_1_HSE :
            CLR_BIT(MRCC->CFGR,21);
            SET_BIT(MRCC->CFGR,22);
            break;
        case MCO_1_HSI :
            CLR_BIT(MRCC->CFGR,21);
            CLR_BIT(MRCC->CFGR,22);
            break;
        case MCO_1_PLL :
            SET_BIT(MRCC->CFGR,21);
            SET_BIT(MRCC->CFGR,22);
            break;
        default:/*ERROR*/break;

    }

}



void MRCC_vOutMCO_1Pre(MCO_1_Pre_t Copy_tPreMco_1 ){
    switch (Copy_tPreMco_1)
    {
    case MCO_1_DiV_1:
        CLR_BIT(MRCC->CFGR,26);
        break;
    case MCO_1_DiV_2:
        SET_BIT(MRCC->CFGR,26);
        CLR_BIT(MRCC->CFGR,25);
        CLR_BIT(MRCC->CFGR,24);
        break;
    case MCO_1_DiV_3:
        SET_BIT(MRCC->CFGR,26);
        SET_BIT(MRCC->CFGR,24);
        CLR_BIT(MRCC->CFGR,25);
        break;
    case MCO_1_D,iV_4:
        SET_BIT(MRCC->CFGR,26);
        SET_BIT(MRCC->CFGR,25);
        CLR_BIT(MRCC->CFGR,24);
        break;
    case MCO_1_DiV_5:
        SET_BIT(MRCC->CFGR,26);
        SET_BIT(MRCC->CFGR,25);
        SET_BIT(MRCC->CFGR,24);
        break;                

    default:
    /*ERROR*/
        break;
    }
}


void MRCC_vInitSystemCLK_Systick(u8 Copy_u8Dev){
    SET_BIT(MRCC ->CR,0U);
    /*select the system clock source*/
    CLR_BIT(MRCC ->CFGR,0U);
    CLR_BIT(MRCC ->CFGR,1U);
    if(Copy_u8Dev==1){
        SET_BIT(MRCC ->CFGR,7U);
        CLR_BIT(MRCC ->CFGR,6U);
        CLR_BIT(MRCC ->CFGR,5U);
        CLR_BIT(MRCC ->CFGR,4U);
    }
    else{
        /*Misra*/
    }
}