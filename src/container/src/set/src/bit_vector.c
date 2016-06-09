#include "bit_vector.h"

struct BitVector *bit_vector_alloc(const int min,
				   const int max)
{
	const int range = max - min;

	const unsigned int length = next_pow_two((unsigned int) range);

	const unsigned int bucket_cnt = (length / BIT_SIZE(word_t)) + 1ul;

	struct BitVector *set;
	HANDLE_MALLOC(set, sizeof(struct BitVector));
	HANDLE_CALLOC(set->buckets, bucket_cnt, sizeof(word_t));

	set->min = min;
	set->max = min + length;
	set->lg_length = log_base_two(length);
	set->length_m1 = length - 1ul;
	set->size = 0ul;

	return set;
}

void bit_vector_init(const int min,
		     const int max)
{
}


bool bit_vector_in_bounds(struct BitVector *set,
			  const int x)
{
	return (x <= set->max) && (x >= set->min);
}

bool bit_vector_out_of_bounds(struct BitVector *set,
			      const int x)
{
	return (x > set->max) || (x < set->min);
}


bool bit_vector_member(struct BitVector *set,
		       const int x)
{
	if (bit_vector_out_of_bounds(set, x))
		return false;

	const unsigned int offset_x = x - set->min;
	const unsigned int i_bucket = offset_x >> set->lg_length;
	const unsigned int i_bit    = offset_x &  set->length_m1;

	const word_t bit_x = 1ull << i_bit;

	return set->buckets[i_bucket] & bit_x;
}


bool bit_vector_handle_put(struct BitVector *set,
			   const int x)
{
	if (bit_vector_out_of_bounds(set, x))
		EXIT_ON_FAILURE("'%d' is out of bounds"
				"\e24m]\n\n{\n"
				"\tmin:       %d"
				"\tmax:       %d"
				"\tlg_length: %zu"
				"\tlength_m1: %zu"
				"\tsize:      %zu"
				"}\n\n",
				x,
				set->min
				set_max,
				set->lg_length,
				set->length_m1);

	return bit_vector_put(set, x);
}

bool bit_vector_put(struct BitVector *set,
		    const int x)
{
	const unsigned int offset_x = x - set->min;
	const unsigned int i_bucket = offset_x >> set->lg_length;
	const unsigned int i_bit    = offset_x &  set->length_m1;

	const word_t bit_x = 1ull << i_bit;

	word_t *bucket_x = &set->buckets[i_bucket];


	if ((*bucket_x) & bit_x)
		return false;

	(*bucket_x) |= bit_x;

	++(set->size);

	return true;
}


