#include "bit_vector.h"

struct BitVector *bit_vector_alloc(const int min,
				   const int max)
{
	const int range = max - min;

	const size_t span = next_pow_two((size_t) range);

	const size_t bkt_cnt = (span / BIT_SIZE(word_t)) + 1ul;

	struct BitVector *set;
	HANDLE_MALLOC(set, sizeof(struct BitVector));
	HANDLE_CALLOC(bits, bkt_cnt, sizeof(word_t));

	set->min = min;
	set->max = min + span;
	set->lg_span = log_base_two(span);
	set->span_m1 = span - 1ul;
	set->size = 0ul;
	set->bits = bits;

	return set;
}

void bit_vector_init(const int min,
		     const int max)
{
}


bool bit_vector_member(struct BitVector *set,
		       const int x)
{
	if ((x < set->min) || (x > set->max))
		return false;

	const size_t off_x = x - set->min;
	const size_t i_bkt = off_x >> set->lg_span;
	const size_t i_bit = off_x &  set->span_m1;

	const word_t bit_x = 1ull << i_bit;

	return set->bits[i_bkt] & bit_x;
}

bool bit_vector_in_bounds(struct BitVector *set,
			  const int x)
{
	return (x <= set->max) && (x >= set->min);
}

bool bit_vector_put(struct BitVector *set,
		    const int x)
{
	if ((x < set->min) || (x > set->max))
		EXIT_ON_FAILURE("%d is OB", x);

	const size_t off_x = x - set->min;
	const size_t i_bkt = off_x >> set->lg_span;
	const size_t i_bit = off_x &  set->span_m1;

	const word_t bit_x = 1ull << i_bit;

	word_t *bkt_x = &set->bits[i_bkt];


	if ((*bkt_x) & bit_x)
		return false;

	(*bkt_x) |= bit_x;

	++(set->size);

	return true;
}


