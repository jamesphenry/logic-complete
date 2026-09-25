#include "unity.h"
#include "memory.h"
#include "ram.h"
#include "rom.h"

void test_memory_read_rom(void)
{
    uint8_t rom_data[] = {10, 20, 30, 40};

    ROM rom;
    RAM ram;
    Memory memory;

    rom_init(&rom, rom_data, 4);
    ram_init(&ram, 128);

    memory_init(&memory, &rom, &ram);

    TEST_ASSERT_EQUAL_UINT8(10, memory_read(&memory, 0));
    TEST_ASSERT_EQUAL_UINT8(20, memory_read(&memory, 1));
    TEST_ASSERT_EQUAL_UINT8(30, memory_read(&memory, 2));
    TEST_ASSERT_EQUAL_UINT8(40, memory_read(&memory, 3));

    rom_destroy(&rom);
    ram_destroy(&ram);
}

void test_memory_read_ram(void)
{
    ROM rom;
    RAM ram;
    Memory memory;

    uint8_t rom_data[] = {10, 20, 30, 40};

    rom_init(&rom, rom_data, 4);
    ram_init(&ram, 128);

    memory_init(&memory, &rom, &ram);

    ram_write(&ram, 0, 99);

    TEST_ASSERT_EQUAL_UINT8(99, memory_read(&memory, 128));

    rom_destroy(&rom);
    ram_destroy(&ram);
}

void test_memory_write_ram(void)
{
    ROM rom;
    RAM ram;
    Memory memory;

    uint8_t rom_data[] = {10, 20, 30, 40};

    rom_init(&rom, rom_data, 4);
    ram_init(&ram, 128);

    memory_init(&memory, &rom, &ram);

    memory_write(&memory, 128, 99);

    TEST_ASSERT_EQUAL_UINT8(99, ram_read(&ram, 0));

    rom_destroy(&rom);
    ram_destroy(&ram);
}

void test_memory_cannot_write_rom(void)
{
    ROM rom;
    RAM ram;
    Memory memory;

    uint8_t rom_data[] = {10, 20, 30, 40};

    rom_init(&rom, rom_data, 4);
    ram_init(&ram, 128);

    memory_init(&memory, &rom, &ram);

    memory_write(&memory, 0, 99);

    TEST_ASSERT_EQUAL_UINT8(10, memory_read(&memory, 0));

    rom_destroy(&rom);
    ram_destroy(&ram);
}