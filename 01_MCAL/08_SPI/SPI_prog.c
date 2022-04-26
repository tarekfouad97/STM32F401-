#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"




void MSPI_vinit(void){
    
    #if MSPI1_STATUS == MSPI_ENABLE
    /***************MODE SELECT*************/
    /*CLOCK PHASE AND POLARITY*/ 
        #if   MSPI1_CLOCK_MODE == MSPI_MODE0
        CLR_BIT(MSPI1->CR1,CR1_REG->CPHA); 
        CLR_BIT(MSPI1->CR1,CR1_REG->CPOL);
        #elif MSPI1_CLOCK_MODE == MSPI_MODE1
        SET_BIT(MSPI1->CR1,CR1_REG->CPHA);
        CLR_BIT(MSPI1->CR1,CR1_REG->CPOL);
        #elif MSPI1_CLOCK_MODE == MSPI_MODE2
        CLR_BIT(MSPI1->CR1,CR1_REG->CPHA);
        SET_BIT(MSPI1->CR1,CR1_REG->CPOL);
        #elif MSPI1_CLOCK_MODE == MSPI_MODE3
        SET_BIT(MSPI1->CR1,CR1_REG->CPHA);
        SET_BIT(MSPI1->CR1,CR1_REG->CPOL);   
        #endif
    /***********Master Selection************/
        #if     MSPI_MASTER_SLAVE == MSPI_MASTER
                SET_BIT(MSPI1->CR1,CR1_REG->MSTR);
        #elif   MSPI_MASTER_SLAVE == MSPI_SLAVE
                CLR_BIT(MSPI1->CR1,CR1_REG->MSTR);
        #endif
    /**************FRAME FORMAT**************/
        #if   SPI1_DATA_ORDER == MSPI_MSB_FIRST
              CLR_BIT(MSPI1->CR1,CR1_REG->LSBFIRST);
        #elif SPI1_DATA_ORDER == MSPI_LSB_FIRST
              SET_BIT(MSPI1->CR1,CR1_REG->LSBFIRST);
        #endif
    /************Software slave management****/
        #if   MSPI1_SSM_MANAGE  == SSM_SWITCH_CLOSE
                CLR_BIT(MSPI1->CR1,CR1_REG->SSM);
        #elif MSPI1_SSM_MANAGE  == SSM_SWITCH_OPEN
                SET_BIT(MSPI1->CR1,CR1_REG->SSM);
        #endif
    /*******Internal slave select VCC or GND******/
        #if   MSPI1_SSI_MODE == SSI_VCC
                SET_BIT(MSPI1->CR1,CR1_REG->SSI);
        #elif MSPI1_SSI_MODE == SSI_GND
                CLR_BIT(MSPI1->CR1,CR1_REG->SSI);
        #endif
    /***********DATA SIZE***************/
        #if     MSPI1_DATA_SIZE == MSPI_8BIT_DATA
                CLR_BIT(MSPI1->CR1,CR1_REG->DFF);
        #elif   MSPI1_DATA_SIZE == MSPI_16BIT_DATA
                SET_BIT(MSPI1->CR1,CR1_REG->DFF);
        #endif
    /*************  SPI INT EN/DISABLE****/ 
        #if     MSPI_INT_STATUS == MSPI_INT_DISABLE
                    MSPI1->CR2 =0;
        #elif   MSPI_INT_STATUS == MSPI_INT_TXIE_EABLE
                    SET_BIT(MSPI1->CR2,CR2_REG->TXEIE);
        #elif   MSPI_INT_STATUS == MSPI_INT_RXIE_ENABLE
                    SET_BIT(MSPI1->CR2,CR2_REG->RXNEIE);
        #endif
    #endif
}   
