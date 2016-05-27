#ifndef RANDOM_RANDOM_H_
#define RANDOM_RANDOM_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <time.h>			/* unique seed */
#include <stdbool.h>			/* true, false */
#include <memory_utils/memory_swap.h>	/* memory swap utils, <utils/utils.h> */
#include "pcg_basic.h"			/* psuedorandom number generator */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* CONSTANTS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define RNG_MAX UINT32_MAX

/* CONSTANTS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

pcg32_random_t _RNG;	/* global random number generator state */

inline void rng_init(void)
{
	pcg32_srandom_r(&_RNG, time(NULL), (intptr_t) &_RNG);
}

inline bool coin_flip(void)
{
	return (bool) (pcg32_random_r(&_RNG) & 1u);
}

inline uint32_t random_uint_upto(const uint32_t rbound)
{
	const uint32_t range_length = rbound + 1u;
	const uint32_t valid_limit  = RNG_MAX - (RNG_MAX % range_length);

	uint32_t random;

	do {
		random = pcg32_random_r(&_RNG);

	} while (random > valid_limit);

	return random % range_length;
}

inline int32_t random_in_int_range(const int32_t lbound,
				   const int32_t rbound)
{

	const uint32_t range_length = rbound - lbound + 1u;
	const uint32_t valid_limit  = RNG_MAX - (RNG_MAX % range_length);

	uint32_t random;

	do {
		random = pcg32_random_r(&_RNG);

	} while (random > valid_limit);

	return ((int32_t) (random % range_length)) + lbound;
}

inline double random_dbl_upto(const double rbound)
{
	return (((double) pcg32_random_r(&_RNG)) / ((double) RNG_MAX)) * rbound;
}

inline double random_in_dbl_range(const double lbound,
				  const double rbound)
{
	return (((double) pcg32_random_r(&_RNG)) / ((double) RNG_MAX))
	       * (rbound - lbound)
	       + lbound;
}

void shuffle_array_by_width(void *array,
			    const uint32_t length,
			    const size_t width);

void shuffle_array_by_swap(void *array,
			   const uint32_t length,
			   const size_t width,
			   MemorySwap *swap);

inline void shuffle_array(void *array,
			  const uint32_t length,
			  const size_t width)
{
	if (length == 0u)
		return;

	MemorySwap *swap = assign_memory_swap(width);

	if (swap == NULL)
		shuffle_array_by_width(array, length, width);
	else
		shuffle_array_by_swap(array, length, width, swap);
}


inline int32_t *init_random_int_array(const size_t length)
{
	int32_t *array;

	HANDLE_MALLOC(array, sizeof(int32_t) * length);

	for (ptrdiff_t i = 0l; i < length; ++i)
		array[i] = pcg32_random_r(&_RNG);

	return array;
}


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef RANDOM_RANDOM_H_ */
