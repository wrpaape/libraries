#ifndef UTILS_WORD_H_
#define UTILS_WORD_H_

#ifdef _cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <limits.h>	/* ULONG_MAX */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

typedef unsigned long int word_t;

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define WORD_MAX ULONG_MAX

#if   (WORD_MAX == UINT64_MAX)
#	define WORD_WIDTH 8
#	define WORD_SIZE 8lu
#	define MULT_WORD_SIZE(X) (X) << 3
#	define DIV_WORD_SIZE(X)  (X) >> 3
#	define REM_WORD_SIZE(X)  (X) &  7lu
#elif (WORD_MAX == ((1llu << 56) - 1llu))
#	define WORD_WIDTH 7
#	define WORD_SIZE 7lu
#	define MULT_WORD_SIZE(X) (X) * 7lu
#	define DIV_WORD_SIZE(X)  (X) / 7lu
#	define REM_WORD_SIZE(X)  (X) % 7lu
#elif (WORD_MAX == ((1llu << 48) - 1llu))
#	define WORD_WIDTH 6
#	define WORD_SIZE 6lu
#	define MULT_WORD_SIZE(X) (X) * 6lu
#	define DIV_WORD_SIZE(X)  (X) / 6lu
#	define REM_WORD_SIZE(X)  (X) % 6lu
#elif (WORD_MAX == ((1llu << 40) - 1llu))
#	define WORD_WIDTH 5
#	define WORD_SIZE 5lu
#	define MULT_WORD_SIZE(X) (X) * 5lu
#	define DIV_WORD_SIZE(X)  (X) / 5lu
#	define REM_WORD_SIZE(X)  (X) % 5lu
#elif (WORD_MAX == UINT32_MAX)
#	define WORD_SIZE 4lu
#	define WORD_WIDTH 4
#	define MULT_WORD_SIZE(X) (X) << 2
#	define DIV_WORD_SIZE(X)  (X) >> 2
#	define REM_WORD_SIZE(X)  (X) & 3lu
#elif (WORD_MAX == ((1llu << 24) - 1llu))
#	define WORD_WIDTH 3
#	define WORD_SIZE 3lu
#	define MULT_WORD_SIZE(X) (X) * 3lu
#	define DIV_WORD_SIZE(X)  (X) / 3lu
#	define REM_WORD_SIZE(X)  (X) % 3lu
#elif (WORD_MAX == UINT16_MAX)
#	define WORD_WIDTH 2
#	define WORD_SIZE 2lu
#	define MULT_WORD_SIZE(X) (X) << 1
#	define DIV_WORD_SIZE(X)  (X) >> 1
#	define REM_WORD_SIZE(X)  (X) & 1lu
#elif (WORD_MAX == UINT8_MAX)
#	define WORD_WIDTH 1
#	define WORD_SIZE 1lu
#	define MULT_WORD_SIZE(X) X
#	define DIV_WORD_SIZE(X)  X
#	define REM_WORD_SIZE(X)  0lu
#elif (WORD_MAX == 0lu)
#	error "sizeof(word_t) is 0"
#else
#	warn "sizeof(word_t) is unknown to preprocessor: 'WORD_SIZE' is undefined"
#endif

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS */

#ifdef _cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_WORD_H_ */
