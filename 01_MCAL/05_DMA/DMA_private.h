#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define DMA_1_BASS_ADRESS 0x40026000
#define DMA_2_BASS_ADRESS 0x40026400

typedef struct{

    volatile u32 CR;
    volatile u32 NDTR;
    volatile u32 PAR;
    volatile u32 M0AR;
    volatile u32 M1AR;
    volatile u32 FCR;

}DMA_Stream_t;

typedef struct 
{
    volatile u32 LISR;
    volatile u32 HISR;
    volatile u32 LIFCR;
    volatile u32 HIFCR;
    DMA_Stream_t StreamID[8]; 

}DMA_t;

#define DMA_1 ((DMA_t  *)DMA_1_BASS_ADRESS)
#define DMA_2 ((DMA_t  *)DMA_2_BASS_ADRESS)






#endif /*DMA_PRIVATE_H*/