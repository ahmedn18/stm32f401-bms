#ifndef bit_math.h
#define bit_math.h

void SET_BIT(volatile unsigned char *REG, unsigned char BIT){
   *REG |= (1 << BIT);
}

void CLEAR_BIT(volatile unsigned char *REG, unsigned char BIT){
   *REG &= ~(1 << BIT);
}

void TOGGLE_BIT(volatile unsigned char *REG, unsigned char BIT){
   *REG ^= (1 << BIT);
}

unsigned char READ_BIT(volatile unsigned char *REG, unsigned char BIT){
   return ((*REG >> BIT) & 1);
}









#endif