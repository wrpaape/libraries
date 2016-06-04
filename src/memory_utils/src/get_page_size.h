#ifndef MEMORY_UTILS_GET_PAGE_SIZE_H_
#define MEMORY_UTILS_GET_PAGE_SIZE_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

#ifdef PAGE_SIZE
#define GET_PAGE_SIZE() PAGE_SIZE

#else

#ifdef __MACH__
#include <mach/mach.h>	/* set equal to 'vm_page_size' */

#define GET_PAGE_SIZE() vm_page_size

#else

#include <unistd.h>	/* make system call to 'sysconf' */
#define GET_PAGE_SIZE() sysconf(_SC_PAGE_SIZE)

#endif /* ifdef __MACH__ */
#endif /* ifdef PAGE_SIZE */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef MEMORY_UTILS_GET_PAGE_SIZE_H_ */
