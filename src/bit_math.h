#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Register access is 32-bit, so the shifted operand must be unsigned (1U):
   a signed `1 << 31` is undefined behaviour. */
#define SET_BIT(REG, BIT)    ((REG) |=  (1U << (BIT)))
#define CLEAR_BIT(REG, BIT)  ((REG) &= ~(1U << (BIT)))
#define TOGGLE_BIT(REG, BIT) ((REG) ^=  (1U << (BIT)))
#define GET_BIT(REG, BIT)    (((REG) >> (BIT)) & 1U)
#define READ_BIT(REG, BIT)   GET_BIT((REG), (BIT))

#endif
