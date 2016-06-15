#ifndef MEMORY_UTILS_MEMORY_GET_H_
#define MEMORY_UTILS_MEMORY_GET_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_utils.h" /* Width<WIDTH> */

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

/* lookup for 'assign_memory_get' (+1 for extra NULL slot) */
extern MemoryGet *const MEMORY_GET_MAP[WIDTH_MAX + 1ul];

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
	return (width > WIDTH_MAX) ? NULL : MEMORY_GET_MAP[width];
}

/* define memory_get<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX */
inline void *memory_get1(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width1 *const restrict) ptr) + i);
}

inline void *memory_get2(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width2 *const restrict) ptr) + i);
}

inline void *memory_get3(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width3 *const restrict) ptr) + i);
}

inline void *memory_get4(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width4 *const restrict) ptr) + i);
}

inline void *memory_get5(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width5 *const restrict) ptr) + i);
}

inline void *memory_get6(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width6 *const restrict) ptr) + i);
}

inline void *memory_get7(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width7 *const restrict) ptr) + i);
}

inline void *memory_get8(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width8 *const restrict) ptr) + i);
}

inline void *memory_get9(const void *const restrict ptr,
			 const ptrdiff_t i)
{
	return (void *) (((const Width9 *const restrict) ptr) + i);
}

inline void *memory_get10(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width10 *const restrict) ptr) + i);
}

inline void *memory_get11(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width11 *const restrict) ptr) + i);
}

inline void *memory_get12(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width12 *const restrict) ptr) + i);
}

inline void *memory_get13(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width13 *const restrict) ptr) + i);
}

inline void *memory_get14(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width14 *const restrict) ptr) + i);
}

inline void *memory_get15(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width15 *const restrict) ptr) + i);
}

inline void *memory_get16(const void *const restrict ptr,
			  const ptrdiff_t i)
{
	return (void *) (((const Width16 *const restrict) ptr) + i);
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
