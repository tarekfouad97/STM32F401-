#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

struct 
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}MSTK_t;

#define SYSTICK_BASE_ADDRESS 0xE000E010
#define MSTK ((MSTK_t *)(SYSTICK_BASE_ADDRESS))

#endif