#include "random.h"
#include "random_imp.c"	/* implementation */

extern rng_t glob_rng; /* global random number generator state */

void glob_rng_ctor(void)
{
	pcg32_srandom_r(&glob_rng, time(NULL), (intptr_t) &glob_rng);
}

