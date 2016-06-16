#ifndef MEMORY_UTILS_MEMORY_SWAP_H_
#define MEMORY_UTILS_MEMORY_SWAP_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

/* macros defined with leading underscores used for keeping consistency between
 * declarations and definitions with 'memory_swap.c', not needed for interface */

/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_utils.h" /* Width<WIDTH> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* swap memory for a particular byte width */
typedef void MemorySwap(void *const restrict,
			void *const restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *

 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_swap' (+1 for extra NULL slot) */
extern MemorySwap *const MEMORY_SWAP_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* swap variables (same type) */
#define VAR_SWAP(X, Y)				\
do {						\
	const __typeof__(X) __swap_tmp = X;	\
	X = Y;					\
	Y = __swap_tmp;				\
} while(0)

/* swap elements of 'ARRAY' at indices 'I', 'J' */
#define EL_SWAP(ARRAY, I, J)				\
do {							\
	const __typeof__(*ARRAY) __swap_tmp = ARRAY[I];	\
	ARRAY[I] = ARRAY[J];				\
	ARRAY[J] =  __swap_tmp;				\
} while(0)

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* memory swap arbitrary byte size, 'width' */
inline void memory_swap_width(void *const restrict x,
			      void *const restrict y,
			      const size_t width)
{
	Width1 buffer[width];
	memcpy(&buffer[0l], x,		 width);
	memcpy(x,	    y,		 width);
	memcpy(y,	    &buffer[0l], width);
}

/* same as 'memory_swap_width' except 'buffer' is provided by caller, not
 * allocated on stack */
inline void memory_swap_buffer(void *const restrict x,
			       void *const restrict y,
			       void *const restrict buffer,
			       const size_t width)
{
	memcpy(buffer, x,      width);
	memcpy(x,      y,      width);
	memcpy(y,      buffer, width);
}

inline MemorySwap *assign_memory_swap(const size_t width)
{
	return (width > WIDTH_MAX_SIZE) ? NULL : MEMORY_SWAP_MAP[width];
}

/* define memory_swap<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX_SIZE */
inline void memory_swap1(void *const restrict x,
			 void *const restrict y)
{
	const Width1 swap = *((Width1 *const restrict) x);
	*((Width1 *const restrict) x) = *((Width1 *const restrict) y);
	*((Width1 *const restrict) y) = swap;
}

inline void memory_swap2(void *const restrict x,
			 void *const restrict y)
{
	const Width2 swap = *((Width2 *const restrict) x);
	*((Width2 *const restrict) x) = *((Width2 *const restrict) y);
	*((Width2 *const restrict) y) = swap;
}

inline void memory_swap3(void *const restrict x,
			 void *const restrict y)
{
	const Width3 swap = *((Width3 *const restrict) x);
	*((Width3 *const restrict) x) = *((Width3 *const restrict) y);
	*((Width3 *const restrict) y) = swap;
}

inline void memory_swap4(void *const restrict x,
			 void *const restrict y)
{
	const Width4 swap = *((Width4 *const restrict) x);
	*((Width4 *const restrict) x) = *((Width4 *const restrict) y);
	*((Width4 *const restrict) y) = swap;
}

inline void memory_swap5(void *const restrict x,
			 void *const restrict y)
{
	const Width5 swap = *((Width5 *const restrict) x);
	*((Width5 *const restrict) x) = *((Width5 *const restrict) y);
	*((Width5 *const restrict) y) = swap;
}

inline void memory_swap6(void *const restrict x,
			 void *const restrict y)
{
	const Width6 swap = *((Width6 *const restrict) x);
	*((Width6 *const restrict) x) = *((Width6 *const restrict) y);
	*((Width6 *const restrict) y) = swap;
}

inline void memory_swap7(void *const restrict x,
			 void *const restrict y)
{
	const Width7 swap = *((Width7 *const restrict) x);
	*((Width7 *const restrict) x) = *((Width7 *const restrict) y);
	*((Width7 *const restrict) y) = swap;
}

inline void memory_swap8(void *const restrict x,
			 void *const restrict y)
{
	const Width8 swap = *((Width8 *const restrict) x);
	*((Width8 *const restrict) x) = *((Width8 *const restrict) y);
	*((Width8 *const restrict) y) = swap;
}

inline void memory_swap9(void *const restrict x,
			 void *const restrict y)
{
	const Width9 swap = *((Width9 *const restrict) x);
	*((Width9 *const restrict) x) = *((Width9 *const restrict) y);
	*((Width9 *const restrict) y) = swap;
}

inline void memory_swap10(void *const restrict x,
			  void *const restrict y)
{
	const Width10 swap = *((Width10 *const restrict) x);
	*((Width10 *const restrict) x) = *((Width10 *const restrict) y);
	*((Width10 *const restrict) y) = swap;
}

inline void memory_swap11(void *const restrict x,
			  void *const restrict y)
{
	const Width11 swap = *((Width11 *const restrict) x);
	*((Width11 *const restrict) x) = *((Width11 *const restrict) y);
	*((Width11 *const restrict) y) = swap;
}

inline void memory_swap12(void *const restrict x,
			  void *const restrict y)
{
	const Width12 swap = *((Width12 *const restrict) x);
	*((Width12 *const restrict) x) = *((Width12 *const restrict) y);
	*((Width12 *const restrict) y) = swap;
}

inline void memory_swap13(void *const restrict x,
			  void *const restrict y)
{
	const Width13 swap = *((Width13 *const restrict) x);
	*((Width13 *const restrict) x) = *((Width13 *const restrict) y);
	*((Width13 *const restrict) y) = swap;
}

inline void memory_swap14(void *const restrict x,
			  void *const restrict y)
{
	const Width14 swap = *((Width14 *const restrict) x);
	*((Width14 *const restrict) x) = *((Width14 *const restrict) y);
	*((Width14 *const restrict) y) = swap;
}

inline void memory_swap15(void *const restrict x,
			  void *const restrict y)
{
	const Width15 swap = *((Width15 *const restrict) x);
	*((Width15 *const restrict) x) = *((Width15 *const restrict) y);
	*((Width15 *const restrict) y) = swap;
}

inline void memory_swap16(void *const restrict x,
			  void *const restrict y)
{
	const Width16 swap = *((Width16 *const restrict) x);
	*((Width16 *const restrict) x) = *((Width16 *const restrict) y);
	*((Width16 *const restrict) y) = swap;
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_UTILS_MEMORY_SWAP_H_ */
