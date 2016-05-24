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

#include "memory_utils.h" /* ByteBuffer<WIDTH> */

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
extern MemorySwap *const MEMORY_SWAP_MAP[BYTE_BUFFER_MAX_WIDTH + 1ul];

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

inline MemorySwap *assign_memory_swap(const size_t width)
{
	return (width > BYTE_BUFFER_MAX_WIDTH) ? NULL : MEMORY_SWAP_MAP[width];
}

/* memory swap arbitrary byte size, 'width' */
inline void memory_swap_width(void *restrict x,
			      void *restrict y,
			      const size_t width)
{
	ByteBuffer1 buffer[width];
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

/* define memory_swap<WIDTH> functions for WIDTH = 1 .. BYTE_BUFFER_MAX_WIDTH */
inline void memory_swap1(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer1 swap = *((ByteBuffer1 *) x);
	*((ByteBuffer1 *) x)   = *((ByteBuffer1 *) y);
	*((ByteBuffer1 *) y)   = swap;
}

inline void memory_swap2(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer2 swap = *((ByteBuffer2 *) x);
	*((ByteBuffer2 *) x)   = *((ByteBuffer2 *) y);
	*((ByteBuffer2 *) y)   = swap;
}

inline void memory_swap3(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer3 swap = *((ByteBuffer3 *) x);
	*((ByteBuffer3 *) x)   = *((ByteBuffer3 *) y);
	*((ByteBuffer3 *) y)   = swap;
}

inline void memory_swap4(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer4 swap = *((ByteBuffer4 *) x);
	*((ByteBuffer4 *) x)   = *((ByteBuffer4 *) y);
	*((ByteBuffer4 *) y)   = swap;
}

inline void memory_swap5(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer5 swap = *((ByteBuffer5 *) x);
	*((ByteBuffer5 *) x)   = *((ByteBuffer5 *) y);
	*((ByteBuffer5 *) y)   = swap;
}

inline void memory_swap6(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer6 swap = *((ByteBuffer6 *) x);
	*((ByteBuffer6 *) x)   = *((ByteBuffer6 *) y);
	*((ByteBuffer6 *) y)   = swap;
}

inline void memory_swap7(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer7 swap = *((ByteBuffer7 *) x);
	*((ByteBuffer7 *) x)   = *((ByteBuffer7 *) y);
	*((ByteBuffer7 *) y)   = swap;
}

inline void memory_swap8(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer8 swap = *((ByteBuffer8 *) x);
	*((ByteBuffer8 *) x)   = *((ByteBuffer8 *) y);
	*((ByteBuffer8 *) y)   = swap;
}

inline void memory_swap9(void *restrict x,
			 void *restrict y)
{
	const ByteBuffer9 swap = *((ByteBuffer9 *) x);
	*((ByteBuffer9 *) x)   = *((ByteBuffer9 *) y);
	*((ByteBuffer9 *) y)   = swap;
}

inline void memory_swap10(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer10 swap = *((ByteBuffer10 *) x);
	*((ByteBuffer10 *) x)   = *((ByteBuffer10 *) y);
	*((ByteBuffer10 *) y)   = swap;
}

inline void memory_swap11(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer11 swap = *((ByteBuffer11 *) x);
	*((ByteBuffer11 *) x)   = *((ByteBuffer11 *) y);
	*((ByteBuffer11 *) y)   = swap;
}

inline void memory_swap12(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer12 swap = *((ByteBuffer12 *) x);
	*((ByteBuffer12 *) x)   = *((ByteBuffer12 *) y);
	*((ByteBuffer12 *) y)   = swap;
}

inline void memory_swap13(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer13 swap = *((ByteBuffer13 *) x);
	*((ByteBuffer13 *) x)   = *((ByteBuffer13 *) y);
	*((ByteBuffer13 *) y)   = swap;
}

inline void memory_swap14(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer14 swap = *((ByteBuffer14 *) x);
	*((ByteBuffer14 *) x)   = *((ByteBuffer14 *) y);
	*((ByteBuffer14 *) y)   = swap;
}

inline void memory_swap15(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer15 swap = *((ByteBuffer15 *) x);
	*((ByteBuffer15 *) x)   = *((ByteBuffer15 *) y);
	*((ByteBuffer15 *) y)   = swap;
}

inline void memory_swap16(void *restrict x,
			  void *restrict y)
{
	const ByteBuffer16 swap = *((ByteBuffer16 *) x);
	*((ByteBuffer16 *) x)   = *((ByteBuffer16 *) y);
	*((ByteBuffer16 *) y)   = swap;
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
