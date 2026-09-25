#include "unity.h"

#include "pc_next.h"

void test_pc_next_selects_increment(void)
{
    uint8_t result = pc_next(10, 99, 0);

    TEST_ASSERT_EQUAL_UINT8(11, result);
}

void test_pc_next_selects_alternate(void)
{
    uint8_t result = pc_next(10, 99, 1);

    TEST_ASSERT_EQUAL_UINT8(99, result);
}

void test_pc_next_wraps_at_255(void)
{
    uint8_t result = pc_next(255, 99, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result);
}