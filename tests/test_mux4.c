#include "unity.h"
#include "mux.h"

void test_mux4_select_a(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 0);

    TEST_ASSERT_EQUAL_UINT8(10, result);
}

void test_mux4_select_b(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 1);

    TEST_ASSERT_EQUAL_UINT8(20, result);
}

void test_mux4_select_c(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 2);

    TEST_ASSERT_EQUAL_UINT8(30, result);
}

void test_mux4_select_d(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 3);

    TEST_ASSERT_EQUAL_UINT8(40, result);
}