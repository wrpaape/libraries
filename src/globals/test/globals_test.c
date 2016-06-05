#include <unity/unity.h>
#include "globals.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_globals(void)
{
	TEST_ASSERT_EQUAL_INT(42, globals());
}