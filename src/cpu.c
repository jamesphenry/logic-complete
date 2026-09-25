#include "cpu.h"
#include "pc_next.h"
#include "alu.h"

void cpu_init(
    CPU *cpu,
    const uint8_t *program,
    size_t program_size,
    size_t ram_size)
{
    
    register_file_init(&cpu->registers);
    flags_init(&cpu->flags);

    rom_init(&cpu->rom, program, program_size);
    ram_init(&cpu->ram, ram_size);

    memory_init(
        &cpu->memory,
        &cpu->rom,
        &cpu->ram);

    register_init(&cpu->pc);
    register_init(&cpu->instruction);
    cpu->alu_operation = ALU_ADD;
    cpu->alu_result_enable = 0;
}

void cpu_step(
    CPU *cpu)
{
    
    uint8_t address = register_read(&cpu->pc);

    uint8_t instruction = memory_read(
        &cpu->memory,
        address);

    register_write(
        &cpu->instruction,
        instruction,
        1);

    uint8_t next_address = pc_next(
        address,
        0,
        0);

    register_write(
        &cpu->pc,
        next_address,
        1);

    uint8_t alu_a = register_read(&cpu->registers.registers[0]);
    uint8_t alu_b = register_read(&cpu->registers.registers[1]);

    ALU8 alu = alu8(
        alu_a,
        alu_b,
        cpu->alu_operation);

    register_write(
        &cpu->registers.registers[2],
        alu.result,
        cpu->alu_result_enable);
}

void cpu_destroy(
    CPU *cpu)
{
    rom_destroy(&cpu->rom);
    ram_destroy(&cpu->ram);
}
