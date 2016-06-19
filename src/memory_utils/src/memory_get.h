#ifndef MEMORY_UTILS_MEMORY_GET_H_
#define MEMORY_UTILS_MEMORY_GET_H_

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

#include "memory_get_width.h" /* MEMORY_GET_WIDTH */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* index access for an ptr of particular byte width */
typedef void *MemoryGet(const void *const restrict,
			const ptrdiff_t);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_get' */
extern MemoryGet *const MEMORY_GET_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
#define MEMORY_GET_WIDTH(PTR, I, WIDTH)					\
((void *) (((const Width ## WIDTH *const restrict) (PTR)) + (I)))

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* return address of object offset 'i * width' bytes from 'ptr', i.e. 'i'th
 * member of array refrerenced by 'ptr'  */
inline void *memory_get_width(const void *const restrict ptr,
			      const ptrdiff_t i,
			      const size_t width)
{
	return (void *) (((const Width1 *const restrict) ptr) + (i * width));
}

inline MemoryGet *assign_memory_get(const size_t width)
{
	return (width > WIDTH_MAX_SIZE) ? NULL_POINTER : MEMORY_GET_MAP[width];
}

/* define memory_get<WIDTH> functions for WIDTH = 0 .. WIDTH_MAX_SIZE */
inline void *memory_get0(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) ptr;
}

inline void *memory_get1(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 1);
}

inline void *memory_get2(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 2);
}

inline void *memory_get3(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 3);
}

inline void *memory_get4(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 4);
}

inline void *memory_get5(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 5);
}

inline void *memory_get6(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 6);
}

inline void *memory_get7(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 7);
}

inline void *memory_get8(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 8);
}

inline void *memory_get9(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 9);
}

inline void *memory_get10(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 10);
}

inline void *memory_get11(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 11);
}

inline void *memory_get12(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 12);
}

inline void *memory_get13(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 13);
}

inline void *memory_get14(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 14);
}

inline void *memory_get15(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 15);
}

inline void *memory_get16(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return MEMORY_GET_WIDTH(ptr, i, 16);
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

#endif /* ifndef MEMORY_UTILS_MEMORY_GET_H_ */
