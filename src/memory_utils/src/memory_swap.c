#include "memory_swap.h"

extern inline MemorySwap *assign_memory_swap(const size_t width);

/* define lookup for 'assign_memory_swap' (zero-width maps to NULL) */
MemorySwap *const MEMORY_SWAP_MAP[BYTE_BUFFER_MAX_WIDTH + 1ul] = {
	NULL,
	&memory_swap1,  &memory_swap2,  &memory_swap3,  &memory_swap4,
	&memory_swap5,  &memory_swap6,  &memory_swap7,  &memory_swap8,
	&memory_swap9,  &memory_swap10, &memory_swap11, &memory_swap12,
	&memory_swap13, &memory_swap14, &memory_swap15, &memory_swap16,
};

extern inline void memory_swap_width(void *restrict x,
				     void *restrict y,
				     const size_t width);

extern inline void memory_swap_buffer(void *restrict x,
				      void *restrict y,
				      void *restrict buffer,
				      const size_t width);

/* declare all memory_swap<WIDTH> functions extern */
extern inline void memory_swap1(void *restrict x,
				void *restrict y);

extern inline void memory_swap2(void *restrict x,
				void *restrict y);

extern inline void memory_swap3(void *restrict x,
				void *restrict y);

extern inline void memory_swap4(void *restrict x,
				void *restrict y);

extern inline void memory_swap5(void *restrict x,
				void *restrict y);

extern inline void memory_swap6(void *restrict x,
				void *restrict y);

extern inline void memory_swap7(void *restrict x,
				void *restrict y);

extern inline void memory_swap8(void *restrict x,
				void *restrict y);

extern inline void memory_swap9(void *restrict x,
				void *restrict y);

extern inline void memory_swap10(void *restrict x,
				 void *restrict y);

extern inline void memory_swap11(void *restrict x,
				 void *restrict y);

extern inline void memory_swap12(void *restrict x,
				 void *restrict y);

extern inline void memory_swap13(void *restrict x,
				 void *restrict y);

extern inline void memory_swap14(void *restrict x,
				 void *restrict y);

extern inline void memory_swap15(void *restrict x,
				 void *restrict y);

extern inline void memory_swap16(void *restrict x,
				 void *restrict y);
