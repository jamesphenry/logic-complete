#include "unity.h"

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