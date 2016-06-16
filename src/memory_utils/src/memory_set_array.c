#include "memory_set_array.h"

extern inline MemorySetArray *assign_memory_set_array(const size_t width);

/* define lookup for 'assign_memory_set_array' (zero-width maps to NULL) */
MemorySetArray *const MEMORY_SET_ARRAY_MAP[WIDTH_MAX_SIZE + 1ul] = {
	NULL,
	&memory_set_array1,  &memory_set_array2,  &memory_set_array3,
	&memory_set_array4,  &memory_set_array5,  &memory_set_array6,
	&memory_set_array7,  &memory_set_array8,  &memory_set_array9,
	&memory_set_array10, &memory_set_array11, &memory_set_array12,
	&memory_set_array13, &memory_set_array14, &memory_set_array15,
	&memory_set_array16
};


extern inline void memory_set_array_width(void *restrict x,
					  const void *restrict y,
					  const size_t length,
					  const size_t width);


/* declare all memory_set_array<WIDTH> functions extern */
extern inline void memory_set_array1(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array2(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array3(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array4(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array5(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array6(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array7(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array8(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array9(void *restrict x,
				     const void *restrict y,
				     const size_t length);

extern inline void memory_set_array10(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array11(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array12(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array13(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array14(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array15(void *restrict x,
				      const void *restrict y,
				      const size_t length);

extern inline void memory_set_array16(void *restrict x,
				      const void *restrict y,
				      const size_t length);
