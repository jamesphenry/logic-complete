#include "flags.h"

void flags_init(Flags *flags)
{
    flags->zero = 0;
    flags->carry = 0;
    flags->borrow = 0;
    flags->negative = 0;
    flags->overflow = 0;
}

void flags_write_zero(Flags *flags, uint8_t value)
{
    flags->zero = value;
}

void flags_write_carry(Flags *flags, uint8_t value)
{
    flags->carry = value;
}

void flags_write_borrow(Flags *flags, uint8_t value)
{
    flags->borrow = value;
}

void flags_write_negative(Flags *flags, uint8_t value)
{
    flags->negative = value;
}

void flags_write_overflow(Flags *flags, uint8_t value)
{
    flags->overflow = value;
}

uint8_t flags_read_zero(const Flags *flags)
{
    return flags->zero;
}

uint8_t flags_read_carry(const Flags *flags)
{
    return flags->carry;
}

uint8_t flags_read_borrow(const Flags *flags)
{
    return flags->borrow;
}

uint8_t flags_read_negative(const Flags *flags)
{
    return flags->negative;
}

uint8_t flags_read_overflow(const Flags *flags)
{
    return flags->overflow;
}