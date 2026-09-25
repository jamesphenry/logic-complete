#include "register.h"

void register_init(Register *reg)
{
    reg->value = 0;
}

void register_write(Register *reg, uint8_t value, uint8_t enable)
{
    if (enable)
    {
        reg->value = value;
    }
}

uint8_t register_read(const Register *reg)
{
    return reg->value;
}