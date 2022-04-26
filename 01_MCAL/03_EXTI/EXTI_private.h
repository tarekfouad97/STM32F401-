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


#define MEXTI ((volatile EXIT_t*)(0x40013C00))


#endif