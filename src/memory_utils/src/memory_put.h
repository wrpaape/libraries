#ifndef MEMORY_UTILS_MEMORY_PUT_H_
#define MEMORY_UTILS_MEMORY_PUT_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_set.h" /* Width<WIDTH>, memory_set<WIDTH> */
#include "memory_get.h" /* memory_get<WIDTH> */

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

/* lookup for 'assign_memory_put' (+1 for extra NULL slot) */
extern MemoryPut *const MEMORY_PUT_MAP[WIDTH_MAX + 1ul];

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
	memory_set_width(x, y, width);

	return memory_get_width(x, 1l, width);
}

inline MemoryPut *assign_memory_put(const size_t width)
{
	return (width > WIDTH_MAX) ? NULL : MEMORY_PUT_MAP[width];
}

/* define memory_put<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX */
inline void *memory_put1(void *const restrict x,
			 const void *const restrict y)
{
	memory_set1(x, y);

	return memory_get1(x, 1l);
}

inline void *memory_put2(void *const restrict x,
			 const void *const restrict y)
{
	memory_set2(x, y);

	return memory_get2(x, 1l);
}

inline void *memory_put3(void *const restrict x,
			 const void *const restrict y)
{
	memory_set3(x, y);

	return memory_get3(x, 1l);
}

inline void *memory_put4(void *const restrict x,
			 const void *const restrict y)
{
	memory_set4(x, y);

	return memory_get4(x, 1l);
}

inline void *memory_put5(void *const restrict x,
			 const void *const restrict y)
{
	memory_set5(x, y);

	return memory_get5(x, 1l);
}

inline void *memory_put6(void *const restrict x,
			 const void *const restrict y)
{
	memory_set6(x, y);

	return memory_get6(x, 1l);
}

inline void *memory_put7(void *const restrict x,
			 const void *const restrict y)
{
	memory_set7(x, y);

	return memory_get7(x, 1l);
}

inline void *memory_put8(void *const restrict x,
			 const void *const restrict y)
{
	memory_set8(x, y);

	return memory_get8(x, 1l);
}

inline void *memory_put9(void *const restrict x,
			 const void *const restrict y)
{
	memory_set9(x, y);

	return memory_get9(x, 1l);
}

inline void *memory_put10(void *const restrict x,
			  const void *const restrict y)
{
	memory_set10(x, y);

	return memory_get10(x, 1l);
}

inline void *memory_put11(void *const restrict x,
			  const void *const restrict y)
{
	memory_set11(x, y);

	return memory_get11(x, 1l);
}

inline void *memory_put12(void *const restrict x,
			  const void *const restrict y)
{
	memory_set12(x, y);

	return memory_get12(x, 1l);
}

inline void *memory_put13(void *const restrict x,
			  const void *const restrict y)
{
	memory_set13(x, y);

	return memory_get13(x, 1l);
}

inline void *memory_put14(void *const restrict x,
			  const void *const restrict y)
{
	memory_set14(x, y);

	return memory_get14(x, 1l);
}

inline void *memory_put15(void *const restrict x,
			  const void *const restrict y)
{
	memory_set15(x, y);

	return memory_get15(x, 1l);
}

inline void *memory_put16(void *const restrict x,
			  const void *const restrict y)
{
	memory_set16(x, y);

	return memory_get16(x, 1l);
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
