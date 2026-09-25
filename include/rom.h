#ifndef ROM_H
#define ROM_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
    uint8_t *data;
    size_t size;
} ROM;

void rom_init(
    ROM *rom,
    const uint8_t *data,
    size_t size
);

uint8_t rom_read(
    const ROM *rom,
    size_t address
);

void rom_destroy(ROM *rom);

#endif