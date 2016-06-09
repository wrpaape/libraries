#include "global_page_size.h"

#if   defined(PAGE_SIZE)
#	define GET_GLOBAL_PAGE_SIZE() PAGE_SIZE

#elif defined(__MACH__)
#	include <mach/mach.h>	/* set equal to 'vm_page_size' */
#	define GET_GLOBAL_PAGE_SIZE() vm_page_size

#else
#	include <unistd.h>	/* make system call to 'sysconf' */
#	define GET_GLOBAL_PAGE_SIZE() sysconf(_SC_PAGE_SIZE)

#endif

size_t global_page_size = 0ul; /* zero indicates unset */

void set_global_page_size(void)
{
	global_page_size = GET_GLOBAL_PAGE_SIZE();
}
