#include "glob_page_size_ctor.h"

#if   defined(PAGE_SIZE)
#	define GET_GLOBAL_PAGE_SIZE() PAGE_SIZE

#elif defined(__MACH__)
#	include <mach/mach.h>	/* set equal to 'vm_page_size' */
#	define GET_GLOBAL_PAGE_SIZE() vm_page_size

#else
#	include <unistd.h>	/* make system call to 'sysconf' */
#	define GET_GLOBAL_PAGE_SIZE() sysconf(_SC_PAGE_SIZE)

#endif

size_t glob_page_size; /* indicates unset */

void glob_page_size_ctor(void)
{
	glob_page_size = GET_GLOBAL_PAGE_SIZE();
}
