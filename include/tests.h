#ifndef TESTS_H
#define TESTS_H

/* Register tests */
void test_register_initializes_to_zero(void);
void test_register_can_store_value(void);
void test_register_can_store_maximum_value(void);
void test_register_overwrites_previous_value(void);

/* MUX tests */
void test_mux_selects_a_when_select_is_zero(void);
void test_mux_selects_b_when_select_is_one(void);
void test_mux_can_select_zero(void);
void test_mux_can_select_maximum_value(void);
void test_mux_inputs_are_independent(void);

/* Logic tests */

void test_logic_not_zero(void);
void test_logic_not_one(void);

void test_logic_and(void);
void test_logic_or(void);
void test_logic_xor(void);
void test_logic_nand(void);
void test_logic_nor(void);

void test_half_adder_zero_zero(void);
void test_half_adder_zero_one(void);
void test_half_adder_one_zero(void);
void test_half_adder_one_one(void);

#endif