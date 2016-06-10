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
	bit_vector_destroy(set);
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
	TEST_ASSERT_TRUE(bit_vector_is_ob(set,
					  set->min - 1u));
	TEST_ASSERT_FALSE(bit_vector_is_ob(set,
					   set->min));

	TEST_ASSERT_TRUE(bit_vector_is_ob(set,
					  set->max + 1u));
	TEST_ASSERT_FALSE(bit_vector_is_ob(set,
					   set->max));
}

void test_bit_vector_put(void)
{
	int x;

	TEST_ASSERT_EQUAL_UINT(0u, set->size);

	x = set->min;

	TEST_ASSERT_TRUE(bit_vector_put(set, x));
	TEST_ASSERT_EQUAL_UINT(1u, set->size);

	TEST_ASSERT_FALSE(bit_vector_put(set, x));
	TEST_ASSERT_EQUAL_UINT(1u, set->size);


	if (x == set->max)
		return;


	x = set->max;

	TEST_ASSERT_TRUE(bit_vector_put(set, x));
	TEST_ASSERT_EQUAL_UINT(2u, set->size);

	TEST_ASSERT_FALSE(bit_vector_put(set, x));
	TEST_ASSERT_EQUAL_UINT(2u, set->size);
}

void test_bit_vector_member(void)
{
	int x;

	x = set->max;

	TEST_ASSERT_FALSE(bit_vector_member(set, x));
	bit_vector_put(set, x);
	TEST_ASSERT_TRUE(bit_vector_member(set, x));

	if (x == set->min)
		return;

	x = set->min;

	TEST_ASSERT_FALSE(bit_vector_member(set, x));
	bit_vector_put(set, x);
	TEST_ASSERT_TRUE(bit_vector_member(set, x));
}

void test_bit_vector_delete(void)
{
	const size_t length = 100lu;
	rint_t rand_array[length];
	init_random_int_array_in_range(&rand_array[0],
				       length,
				       set->min,
				       set->max);

	const rint_t rand_int = rand_array[random_uint_upto(length - 1lu)];

	TEST_ASSERT_EQUAL_UINT(0u, set->size);

	TEST_ASSERT_FALSE(bit_vector_delete(set, rand_int));

	for (size_t i = 0; i < length; ++i)
		bit_vector_put_ib(set, rand_array[i]);

	const unsigned int loaded_size = set->size;

	TEST_ASSERT_TRUE(loaded_size > 0u);

	TEST_ASSERT_TRUE(bit_vector_delete(set, rand_int));

	TEST_ASSERT_TRUE(loaded_size > set->size);

	for (size_t i = 0; i < length; ++i)
		bit_vector_delete(set, rand_array[i]);

	TEST_ASSERT_EQUAL_UINT(0u, set->size);
}
