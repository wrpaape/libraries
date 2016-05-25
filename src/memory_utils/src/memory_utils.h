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

#include <utils/utils.h>	/* stdint, m/c/realloc/free, EXIT_ON_FAILURE */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* byte buffers where sizeof(ByteWidth<WIDTH>) = WIDTH
 * ========================================================================== */
/* common byte widths */
typedef uint_fast8_t ByteWidth1;
typedef uint_fast16_t ByteWidth2;
typedef uint_fast32_t ByteWidth4;
typedef uint_fast64_t ByteWidth8;
typedef __uint128_t ByteWidth16;

/* uncommon widths (backed by an array of 'WIDTH' bytes) */
typedef struct ByteWidth3  { ByteWidth1 bytes[ 3]; } ByteWidth3;
typedef struct ByteWidth5  { ByteWidth1 bytes[ 5]; } ByteWidth5;
typedef struct ByteWidth6  { ByteWidth1 bytes[ 6]; } ByteWidth6;
typedef struct ByteWidth7  { ByteWidth1 bytes[ 7]; } ByteWidth7;
typedef struct ByteWidth9  { ByteWidth1 bytes[ 9]; } ByteWidth9;
typedef struct ByteWidth10 { ByteWidth1 bytes[10]; } ByteWidth10;
typedef struct ByteWidth11 { ByteWidth1 bytes[11]; } ByteWidth11;
typedef struct ByteWidth12 { ByteWidth1 bytes[12]; } ByteWidth12;
typedef struct ByteWidth13 { ByteWidth1 bytes[13]; } ByteWidth13;
typedef struct ByteWidth14 { ByteWidth1 bytes[14]; } ByteWidth14;
typedef struct ByteWidth15 { ByteWidth1 bytes[15]; } ByteWidth15;

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define BYTE_WIDTH_MAX 16ul

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

#endif /* ifndef MEMORY_UTILS_MEMORY_UTILS_H_ */
