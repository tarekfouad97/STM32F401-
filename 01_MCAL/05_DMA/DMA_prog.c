#include "00_LIB/01_BIT_MATH/BIT_MATH.h"
#include "00_LIB/00_STD_TYPE/STD_TYPE.h"
#include "DMA_config.h"
#include "DMA_interface.h"
#include "DMA_private.h"

void MDMA2_vStreamInit(void){
    if (DMA_2->StreamID[0].CR==1){
        DMA_2->StreamID[0].CR&=~(1U<<0);
        while (DMA_2->StreamID[0].CR==1){}
        }
    else{
        
    }   
  
    SET_BIT(DMA_2->StreamID[0].CR,16);
    SET_BIT(DMA_2->StreamID[0].CR,17);

    SET_BIT(DMA_2->StreamID[0].CR,7);
    CLR_BIT(DMA_2->StreamID[0].CR,6); 

    SET_BIT(DMA_2->StreamID[0].CR,12);
    CLR_BIT(DMA_2->StreamID[0].CR,11); 

    SET_BIT(DMA_2->StreamID[0].CR,14);
    CLR_BIT(DMA_2->StreamID[0].CR,13);

    CLR_BIT(DMA_2->StreamID[0].FCR,2);
    SET_BIT(DMA_2->StreamID[0].FCR,1);
    SET_BIT(DMA_2->StreamID[0].FCR,0);
    
    SET_BIT(DMA_2->StreamID[0].CR,10);
    SET_BIT(DMA_2->StreamID[0].CR,9);

    SET_BIT(DMA_2->StreamID[0].CR,4);


}


void MDMA2_vSetAdresses (u32 *Ptr_SrcAdd,u32* Ptr_DisAdd,u32 Copy_u32Size){
    DMA_2->StreamID[0].PAR =(u32)Ptr_SrcAdd;
    DMA_2->StreamID[0].M0AR=(u32)Ptr_DisAdd;
    DMA_2->StreamID[0].NDTR=(u32)Copy_u32Size;
}

void MDMA_vEnable(void){
    SET_BIT(DMA_2->LIFCR,0);
    SET_BIT(DMA_2->LIFCR,2);
    SET_BIT(DMA_2->LIFCR,3);
    SET_BIT(DMA_2->LIFCR,4);
    SET_BIT(DMA_2->LIFCR,5);
    SET_BIT(DMA_2->StreamID[0].CR,0);
}
