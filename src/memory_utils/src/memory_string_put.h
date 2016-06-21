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
#include "memory_put_width.h"	/* Width<WIDTH>, MEMORY_PUT/GET_WIDTH */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

typedef void *MemoryStringPut(void *restrict,
			      const struct MemoryString *const restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* lookup for dynamic Putter assignment */
extern MemoryStringPut *const
MEMORY_STRING_PUT_REM_MAP[WIDTH_MAX_SIZE + 1ul];

extern MemoryStringPut *const
MEMORY_STRING_PUT_REM_WORDS_MAP[WIDTH_MAX_SIZE + 1ul];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define MEMORY_STRING_PUT_WORDS_REM_BODY(BUFFER, STRING, REM_WIDTH)	\
void *const restrict end_ptr = BUFFER + STRING->length;			\
const word_t *restrict words = STRING->words;				\
MEMORY_PUT_WIDTH(BUFFER, STRING->rem, REM_WIDTH, BUFFER =);		\
while (1) {								\
	*((word_t *restrict) BUFFER) = *words;				\
	BUFFER = (void *restrict) (((word_t *restrict) BUFFER) + 1l);	\
	if (BUFFER == end_ptr)						\
		return BUFFER;						\
	++words;							\
}

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

/* put words remainder */
inline void *
memory_string_put_rem0(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	return (void *) buffer;
}


inline void *
memory_string_put_rem1(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 1, return);
}


inline void *
memory_string_put_rem2(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 2, return);
}

inline void *
memory_string_put_rem3(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 3, return);
}

inline void *
memory_string_put_rem4(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 4, return);
}

inline void *
memory_string_put_rem5(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 5, return);
}

inline void *
memory_string_put_rem6(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 6, return);
}

inline void *
memory_string_put_rem7(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 7, return);
}

inline void *
memory_string_put_rem8(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 8, return);
}

inline void *
memory_string_put_rem9(void *restrict buffer,
		       const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 9, return);
}

inline void *
memory_string_put_rem10(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 10, return);
}

inline void *
memory_string_put_rem11(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 11, return);
}

inline void *
memory_string_put_rem12(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 12, return);
}

inline void *
memory_string_put_rem13(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 13, return);
}

inline void *
memory_string_put_rem14(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 14, return);
}

inline void *
memory_string_put_rem15(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 15, return);
}

inline void *
memory_string_put_rem16(void *restrict buffer,
			const struct MemoryString *const restrict string)
{
	MEMORY_PUT_WIDTH(buffer, string->rem, 16, return);
}


/* put words with no remainder */
inline void *
memory_string_put_rem_words0(void *restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, Max)
}


/* put words with remainder <WIDTH> > 0 */
inline void *
memory_string_put_rem_words1(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 1)
}

inline void *
memory_string_put_rem_words2(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 2)
}

inline void *
memory_string_put_rem_words3(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 3)
}

inline void *
memory_string_put_rem_words4(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 4)
}

inline void *
memory_string_put_rem_words5(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 5)
}

inline void *
memory_string_put_rem_words6(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 6)
}

inline void *
memory_string_put_rem_words7(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 7)
}

inline void *
memory_string_put_rem_words8(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 8)
}

inline void *
memory_string_put_rem_words9(void *const restrict buffer,
			     const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 9)
}

inline void *
memory_string_put_rem_words10(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 10)
}

inline void *
memory_string_put_rem_words11(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 11)
}

inline void *
memory_string_put_rem_words12(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 12)
}

inline void *
memory_string_put_rem_words13(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 13)
}

inline void *
memory_string_put_rem_words14(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 14)
}

inline void *
memory_string_put_rem_words15(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 15)
}

inline void *
memory_string_put_rem_words16(void *const restrict buffer,
			      const struct MemoryString *const restrict string)
{
	MEMORY_STRING_PUT_WORDS_REM_BODY(buffer, string, 16)
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS */

#ifdef _cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_UTILS_MEMORY_STRING_PUT_H_ */
