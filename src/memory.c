#include "memory.h"
#include "ram.h"
#include "rom.h"

void memory_init(
    Memory *memory,
    ROM *rom,
    RAM *ram
)
{
    memory->rom = rom;
    memory->ram = ram;
}

uint8_t memory_read(
    const Memory *memory,
    uint8_t address
)
{
    if (address < 128)
    {
        return rom_read(memory->rom, address);
    }

    return ram_read(memory->ram, address - 128);
}

void memory_write(
    Memory *memory,
    uint8_t address,
    uint8_t value
)
{
    if (address >= 128)
    {
        ram_write(memory->ram, address - 128, value);
    }
}