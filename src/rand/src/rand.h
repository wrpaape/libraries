#ifndef RAND_RAND_H_
#define RAND_RAND_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <time.h>		/* unique seed */
#include <stdbool.h>		/* true, false */
#include <utils/utils.h>	/* malloc, memcpy, ptrdiff_t */
#include "pcg_basic.h"		/* psuedorandom number generator */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* CONSTANTS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define RNG_MAX UINT32_MAX

/* CONSTANTS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

pcg32_random_t _RNG;	/* global random number generator state */

inline void init_rng(void)
{
	pcg32_srandom_r(&_RNG, time(NULL), (intptr_t)&_RNG);
}

inline bool coin_flip(void)
{
	return (bool) (pcg32_random_r(&_RNG) & 1u);
}

inline uint32_t rand_uint_upto(const uint32_t rbound)
{
	const uint32_t range_length = rbound + 1u;
	const uint32_t valid_limit  = RNG_MAX - (RNG_MAX % range_length);

	uint32_t rand;

	do {
		rand = pcg32_random_r(&_RNG);

	} while (rand > valid_limit);

	return rand % range_length;
}

inline int32_t rand_in_int_range(const int32_t lbound,
				 const int32_t rbound)
{

	const uint32_t range_length = rbound - lbound + 1u;
	const uint32_t valid_limit  = RNG_MAX - (RNG_MAX % range_length);

	uint32_t rand;

	do {
		rand = pcg32_random_r(&_RNG);

	} while (rand > valid_limit);

	return ((int32_t) (rand % range_length)) + lbound;
}

inline double rand_dbl_upto(const double rbound)
{
	return (((double) pcg32_random_r(&_RNG)) / ((double) RNG_MAX)) * rbound;
}

inline double rand_in_dbl_range(const double lbound,
				const double rbound)
{
	return (((double) pcg32_random_r(&_RNG)) / ((double) RNG_MAX))
	       * (rbound - lbound)
	       + lbound;
}

static inline void swap_els(void *__restrict__ el1,
			    void *__restrict__ el2,
			    void *__restrict__ buf,
			    const size_t width);

void shuffle_array(void *array,
		   const size_t length,
		   const size_t width);

inline int32_t *init_rand_int_array(const size_t length)
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

#endif /* ifndef RAND_RAND_H_ */
