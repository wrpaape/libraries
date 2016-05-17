#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <stdlib.h>	/* m/c/realloc, free, exit */
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

/* error handlers
 * ========================================================================== */
#ifdef __cplusplus /* for c++ files */
/* memory allocation (cast returned alloc, 'nullptr' instead of 'NULL') */
#define HANDLE_MALLOC(PTR, SIZE)					\
do {									\
	PTR = (__typeof__(PTR)) malloc(SIZE);				\
	if (PTR == nullptr)						\
		EXIT_ON_FAILURE("failed to allocate %lu bytes of "	\
				"memory for '" #PTR "'", SIZE);		\
} while (0)
#define HANDLE_CALLOC(PTR, COUNT, SIZE)					\
do {									\
	PTR = (__typeof__(PTR)) calloc(COUNT, SIZE);			\
	if (PTR == nullptr)						\
		EXIT_ON_FAILURE("failed to allocate %lu blocks of %lu"	\
				"bytes of zeroed memory for '" #PTR	\
				"'", COUNT, SIZE);			\
} while (0)
#define HANDLE_REALLOC(PTR, SIZE)					\
do {									\
	PTR = (__typeof__(PTR)) realloc(PTR, SIZE);			\
	if (PTR == nullptr)						\
		EXIT_ON_FAILURE("failed to reallocate memory for '"	\
				#PTR "' to %lu bytes", SIZE);		\
} while (0)


#else	/* for c files */

/* memory allocation */
#define HANDLE_MALLOC(PTR, SIZE)					\
do {									\
	PTR = malloc(SIZE);						\
	if (PTR == NULL)						\
		EXIT_ON_FAILURE("failed to allocate %lu bytes of "	\
				"memory for '" #PTR "'", SIZE);		\
} while (0)
#define HANDLE_CALLOC(PTR, COUNT, SIZE)					\
do {									\
	PTR = calloc(COUNT, SIZE);					\
	if (PTR == NULL)						\
		EXIT_ON_FAILURE("failed to allocate %lu blocks of %lu"	\
				"bytes of zeroed memory for '" #PTR	\
				"'", COUNT, SIZE);			\
} while (0)
#define HANDLE_REALLOC(PTR, SIZE)					\
do {									\
	PTR = realloc(PTR, SIZE);					\
	if (PTR == NULL)						\
		EXIT_ON_FAILURE("failed to reallocate memory for '"	\
				#PTR "' to %lu bytes", SIZE);		\
} while (0)

#endif	/* ifdef __cplusplus */


/* returns 'THIS' or 'THAT' according to the predicate 'THIS CMP THAT',
 * where 'CMP' is a binary relational operator */
#define THIS_OR_THAT(THIS, THAT, CMP) (((THIS) CMP (THAT)) ? (THIS) : (THAT))

/* returns minimum of 'X' and 'Y' */
#define MIN(X, Y) THIS_OR_THAT(X, Y, <)

/* returns maximum of 'X' and 'Y' */
#define MAX(X, Y) THIS_OR_THAT(X, Y, >)

/* swap variables (same type) */
#define VAR_SWAP(X, Y)				\
do {						\
	const __typeof__(X) __swap_tmp = X;	\
	X = Y;					\
	Y = __swap_tmp;				\
} while(0)

/* swap elements of 'ARRAY' at indices 'I', 'J' */
#define EL_SWAP(ARRAY, I, J)				\
do {							\
	const __typeof__(*ARRAY) __swap_tmp = ARRAY[I];	\
	ARRAY[I] = ARRAY[J];				\
	ARRAY[J] =  __swap_tmp;				\
} while(0)

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

inline void mem_swap(void *__restrict__ x,
		     void *__restrict__ y,
		     const size_t width)
{
	char buffer[width];
	memcpy(&buffer[0l], x,		 width);
	memcpy(x,	    y,		 width);
	memcpy(y,	    &buffer[0l], width);
}


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_UTILS_H_ */
