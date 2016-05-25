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
typedef void MemorySwap(void *const restrict,
			void *const restrict);

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
inline void memory_swap_width(void *const restrict x,
			      void *const restrict y,
			      const size_t width)
{
	ByteWidth1 buffer[width];
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
	return (width > BYTE_WIDTH_MAX) ? NULL : MEMORY_SWAP_MAP[width];
}

/* define memory_swap<WIDTH> functions for WIDTH = 1 .. BYTE_WIDTH_MAX */
inline void memory_swap1(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth1 swap = *((ByteWidth1 *const restrict) x);
	*((ByteWidth1 *const restrict) x) = *((ByteWidth1 *const restrict) y);
	*((ByteWidth1 *const restrict) y) = swap;
}

inline void memory_swap2(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth2 swap = *((ByteWidth2 *const restrict) x);
	*((ByteWidth2 *const restrict) x) = *((ByteWidth2 *const restrict) y);
	*((ByteWidth2 *const restrict) y) = swap;
}

inline void memory_swap3(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth3 swap = *((ByteWidth3 *const restrict) x);
	*((ByteWidth3 *const restrict) x) = *((ByteWidth3 *const restrict) y);
	*((ByteWidth3 *const restrict) y) = swap;
}

inline void memory_swap4(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth4 swap = *((ByteWidth4 *const restrict) x);
	*((ByteWidth4 *const restrict) x) = *((ByteWidth4 *const restrict) y);
	*((ByteWidth4 *const restrict) y) = swap;
}

inline void memory_swap5(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth5 swap = *((ByteWidth5 *const restrict) x);
	*((ByteWidth5 *const restrict) x) = *((ByteWidth5 *const restrict) y);
	*((ByteWidth5 *const restrict) y) = swap;
}

inline void memory_swap6(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth6 swap = *((ByteWidth6 *const restrict) x);
	*((ByteWidth6 *const restrict) x) = *((ByteWidth6 *const restrict) y);
	*((ByteWidth6 *const restrict) y) = swap;
}

inline void memory_swap7(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth7 swap = *((ByteWidth7 *const restrict) x);
	*((ByteWidth7 *const restrict) x) = *((ByteWidth7 *const restrict) y);
	*((ByteWidth7 *const restrict) y) = swap;
}

inline void memory_swap8(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth8 swap = *((ByteWidth8 *const restrict) x);
	*((ByteWidth8 *const restrict) x) = *((ByteWidth8 *const restrict) y);
	*((ByteWidth8 *const restrict) y) = swap;
}

inline void memory_swap9(void *const restrict x,
			 void *const restrict y)
{
	const ByteWidth9 swap = *((ByteWidth9 *const restrict) x);
	*((ByteWidth9 *const restrict) x) = *((ByteWidth9 *const restrict) y);
	*((ByteWidth9 *const restrict) y) = swap;
}

inline void memory_swap10(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth10 swap = *((ByteWidth10 *const restrict) x);
	*((ByteWidth10 *const restrict) x) = *((ByteWidth10 *const restrict) y);
	*((ByteWidth10 *const restrict) y) = swap;
}

inline void memory_swap11(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth11 swap = *((ByteWidth11 *const restrict) x);
	*((ByteWidth11 *const restrict) x) = *((ByteWidth11 *const restrict) y);
	*((ByteWidth11 *const restrict) y) = swap;
}

inline void memory_swap12(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth12 swap = *((ByteWidth12 *const restrict) x);
	*((ByteWidth12 *const restrict) x) = *((ByteWidth12 *const restrict) y);
	*((ByteWidth12 *const restrict) y) = swap;
}

inline void memory_swap13(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth13 swap = *((ByteWidth13 *const restrict) x);
	*((ByteWidth13 *const restrict) x) = *((ByteWidth13 *const restrict) y);
	*((ByteWidth13 *const restrict) y) = swap;
}

inline void memory_swap14(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth14 swap = *((ByteWidth14 *const restrict) x);
	*((ByteWidth14 *const restrict) x) = *((ByteWidth14 *const restrict) y);
	*((ByteWidth14 *const restrict) y) = swap;
}

inline void memory_swap15(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth15 swap = *((ByteWidth15 *const restrict) x);
	*((ByteWidth15 *const restrict) x) = *((ByteWidth15 *const restrict) y);
	*((ByteWidth15 *const restrict) y) = swap;
}

inline void memory_swap16(void *const restrict x,
			  void *const restrict y)
{
	const ByteWidth16 swap = *((ByteWidth16 *const restrict) x);
	*((ByteWidth16 *const restrict) x) = *((ByteWidth16 *const restrict) y);
	*((ByteWidth16 *const restrict) y) = swap;
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
