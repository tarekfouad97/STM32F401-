#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG , BITNUM) REG |= 1U<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1U<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1U<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1U )
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif /* BIT_MATH_H_ */