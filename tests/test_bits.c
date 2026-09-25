#include "unity.h"
#include "bits.h"

void test_get_bit_zero(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, get_bit(0x00, 0));
}

void test_get_bit_one(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, get_bit(0x01, 0));
}

void test_get_bit_from_middle(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, get_bit(0x42, 1));
}

void test_get_bit_from_high_bit(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, get_bit(0x80, 7));
}

void test_get_bit_clear_bit(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, get_bit(0x42, 7));
}

void test_set_bit_sets_clear_bit(void)
{
    uint8_t value = 0x00;

    set_bit(&value, 3, 1);

    TEST_ASSERT_EQUAL_UINT8(0x08, value);
}

void test_set_bit_sets_high_bit(void)
{
    uint8_t value = 0x00;

    set_bit(&value, 7, 1);

    TEST_ASSERT_EQUAL_UINT8(0x80, value);
}

void test_set_bit_clears_set_bit(void)
{
    uint8_t value = 0x08;

    set_bit(&value, 3, 0);

    TEST_ASSERT_EQUAL_UINT8(0x00, value);
}

void test_set_bit_does_not_change_other_bits(void)
{
    uint8_t value = 0xAA;

    set_bit(&value, 0, 1);

    TEST_ASSERT_EQUAL_UINT8(0xAB, value);
}

void test_set_bit_can_clear_one_bit_without_affecting_others(void)
{
    uint8_t value = 0xFF;

    set_bit(&value, 4, 0);

    TEST_ASSERT_EQUAL_UINT8(0xEF, value);
}

