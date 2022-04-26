
/********************************************************************************************************
*                           *
*********************************************************************************************************/
#include "GPIO_interface.h"
#include "STD_TYPE.h"
#include "GPIO_private.h"
#include "BIT_MATH.h"

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
        case GPIOA_PORT : MGPIOA->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        case GPIOB_PORT : MGPIOB->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        case GPIOC_PORT : MGPIOC->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        case GPIOD_PORT : MGPIOD->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        case GPIOE_PORT : MGPIOE->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        case GPIOH_PORT : MGPIOH->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << ( 2U* Copy_u8PinNum)); break;
        default : /* ERROR */ break;
	}
}
/********************************************************************************************************
*                           *
*********************************************************************************************************/
u8 MGPIO_u8ReadData(u8 Copy_u8PORT ,u8 Copy_u8PIN)
{
	u8 L_u8Data = 0 ;
	switch(Copy_u8PORT)
	{
	  case GPIOA_PORT :L_u8Data= GET_BIT(MGPIOA->IDR,Copy_u8PIN ) ; break;

	  case GPIOB_PORT :L_u8Data= GET_BIT(MGPIOB->IDR,Copy_u8PIN ) ; break;

	  case GPIOC_PORT :L_u8Data= GET_BIT(MGPIOC->IDR,Copy_u8PIN ) ; break;

	  case GPIOD_PORT :L_u8Data= GET_BIT(MGPIOD->IDR,Copy_u8PIN) ; break;

	  case GPIOE_PORT :L_u8Data= GET_BIT(MGPIOE->IDR,Copy_u8PIN) ; break;

	  case GPIOH_PORT :L_u8Data= GET_BIT(MGPIOH->IDR,Copy_u8PIN) ; break;
	  default : /*ERROR*/ break ;

	}
	return L_u8Data;

}


void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	if(Copy_u8State==LOGIC_HIGH )
	{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT :  SET_BIT(MGPIOA ->ODR,Copy_u8PinNum); break;

		case GPIOB_PORT :  SET_BIT(MGPIOB ->ODR,Copy_u8PinNum); break;

		case GPIOC_PORT :  SET_BIT(MGPIOC ->ODR,Copy_u8PinNum); break;

		case GPIOD_PORT :  SET_BIT(MGPIOD ->ODR,Copy_u8PinNum); break;

		case GPIOE_PORT :  SET_BIT(MGPIOE ->ODR,Copy_u8PinNum); break;

		case GPIOH_PORT :  SET_BIT(MGPIOH ->ODR,Copy_u8PinNum); break;

		default : /*ERROR*/ break ;
		}

	}
	else{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT :  CLR_BIT(MGPIOA ->ODR,Copy_u8PinNum); break;

		case GPIOB_PORT :  CLR_BIT(MGPIOB ->ODR,Copy_u8PinNum); break;

		case GPIOC_PORT :  CLR_BIT(MGPIOC ->ODR,Copy_u8PinNum); break;

		case GPIOD_PORT :  CLR_BIT(MGPIOD ->ODR,Copy_u8PinNum); break;

		case GPIOE_PORT :  CLR_BIT(MGPIOE ->ODR,Copy_u8PinNum); break;

		case GPIOH_PORT :  CLR_BIT(MGPIOH ->ODR,Copy_u8PinNum); break;

		default : /*ERROR*/ break ;
		}
	}
}

void MGPIO_vPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum){
	switch(Copy_u8PortName)
		{
		case GPIOA_PORT :  
			SET_BIT(MGPIOA->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOA->LCKR,16);
			while(!(GET_BIT(MGPIOA->LCKR,16))){}
		 	break;

		case GPIOB_PORT :  
			SET_BIT(MGPIOB->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOB->LCKR,16);
			while(!(GET_BIT(MGPIOB->LCKR,16))){}
		 	break;

		case GPIOC_PORT :  
			SET_BIT(MGPIOC->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOC->LCKR,16);
			while(!(GET_BIT(MGPIOC->LCKR,16))){}
		 	break;

		case GPIOD_PORT :  
			SET_BIT(MGPIOD->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOD->LCKR,16);
			while(!(GET_BIT(MGPIOD->LCKR,16))){}
		 	break;

		case GPIOE_PORT :  
			SET_BIT(MGPIOE->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOE->LCKR,16);
			while(!(GET_BIT(MGPIOE->LCKR,16))){}
		 	break;

		case GPIOH_PORT :  
			SET_BIT(MGPIOH->LCKR,Copy_u8PinNum);
			SET_BIT(MGPIOH->LCKR,16);
			while(!(GET_BIT(MGPIOH->LCKR,16))){}
		 	break;

		default : /*ERROR*/ break ;
		}
}

void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF ){
	
}