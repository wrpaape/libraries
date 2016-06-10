#include <unity/unity.h>
#include <random/random.h>
#include "bit_vector.h"

#define MIN_FLOOR -999
#define MIN_CEIL 999

#define RANGE_CEIL 999u

static struct BitVector *set;

void setUp(void)
{
	set = bit_vector_create(random_int_in_range(MIN_FLOOR,
						    MIN_CEIL),
				random_uint_upto(RANGE_CEIL));
}

void tearDown(void)
{
	bit_vector_free(set);
}

void test_bit_vector_is_ib(void)
{
	TEST_ASSERT_TRUE(bit_vector_is_ib(set,
					  set->min));
	TEST_ASSERT_FALSE(bit_vector_is_ib(set,
					   set->min - 1u));

	TEST_ASSERT_TRUE(bit_vector_is_ib(set,
					  set->max));
	TEST_ASSERT_FALSE(bit_vector_is_ib(set,
					   set->max + 1u));
}


void test_bit_vector_is_ob(void)
{
	TEST_ASSERT_FALSE(bit_vector_is_ob(set,
					  set->min));
	TEST_ASSERT_TRUE(bit_vector_is_ob(set,
					  set->min - 1u));

	TEST_ASSERT_FALSE(bit_vector_is_ob(set,
					  set->max));
	TEST_ASSERT_TRUE(bit_vector_is_ob(set,
					  set->max + 1u));
}

void test_bit_vector_put(void)
{
	int x;


	x = set->min;

	TEST_ASSERT_EQUAL_UINT(0u, set->size);

	TEST_ASSERT_TRUE(bit_vector_put(set,
					x));
	TEST_ASSERT_EQUAL_UINT(1u, set->size);

	TEST_ASSERT_FALSE(bit_vector_put(set,
					 x));
	TEST_ASSERT_EQUAL_UINT(1u, set->size);


	if (x == set->max)
		return;


	x = set->max;

	TEST_ASSERT_TRUE(bit_vector_put(set,
					x));
	TEST_ASSERT_EQUAL_UINT(2u, set->size);

	TEST_ASSERT_FALSE(bit_vector_put(set,
					 x));
	TEST_ASSERT_EQUAL_UINT(2u, set->size);
}
