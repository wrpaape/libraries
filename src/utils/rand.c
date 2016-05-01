#include <utils/rand.h>

extern inline void init_rng(void);

extern inline bool coin_flip(void);

extern inline uint32_t rand_uint_upto(const uint32_t rbound);

extern inline int32_t rand_in_int_range(const int32_t lbound,
					const int32_t rbound);

extern inline double rand_dbl_upto(const double rbound);

extern inline double rand_in_dbl_range(const double lbound,
				       const double rbound);

extern inline int32_t *init_rand_int_array(const size_t length);

inline void swap_els(void *__restrict__ el1,
		     void *__restrict__ el2,
		     void *__restrict__ buf,
		     const size_t width)
{
	memcpy(buf, el1, width);
	memcpy(el1, el2, width);
	memcpy(el2, buf, width);
}

void shuffle_array(void *array,
		   const size_t length,
		   const size_t width)
{
	const uint32_t i_lim = length - 1u;

	char *bytes = (char *) array;

	char buffer[width];
	uint32_t i_ini, i_swp;
	ptrdiff_t o_ini, o_swp;

	for (i_ini = 0u, o_ini = 0l; i_ini < i_lim; ++i_ini, o_ini += width) {

		i_swp = rand_uint_upto(i_lim - i_ini);
		o_swp = (i_ini + i_swp) * width;

		swap_els(&bytes[o_ini], &bytes[o_swp], &buffer[0l], width);
	}
}
