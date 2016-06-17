#include <unity/unity.h>
#include "memory_set_array.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_assign_memory_set_array(void)
{
	TEST_ASSERT_NULL(assign_memory_set_array(0));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array1,
			      assign_memory_set_array(sizeof(Width1)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array2,
			      assign_memory_set_array(sizeof(Width2)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array3,
			      assign_memory_set_array(sizeof(Width3)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array4,
			      assign_memory_set_array(sizeof(Width4)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array5,
			      assign_memory_set_array(sizeof(Width5)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array6,
			      assign_memory_set_array(sizeof(Width6)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array7,
			      assign_memory_set_array(sizeof(Width7)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array8,
			      assign_memory_set_array(sizeof(Width8)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array9,
			      assign_memory_set_array(sizeof(Width9)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array10,
			      assign_memory_set_array(sizeof(Width10)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array11,
			      assign_memory_set_array(sizeof(Width11)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array12,
			      assign_memory_set_array(sizeof(Width12)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array13,
			      assign_memory_set_array(sizeof(Width13)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array14,
			      assign_memory_set_array(sizeof(Width14)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array15,
			      assign_memory_set_array(sizeof(Width15)));

	TEST_ASSERT_EQUAL_PTR(&memory_set_array16,
			      assign_memory_set_array(sizeof(Width16)));

	TEST_ASSERT_NULL(assign_memory_set_array(WIDTH_MAX_SIZE + 1ul));
}


void test_assign_memory_set_array_then_set_array(void)
{
	MemorySetArray *set_array;

	char x_string[1000] = { [0 ... 999] = '\0' };
	char y_string[1000] = { [0 ... 998] = 'y', [999] = '\0' };

	set_array = assign_memory_set_array(sizeof(char));

	TEST_ASSERT_NOT_NULL(set_array);

	(*set_array)(&x_string[0], &y_string[0], 1000lu);

	TEST_ASSERT_EQUAL_STRING(&y_string[0], &x_string[0]);


	double zros[4] = {0.00l, 0.00l, 0.00l, 0.00l };
	double nums[4] = {-1e6l, 2e-7l, -3e8l, 4e-9l };

	set_array = assign_memory_set_array(sizeof(double));

	TEST_ASSERT_NOT_NULL(set_array);

	(*set_array)(&zros[0], &nums[0], 4lu);

	TEST_ASSERT_EQUAL_DOUBLE_ARRAY(&nums[0], &zros[0], 4lu);
}
