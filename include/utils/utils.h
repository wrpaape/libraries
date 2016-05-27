#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <stdlib.h>	/* exit */
#include <stddef.h>	/* ptrdiff_t */
#include <stdio.h>	/* printf, fprintf */
#include <errno.h>	/* errno */
#include <string.h>	/* strerror */
#include <limits.h>	/* CHAR_BIT */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define BIT_SIZE(TYPE) (sizeof(TYPE) * CHAR_BIT)

#define EXIT_ON_FAILURE(FORMAT, ...)					\
do {									\
	fprintf(stderr,							\
		"\n\e[31m\e[5mERROR:\e[25m\t\e[4m" FORMAT "\e[24m\n\n"	\
		"errno: %s\n\n"						\
		"file:  %s\n\n"						\
		"func:  %s\n\n"						\
		"line:  %d\e[0m\n",					\
		##__VA_ARGS__,						\
		strerror(errno), __FILE__, __func__, __LINE__);		\
	exit(EXIT_FAILURE);						\
} while (0)



/* returns 'THIS' or 'THAT' according to the predicate 'THIS CMP THAT',
 * where 'CMP' is a binary relational operator */
#define THIS_OR_THAT(THIS, THAT, CMP) (((THIS) CMP (THAT)) ? (THIS) : (THAT))

/* returns minimum of 'X' and 'Y' */
#define MIN(X, Y) THIS_OR_THAT(X, Y, <)

/* returns maximum of 'X' and 'Y' */
#define MAX(X, Y) THIS_OR_THAT(X, Y, >)


/* print elements of 'ARRAY' */
#define PRINT_ARRAY(ARRAY, LENGTH, FORMAT)		\
do {							\
	printf(#ARRAY ": {\n" FORMAT, ARRAY[0l]);	\
	for (ptrdiff_t i = 1; i < LENGTH; ++i)		\
		printf(", " FORMAT, ARRAY[i]);		\
	puts("\n}");					\
} while (0)

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

inline size_t next_pow_two(const size_t num)
{
	return 1lu << (BIT_SIZE(size_t) - __builtin_clzl(num - 1lu));
}

inline size_t log_base_two(const size_t num)
{
	return __builtin_ctzl(num);
}

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_UTILS_H_ */
