#ifndef MEMORY_UTILS_MEMORY_WORD_REM_SET_H_
#define MEMORY_UTILS_MEMORY_WORD_REM_SET_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include "memory_utils.h"	/* Width<WIDTH> */
#include <utils/types/word.h>	/* word_t */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
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


#define CASE_REM_SET(X, Y, TYPE)	\
*((Type *const restrict) (X)) = *((Type *const restrict) (Y))


#if   !defined(WORD_SIZE)
#	error "'WORD_SIZE' is undefined"
#elif (WORD_SIZE <= 0lu)
#	error "'WORD_SIZE' <= 0"
#elif (WORD_SIZE == 1lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)
#elif (WORD_SIZE == 2lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		if (REM == 1lu)					\
			CASE_REM_SET(X, Y, Width1);		\
		return;						\
	} while (0)
#elif (WORD_SIZE == 3lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		default:  CASE_REM_SET(X, Y, Width2); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 4lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		default:  CASE_REM_SET(X, Y, Width3); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 5lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		default:  CASE_REM_SET(X, Y, Width4); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 6lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4); return;	\
		default:  CASE_REM_SET(X, Y, Width5); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 7lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4); return;	\
		case 5lu: CASE_REM_SET(X, Y, Width5); return;	\
		default:  CASE_REM_SET(X, Y, Width6); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 8lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4); return;	\
		case 5lu: CASE_REM_SET(X, Y, Width5); return;	\
		case 6lu: CASE_REM_SET(X, Y, Width6); return;	\
		default:  CASE_REM_SET(X, Y, Width7); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 9lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4); return;	\
		case 5lu: CASE_REM_SET(X, Y, Width5); return;	\
		case 6lu: CASE_REM_SET(X, Y, Width6); return;	\
		case 7lu: CASE_REM_SET(X, Y, Width7); return;	\
		default:  CASE_REM_SET(X, Y, Width8); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 10lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1); return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2); return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3); return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4); return;	\
		case 5lu: CASE_REM_SET(X, Y, Width5); return;	\
		case 6lu: CASE_REM_SET(X, Y, Width6); return;	\
		case 7lu: CASE_REM_SET(X, Y, Width7); return;	\
		case 8lu: CASE_REM_SET(X, Y, Width8); return;	\
		default:  CASE_REM_SET(X, Y, Width9); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 11lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu: return;				\
		case 1lu: CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu: CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu: CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu: CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu: CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu: CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu: CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu: CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu: CASE_REM_SET(X, Y, Width9);  return;	\
		default:  CASE_REM_SET(X, Y, Width10); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 12lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		default:   CASE_REM_SET(X, Y, Width11); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 13lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		case 11lu: CASE_REM_SET(X, Y, Width11); return;	\
		default:   CASE_REM_SET(X, Y, Width12); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 14lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		case 11lu: CASE_REM_SET(X, Y, Width11); return;	\
		case 12lu: CASE_REM_SET(X, Y, Width12); return;	\
		default:   CASE_REM_SET(X, Y, Width13); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 15lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		case 11lu: CASE_REM_SET(X, Y, Width11); return;	\
		case 12lu: CASE_REM_SET(X, Y, Width12); return;	\
		case 13lu: CASE_REM_SET(X, Y, Width13); return;	\
		default:   CASE_REM_SET(X, Y, Width14); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 16lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		case 11lu: CASE_REM_SET(X, Y, Width11); return;	\
		case 12lu: CASE_REM_SET(X, Y, Width12); return;	\
		case 13lu: CASE_REM_SET(X, Y, Width13); return;	\
		case 14lu: CASE_REM_SET(X, Y, Width14); return;	\
		default:   CASE_REM_SET(X, Y, Width15); return;	\
		}						\
	} while (0)
#elif (WORD_SIZE == 17lu)
#	define MEMORY_WORD_REM_SET(X, Y, REM)			\
	do {							\
		switch (REM) {					\
		case 0lu:  return;				\
		case 1lu:  CASE_REM_SET(X, Y, Width1);  return;	\
		case 2lu:  CASE_REM_SET(X, Y, Width2);  return;	\
		case 3lu:  CASE_REM_SET(X, Y, Width3);  return;	\
		case 4lu:  CASE_REM_SET(X, Y, Width4);  return;	\
		case 5lu:  CASE_REM_SET(X, Y, Width5);  return;	\
		case 6lu:  CASE_REM_SET(X, Y, Width6);  return;	\
		case 7lu:  CASE_REM_SET(X, Y, Width7);  return;	\
		case 8lu:  CASE_REM_SET(X, Y, Width8);  return;	\
		case 9lu:  CASE_REM_SET(X, Y, Width9);  return;	\
		case 10lu: CASE_REM_SET(X, Y, Width10); return;	\
		case 11lu: CASE_REM_SET(X, Y, Width11); return;	\
		case 12lu: CASE_REM_SET(X, Y, Width12); return;	\
		case 13lu: CASE_REM_SET(X, Y, Width13); return;	\
		case 14lu: CASE_REM_SET(X, Y, Width14); return;	\
		case 15lu: CASE_REM_SET(X, Y, Width15); return;	\
		default:   CASE_REM_SET(X, Y, Width16); return;	\
		}						\
	} while (0)
#else
#	error "'WORD_SIZE' > 'WIDTH_MAX_SIZE' + 1"
#endif /* if (WORD_SIZE <= 0lu) */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
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

#endif /* ifndef MEMORY_UTILS_MEMORY_WORD_REM_SET_H_ */
