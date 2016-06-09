#include <unity/unity.h>
#include <string.h>
#include "random_nogc.h"

__typeof__(glob_rng) unset_glob_rng;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_no_glob_rng_ctor(void)
{
	TEST_ASSERT_EQUAL(0,
			  memcmp(&glob_rng,
				 &unset_glob_rng,
				 sizeof(glob_rng)));
}

