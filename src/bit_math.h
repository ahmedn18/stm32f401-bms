# define SET_BIT(REG,BIT)     (REG |= (1 << BIT))
# define CLEAR_BIT(REG,BIT)   (REG &= ~(1 << BIT))
# define TOGGLE_BIT(REG,BIT)  (REG ^= (1 << BIT))
# define GET_BIT(REG,BIT)     ((REG & (1 << BIT)) ? 1 : 0)