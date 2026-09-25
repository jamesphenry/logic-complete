#include "unity.h"
#include "logic.h"

void test_logic_not_zero(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, logic_not(0));
}

void test_logic_not_one(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_not(1));
}


/* AND */

void test_logic_and(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_and(0, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_and(0, 1));
    TEST_ASSERT_EQUAL_UINT8(0, logic_and(1, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_and(1, 1));
}


/* OR */

void test_logic_or(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_or(0, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_or(0, 1));
    TEST_ASSERT_EQUAL_UINT8(1, logic_or(1, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_or(1, 1));
}


/* XOR */

void test_logic_xor(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_xor(0, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_xor(0, 1));
    TEST_ASSERT_EQUAL_UINT8(1, logic_xor(1, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_xor(1, 1));
}


/* NAND */

void test_logic_nand(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, logic_nand(0, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_nand(0, 1));
    TEST_ASSERT_EQUAL_UINT8(1, logic_nand(1, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_nand(1, 1));
}


/* NOR */

void test_logic_nor(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, logic_nor(0, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_nor(0, 1));
    TEST_ASSERT_EQUAL_UINT8(0, logic_nor(1, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_nor(1, 1));
}

void test_logic_equal_zero_zero(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, logic_equal(0, 0));
}

void test_logic_equal_zero_one(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_equal(0, 1));
}

void test_logic_equal_one_zero(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_equal(1, 0));
}

void test_logic_equal_one_one(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, logic_equal(1, 1));
}

void test_logic_greater(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_greater(0, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_greater(0, 1));
    TEST_ASSERT_EQUAL_UINT8(1, logic_greater(1, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_greater(1, 1));
}

void test_logic_less(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, logic_less(0, 0));
    TEST_ASSERT_EQUAL_UINT8(1, logic_less(0, 1));
    TEST_ASSERT_EQUAL_UINT8(0, logic_less(1, 0));
    TEST_ASSERT_EQUAL_UINT8(0, logic_less(1, 1));
}

void test_logic_not8(void)
{
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_not8(0x00));
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_not8(0xFF));
    TEST_ASSERT_EQUAL_UINT8(0xAA, logic_not8(0x55));
    TEST_ASSERT_EQUAL_UINT8(0x55, logic_not8(0xAA));
    TEST_ASSERT_EQUAL_UINT8(0xF0, logic_not8(0x0F));
}

void test_logic_and8(void)
{
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_and8(0x00, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_and8(0xFF, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_and8(0xFF, 0xFF));
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_and8(0x55, 0xAA));
    TEST_ASSERT_EQUAL_UINT8(0x50, logic_and8(0xF0, 0x55));
}

void test_logic_or8(void)
{
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_or8(0x00, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_or8(0xFF, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_or8(0xFF, 0xFF));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_or8(0x55, 0xAA));
    TEST_ASSERT_EQUAL_UINT8(0xF5, logic_or8(0xF0, 0x05));
}

void test_logic_xor8(void)
{
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_xor8(0x00, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_xor8(0xFF, 0x00));
    TEST_ASSERT_EQUAL_UINT8(0x00, logic_xor8(0xFF, 0xFF));
    TEST_ASSERT_EQUAL_UINT8(0xFF, logic_xor8(0x55, 0xAA));
    TEST_ASSERT_EQUAL_UINT8(0xA5, logic_xor8(0xF0, 0x55));
}