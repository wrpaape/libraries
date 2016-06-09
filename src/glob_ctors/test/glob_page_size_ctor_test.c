#include <unity/unity.h>
#include <string.h>
#include "glob_page_size_ctor.h"

__typeof__(glob_page_size) unset_glob_page_size;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_set_glob_page_size_constructor(void)
{
	TEST_ASSERT_NOT_EQUAL(0,
			      memcmp(&glob_page_size,
				     &unset_glob_page_size,
				     sizeof(glob_page_size)));
}
