#include <unity/unity.h>
#include "memory_get.h"

void getUp(void)
{
}

void tearDown(void)
{
}

void test_assign_memory_get(void)
{
	TEST_ASSERT_NULL(assign_memory_get(0));

	TEST_ASSERT_EQUAL_PTR(&memory_get1,
			      assign_memory_get(sizeof(Width1)));

	TEST_ASSERT_EQUAL_PTR(&memory_get2,
			      assign_memory_get(sizeof(Width2)));

	TEST_ASSERT_EQUAL_PTR(&memory_get3,
			      assign_memory_get(sizeof(Width3)));

	TEST_ASSERT_EQUAL_PTR(&memory_get4,
			      assign_memory_get(sizeof(Width4)));

	TEST_ASSERT_EQUAL_PTR(&memory_get5,
			      assign_memory_get(sizeof(Width5)));

	TEST_ASSERT_EQUAL_PTR(&memory_get6,
			      assign_memory_get(sizeof(Width6)));

	TEST_ASSERT_EQUAL_PTR(&memory_get7,
			      assign_memory_get(sizeof(Width7)));

	TEST_ASSERT_EQUAL_PTR(&memory_get8,
			      assign_memory_get(sizeof(Width8)));

	TEST_ASSERT_EQUAL_PTR(&memory_get9,
			      assign_memory_get(sizeof(Width9)));

	TEST_ASSERT_EQUAL_PTR(&memory_get10,
			      assign_memory_get(sizeof(Width10)));

	TEST_ASSERT_EQUAL_PTR(&memory_get11,
			      assign_memory_get(sizeof(Width11)));

	TEST_ASSERT_EQUAL_PTR(&memory_get12,
			      assign_memory_get(sizeof(Width12)));

	TEST_ASSERT_EQUAL_PTR(&memory_get13,
			      assign_memory_get(sizeof(Width13)));

	TEST_ASSERT_EQUAL_PTR(&memory_get14,
			      assign_memory_get(sizeof(Width14)));

	TEST_ASSERT_EQUAL_PTR(&memory_get15,
			      assign_memory_get(sizeof(Width15)));

	TEST_ASSERT_EQUAL_PTR(&memory_get16,
			      assign_memory_get(sizeof(Width16)));

	TEST_ASSERT_NULL(assign_memory_get(WIDTH_MAX + 1ul));
}

void test_memory_get_width_basic_primitive_types(void)
{
	TEST_IGNORE();
}

void test_assign_memory_get_then_get(void)
{
	MemoryGet *get;
	ptrdiff_t i;

	char chars[] = "0123456789";

	get = assign_memory_get(sizeof(char));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(chars) / sizeof(char)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL(chars[i], *((char *) get(&chars[0], i)));


	int32_t ints[] = { INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN };

	get = assign_memory_get(sizeof(int32_t));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(ints) / sizeof(int32_t)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL_INT32(ints[i], *((int32_t *) get(&ints[0], i)));


	double dbls[] = { 0.0, 1.1, 22.22, 333.333, 4444.4444 };

	get = assign_memory_get(sizeof(double));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(dbls) / sizeof(double)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL_DOUBLE(dbls[i], *((double *) get(&dbls[0], i)));
}
