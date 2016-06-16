#include "memory_set.h"

extern inline MemorySet *assign_memory_set(const size_t width);

/* define lookup for 'assign_memory_set' (zero-width maps to NULL) */
MemorySet *const MEMORY_SET_MAP[WIDTH_MAX_SIZE + 1ul] = {
	NULL,
	&memory_set1,  &memory_set2,  &memory_set3,  &memory_set4,
	&memory_set5,  &memory_set6,  &memory_set7,  &memory_set8,
	&memory_set9,  &memory_set10, &memory_set11, &memory_set12,
	&memory_set13, &memory_set14, &memory_set15, &memory_set16
};


extern inline void memory_set_width(void *const restrict x,
				    const void *const restrict y,
				    const size_t width);

/* declare all memory_set<WIDTH> functions extern */
extern inline void memory_set1(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set2(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set3(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set4(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set5(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set6(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set7(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set8(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set9(void *const restrict x,
			       const void *const restrict y);

extern inline void memory_set10(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set11(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set12(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set13(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set14(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set15(void *const restrict x,
				const void *const restrict y);

extern inline void memory_set16(void *const restrict x,
				const void *const restrict y);
