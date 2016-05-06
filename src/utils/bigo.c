#include <utils/bigo.h>

extern inline char *time_complexity_class(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_order(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_rating(const enum TimeComplexityClass tcc);



enum TimeComplexityClass approximate_time_complexity(const size_t n_min,
						     const size_t n_max,
						     const size_t n_res,
						     struct timeval *restrict timeout,
						     void (*range_generator)(const size_t *,
									     const size_t,
									     const size_t,
									     const size_t),
						     clock_t (*function_timer)(const size_t))
{

	clock_t n_ticks[n_res];
	size_t n_range[n_res];
	long long double n_ratios


	return tc_clas;
}
