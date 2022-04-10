#ifdef  RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "00_LIB/00_STD_TYPE/STD_TYPE.h"

typedef enum {
    AHB1 = 0,
    AHB2,
    APB1,
    APB2
}BusName_t;





/************************************************************************
*    Macros enable RCC AHB1 peripheral reset register (RCC_AHB1RSTR)    *
*************************************************************************/
#define PERIPHERAL_EN_GPIOA            0U
#define PERIPHERAL_EN_GPIOB            1U
#define PERIPHERAL_EN_GPIOC            2U
#define PERIPHERAL_EN_GPIOD            3U
#define PERIPHERAL_EN_GPIOE            4U    
#define PERIPHERAL_EN_GPIOH            7U
#define PERIPHERAL_EN_CRCEN           12U
#define PERIPHERAL_EN_DMA1EN          21U
#define PERIPHERAL_EN_DMA2EN          22U
/************************************************************************
*    Macros enable RCC AHB2 peripheral reset register (RCC_AHB2ENR)    *
*************************************************************************/
#define PERIPHERAL_EN_OTGFSEN          7U
/************************************************************************
*    Macros enable RCC APB1 peripheral reset register (RCC_APB1ENR)    *
*************************************************************************/
#define PERIPHERAL_EN_TIM2             0U    
#define PERIPHERAL_EN_TIM3             1U   
#define PERIPHERAL_EN_TIM4             2U   
#define PERIPHERAL_EN_TIM5             3U 
#define PERIPHERAL_EN_WWDG            11U 
#define PERIPHERAL_EN_SPI2            14U 
#define PERIPHERAL_EN_SPI3            15U
#define PERIPHERAL_EN_USART2          17U
#define PERIPHERAL_EN_I2C1            21U
#define PERIPHERAL_EN_I2C2            22U
#define PERIPHERAL_EN_I2C3            23U
#define PERIPHERAL_EN_PWR             28U
/************************************************************************
*    Macros enable RCC APB2 peripheral reset register (RCC_APB2ENR)    *
*************************************************************************/
#define PERIPHERAL_EN_TIM1             0U    
#define PERIPHERAL_EN_UART1            4U   
#define PERIPHERAL_EN_UART6            5U   
#define PERIPHERAL_EN_ADC1             8U 
#define PERIPHERAL_EN_SDIO            11U 
#define PERIPHERAL_EN_SPI1            12U 
#define PERIPHERAL_EN_SPI4            13U
#define PERIPHERAL_EN_SYSCFG          14U
#define PERIPHERAL_EN_TIMER9          16U
#define PERIPHERAL_EN_TIMER10         17U
#define PERIPHERAL_EN_TIMER11         18U
/************************************************************************
*                           Function Prototypes                         *
*************************************************************************/
/*Function to Enable a specific Prepheral
    Options for BusName :
                        AHB1
                        AHB2
                        APB1
                        APB2
    Options for Copy_u8PerNum :
                        Bus Register Macro 
*/
void MRCC_vEnableClock(BusName_t BusName,u8 Copy_u8PerNum );
/*Function to Disable a specific Prepheral
    Options for BusName :
                        AHB1
                        AHB2
                        APB1
                        APB2
    Options for Copy_u8PerNum :
                        Bus Register Macro 
*/
void MRCC_vDisableClock(BusName_t BusName,u8 Copy_u8PerNum);

/*Function to Enable Security System*/
void MRCC_vEnableSecuritySystem(void);
/*Function to Disable Security System*/
void MRCC_vDisableSecuritySystem(void);


#endif /*RCC_INTERFACE_H*/