#ifndef GLOBALS_GLOBAL_PAGE_SIZE_H_
#define GLOBALS_GLOBAL_PAGE_SIZE_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


#if   defined(PAGE_SIZE)
#	define GET_GLOBAL_PAGE_SIZE() PAGE_SIZE

#elif defined(__MACH__)
#	include <mach/mach.h>	/* set equal to 'vm_page_size' */
#	define GET_GLOBAL_PAGE_SIZE() vm_page_size

#else
#	include <unistd.h>	/* make system call to 'sysconf' */
#	define GET_GLOBAL_PAGE_SIZE() sysconf(_SC_PAGE_SIZE)

#endif

extern size_t global_page_size;

inline void set_global_page_size(void)
{
	global_page_size = GET_GLOBAL_PAGE_SIZE();
}

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef GLOBALS_GLOBAL_PAGE_SIZE_H_ */
