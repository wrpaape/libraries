#ifndef GLOB_CTORS_GLOB_RNG_CTOR_H_
#define GLOB_CTORS_GLOB_RNG_CTOR_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

#include <random/pcg_basic.h>	/* pcg32_random_t */

extern pcg32_random_t glob_rng;

void glob_rng_ctor(void) __attribute__((constructor));

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef GLOB_CTORS_GLOB_RNG_CTOR_H_ */
