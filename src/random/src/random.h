#ifndef RANDOM_RANDOM_H_
#define RANDOM_RANDOM_H_

#include "random_imp.h"	/* implementation */

void glob_rng_ctor(void) __attribute__((constructor));

#endif /* ifndef RANDOM_RANDOM_H_ */
