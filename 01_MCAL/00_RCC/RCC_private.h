


/****************************************************************
*              guard of file will call on time in .c            *
*****************************************************************/ 
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#include "00_LIB/00_STD_TYPE/STD_TYPE.h"

/****************************************************************
*                             Macros                            *
*           Base_Address is				0x40023800              *
****************************************************************/
#define MRCC_BASE_ADDRESS   0x40023800 
/****************************************************************
*                          Struct Macros                        * 
*                        Base_Address RRC                       *                
****************************************************************/                       
#define MRCC                ((RCC_TypeDef*)MRCC_BASE_ADDRESS)

#define CSSON 19U

typedef struct {
  volatile u32 CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */ 
  volatile u32 PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile u32 CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile u32 CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile u32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile u32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile u32 RESERVED0;     /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */ 
  volatile u32 RESERVED1;     /*!< Reserved, 0x1C                                                                    */
  volatile u32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile u32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  volatile u32 RESERVED2[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile u32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile u32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile u32 RESERVED3;     /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */   
  volatile u32 RESERVED4;     /*!< Reserved, 0x3C                                                                    */
  volatile u32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile u32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  volatile u32 RESERVED5[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile u32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile u32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile u32 RESERVED6;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */ 
  volatile u32 RESERVED7;     /*!< Reserved, 0x5C                                                                    */
  volatile u32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile u32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  volatile u32 RESERVED8[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile u32 BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile u32 CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  volatile u32 RESERVED9[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile u32 SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile u32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile u32 RESERVED10[1]; /*!< Reserved, 0x88                                                                    */ 
  volatile u32 DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;

#endif /*RCC_PRIVATE_H*/