#include "mem_swap.h"

#define _COMMA ,
#define _SEMICOLON ;

extern inline void mem_swap(void *restrict x,
			    void *restrict y,
			    const size_t width);

/* declare all mem_swap<WIDTH> functions extern */
_FOR_ALL_BYTE_BUFF_WIDTHS(extern _MEM_SWAP_PROTOTYPE, _SEMICOLON);

extern inline void (*assign_mem_swap(const size_t width))(void *restrict,
							  void *restrict);

/* define lookup for 'assign_mem_swap' (zero-width maps to NULL) */
MemSwap *const MEM_SWAP_MAP[_MEM_SWAP_MAP_SIZE] = {
	NULL, _FOR_ALL_BYTE_BUFF_WIDTHS(&_MEM_SWAP_SYMBOL, _COMMA)
};
