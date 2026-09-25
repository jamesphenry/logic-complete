#include "rom.h"

#include <stdlib.h>

void rom_init(
    ROM *rom,
    const uint8_t *data,
    size_t size
)
{
    rom->data = malloc(size);
    rom->size = size;

    for (size_t address = 0; address < size; address++)
    {
        rom->data[address] = data[address];
    }
}

uint8_t rom_read(
    const ROM *rom,
    size_t address
)
{
    return rom->data[address];
}

void rom_destroy(ROM *rom)
{
    free(rom->data);

    rom->data = NULL;
    rom->size = 0;
}