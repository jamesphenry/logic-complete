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

    RUN_TEST(test_get_bit_zero);
    RUN_TEST(test_get_bit_one);
    RUN_TEST(test_get_bit_from_middle);
    RUN_TEST(test_get_bit_from_high_bit);
    RUN_TEST(test_get_bit_clear_bit);

    RUN_TEST(test_set_bit_sets_clear_bit);
    RUN_TEST(test_set_bit_sets_high_bit);
    RUN_TEST(test_set_bit_clears_set_bit);
    RUN_TEST(test_set_bit_does_not_change_other_bits);
    RUN_TEST(test_set_bit_can_clear_one_bit_without_affecting_others);

    RUN_TEST(test_logic_equal_zero_zero);
    RUN_TEST(test_logic_equal_zero_one);
    RUN_TEST(test_logic_equal_one_zero);
    RUN_TEST(test_logic_equal_one_one);

    RUN_TEST(test_comparator_equal);
    RUN_TEST(test_comparator_less);
    RUN_TEST(test_comparator_greater);

    RUN_TEST(test_logic_greater);

    RUN_TEST(test_logic_less);

    RUN_TEST(test_logic_not8);

    RUN_TEST(test_subtractor8_zero);
    RUN_TEST(test_subtractor8_simple);
    RUN_TEST(test_subtractor8_borrow);
    RUN_TEST(test_subtractor8_equal);

    RUN_TEST(test_logic_and8);
    RUN_TEST(test_logic_or8);
    RUN_TEST(test_logic_xor8);
    RUN_TEST(test_logic_nand8);

    RUN_TEST(test_shift_left8);
    RUN_TEST(test_shift_left8_carry);
    RUN_TEST(test_shift_right8);
    RUN_TEST(test_shift_right8_carry);

    RUN_TEST(test_alu_add);
    RUN_TEST(test_alu_add_overflow);
    RUN_TEST(test_alu_sub_borrow);

    RUN_TEST(test_alu_sub_borrow);
    RUN_TEST(test_alu_sub);
    RUN_TEST(test_alu_and);
    RUN_TEST(test_alu_and_partial);

    RUN_TEST(test_alu_or);
    RUN_TEST(test_alu_or_partial);

    RUN_TEST(test_alu_xor);
    RUN_TEST(test_alu_xor_partial);

    RUN_TEST(test_alu_shl);
    RUN_TEST(test_alu_shl_overflow);

    RUN_TEST(test_alu_shr);
    RUN_TEST(test_alu_shr_overflow);

    RUN_TEST(test_zero_flag8_zero);
    RUN_TEST(test_zero_flag8_nonzero);
    RUN_TEST(test_zero_flag8_high_bit);
    RUN_TEST(test_zero_flag8_middle_bit);

    RUN_TEST(test_alu_zero_flag);
    RUN_TEST(test_alu_nonzero_flag);

    RUN_TEST(test_alu_add_carry);
    RUN_TEST(test_alu_add_no_carry);

    RUN_TEST(test_alu_sub_borrow);
    RUN_TEST(test_alu_sub_no_borrow);

    RUN_TEST(test_negative_flag8_clear);
    RUN_TEST(test_negative_flag8_set);
    RUN_TEST(test_negative_flag8_max);

    return UNITY_END();
}