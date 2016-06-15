#ifndef MEMORY_UTILS_MEMORY_SET_H_
#define MEMORY_UTILS_MEMORY_SET_H_

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

/* set memory for a particular byte width */
typedef void MemorySet(void *const restrict,
		       const void *const restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_set' (+1 for extra NULL slot) */
extern MemorySet *const MEMORY_SET_MAP[WIDTH_MAX + 1ul];

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

#define memory_set_width(X, Y, WIDTH) memset(X, ((int) Y), WIDTH)

inline MemorySet *assign_memory_set(const size_t width)
{
	return (width > WIDTH_MAX) ? NULL : MEMORY_SET_MAP[width];
}

/* define memory_set<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX */
inline void memory_set1(void *const restrict x,
			const void *const restrict y)
{
	*((Width1 *const restrict) x) = *((const Width1 *const restrict) y);
}

inline void memory_set2(void *const restrict x,
			const void *const restrict y)
{
	*((Width2 *const restrict) x) = *((const Width2 *const restrict) y);
}

inline void memory_set3(void *const restrict x,
			const void *const restrict y)
{
	*((Width3 *const restrict) x) = *((const Width3 *const restrict) y);
}

inline void memory_set4(void *const restrict x,
			const void *const restrict y)
{
	*((Width4 *const restrict) x) = *((const Width4 *const restrict) y);
}

inline void memory_set5(void *const restrict x,
			const void *const restrict y)
{
	*((Width5 *const restrict) x) = *((const Width5 *const restrict) y);
}

inline void memory_set6(void *const restrict x,
			const void *const restrict y)
{
	*((Width6 *const restrict) x) = *((const Width6 *const restrict) y);
}

inline void memory_set7(void *const restrict x,
			const void *const restrict y)
{
	*((Width7 *const restrict) x) = *((const Width7 *const restrict) y);
}

inline void memory_set8(void *const restrict x,
			const void *const restrict y)
{
	*((Width8 *const restrict) x) = *((const Width8 *const restrict) y);
}

inline void memory_set9(void *const restrict x,
			const void *const restrict y)
{
	*((Width9 *const restrict) x) = *((const Width9 *const restrict) y);
}

inline void memory_set10(void *const restrict x,
			 const void *const restrict y)
{
	*((Width10 *const restrict) x) = *((const Width10 *const restrict) y);
}

inline void memory_set11(void *const restrict x,
			 const void *const restrict y)
{
	*((Width11 *const restrict) x) = *((const Width11 *const restrict) y);
}

inline void memory_set12(void *const restrict x,
			 const void *const restrict y)
{
	*((Width12 *const restrict) x) = *((const Width12 *const restrict) y);
}

inline void memory_set13(void *const restrict x,
			 const void *const restrict y)
{
	*((Width13 *const restrict) x) = *((const Width13 *const restrict) y);
}

inline void memory_set14(void *const restrict x,
			 const void *const restrict y)
{
	*((Width14 *const restrict) x) = *((const Width14 *const restrict) y);
}

inline void memory_set15(void *const restrict x,
			 const void *const restrict y)
{
	*((Width15 *const restrict) x) = *((const Width15 *const restrict) y);
}

inline void memory_set16(void *const restrict x,
			 const void *const restrict y)
{
	*((Width16 *const restrict) x) = *((const Width16 *const restrict) y);
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

#endif /* ifndef MEMORY_UTILS_MEMORY_SET_H_ */
