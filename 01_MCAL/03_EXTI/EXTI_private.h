#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H




typedef struct  
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXIT_t;

typedef struct 
{
     volatile u32 unnammed;
     volatile u32 unnammed2;
     volatile u32 EXTICR1;
     volatile u32 EXTICR2;
     volatile u32 EXTICR3;
     volatile u32 EXTICR4;
     volatile u32 unnammed3;
}SYSCFG_t;


#define MEXTI       ((volatile EXIT_t*)(0x40013C00))
#define MSYSCFG     ((volatile SYSCFG_t*)(0x40013800))

#endif
