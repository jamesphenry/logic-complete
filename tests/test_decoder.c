#include "unity.h"
#include "decoder.h"

void test_decoder_00(void)
{
    Decoder2to4 result = decoder2to4(0, 0);

    TEST_ASSERT_EQUAL_UINT8(1, result.output0);
    TEST_ASSERT_EQUAL_UINT8(0, result.output1);
    TEST_ASSERT_EQUAL_UINT8(0, result.output2);
    TEST_ASSERT_EQUAL_UINT8(0, result.output3);
}

void test_decoder_01(void)
{
    Decoder2to4 result = decoder2to4(0, 1);

    TEST_ASSERT_EQUAL_UINT8(0, result.output0);
    TEST_ASSERT_EQUAL_UINT8(1, result.output1);
    TEST_ASSERT_EQUAL_UINT8(0, result.output2);
    TEST_ASSERT_EQUAL_UINT8(0, result.output3);
}

void test_decoder_10(void)
{
    Decoder2to4 result = decoder2to4(1, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result.output0);
    TEST_ASSERT_EQUAL_UINT8(0, result.output1);
    TEST_ASSERT_EQUAL_UINT8(1, result.output2);
    TEST_ASSERT_EQUAL_UINT8(0, result.output3);
}

void test_decoder_11(void)
{
    Decoder2to4 result = decoder2to4(1, 1);

    TEST_ASSERT_EQUAL_UINT8(0, result.output0);
    TEST_ASSERT_EQUAL_UINT8(0, result.output1);
    TEST_ASSERT_EQUAL_UINT8(0, result.output2);
    TEST_ASSERT_EQUAL_UINT8(1, result.output3);
}