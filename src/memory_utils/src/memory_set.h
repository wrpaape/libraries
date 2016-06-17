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
extern MemorySet *const MEMORY_SET_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define MEMORY_SET_WIDTH(X, Y, WIDTH)		\
*((Width ## WIDTH *const restrict) X) =		\
*((const Width ## WIDTH *const restrict) Y)

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* memory set arbitrary byte size, 'width' */
inline void memory_set_width(void *const restrict x,
			     const void *const restrict y,
			     const size_t width)
{
	memcpy(x, y, width);
}

inline MemorySet *assign_memory_set(const size_t width)
{
	return (width > WIDTH_MAX_SIZE) ? NULL : MEMORY_SET_MAP[width];
}


/* define memory_set<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX_SIZE */
inline void memory_set1(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 1);
}

inline void memory_set2(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 2);
}

inline void memory_set3(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 3);
}

inline void memory_set4(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 4);
}

inline void memory_set5(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 5);
}

inline void memory_set6(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 6);
}

inline void memory_set7(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 7);
}

inline void memory_set8(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 8);
}

inline void memory_set9(void *const restrict x,
			const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 9);
}

inline void memory_set10(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 10);
}

inline void memory_set11(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 11);
}

inline void memory_set12(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 12);
}

inline void memory_set13(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 13);
}

inline void memory_set14(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 14);
}

inline void memory_set15(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 15);
}

inline void memory_set16(void *const restrict x,
			 const void *const restrict y)
{
	MEMORY_SET_WIDTH(x, y, 16);
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
