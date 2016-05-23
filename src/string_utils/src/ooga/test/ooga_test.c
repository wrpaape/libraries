#include <unity/unity.h>
#include "ooga.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ooga(void)
{
	TEST_ASSERT_EQUAL_INT(42, ooga());
}