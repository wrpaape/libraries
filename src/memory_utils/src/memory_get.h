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

#include "memory_utils.h" /* ByteWidth<WIDTH> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* index access for an array of particular byte width */
typedef void *MemoryGet(const void *const restrict,
			const ptrdiff_t);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_get' (+1 for extra NULL slot) */
extern MemoryGet *const MEMORY_GET_MAP[BYTE_WIDTH_MAX + 1ul];

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

inline MemoryGet *assign_memory_get(const size_t width)
{
	return (width > BYTE_WIDTH_MAX) ? NULL : MEMORY_GET_MAP[width];
}

/* define memory_get<WIDTH> functions for WIDTH = 1 .. BYTE_WIDTH_MAX */
inline void *memory_get1(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth1 *const restrict) array)[i]);
}

inline void *memory_get2(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth2 *const restrict) array)[i]);
}

inline void *memory_get3(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth3 *const restrict) array)[i]);
}

inline void *memory_get4(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth4 *const restrict) array)[i]);
}

inline void *memory_get5(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth5 *const restrict) array)[i]);
}

inline void *memory_get6(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth6 *const restrict) array)[i]);
}

inline void *memory_get7(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth7 *const restrict) array)[i]);
}

inline void *memory_get8(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth8 *const restrict) array)[i]);
}

inline void *memory_get9(const void *const restrict array,
			 const ptrdiff_t i)
{
	return (void *) (((const ByteWidth9 *const restrict) array)[i]);
}

inline void *memory_get10(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth10 *const restrict) array)[i]);
}

inline void *memory_get11(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth11 *const restrict) array)[i]);
}

inline void *memory_get12(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth12 *const restrict) array)[i]);
}

inline void *memory_get13(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth13 *const restrict) array)[i]);
}

inline void *memory_get14(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth14 *const restrict) array)[i]);
}

inline void *memory_get15(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth15 *const restrict) array)[i]);
}

inline void *memory_get16(const void *const restrict array,
			  const ptrdiff_t i)
{
	return (void *) (((const ByteWidth16 *const restrict) array)[i]);
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
