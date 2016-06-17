#ifndef MEMORY_UTILS_MEMORY_UTILS_H_
#define MEMORY_UTILS_MEMORY_UTILS_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* m/c/realloc/free, limits, EXIT_ON_FAILURE */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* byte buffers where sizeof(Width<WIDTH>) = WIDTH
 * ========================================================================== */
/* common byte widths */
typedef uint_fast8_t Width1;
typedef uint_fast16_t Width2;
typedef uint_fast32_t Width4;
typedef uint_fast64_t Width8;
typedef __uint128_t Width16;

/* uncommon widths (backed by an array of 'WIDTH' bytes) */
typedef struct Width3  { Width1 bytes[ 3]; } Width3;
typedef struct Width5  { Width1 bytes[ 5]; } Width5;
typedef struct Width6  { Width1 bytes[ 6]; } Width6;
typedef struct Width7  { Width1 bytes[ 7]; } Width7;
typedef struct Width9  { Width1 bytes[ 9]; } Width9;
typedef struct Width10 { Width1 bytes[10]; } Width10;
typedef struct Width11 { Width1 bytes[11]; } Width11;
typedef struct Width12 { Width1 bytes[12]; } Width12;
typedef struct Width13 { Width1 bytes[13]; } Width13;
typedef struct Width14 { Width1 bytes[14]; } Width14;
typedef struct Width15 { Width1 bytes[15]; } Width15;

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define WIDTH_MAX_SIZE 16ul

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* m/c/realloc handlers
 * ========================================================================== */
#ifdef __cplusplus /* for c++ files ───────────────────────────────────────── */
/* cast returned alloc, 'nullptr' instead of 'NULL' */
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

#else /* for c files ───────────────────────────────────────────────── */
/* leave alloc uncasted, 'NULL' instead of 'nullptr' */
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

/* call memory action function */
#define MEMORY_ACTION_WIDTH(ACTION, WIDTH, ...)				\
memory_ ## ACTION ## WIDTH (__VA_ARGS__)

#define EXPAND_MEMORY_ACTION_WIDTH(ACTION, WIDTH, ...)			\
MACRO_EXPAND_ARGS(MEMORY_ACTION_WIDTH, ACTION, WIDTH, ##__VA_ARGS__)

MEMORY_EXPAND_WIDTH
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* return a pointer to memory displaced 'offset' bytes from that referenced
 * by 'pointer' */
inline void *memory_offset(const void *const restrict pointer,
			   const ptrdiff_t offset)
{
	return (void *) (((const Width1 *const restrict) pointer) + offset);
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

#endif /* ifndef MEMORY_UTILS_MEMORY_UTILS_H_ */
