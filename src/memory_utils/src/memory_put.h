#ifndef MEMORY_UTILS_MEMORY_PUT_H_
#define MEMORY_UTILS_MEMORY_PUT_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#	ifndef restrict /* use c++ compatible '__restrict__' */
#		define restrict __restrict__
#	endif
#	ifndef NULL_POINTER /* use c++ null pointer macro */
#		define NULL_POINTER nullptr
#	endif
#else
#	ifndef NULL_POINTER /* use traditional c null pointer macro */
#		define NULL_POINTER NULL
#	endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_put_width.h" /* Width<WIDTH>, MEMORY_PUT/GET_WIDTH */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* put memory for a particular byte width */
typedef void *MemoryPut(void *const restrict,
			const void *const restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_put' */
extern MemoryPut *const MEMORY_PUT_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* memory put arbitrary byte size, 'width' */
inline void *memory_put_width(void *const restrict x,
			      const void *const restrict y,
			      const size_t width)
{
	memcpy(x, y, width);

	return MEMORY_GET_WIDTH(x, width, 1);
}

inline MemoryPut *assign_memory_put(const size_t width)
{
	return (width > WIDTH_MAX_SIZE) ? NULL_POINTER : MEMORY_PUT_MAP[width];
}

/* define memory_put<WIDTH> functions for WIDTH = 0 .. WIDTH_MAX_SIZE */
inline void *memory_put0(void *const restrict x,
			 const void *const restrict y)
{
	return x;
}

inline void *memory_put1(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 1, return);
}

inline void *memory_put2(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 2, return);
}

inline void *memory_put3(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 3, return);
}

inline void *memory_put4(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 4, return);
}

inline void *memory_put5(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 5, return);
}

inline void *memory_put6(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 6, return);
}

inline void *memory_put7(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 7, return);
}

inline void *memory_put8(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 8, return);
}

inline void *memory_put9(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 9, return);
}

inline void *memory_put10(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 10, return);
}

inline void *memory_put11(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 11, return);
}

inline void *memory_put12(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 12, return);
}

inline void *memory_put13(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 13, return);
}

inline void *memory_put14(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 14, return);
}

inline void *memory_put15(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 15, return);
}

inline void *memory_put16(void *const restrict x,
			  const void *const restrict y)
{
	MEMORY_PUT_WIDTH(x, y, 16, return);
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

#endif /* ifndef MEMORY_UTILS_MEMORY_PUT_H_ */
