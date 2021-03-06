/*
 * unity_config.h
 *
 *  Created on: Aug 11, 2016
 *      Author: aaron
 */

#ifndef UNITY_CONFIG_H_
#define UNITY_CONFIG_H_

//we are included from *inside* an extern "C" block
//#ifdef __cplusplus
//extern "C" {
//#endif

void __unity_print_char(int c);


#ifdef __cplusplus
} // extern "C" { //from unity_internals.h

#include <list>
#include "application.h"
void __unity_set_print(Print& output);
Print* __unity_get_print();

void __unity_register_test(const char* group_id, const char* test_id,
		void (*func)());

void __unity_run_tests();


#define UNITY_SET_PRINT(print) __unity_set_print(print)
#define UNITY_PRINT(...) __unity_get_print()->print(__VA_ARGS__)
#define UNITY_PRINTF(...) __unity_get_print()->printf(__VA_ARGS__)
#define UNITY_PRINTLN(...) __unity_get_print()->println(__VA_ARGS__)
#define UNITY_PRINTLNF(...) __unity_get_print()->printlnf(__VA_ARGS__)

#ifdef TEST
#undef TEST
#endif

#define TEST(group_id, test_id) void test_id(); __unity_register_test(#group_id, #test_id, test_id); void test_id()
#define UNITY_RUN_TESTS() __unity_run_tests()

extern "C" {
#endif

#define UNITY_INCLUDE_DOUBLE
#define UNITY_DOUBLE_VERBOSE
#define UNITY_FLOAT_VERBOSE
#define UNITY_DIFFERENTIATE_FINAL_FAIL
//#define UNITY_SUPPORT_TEST_CASES
#define UNITY_OUTPUT_CHAR(a) __unity_print_char(a)


#endif /* UNITY_CONFIG_H_ */
