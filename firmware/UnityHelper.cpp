/*
 * UnityHelper.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: aaron
 */
#include "application.h"

static Print* print = &Serial;

extern "C" void __unity_print_char(int c) {
	print->write(c);
}

void __unity_set_print(Print& output) {
	print = &output;
}

Print* __unity_get_print() {
	return print;
}

