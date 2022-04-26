#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_1_BASE_ADDRESS 0x40013000 
#define SPI_2_BASE_ADDRESS 0x40013800 
#define SPI_3_BASE_ADDRESS 0x40013C00 
#define SPI_4_BASE_ADDRESS 0x40013400 
 
#define _CR1_CPHA           1U
#define _CR1_CPOL           2U
#define _CR1_MSTR           3U
#define _CR1_BR             6U
#define _CR1_SPE            7U
#define _CR1_LSBFIRST       8U   
#define _CR1_SSI            9U
#define _CR1_SSM            10U
#define _CR1_DFF            11U
#define _CR1_CRCNEXT        12U 
#define _CR1_BIDIOE         13U
#define _CR1_BIDIMODE       14U

typedef struct 
{
 volatile u32  CPHA     :1;
 volatile u32  CPOL     :1;
 volatile u32  MSTR     :1;
 volatile u32  BR       :3;
 volatile u32  SPE      :1;
 volatile u32  LSBFIRST :1;
 volatile u32  SSI      :1;
 volatile u32  SSM      :1;
 volatile u32  DFF      :1;
 volatile u32  CRCNEXT  :1;
 volatile u32  BIDIOE   :1;
 volatile u32  BIDIMODE :1;
 volatile u32  RESERVED :16;
}CR1_t;
typedef volatile CR1_t* CR1_REG;
typedef struct
{
    volatile u16 RXDMAEN :1;    
    volatile u16 TXDMAEN :1;    
    volatile u16 SSOE    :1;
    volatile u16         :1;
    volatile u16 FRF     :1;    
    volatile u16 ERRIE   :1;
    volatile u16 RXNEIE  :1;
    volatile u16 TXEIE   :1; 
    volatile u16         :8;
}CR2_t;
typedef volatile CR2_t* CR2_REG;




typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;
#define MSPI1 ((SPI_t*)0x40013000) 
#define MSPI2 ((SPI_t*)0x40013800) 
#define MSPI3 ((SPI_t*)0x40013C00) 
#define MSPI4 ((SPI_t*)0x40013400) 

#endif