#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H



/*Options : HSI 
            HSE
            PLL
               */
#define CLKSRC HSI



#if CLKSRC == HSE
   /*Options : _HSE_CRYSTAL
               _HSE_RC
               */
   #define HSE_SRC  _HSE_RC
#endif

#if CLKSRC == PLL
   /*Options : _HSE_PLL
               _HSI_PLL
                      */
 #define PLL_SRC _HSE_PLL
#endif
#endif
