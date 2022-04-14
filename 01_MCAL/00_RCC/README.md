
# Reset and Clock Register (RCC)
---

## 1. Processor Clock Selection
| Clock | Source | MHz |
| ----------- | ----------- |----------- |
| HSI | RC  | 8MHz |
| HSE | RC  | up to 25 MHz |
|     | Crystal | from 4 MHz to 25 Mhz|
| PLL | HSI | | 
|     | HSE | | 
---
## 2. Enable/Disable Peripheral Clock
#### How peripheral is enabled ?
by periodiclly checking the enable bit.\
by defualt all peripherals are disconnected from the clock source.\
Expect
- RCC
- Core Peripherals
---
## Functions


- Function To Enable Prepheral :
`
void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum );
`
- Function To Disable Prepheral :
`
void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum );
`
- Function To Enable Security System :
`
void MRCC_vEnableSecuritySystem(void);
`

- Function To Disable Security System :
`
void MRCC_vDisableSecuritySystem(void);
`

- Function To Set System CLK :
`
void MRCC_vInitSystemCLK(void);
`

- Function To Set MCO_1 Output
`
void MRCC_vOutMCO_1(u8 Copy_u8MC1_0SRC );
`

- Function To Set MCO_1 Output Prescaller :
 `
void MRCC_vOutMCO_1Pre(MCO_1_Pre_t Copy_tPreMco_1 );
`
