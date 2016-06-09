#ifndef GLOB_CTORS_GLOB_PAGE_SIZE_CTOR_H_
#define GLOB_CTORS_GLOB_PAGE_SIZE_CTOR_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

#include <stddef.h>	/* size_t */

extern size_t glob_page_size;

void glob_page_size_ctor(void) __attribute__((constructor));

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef GLOB_CTORS_GLOB_PAGE_SIZE_CTOR_H_ */
