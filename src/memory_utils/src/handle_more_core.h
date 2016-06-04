#ifndef MEMORY_UTILS_HANDLE_MORE_CORE_H_
#define MEMORY_UTILS_HANDLE_MORE_CORE_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <sys/mman.h>		/* size_t, mmap */
#include <mach/vm_statistics.h>	/* PAGE_SIZE, VM_MAKE_TAG, VM_MEMORY_MALLOC */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset); */
/* mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, VM_MAKE_TAG(VM_MEMORY_MALLOC), 0); */

#define MMAP_PROT PROT_READ | PROT_WRITE
#define MMAP_FLAGS MAP_ANON | MAP_PRIVATE
#define MMAP_FD VM_MAKE_TAG(VM_MEMORY_MALLOC)
#define MMAP_ADDR ((void *) 0)
#define MMAP_OFFSET ((off_t) 0)

#define HANDLE_MORE_CORE(BUFFER, LEN)		\
HANDLE_MMAP(BUFFER,				\
	    (void *) 0,				\
	    LEN,				\
	    PROT_READ | PROT_WRITE,		\
	    MAP_ANONYMOUS | MAP_PRIVATE,	\
	    VM_MAKE_TAG(VM_MEMORY_MALLOC),	\
	    (off_t) 0)

#define HANDLE_MMAP(BUFFER, ADDR, LEN, PROT, FLAGS, FD, OFFSET)		\
do {									\
	BUFFER = mmap(ADDR, LEN, PROT, FLAGS, FD, OFFSET);		\
	if (BUFFER == MAP_FAILED)					\
		EXIT_ON_FAILURE("failed to allocate %zu additional "	\
				"bytes of memory onto the heap"		\
				"\e24m]\n\n{\n"				\
				"\taddr:   '" #ADDR   "',\n"		\
				"\tlen:    '" #LEN    "',\n"		\
				"\tprot:   '" #PROT   "',\n"		\
				"\tflags:  '" #FLAGS  "',\n"		\
				"\tfd:     '" #FD     "',\n"		\
				"\toffset: '" #OFFSET "'\n"		\
				"}\n\n"					\
				"mmap failure: %s",			\
				LEN,					\
				MMAP_FAILURE(errno));			\
} while (0)
#define MMAP_FAILURE(ERRNO)						\
  ((ERRNO == EACCES)							\
? "(one of the following)\n"						\
  "\t- The flag 'PROT_READ' was specified as part of the 'prot' "	\
  "argument and 'fd' was not open for reading.\n"			\
  "\t- The flags 'MAP_SHARED' and 'PROT_WRITE' were specified as part "	\
  "of the flags and 'prot' argument and 'fd' was not open for writing."	\
: ((ERRNO == EBADF)							\
? "The 'fd' argument is not a valid open file descriptor."		\
: ((ERRNO == EINVAL)							\
? "(one of the following)\n"						\
  "\t- 'MAP_FIXED' was specified and the addr argument was not page "	\
  "aligned, or part of the desired address space resides out of "	\
  "the valid address space for a user process.\n"			\
  "\t- 'flags' does not include either 'MAP_PRIVATE' or 'MAP_SHARED'\n"	\
  "\t- The 'len' argument was negative or zero.\n"			\
  "\t- The 'offset' argument was not page-aligned based on the page "	\
  "size as returned by 'getpagesize(3)'."				\
: ((ERRNO == ENODEV)							\
? "'MAP_ANON' has not been specified and the file 'fd' refers to does "	\
  "not support mapping."						\
: ((ERRNO == ENOMEM)							\
? "(one of the following)\n"						\
  "\t- 'MAP_FIXED' was specified and the 'addr' argument was not "	\
  "available.\n"							\
  "\t- 'MAP_FIXED' was specified and the address range specified "	\
  "exceeds the address space limit for the process.\n"			\
  "\t- 'MAP_ANON' was specified and insufficient memory was available."	\
: ((ERRNO == ENXIO)							\
? "Addresses in the specified range are invalid for 'fd'."		\
: ((ERRNO == EOVERFLOW)							\
? "Addresses in the specified range exceed the maximum offset set for "	\
  "'fd'."								\
: "unknown")))))))

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

#endif /* ifndef MEMORY_UTILS_HANDLE_MORE_CORE_H_ */
