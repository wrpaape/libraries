#ifndef MEMORY_UTILS_MEMORY_STRING_PUT_H_
#define MEMORY_UTILS_MEMORY_STRING_PUT_H_

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

#include "memory_string.h"	/* struct MemoryString, word_t, WORD_SIZE */
#include "word_rem_utils.h"	/* PUT_WORDS_LOOP, WORD_REM_SWITCH */
#include "memory_put_width.h" /* Width<WIDTH>, MEMORY_PUT/GET_WIDTH */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

typedef void *MemoryStringPut(void *const restrict,
			      const struct MemoryString *const restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
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
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

inline void *
memory_string_put_words(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	const word_t *restrict words         = string->words;
	const word_t *const restrict end_ptr = (const word_t *const restrict)
					       string->rem;



	return (void *) buffer;
}



/* put words remainder */
inline void *
memory_string_put_rem0(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	return (void *) buffer;
}


inline void *
memory_string_put_rem1(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 1, return);
}


inline void *
memory_string_put_rem2(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 2, return);
}

inline void *
memory_string_put_rem3(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 3, return);
}

inline void *
memory_string_put_rem4(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 4, return);
}

inline void *
memory_string_put_rem5(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 5, return);
}

inline void *
memory_string_put_rem6(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 6, return);
}

inline void *
memory_string_put_rem7(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 7, return);
}

inline void *
memory_string_put_rem8(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 8, return);
}

inline void *
memory_string_put_rem9(void *const restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 9, return);
}

inline void *
memory_string_put_rem10(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 10, return);
}

inline void *
memory_string_put_rem11(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 11, return);
}

inline void *
memory_string_put_rem12(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 12, return);
}

inline void *
memory_string_put_rem13(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 13, return);
}

inline void *
memory_string_put_rem14(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 14, return);
}

inline void *
memory_string_put_rem15(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 15, return);
}

inline void *
memory_string_put_rem16(void *const restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 16, return);
}




inline MemoryPut *assign_memory_string_put(const size_t size)
{
	if (size <= WIDTH_MAX_SIZE)
		return MEMORY_PUT_MAP[size];

	const size_t length_words = DIV_WORD_SIZE(size);
	const size_t rem_size	  = REM_WORD_SIZE(size);

}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS */

#ifdef _cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_UTILS_MEMORY_STRING_PUT_H_ */
