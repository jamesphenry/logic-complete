#ifndef FLAGS_H
#define FLAGS_H

#include <stdint.h>

typedef struct
{
    uint8_t zero;
    uint8_t carry;
    uint8_t borrow;
    uint8_t negative;
    uint8_t overflow;
} Flags;

void flags_init(Flags *flags);

void flags_write_zero(Flags *flags, uint8_t value);
void flags_write_carry(Flags *flags, uint8_t value);
void flags_write_borrow(Flags *flags, uint8_t value);
void flags_write_negative(Flags *flags, uint8_t value);
void flags_write_overflow(Flags *flags, uint8_t value);

uint8_t flags_read_zero(const Flags *flags);
uint8_t flags_read_carry(const Flags *flags);
uint8_t flags_read_borrow(const Flags *flags);
uint8_t flags_read_negative(const Flags *flags);
uint8_t flags_read_overflow(const Flags *flags);

#endif