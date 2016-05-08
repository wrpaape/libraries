#include <utils/time.h>

extern inline void get_real_time(struct timespec *restrict time);

extern inline void set_time_limit(struct timespec *restrict time_limit,
				  const struct timespec *restrict timeout);

