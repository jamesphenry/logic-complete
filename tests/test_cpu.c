#include "unity.h"
#include "cpu.h"

void test_cpu_fetches_instruction(void)
{
    uint8_t program[] = {
        42,
        64,
        99
    };

    CPU cpu;

    cpu_init(
        &cpu,
        program,
        3,
        128
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        42,
        register_read(&cpu.instruction)
    );

    cpu_destroy(&cpu);
}

void test_cpu_increments_program_counter(void)
{
    uint8_t program[] = {
        42,
        64,
        99
    };

    CPU cpu;

    cpu_init(
        &cpu,
        program,
        3,
        128
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        1,
        register_read(&cpu.pc)
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        2,
        register_read(&cpu.pc)
    );

    cpu_destroy(&cpu);
}

void test_cpu_fetches_sequential_instructions(void)
{
    uint8_t program[] = {
        42,
        64,
        99
    };

    CPU cpu;

    cpu_init(
        &cpu,
        program,
        3,
        128
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        42,
        register_read(&cpu.instruction)
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        64,
        register_read(&cpu.instruction)
    );

    cpu_step(&cpu);

    TEST_ASSERT_EQUAL_UINT8(
        99,
        register_read(&cpu.instruction)
    );

    cpu_destroy(&cpu);
}
