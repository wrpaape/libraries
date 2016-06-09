#include <unity/unity.h>
#include "bit_vector.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bit_vector(void)
{
	TEST_ASSERT_EQUAL_INT(42, bit_vector());
}