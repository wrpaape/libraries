#include "memory_put.h"

extern inline MemoryPut *assign_memory_put(const size_t width);

/* define lookup for 'assign_memory_put' (zero-width maps to NULL) */
MemoryPut *const MEMORY_PUT_MAP[WIDTH_MAX + 1ul] = {
	NULL,
	&memory_put1,  &memory_put2,  &memory_put3,  &memory_put4,
	&memory_put5,  &memory_put6,  &memory_put7,  &memory_put8,
	&memory_put9,  &memory_put10, &memory_put11, &memory_put12,
	&memory_put13, &memory_put14, &memory_put15, &memory_put16
};


extern inline void *memory_put_width(void *const restrict x,
				     const void *const restrict y,
				     const size_t width);


/* declare all memory_put<WIDTH> functions extern */
extern inline void *memory_put1(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put2(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put3(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put4(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put5(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put6(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put7(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put8(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put9(void *const restrict x,
				const void *const restrict y);

extern inline void *memory_put10(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put11(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put12(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put13(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put14(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put15(void *const restrict x,
				 const void *const restrict y);

extern inline void *memory_put16(void *const restrict x,
				 const void *const restrict y);
