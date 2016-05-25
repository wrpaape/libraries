#include <unity/unity.h>
#include "memory_set.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_assign_memory_set(void)
{
	TEST_ASSERT_NULL(assign_memory_set(0));

	TEST_ASSERT_EQUAL_PTR(&memory_set1,
			      assign_memory_set(sizeof(ByteWidth1)));

	TEST_ASSERT_EQUAL_PTR(&memory_set2,
			      assign_memory_set(sizeof(ByteWidth2)));
	TEST_ASSERT_EQUAL_PTR(&memory_set3,
			      assign_memory_set(sizeof(ByteWidth3)));
	TEST_ASSERT_EQUAL_PTR(&memory_set4,
			      assign_memory_set(sizeof(ByteWidth4)));

	TEST_ASSERT_EQUAL_PTR(&memory_set5,
			      assign_memory_set(sizeof(ByteWidth5)));

	TEST_ASSERT_EQUAL_PTR(&memory_set6,
			      assign_memory_set(sizeof(ByteWidth6)));

	TEST_ASSERT_EQUAL_PTR(&memory_set7,
			      assign_memory_set(sizeof(ByteWidth7)));

	TEST_ASSERT_EQUAL_PTR(&memory_set8,
			      assign_memory_set(sizeof(ByteWidth8)));

	TEST_ASSERT_EQUAL_PTR(&memory_set9,
			      assign_memory_set(sizeof(ByteWidth9)));

	TEST_ASSERT_EQUAL_PTR(&memory_set10,
			      assign_memory_set(sizeof(ByteWidth10)));

	TEST_ASSERT_EQUAL_PTR(&memory_set11,
			      assign_memory_set(sizeof(ByteWidth11)));

	TEST_ASSERT_EQUAL_PTR(&memory_set12,
			      assign_memory_set(sizeof(ByteWidth12)));

	TEST_ASSERT_EQUAL_PTR(&memory_set13,
			      assign_memory_set(sizeof(ByteWidth13)));

	TEST_ASSERT_EQUAL_PTR(&memory_set14,
			      assign_memory_set(sizeof(ByteWidth14)));

	TEST_ASSERT_EQUAL_PTR(&memory_set15,
			      assign_memory_set(sizeof(ByteWidth15)));

	TEST_ASSERT_EQUAL_PTR(&memory_set16,
			      assign_memory_set(sizeof(ByteWidth16)));

	TEST_ASSERT_NULL(assign_memory_set(BYTE_WIDTH_MAX + 1ul));
}

void test_assign_memory_set_then_set(void)
{
	MemorySet *set;

	char x;
	char y = 'y';

	set = assign_memory_set(sizeof(char));

	TEST_ASSERT_NOT_NULL(set);

	(*set)(&x, &y);

	TEST_ASSERT_EQUAL(x, 'y');

	long long int a;
	long long int b = 0xBBBB;

	set = assign_memory_set(sizeof(long long int));

	TEST_ASSERT_NOT_NULL(set);

	(*set)(&a, &b);

	TEST_ASSERT_EQUAL_INT(a, 0xBBBB);

	long double pi;
	long double e  = 2.718281828459045l;

	set = assign_memory_set(sizeof(long double));

	TEST_ASSERT_NOT_NULL(set);

	(*set)(&pi, &e);

	TEST_ASSERT_EQUAL_DOUBLE(2.718281828459045l, pi);

	uint32_t ab[2]	     = { 0xA, 0xB };
	uint32_t cdef[4]     = { 0xC, 0xD, 0xE, 0xF };
	uint32_t expected[6] = { 0xA, 0xB, 0xC, 0xD, 0xE, 0xF };
	uint32_t abcdef[6];

	set = assign_memory_set(sizeof(ab));

	(*set)(&abcdef[0], &ab[0]);

	set = assign_memory_set(sizeof(cdef));

	(*set)(&abcdef[2], &cdef[0]);

	TEST_ASSERT_EQUAL_INT32_ARRAY(&expected[0], &abcdef[0], 6);
}
