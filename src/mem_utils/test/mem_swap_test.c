#include <unity/unity.h>
#include "mem_swap.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_VAR_SWAP(void)
{
	char *this = "this";
	char *that = "that";

	VAR_SWAP(this, that);

	TEST_ASSERT_EQUAL_STRING("this", that);
	TEST_ASSERT_EQUAL_STRING("that", this);

	VAR_SWAP(this, that);

	TEST_ASSERT_EQUAL_STRING("this", this);
	TEST_ASSERT_EQUAL_STRING("that", that);
}

void test_EL_SWAP_char(void)
{
	char array[] = "ooga";

	EL_SWAP(array, 1, 2);

	TEST_ASSERT_EQUAL_STRING("ogoa", &array[0]);

	EL_SWAP(array, 1, 2);

	TEST_ASSERT_EQUAL_STRING("ooga", &array[0]);
}

void test_EL_SWAP_int64(void)
{
	int64_t array[] = { 0, 1, 2, 3, 4, 5 };

	EL_SWAP(array, 0, 5);

	TEST_ASSERT_EQUAL_INT64(array[0], 5);
	TEST_ASSERT_EQUAL_INT64(array[5], 0);

	EL_SWAP(array, 0, 5);

	TEST_ASSERT_EQUAL_INT64(array[0], 0);
	TEST_ASSERT_EQUAL_INT64(array[5], 5);
}

void test_mem_swap_basic_primitive_types(void)
{
	char x = 'x';
	char y = 'y';

	mem_swap(&x, &y, sizeof(char));

	TEST_ASSERT_EQUAL(x, 'y');
	TEST_ASSERT_EQUAL(y, 'x');

	int threes = 333;
	int sevens = 777;

	mem_swap(&threes, &sevens, sizeof(short));

	TEST_ASSERT_EQUAL_INT(333, sevens);
	TEST_ASSERT_EQUAL_INT(777, threes);

	double pi = 3.141;
	double e  = 2.718;

	mem_swap(&pi, &e, sizeof(short));

	TEST_ASSERT_EQUAL_DOUBLE(3.141, e);
	TEST_ASSERT_EQUAL_DOUBLE(2.718, pi);
}


void test_mem_swap_string(void)
{
	char this[] = "_this_ is 'this'";
	char that[] = "_this_ is 'that'";

	mem_swap(&this[0], &that[0], sizeof(this));

	TEST_ASSERT_EQUAL_STRING("_this_ is 'that'", &this[0]);
	TEST_ASSERT_EQUAL_STRING("_this_ is 'this'", &that[0]);
}

void test_mem_swap_pointers(void)
{
	MemSwap *this[3] = { &mem_swap1, &mem_swap2, &mem_swap3 };
	MemSwap *that[3] = { &mem_swap3, &mem_swap2, &mem_swap1 };

	MemSwap *this_copy[3];
	MemSwap *that_copy[3];

	memcpy(&this_copy[0], &this[0], sizeof(MemSwap *));
	memcpy(&that_copy[0], &that[0], sizeof(MemSwap *));

	TEST_ASSERT_EQUAL_PTR_ARRAY_MESSAGE(&this[0], &this_copy[0], 3,
					    "bad memcpy");
	TEST_ASSERT_EQUAL_PTR_ARRAY_MESSAGE(&that[0], &that_copy[0], 3,
					    "bad memcpy");

	mem_swap(&this[0], &that[0], sizeof(MemSwap *));

	TEST_ASSERT_EQUAL_PTR_ARRAY(&this_copy[0],  &that[0], 3);
	TEST_ASSERT_EQUAL_PTR_ARRAY(&that_copy[0], &this[0],  3);
}
