public interface GPIOInterface {
    void set_bit(unsigned char REG, unsigned char BIT);
    void clear_bit(unsigned char REG, unsigned char BIT);
    bool get_bit(unsigned char REG, unsigned char BIT);
    void toggle_bit(unsigned char REG, unsigned char BIT, BitMode mode);
}