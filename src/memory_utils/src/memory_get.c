#include "memory_get.h"

extern inline MemoryGet *assign_memory_get(const size_t width);

/* define lookup for 'assign_memory_get' (zero-width maps to NULL) */
MemoryGet *const MEMORY_GET_MAP[WIDTH_MAX_SIZE + 1ul] = {
	NULL,
	&memory_get1,  &memory_get2,  &memory_get3,  &memory_get4,
	&memory_get5,  &memory_get6,  &memory_get7,  &memory_get8,
	&memory_get9,  &memory_get10, &memory_get11, &memory_get12,
	&memory_get13, &memory_get14, &memory_get15, &memory_get16
};

/* access 'i'th member of 'ptr' having elements of size 'width' */
extern inline void *memory_get_width(const void *const restrict ptr,
				     const ptrdiff_t i,
				     const size_t width);

/* declare all memory_get<WIDTH> functions extern */
extern inline void *memory_get1(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get2(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get3(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get4(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get5(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get6(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get7(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get8(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get9(const void *const restrict ptr,
				const ptrdiff_t i);

extern inline void *memory_get10(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get11(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get12(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get13(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get14(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get15(const void *const restrict ptr,
				 const ptrdiff_t i);

extern inline void *memory_get16(const void *const restrict ptr,
				 const ptrdiff_t i);
