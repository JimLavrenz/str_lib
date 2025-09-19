/*

Combined high-level systems test and unit test of string library.
This library is small enough to not need a library like gtest
for testing.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "str_lib.h"

int test_cntr = 0;

int main(){
	
	// Systems test code.
	string_t *str = str_new("Test");
	
	str_print(str);
	str_append(str, 's');
	str_print(str);
	str_appends(str, " are hard.");
	str_print(str);
	str_assign(str, "A completely new string");
	str_print(str);
	printf("%s\n", str->data);
	
	str_del(str);

// Unit tests code.
	str = str_new("Test");

	printf("testing str_new\n");
    assert((str->data[0] == 'T') && (str->data[1] == 'e') 
        && (str->data[2] == 's') && (str->data[3] == 't')
        && (str->data[4] == '\0'));
    assert(str_len(str) == 4);
    assert(str->alloc == 9);

	test_cntr++;
	printf("%s\n", str->data);
//	
	printf("Testing append of a single character.\n");
	str_append(str, 's');
    assert((str->data[0] == 'T') && (str->data[1] == 'e') 
        && (str->data[2] == 's') && (str->data[3] == 't')
        && (str->data[4] == 's') && (str->data[5] == '\0'));
    assert(str_len(str) == 5);
    assert(str->alloc == 9);

	test_cntr++;
	printf("%s\n", str->data);

	str_appends(str, " 12");

    assert((str->data[0] == 'T') && (str->data[1] == 'e') 
        && (str->data[2] == 's') && (str->data[3] == 't')
        && (str->data[4] == 's') && (str->data[5] == ' ')
        && (str->data[6] == '1') && (str->data[7] == '2')
        && (str->data[8] == '\0'));

    assert(str_len(str) == 8);
    assert(str->alloc == 9);
	test_cntr++;

	printf("%s\n", str->data);
//
	str_assign(str, "THIS IS A TEST");
    assert(str_len(str) == 14);
    assert(str->alloc == 29);

	test_cntr++;
	printf("%s\n", str->data);

	// Test str_del manually within Valgrind or equivalent.	
	str_del(str);

	//TODO: Add more unit tests
    printf("%d unit tests passed.\n", test_cntr);

}