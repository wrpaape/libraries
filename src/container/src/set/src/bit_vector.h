#ifndef SET_BIT_VECTOR_H_
#define SET_BIT_VECTOR_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <memory_utils/memory_utils.h>	/* HANDLE_M/C/REALLOC, utils.h */
#include <utils/word.h>			/* word_t */
#include <stdbool.h>			/* bool */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

struct BitVector {
	int min;
	int max;
	unsigned int lg_length;
	unsigned int length_m1;
	unsigned int size;
	word_t *buckets;
};

struct BitPoint {
	unsigned int i_bucket;
	word_t bit;
};

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define HANDLE_BIT_VECTOR_IS_IB(SET, X)			\
do {							\
	if (bit_vector_is_ob(SET, X))			\
		EXIT_ON_FAILURE("'%d' is out of range"	\
				"\e24m]\n\n{\n"		\
				"\tmin:       %d\n"	\
				"\tmax:       %d\n"	\
				"\tlg_length: %u\n"	\
				"\tlength_m1: %u\n"	\
				"\tsize:      %u\n"	\
				"}\n\n",		\
				X,			\
				SET->min,		\
				SET->max,		\
				SET->lg_length,		\
				SET->length_m1,		\
				SET->size);		\
} while (0)

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

static inline void get_bit_point(struct BitPoint *const restrict point,
				 const struct BitVector *const restrict set,
				 const int x)
{
	const unsigned int offset_x = x - set->min;

	point->i_bucket = offset_x >> set->lg_length;

	point->bit = 1ul << (offset_x & set->length_m1);
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

inline void bit_vector_init(struct BitVector *const restrict set,
			    const int min,
			    const unsigned int range)
{
	const unsigned int length = round_pow_two_lb(range);

	HANDLE_CALLOC(set->buckets,
		      (length / BIT_SIZE(word_t)) + 1ul,
		      sizeof(word_t));

	set->min = min;
	set->max = min + range;
	set->lg_length = log_base_two(length);
	set->length_m1 = length - 1ul;
	set->size = 0ul;
}

inline struct BitVector *bit_vector_create(const int min,
					   const unsigned int range)
{
	struct BitVector *restrict set;

	HANDLE_MALLOC(set, sizeof(struct BitVector));

	bit_vector_init(set, min, range);

	return set;
}

inline void bit_vector_clear(struct BitVector *restrict set)
{
	free(set->buckets);
}

inline void bit_vector_destroy(struct BitVector *restrict set)
{
	bit_vector_clear(set);
	free(set);
}


inline bool bit_vector_is_ib(const struct BitVector *const restrict set,
			     const int x)
{
	return (x <= set->max)
	    && (x >= set->min);
}

inline bool bit_vector_is_ob(const struct BitVector *const restrict set,
				    const int x)
{
	return (x > set->max)
	    || (x < set->min);
}

inline bool bit_vector_member_ib(const struct BitVector *const restrict set,
				 const int x)
{
	struct BitPoint point;

	get_bit_point(&point, set, x);

	return set->buckets[point.i_bucket] & point.bit;
}

inline bool bit_vector_member(const struct BitVector *const restrict set,
			      const int x)
{
	return bit_vector_is_ib(set, x)
	    && bit_vector_member_ib(set, x);
}

inline bool bit_vector_handle_member(const struct BitVector *const restrict set,
				     const int x)
{
	HANDLE_BIT_VECTOR_IS_IB(set, x);

	return bit_vector_member_ib(set, x);
}


inline bool bit_vector_put_ib(struct BitVector *const restrict set,
			      const int x)

{
	struct BitPoint point;

	get_bit_point(&point, set, x);

	word_t *const restrict bucket_x = &set->buckets[point.i_bucket];

	if ((*bucket_x) & point.bit)
		return false;

	(*bucket_x) |= point.bit;

	++(set->size);

	return true;
}

inline bool bit_vector_put(struct BitVector *const restrict set,
			   const int x)
{
	return bit_vector_is_ib(set, x)
	    && bit_vector_put_ib(set, x);
}

inline bool bit_vector_handle_put(struct BitVector *const restrict set,
				  const int x)
{
	HANDLE_BIT_VECTOR_IS_IB(set, x);

	return bit_vector_put_ib(set, x);
}


inline bool bit_vector_delete_ib(struct BitVector *const restrict set,
				 const int x)

{
	struct BitPoint point;

	get_bit_point(&point, set, x);

	word_t *const restrict bucket_x = &set->buckets[point.i_bucket];

	if ((*bucket_x) & point.bit) {

		(*bucket_x) ^= point.bit;

		--(set->size);

		return true;
	}

	return false;
}

inline bool bit_vector_delete(struct BitVector *const restrict set,
			      const int x)
{
	return bit_vector_is_ib(set, x)
	    && bit_vector_delete_ib(set, x);
}

inline bool bit_vector_handle_delete(struct BitVector *const restrict set,
				     const int x)
{
	HANDLE_BIT_VECTOR_IS_IB(set, x);

	return bit_vector_delete_ib(set, x);
}


/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef SET_BIT_VECTOR_H_ */
