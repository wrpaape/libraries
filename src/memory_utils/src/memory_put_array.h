#ifndef MEMORY_UTILS_MEMORY_PUT_ARRAY_H_
#define MEMORY_UTILS_MEMORY_PUT_ARRAY_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_put.h"		/* Width<WIDTH>, memory_get/set<WIDTH> */
#include "word_rem_switch.h"	/* word_t, WORD_REM_SWITCH */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* put_array memory for a particular byte width */
typedef void *MemoryPutArray(void *restrict,
			     const void *restrict,
			     const size_t);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for 'assign_memory_put_array' (+1 for extra NULL slot) */
extern MemoryPutArray *const MEMORY_PUT_ARRAY_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define HANDLE_PUT_REM0(X, Y)  return X
#define HANDLE_PUT_REM1(X, Y)  return memory_put1(X, Y)
#define HANDLE_PUT_REM2(X, Y)  return memory_put2(X, Y)
#define HANDLE_PUT_REM3(X, Y)  return memory_put3(X, Y)
#define HANDLE_PUT_REM4(X, Y)  return memory_put4(X, Y)
#define HANDLE_PUT_REM5(X, Y)  return memory_put5(X, Y)
#define HANDLE_PUT_REM6(X, Y)  return memory_put6(X, Y)
#define HANDLE_PUT_REM7(X, Y)  return memory_put7(X, Y)
#define HANDLE_PUT_REM8(X, Y)  return memory_put8(X, Y)
#define HANDLE_PUT_REM9(X, Y)  return memory_put9(X, Y)
#define HANDLE_PUT_REM10(X, Y) return memory_put10(X, Y)
#define HANDLE_PUT_REM11(X, Y) return memory_put11(X, Y)
#define HANDLE_PUT_REM12(X, Y) return memory_put12(X, Y)
#define HANDLE_PUT_REM13(X, Y) return memory_put13(X, Y)
#define HANDLE_PUT_REM14(X, Y) return memory_put14(X, Y)
#define HANDLE_PUT_REM15(X, Y) return memory_put15(X, Y)
#define HANDLE_PUT_REM16(X, Y) return memory_put16(X, Y)

#define MEMORY_ACTION_WORD(ACTION, ...)			\
EXPAND_MEMORY_ACTION_WIDTH(ACTION, WORD_WIDTH, ##__VA_ARGS__)

#define memory_put_word(X, Y)			\
MEMORY_ACTION_WORD(put, X, Y)

#define memory_get_word(PTR, I)			\
MEMORY_ACTION_WORD(get, PTR, I)

#define memory_put_array_words(X, Y, LENGTH)	\
MEMORY_ACTION_WORD(put_array, X, Y, LENGTH)

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */


/* put at least 1 word */
#define PUT_WORDS_LOOP_BODY(X, Y, LENGTH_WORDS, EXIT_LOOP)		\
void *const restrict end_ptr = (void *) (((word_t *const restrict) X)	\
					 + length);			\
while (1) {								\
	*((word_t *restrict) X) = *((const word_t *restrict) Y);	\
	X = (void *restrict) (((word_t *restrict) X) + 1l);		\
	if (x == end_ptr)						\
		EXIT_LOOP						\
	Y = (void *restrict) (((word_t *restrict) Y) + 1l);		\
}

#define PUT_WORDS_BODY(X, Y, LENGTH)					\
PUT_WORDS_LOOP_BODY(X, Y, LENGTH,					\
		    return X;)

#define PUT_WORDS_AND_REM_BODY(X, Y, LENGTH_WORDS, REM_SIZE)		\
PUT_WORDS_LOOP_BODY(X, Y, LENGTH_WORDS,					\
		    WORD_REM_SWITCH(REM_SIZE, HANDLE_PUT_REM, X, Y))

put_full_words((word_t *restrict) (X),	\
	     (const word_t *restrict) (Y),
	     LENGTH)
/* handles casting */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* memory put_array arbitrary byte size, 'width' */
inline void *memory_put_array_width(void *restrict x,
				    const void *restrict y,
				    const size_t length,
				    const size_t width)
{
	return memory_put_width(x, y, length * width);
}

inline MemoryPutArray *assign_memory_put_array(const size_t width)
{
	return (width > WIDTH_MAX_SIZE) ? NULL : MEMORY_PUT_ARRAY_MAP[width];
}

/* define memory_put_array<WIDTH> functions for WIDTH = 1 .. WIDTH_MAX_SIZE */
inline void *memory_put_array1(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 1lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t length_words = length / WORD_SIZE;
	const size_t rem_size     = length % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array2(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 2lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 2lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array3(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 3lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 3lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array4(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 4lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 4lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array5(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 5lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 5lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array6(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 6lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 6lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array7(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 7lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 7lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array8(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 8lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 8lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array9(void *restrict x,
			       const void *restrict y,
			       const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 9lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 9lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array10(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 10lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 10lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array11(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 11lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 11lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array12(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 12lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 12lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array13(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 13lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 13lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array14(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 14lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 14lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array15(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 15lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 15lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}

inline void *memory_put_array16(void *restrict x,
				const void *restrict y,
				const size_t length)
{
	if (length == 0lu)
		return x;
#if (WORD_SIZE == 16lu)
	PUT_WORDS_BODY(x, y, length)
#else
	const size_t array_size	  = length * 16lu;
	const size_t length_words = array_size / WORD_SIZE;
	const size_t rem_size     = array_size % WORD_SIZE;
	PUT_WORDS_AND_REM_BODY(x, y, length_words, rem_size)
#endif
}
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_UTILS_MEMORY_PUT_ARRAY_H_ */