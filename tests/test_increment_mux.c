#include "unity.h"

#include "increment_mux.h"

void test_pc_increment_mux_selects_increment(void)
{
    uint8_t result = increment_mux(10, 99, 0);

    TEST_ASSERT_EQUAL_UINT8(11, result);
}

void test_increment_mux_selects_alternate(void)
{
    uint8_t result = increment_mux(10, 99, 1);

    TEST_ASSERT_EQUAL_UINT8(99, result);
}

void test_increment_mux_wraps_at_255(void)
{
    uint8_t result = increment_mux(255, 99, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result);
}