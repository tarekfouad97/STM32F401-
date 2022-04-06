
/********************************************************************************************************
*                           *
*********************************************************************************************************/
#include "GPIO_interface.h"
#include "STD_TYPE.h"
#include "GPIO_private.h"

/********************************************************************************************************
*                           *
*********************************************************************************************************/
void MGPIO_vSetMode(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8Mode)
{
    switch (Copy_u8PortName){
        case GPIOA_PORT : MGPIOA->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;
        case GPIOB_PORT : MGPIOB->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;  
        case GPIOC_PORT : MGPIOC->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;
        case GPIOD_PORT : MGPIOD->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;
        case GPIOE_PORT : MGPIOE->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;
        case GPIOH_PORT : MGPIOH->MODER |= (u32)(Copy_u8Mode << (2*Copy_u8PinNum)); break;
        default : /* ERROR */ break;
    }
}
/********************************************************************************************************
*                           *
*********************************************************************************************************/
void MGPIO_vPinOutType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8OutputType){
    switch (Copy_u8PortName){
        case GPIOA_PORT : MGPIOA->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;
        case GPIOB_PORT : MGPIOB->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;  
        case GPIOC_PORT : MGPIOC->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;
        case GPIOD_PORT : MGPIOD->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;
        case GPIOE_PORT : MGPIOE->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;
        case GPIOH_PORT : MGPIOH->OTYPER |= (u32)(Copy_u8OutputType << (Copy_u8PinNum)); break;
        default : /* ERROR */ break;
    }
}
/********************************************************************************************************
*                           *
*********************************************************************************************************/
void MGPIO_vPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PullType){
    switch (Copy_u8PortName){
        case GPIOA_PORT : MGPIOA->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;
        case GPIOB_PORT : MGPIOB->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;  
        case GPIOC_PORT : MGPIOC->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;
        case GPIOD_PORT : MGPIOD->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;
        case GPIOE_PORT : MGPIOE->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;
        case GPIOH_PORT : MGPIOH->PUPDR |= (u32)(Copy_u8PullType << (2*Copy_u8PinNum)); break;
        default : /* ERROR */ break;
    }
}
/********************************************************************************************************
*                           *
*********************************************************************************************************/
void MGPIO_vPinOutSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum,u8 Copy_u8PinOutSpeed){
  switch (Copy_u8PortName){
        case GPIOA_PORT : MGPIOA->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;
        case GPIOB_PORT : MGPIOB->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;  
        case GPIOC_PORT : MGPIOC->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;
        case GPIOD_PORT : MGPIOD->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;
        case GPIOE_PORT : MGPIOE->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;
        case GPIOH_PORT : MGPIOH->OSPEEDR |= (u32)(Copy_u8PinOutSpeed << (2*Copy_u8PinNum)); break;
        default : /* ERROR */ break;
}
/********************************************************************************************************
*                           *
*********************************************************************************************************/
u8 MGPIO_U8ReadData(u8 Copy_u8PortName, u8 Copy_u8PinNum){
    u8 L_u8data = 0;
    switch (Copy_u8PortName){

    }
}