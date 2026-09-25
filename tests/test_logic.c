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