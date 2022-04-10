
#include "00_LIB/01_BIT_MATH/BIT_MATH.h"
#include "00_LIB/00_STD_TYPE/STD_TYPE.h"

#include "00_RCC/RCC_config.h"
#include "00_RCC/RCC_interface.h"
#include "00_RCC/RCC_private.h"


/*Options : HSI 
            HSE
            PLL
               */
#define CLKSRC PLL
/*Options : CRYSTAL
            RC
               */
#define HSE_SRC  RC

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
    CLR_BIT(MRCC ->CFGR,0U);
    CLR_BIT(MRCC ->CFGR,1U);

#elif   CLKSRC == HSE

        #if     HSE_SRC == CRYSTAL
                /*SET HSEON BIT*/
                SET_BIT(MRCC->CR,16U);
                CLR_BIT(MRCC->CR,18U);
                CLR_BIT(MRCC->CFGR,1U);
                SET_BIT(MRCC->CFGR,0U);
        #elif   HSE_SRC == RC
                /*SET HSEON BIT*/
                SET_BIT(MRCC->CR,16U);
                SET_BIT(MRCC->CR,18U);
                CLR_BIT(MRCC->CFGR,1U);
                SET_BIT(MRCC->CFGR,0U);
        #endif
#elif   CLKSRC == PLL
    /*SET PLLON BIT*/
    SET_BIT(MRCC->CR,24U);
    CLR_BIT(MRCC->CFGR,0U);
    SET_BIT(MRCC->CFGR,1U);
#endif
}