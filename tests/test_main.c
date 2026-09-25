#include "unity.h"
#include "tests.h"

void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_register_initializes_to_zero);
    RUN_TEST(test_register_can_store_value);
    RUN_TEST(test_register_can_store_maximum_value);
    RUN_TEST(test_register_overwrites_previous_value);

    RUN_TEST(test_mux_selects_a_when_select_is_zero);
    RUN_TEST(test_mux_selects_b_when_select_is_one);
    RUN_TEST(test_mux_can_select_zero);
    RUN_TEST(test_mux_can_select_maximum_value);
    RUN_TEST(test_mux_inputs_are_independent);

    RUN_TEST(test_logic_not_zero);
    RUN_TEST(test_logic_not_one);

    RUN_TEST(test_logic_and);
    RUN_TEST(test_logic_or);
    RUN_TEST(test_logic_xor);
    RUN_TEST(test_logic_nand);
    RUN_TEST(test_logic_nor);

    RUN_TEST(test_half_adder_zero_zero);
    RUN_TEST(test_half_adder_zero_one);
    RUN_TEST(test_half_adder_one_zero);
    RUN_TEST(test_half_adder_zero_zero);
    
    RUN_TEST(test_full_adder_zero_zero_zero);
    RUN_TEST(test_full_adder_zero_zero_one);
    RUN_TEST(test_full_adder_zero_one_zero);
    RUN_TEST(test_full_adder_zero_one_one);
    RUN_TEST(test_full_adder_one_zero_zero);
    RUN_TEST(test_full_adder_one_zero_one);
    RUN_TEST(test_full_adder_one_one_zero);
    RUN_TEST(test_full_adder_one_one_one);

    RUN_TEST(test_adder8_zero);
    RUN_TEST(test_adder8_simple_addition);
    RUN_TEST(test_adder8_carry_across_nibble);
    RUN_TEST(test_adder8_carry_out);
    RUN_TEST(test_adder8_pattern_addition);
    RUN_TEST(test_adder8_example_addition);
    RUN_TEST(test_adder8_with_carry_in);
    RUN_TEST(test_adder8_carry_in_and_carry_out);

    return UNITY_END();
}