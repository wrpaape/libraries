#include <unity/unity.h>
#include "global_page_size.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_set_global_page_size_constructor(void)
{
	TEST_ASSERT_TRUE(global_page_size != 0ul);
}
