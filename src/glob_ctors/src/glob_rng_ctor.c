#include "glob_rng_ctor.h"

#include <time.h>

pcg32_random_t glob_rng; /* global random number generator state */

void glob_rng_ctor(void)
{
	pcg32_srandom_r(&glob_rng, time(NULL), (intptr_t) &glob_rng);
}

