#include "unity.h"
#include "comparator.h"

void test_comparator_equal(void)
{
    Comparator8 result = comparator8(0x42, 0x42);

    TEST_ASSERT_EQUAL_UINT8(1, result.equal);
    TEST_ASSERT_EQUAL_UINT8(0, result.less);
    TEST_ASSERT_EQUAL_UINT8(0, result.greater);
}

void test_comparator_less(void)
{
    Comparator8 result = comparator8(0x10, 0x20);

    TEST_ASSERT_EQUAL_UINT8(0, result.equal);
    TEST_ASSERT_EQUAL_UINT8(1, result.less);
    TEST_ASSERT_EQUAL_UINT8(0, result.greater);
}

void test_comparator_greater(void)
{
    Comparator8 result = comparator8(0x20, 0x10);

    TEST_ASSERT_EQUAL_UINT8(0, result.equal);
    TEST_ASSERT_EQUAL_UINT8(0, result.less);
    TEST_ASSERT_EQUAL_UINT8(1, result.greater);
}