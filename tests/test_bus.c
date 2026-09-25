#include "unity.h"
#include "alu.h"
#include "bus.h"

void test_bus_selects_source0(void)
{
    uint8_t result = bus_select(
        10,
        20,
        30,
        40,
        0
    );

    TEST_ASSERT_EQUAL_UINT8(10, result);
}

void test_bus_selects_source1(void)
{
    uint8_t result = bus_select(
        10,
        20,
        30,
        40,
        1
    );

    TEST_ASSERT_EQUAL_UINT8(20, result);
}

void test_bus_selects_source2(void)
{
    uint8_t result = bus_select(
        10,
        20,
        30,
        40,
        2
    );

    TEST_ASSERT_EQUAL_UINT8(30, result);
}

void test_bus_selects_source3(void)
{
    uint8_t result = bus_select(
        10,
        20,
        30,
        40,
        3
    );

    TEST_ASSERT_EQUAL_UINT8(40, result);
}

void test_bus_to_alu_to_bus(void)
{
    uint8_t bus_input = bus_select(
        10,
        20,
        0,
        0,
        1
    );

    ALU8 alu = alu8(
        5,
        bus_input,
        ALU_ADD
    );

    uint8_t bus_output = bus_select(
        0,
        alu.result,
        0,
        0,
        1
    );

    TEST_ASSERT_EQUAL_UINT8(25, bus_output);
}