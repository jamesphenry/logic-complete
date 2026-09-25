#include "unity.h"
#include "negative.h"

void test_negative_flag8_clear(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, negative_flag8(0x7F));
}

void test_negative_flag8_set(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, negative_flag8(0x80));
}

void test_negative_flag8_max(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, negative_flag8(0xFF));
}