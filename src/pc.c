#include "pc.h"

void pc_init(ProgramCounter *pc)
{
    register_init(&pc->value);
}

uint8_t pc_read(const ProgramCounter *pc)
{
    return register_read(&pc->value);
}

void pc_write(
    ProgramCounter *pc,
    uint8_t value,
    uint8_t enable
)
{
    register_write(
        &pc->value,
        value,
        enable
    );
}