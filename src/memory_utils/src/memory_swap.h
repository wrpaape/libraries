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

#include "memory_utils.h" /* ByteWidth<WIDTH> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* swap memory for a particular byte width */
typedef void MemorySwap(void *restrict,
			void *restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *

 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_swap' (+1 for extra NULL slot) */
extern MemorySwap *const MEMORY_SWAP_MAP[BYTE_WIDTH_MAX + 1ul];

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
inline void memory_swap_width(void *restrict x,
			      void *restrict y,
			      const size_t width)
{
	ByteWidth1 buffer[width];
	memcpy(&buffer[0l], x,		 width);
	memcpy(x,	    y,		 width);
	memcpy(y,	    &buffer[0l], width);
}

/* same as 'memory_swap_width' except 'buffer' is provided by caller, not
 * allocated on stack */
inline void memory_swap_buffer(void *restrict x,
			       void *restrict y,
			       void *restrict buffer,
			       const size_t width)
{
	memcpy(buffer, x,      width);
	memcpy(x,      y,      width);
	memcpy(y,      buffer, width);
}

inline MemorySwap *assign_memory_swap(const size_t width)
{
	return (width > BYTE_WIDTH_MAX) ? NULL : MEMORY_SWAP_MAP[width];
}

/* define memory_swap<WIDTH> functions for WIDTH = 1 .. BYTE_WIDTH_MAX */
inline void memory_swap1(void *restrict x,
			 void *restrict y)
{
	const ByteWidth1 swap = *((ByteWidth1 *) x);
	*((ByteWidth1 *) x)   = *((ByteWidth1 *) y);
	*((ByteWidth1 *) y)   = swap;
}

inline void memory_swap2(void *restrict x,
			 void *restrict y)
{
	const ByteWidth2 swap = *((ByteWidth2 *) x);
	*((ByteWidth2 *) x)   = *((ByteWidth2 *) y);
	*((ByteWidth2 *) y)   = swap;
}

inline void memory_swap3(void *restrict x,
			 void *restrict y)
{
	const ByteWidth3 swap = *((ByteWidth3 *) x);
	*((ByteWidth3 *) x)   = *((ByteWidth3 *) y);
	*((ByteWidth3 *) y)   = swap;
}

inline void memory_swap4(void *restrict x,
			 void *restrict y)
{
	const ByteWidth4 swap = *((ByteWidth4 *) x);
	*((ByteWidth4 *) x)   = *((ByteWidth4 *) y);
	*((ByteWidth4 *) y)   = swap;
}

inline void memory_swap5(void *restrict x,
			 void *restrict y)
{
	const ByteWidth5 swap = *((ByteWidth5 *) x);
	*((ByteWidth5 *) x)   = *((ByteWidth5 *) y);
	*((ByteWidth5 *) y)   = swap;
}

inline void memory_swap6(void *restrict x,
			 void *restrict y)
{
	const ByteWidth6 swap = *((ByteWidth6 *) x);
	*((ByteWidth6 *) x)   = *((ByteWidth6 *) y);
	*((ByteWidth6 *) y)   = swap;
}

inline void memory_swap7(void *restrict x,
			 void *restrict y)
{
	const ByteWidth7 swap = *((ByteWidth7 *) x);
	*((ByteWidth7 *) x)   = *((ByteWidth7 *) y);
	*((ByteWidth7 *) y)   = swap;
}

inline void memory_swap8(void *restrict x,
			 void *restrict y)
{
	const ByteWidth8 swap = *((ByteWidth8 *) x);
	*((ByteWidth8 *) x)   = *((ByteWidth8 *) y);
	*((ByteWidth8 *) y)   = swap;
}

inline void memory_swap9(void *restrict x,
			 void *restrict y)
{
	const ByteWidth9 swap = *((ByteWidth9 *) x);
	*((ByteWidth9 *) x)   = *((ByteWidth9 *) y);
	*((ByteWidth9 *) y)   = swap;
}

inline void memory_swap10(void *restrict x,
			  void *restrict y)
{
	const ByteWidth10 swap = *((ByteWidth10 *) x);
	*((ByteWidth10 *) x)   = *((ByteWidth10 *) y);
	*((ByteWidth10 *) y)   = swap;
}

inline void memory_swap11(void *restrict x,
			  void *restrict y)
{
	const ByteWidth11 swap = *((ByteWidth11 *) x);
	*((ByteWidth11 *) x)   = *((ByteWidth11 *) y);
	*((ByteWidth11 *) y)   = swap;
}

inline void memory_swap12(void *restrict x,
			  void *restrict y)
{
	const ByteWidth12 swap = *((ByteWidth12 *) x);
	*((ByteWidth12 *) x)   = *((ByteWidth12 *) y);
	*((ByteWidth12 *) y)   = swap;
}

inline void memory_swap13(void *restrict x,
			  void *restrict y)
{
	const ByteWidth13 swap = *((ByteWidth13 *) x);
	*((ByteWidth13 *) x)   = *((ByteWidth13 *) y);
	*((ByteWidth13 *) y)   = swap;
}

inline void memory_swap14(void *restrict x,
			  void *restrict y)
{
	const ByteWidth14 swap = *((ByteWidth14 *) x);
	*((ByteWidth14 *) x)   = *((ByteWidth14 *) y);
	*((ByteWidth14 *) y)   = swap;
}

inline void memory_swap15(void *restrict x,
			  void *restrict y)
{
	const ByteWidth15 swap = *((ByteWidth15 *) x);
	*((ByteWidth15 *) x)   = *((ByteWidth15 *) y);
	*((ByteWidth15 *) y)   = swap;
}

inline void memory_swap16(void *restrict x,
			  void *restrict y)
{
	const ByteWidth16 swap = *((ByteWidth16 *) x);
	*((ByteWidth16 *) x)   = *((ByteWidth16 *) y);
	*((ByteWidth16 *) y)   = swap;
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
