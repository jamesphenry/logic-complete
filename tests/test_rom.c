#include "unity.h"
#include "rom.h"

void test_rom_init(void)
{
    uint8_t data[] = {10, 20, 30, 40};

    ROM rom;

    rom_init(&rom, data, 4);

    TEST_ASSERT_EQUAL_UINT8(10, rom_read(&rom, 0));
    TEST_ASSERT_EQUAL_UINT8(20, rom_read(&rom, 1));
    TEST_ASSERT_EQUAL_UINT8(30, rom_read(&rom, 2));
    TEST_ASSERT_EQUAL_UINT8(40, rom_read(&rom, 3));

    rom_destroy(&rom);
}

void test_rom_copies_data(void)
{
    uint8_t data[] = {10, 20, 30, 40};

    ROM rom;

    rom_init(&rom, data, 4);

    data[0] = 99;

    TEST_ASSERT_EQUAL_UINT8(10, rom_read(&rom, 0));

    rom_destroy(&rom);
}

void test_rom_destroy(void)
{
    uint8_t data[] = {10, 20, 30, 40};

    ROM rom;

    rom_init(&rom, data, 4);
    rom_destroy(&rom);

    TEST_ASSERT_NULL(rom.data);
    TEST_ASSERT_EQUAL_UINT32(0, rom.size);
}