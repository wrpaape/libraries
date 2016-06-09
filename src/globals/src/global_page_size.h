#ifndef GLOBALS_GLOBAL_PAGE_SIZE_H_
#define GLOBALS_GLOBAL_PAGE_SIZE_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

#include <stddef.h>	/* size_t */

extern size_t global_page_size;

void set_global_page_size(void) __attribute__((constructor));

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef GLOBALS_GLOBAL_PAGE_SIZE_H_ */
