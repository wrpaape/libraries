#ifndef MEMORY_UTILS_MEMORY_SET_ARRAY_H_
#define MEMORY_UTILS_MEMORY_SET_ARRAY_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_put.h" /* Width<WIDTH>, memory_set<WIDTH> */
#include "memory_set.h" /* memory_set<WIDTH> */
#include "memory_get.h" /* memory_get<WIDTH> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* set_array memory for a particular byte width */
typedef void MemorySetArray(void *restrict,
			    const void *restrict,
			    const size_t);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_set_array' (+1 for extra NULL slot) */
extern MemorySetArray *const MEMORY_SET_ARRAY_MAP[WIDTH_MAX + 1ul];

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

/* memory set_array arbitrary byte size, 'width' */
inline void memory_set_array_width(void *restrict x,
				   const void *restrict y,
				   const size_t length,
				   const size_t width)
{
	memory_set_width(x, y, length * width);
}

inline MemorySetArray *assign_memory_set_array(const size_t width)
{
	return (width > WIDTH_MAX) ? NULL : MEMORY_SET_ARRAY_MAP[width];
}

/* define memory_set_array<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX */
inline void memory_set_array1(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get1(x, length);

	while (1) {
		x = memory_put1(x, y);

		if (x == end_ptr)
			return;

		y = memory_get1(y, 1l);
	}
}

inline void memory_set_array2(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get2(x, length);

	while (1) {
		x = memory_put2(x, y);

		if (x == end_ptr)
			return;

		y = memory_get2(y, 1l);
	}
}

inline void memory_set_array3(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get3(x, length);

	while (1) {
		x = memory_put3(x, y);

		if (x == end_ptr)
			return;

		y = memory_get3(y, 1l);
	}
}

inline void memory_set_array4(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get4(x, length);

	while (1) {
		x = memory_put4(x, y);

		if (x == end_ptr)
			return;

		y = memory_get4(y, 1l);
	}
}

inline void memory_set_array5(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get5(x, length);

	while (1) {
		x = memory_put5(x, y);

		if (x == end_ptr)
			return;

		y = memory_get5(y, 1l);
	}
}

inline void memory_set_array6(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get6(x, length);

	while (1) {
		x = memory_put6(x, y);

		if (x == end_ptr)
			return;

		y = memory_get6(y, 1l);
	}
}

inline void memory_set_array7(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get7(x, length);

	while (1) {
		x = memory_put7(x, y);

		if (x == end_ptr)
			return;

		y = memory_get7(y, 1l);
	}
}

inline void memory_set_array8(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get8(x, length);

	while (1) {
		x = memory_put8(x, y);

		if (x == end_ptr)
			return;

		y = memory_get8(y, 1l);
	}
}

inline void memory_set_array9(void *restrict x,
			      const void *restrict y,
			      const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get9(x, length);

	while (1) {
		x = memory_put9(x, y);

		if (x == end_ptr)
			return;

		y = memory_get9(y, 1l);
	}
}

inline void memory_set_array10(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get10(x, length);

	while (1) {
		x = memory_put10(x, y);

		if (x == end_ptr)
			return;

		y = memory_get10(y, 1l);
	}
}

inline void memory_set_array11(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get11(x, length);

	while (1) {
		x = memory_put11(x, y);

		if (x == end_ptr)
			return;

		y = memory_get11(y, 1l);
	}
}

inline void memory_set_array12(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get12(x, length);

	while (1) {
		x = memory_put12(x, y);

		if (x == end_ptr)
			return;

		y = memory_get12(y, 1l);
	}
}

inline void memory_set_array13(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get13(x, length);

	while (1) {
		x = memory_put13(x, y);

		if (x == end_ptr)
			return;

		y = memory_get13(y, 1l);
	}
}

inline void memory_set_array14(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get14(x, length);

	while (1) {
		x = memory_put14(x, y);

		if (x == end_ptr)
			return;

		y = memory_get14(y, 1l);
	}
}

inline void memory_set_array15(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get15(x, length);

	while (1) {
		x = memory_put15(x, y);

		if (x == end_ptr)
			return;

		y = memory_get15(y, 1l);
	}
}

inline void memory_set_array16(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return;

	void *const restrict end_ptr = memory_get16(x, length);

	while (1) {
		x = memory_put16(x, y);

		if (x == end_ptr)
			return;

		y = memory_get16(y, 1l);
	}
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

#endif /* ifndef MEMORY_UTILS_MEMORY_SET_ARRAY_H_ */
