#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stddef.h>

#include "memory.h"
#include "register.h"
#include "register_file.h"
#include "flags.h"

typedef struct
{
    RegisterFile registers;
    Flags flags;

    ROM rom;
    RAM ram;
    Memory memory;

    Register pc;
    Register instruction;
} CPU;

void cpu_init(
    CPU *cpu,
    const uint8_t *program,
    size_t program_size,
    size_t ram_size
);

void cpu_step(
    CPU *cpu
);

void cpu_destroy(
    CPU *cpu
);

#endif
