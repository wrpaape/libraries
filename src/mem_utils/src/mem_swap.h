#ifndef MEMORY_MEM_SWAP_H_
#define MEMORY_MEM_SWAP_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

/* macros defined with leading underscores used for keeping consistency between
 * declarations and definitions with 'mem_swap.c', not needed for interface */

/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* fast int types, <string.h> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* byte buffers where sizeof(ByteBuff<WIDTH>) = WIDTH
 * ========================================================================== */
/* common byte widths */
typedef uint_fast8_t ByteBuff1;
typedef uint_fast16_t ByteBuff2;
typedef uint_fast32_t ByteBuff4;
typedef uint_fast64_t ByteBuff8;
typedef __uint128_t ByteBuff16;

/* uncommon widths (backed by an array of 'WIDTH' bytes) */
typedef struct ByteBuff3 { ByteBuff1 bytes[3]; } ByteBuff3;
typedef struct ByteBuff5 { ByteBuff1 bytes[5]; } ByteBuff5;
typedef struct ByteBuff6 { ByteBuff1 bytes[6]; } ByteBuff6;
typedef struct ByteBuff7 { ByteBuff1 bytes[7]; } ByteBuff7;
typedef struct ByteBuff9 { ByteBuff1 bytes[9]; } ByteBuff9;
typedef struct ByteBuff10 { ByteBuff1 bytes[10]; } ByteBuff10;
typedef struct ByteBuff11 { ByteBuff1 bytes[11]; } ByteBuff11;
typedef struct ByteBuff12 { ByteBuff1 bytes[12]; } ByteBuff12;
typedef struct ByteBuff13 { ByteBuff1 bytes[13]; } ByteBuff13;
typedef struct ByteBuff14 { ByteBuff1 bytes[14]; } ByteBuff14;
typedef struct ByteBuff15 { ByteBuff1 bytes[15]; } ByteBuff15;

/* swap memory for a particular byte width */
typedef void MemSwap(void *restrict,
		     void *restrict);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *

 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define MAX_BYTE_BUFF_WIDTH 16
#define _FOR_ALL_BYTE_BUFF_WIDTHS(MACRO, DELIM)			\
MACRO( 1) DELIM MACRO( 2) DELIM MACRO( 3) DELIM MACRO( 4) DELIM	\
MACRO( 5) DELIM MACRO( 6) DELIM MACRO( 7) DELIM MACRO( 8) DELIM	\
MACRO( 9) DELIM MACRO(10) DELIM MACRO(11) DELIM MACRO(12) DELIM	\
MACRO(13) DELIM MACRO(14) DELIM MACRO(15) DELIM MACRO(16)


/* lookup for 'assign_mem_swap' (+1 for extra NULL slot) */
#define _MEM_SWAP_MAP_SIZE (MAX_BYTE_BUFF_WIDTH + 1ul)
extern MemSwap *const MEM_SWAP_MAP[_MEM_SWAP_MAP_SIZE];

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

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

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* memory swap arbitrary byte size, 'width' */
inline void mem_swap_width(void *restrict x,
			   void *restrict y,
			   const size_t width)
{
	ByteBuff1 buffer[width];
	memcpy(&buffer[0l], x,		 width);
	memcpy(x,	    y,		 width);
	memcpy(y,	    &buffer[0l], width);
}

/* mem_swap<WIDTH> declaration, definition helpers */
#define _MEM_SWAP_SYMBOL(WIDTH)	mem_swap ## WIDTH
#define _MEM_SWAP_PROTOTYPE(WIDTH)			\
inline void _MEM_SWAP_SYMBOL(WIDTH)(void *restrict x,	\
				    void *restrict y)
#define _DEFINE_MEM_SWAP(WIDTH)						\
_MEM_SWAP_PROTOTYPE(WIDTH)						\
{									\
	const ByteBuff ## WIDTH swap = *((ByteBuff ## WIDTH *) x);	\
	*((ByteBuff ## WIDTH *) x)   = *((ByteBuff ## WIDTH *) y);	\
	*((ByteBuff ## WIDTH *) y)   = swap;				\
}
#define _EMPTY

/* define mem_swap<WIDTH> functions for WIDTH = 1 .. MAX_BYTE_BUFF_WIDTH */
_FOR_ALL_BYTE_BUFF_WIDTHS(_DEFINE_MEM_SWAP, _EMPTY)

#undef _EMPTY
#undef _DEFINE_MEM_SWAP

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* inline void (*assign_mem_swap(const size_t width))(void *restrict, */
/* 						   void *restrict) */
inline MemSwap *assign_mem_swap(const size_t width)
{
	return (width > MAX_BYTE_BUFF_WIDTH) ? NULL : MEM_SWAP_MAP[width];
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_MEM_SWAP_H_ */
