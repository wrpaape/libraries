#include "random.h"

extern inline void rng_init(void);

extern inline bool coin_flip(void);

extern inline uint32_t random_uint_upto(const uint32_t rbound);

extern inline int32_t random_in_int_range(const int32_t lbound,
					  const int32_t rbound);

extern inline double random_dbl_upto(const double rbound);

extern inline double random_in_dbl_range(const double lbound,
					 const double rbound);

extern inline int32_t *init_random_int_array(const size_t length);

extern inline void shuffle_array(void *array,
				 const uint32_t length,
				 const size_t width);



void shuffle_array_by_width(void *array,
			    const uint32_t length,
			    const size_t width)
{
	ByteWidth1 buffer[width];
	uint32_t i_old, i_new;
	size_t o_old, o_new;


	ByteWidth1 *const bytes = (ByteWidth1 *) array;
	const uint32_t i_last	= length - 1u;

	for (i_old = 0u, o_old = 0l; i_old < i_last; ++i_old, o_old += width) {

		i_new = random_uint_upto(i_last - i_old);
		o_new = (i_old + i_new) * width;

		memory_swap_buffer(&bytes[o_old],
				   &bytes[o_new],
				   &buffer[0l],
				   width);
	}
}

void shuffle_array_by_swap(void *array,
			   const uint32_t length,
			   const size_t width,
			   MemorySwap *swap)
{
	uint32_t i_old, i_new;
	size_t o_old, o_new;

	ByteWidth1 *const bytes = (ByteWidth1 *) array;
	const uint32_t i_last	= length - 1u;

	for (i_old = 0u, o_old = 0l; i_old < i_last; ++i_old, o_old += width) {

		i_new = random_uint_upto(i_last - i_old);
		o_new = (i_old + i_new) * width;

		swap(&bytes[o_old],
		     &bytes[o_new]);
	}
}
