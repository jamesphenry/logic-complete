#include "unity.h"
#include "decoder.h"
#include "bits.h"

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

void test_decoder4to16(void)
{
    for (uint8_t address = 0; address < 16; address++)
    {
        Decoder4to16 decoder = decoder4to16(
            get_bit(address, 3),
            get_bit(address, 2),
            get_bit(address, 1),
            get_bit(address, 0));

        for (uint8_t output = 0; output < 16; output++)
        {
            uint8_t expected = (output == address) ? 1 : 0;

            TEST_ASSERT_EQUAL_UINT8(expected,decoder.output[output]);
        }
    }
}