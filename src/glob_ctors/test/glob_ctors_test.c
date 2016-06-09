#include <unity/unity.h>
#include "glob_ctors.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_glob_ctors(void)
{
	TEST_ASSERT_EQUAL_INT(42, glob_ctors());
}
