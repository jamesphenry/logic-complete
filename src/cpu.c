#include "cpu.h"

void cpu_init(
    CPU *cpu,
    const uint8_t *program,
    size_t program_size,
    size_t ram_size
)
{
    register_file_init(&cpu->registers);
    flags_init(&cpu->flags);

    rom_init(&cpu->rom, program, program_size);
    ram_init(&cpu->ram, ram_size);

    memory_init(
        &cpu->memory,
        &cpu->rom,
        &cpu->ram
    );

    register_init(&cpu->pc);
    register_init(&cpu->instruction);
}

void cpu_step(
    CPU *cpu
)
{
    uint8_t address = register_read(&cpu->pc);

    uint8_t instruction = memory_read(
        &cpu->memory,
        address
    );

    register_write(
        &cpu->instruction,
        instruction, 1
    );

    uint8_t next_address = address + 1;

    register_write(
        &cpu->pc,
        next_address, 1
    );
}

void cpu_destroy(
    CPU *cpu
)
{
    rom_destroy(&cpu->rom);
    ram_destroy(&cpu->ram);
}
