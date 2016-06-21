#include "memory_string_put.h"

/* define lookup for 'assign_memory_string_put' */
MemoryStringPut *const MEMORY_STRING_PUT_REM_MAP[WIDTH_MAX_SIZE + 1ul] = {
	&memory_string_put_rem0,
	&memory_string_put_rem1,  &memory_string_put_rem2,
	&memory_string_put_rem3,  &memory_string_put_rem4,
	&memory_string_put_rem5,  &memory_string_put_rem6,
	&memory_string_put_rem7,  &memory_string_put_rem8,
	&memory_string_put_rem9,  &memory_string_put_rem10,
	&memory_string_put_rem11, &memory_string_put_rem12,
	&memory_string_put_rem13, &memory_string_put_rem14,
	&memory_string_put_rem15, &memory_string_put_rem16
};

MemoryStringPut *const MEMORY_STRING_PUT_REM_WORDS_MAP[WIDTH_MAX_SIZE + 1ul] = {
	&memory_string_put_rem_words0,
	&memory_string_put_rem_words1,  &memory_string_put_rem_words2,
	&memory_string_put_rem_words3,  &memory_string_put_rem_words4,
	&memory_string_put_rem_words5,  &memory_string_put_rem_words6,
	&memory_string_put_rem_words7,  &memory_string_put_rem_words8,
	&memory_string_put_rem_words9,  &memory_string_put_rem_words10,
	&memory_string_put_rem_words11, &memory_string_put_rem_words12,
	&memory_string_put_rem_words13, &memory_string_put_rem_words14,
	&memory_string_put_rem_words15, &memory_string_put_rem_words16
};


/* declare all memory_string_put_rem[_words]<WIDTH> functions extern */
extern inline void *
memory_string_put_rem0(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem1(void *restrict buffer,
		       const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem2(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem3(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem4(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem5(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem6(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem7(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem8(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem9(void *restrict buffer,
		       const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem10(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem11(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem12(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem13(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem14(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem15(void *restrict buffer,
			const struct MemoryString *const restrict string);
extern inline void *
memory_string_put_rem16(void *restrict buffer,
			const struct MemoryString *const restrict string);

/* put words with no remainder */
extern inline void *
memory_string_put_rem_words0(void *restrict buffer,
			     const struct MemoryString *const restrict string);

/* put words with remainder <WIDTH> > 0 */
extern inline void *
memory_string_put_rem_words1(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words2(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words3(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words4(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words5(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words6(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words7(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words8(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words9(void *const restrict buffer,
			     const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words10(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words11(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words12(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words13(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words14(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words15(void *const restrict buffer,
			      const struct MemoryString *const restrict string);

extern inline void *
memory_string_put_rem_words16(void *const restrict buffer,
