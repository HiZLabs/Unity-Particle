/*
 * UnityHelper.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: aaron
 */
#include "application.h"
#include <list>

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

struct test {
	const char* name;
	void (*func)();
};

struct test_group {
	const char* name;
	std::list<test> tests;
};

static std::list<test_group> groups;

static std::list<test_group>::iterator find_group(const char* group_id) {
	std::list<test_group>::iterator i = groups.begin();
	while (i != groups.end()) {
		if (strcmp(group_id, i->name) == 0)
			break;
		i++;
	}
	return i;
}

void __unity_register_test(const char* group_id, const char* test_id,
		void (*func)()) {
	std::list<test_group>::iterator group = find_group(group_id);
	if (group == groups.end()) {
		test_group newGroup = { group_id };
		groups.push_back(newGroup);
		group = find_group(group_id);
	}


}

int __unity_run_tests() {

}

