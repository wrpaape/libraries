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

#include "memory_utils.h" /* ByteBuffer<WIDTH> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* set memory for a particular byte width */
typedef void MemorySet(void *restrict,
		       const void *restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_set' (+1 for extra NULL slot) */
extern MemorySet *const MEMORY_SET_MAP[BYTE_WIDTH_MAX + 1ul];

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

#define memory_set_width memset

inline MemorySet *assign_memory_set(const size_t width)
{
	return (width > BYTE_WIDTH_MAX) ? NULL : MEMORY_SET_MAP[width];
}

/* define memory_set<WIDTH> functions for WIDTH = 1 .. BYTE_WIDTH_MAX */
inline void memory_set1(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth1 *) x) = *((ByteWidth1 *) y);
}

inline void memory_set2(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth2 *) x) = *((ByteWidth2 *) y);
}

inline void memory_set3(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth3 *) x) = *((ByteWidth3 *) y);
}

inline void memory_set4(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth4 *) x) = *((ByteWidth4 *) y);
}

inline void memory_set5(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth5 *) x) = *((ByteWidth5 *) y);
}

inline void memory_set6(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth6 *) x) = *((ByteWidth6 *) y);
}

inline void memory_set7(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth7 *) x) = *((ByteWidth7 *) y);
}

inline void memory_set8(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth8 *) x) = *((ByteWidth8 *) y);
}

inline void memory_set9(void *restrict x,
			const void *restrict y)
{
	*((ByteWidth9 *) x) = *((ByteWidth9 *) y);
}

inline void memory_set10(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth10 *) x) = *((ByteWidth10 *) y);
}

inline void memory_set11(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth11 *) x) = *((ByteWidth11 *) y);
}

inline void memory_set12(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth12 *) x) = *((ByteWidth12 *) y);
}

inline void memory_set13(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth13 *) x) = *((ByteWidth13 *) y);
}

inline void memory_set14(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth14 *) x) = *((ByteWidth14 *) y);
}

inline void memory_set15(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth15 *) x) = *((ByteWidth15 *) y);
}

inline void memory_set16(void *restrict x,
			 const void *restrict y)
{
	*((ByteWidth16 *) x) = *((ByteWidth16 *) y);
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
