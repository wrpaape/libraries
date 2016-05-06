#include <utils/utils.h>
#include <utils/bigo.h>

extern inline char *time_complexity_class(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_order(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_rating(const enum TimeComplexityClass tcc);

struct SizeStream {
	size_t min;
	size_t max;
	size_t res;
	void (*generator)(const size_t *,
			  const size_t,
			  const size_t,
			  const size_t)
};

long double time_over_1(const clock_t time, const size_t n);
long double time_over_log_n(const clock_t time, const size_t n);
long double time_over_n(const clock_t time, const size_t n);
long double time_over_n_log_n(const clock_t time, const size_t n);
long double time_over_n_squared(const clock_t time, const size_t n);
long double time_over_n_cubed(const clock_t time, const size_t n);
long double time_over_exp_n(const clock_t time, const size_t n);
long double time_over_n_factorial(const clock_t time, const size_t n);

long double (*RATIO_MAP[])

enum TimeComplexityClass approximate_time_complexity(struct SizeStream *restrict n_range,
						     struct timeval *restrict timeout,
						     clock_t (*function_timer)(const size_t))
{

	if (n_range->max < n_range->min)
		EXIT_ON_FAILURE("maximum input 'n' ( %zu ) exceeds minimum ( %zu )",
				n_range->max, n_range->min);



	clock_t ticks[n_range->res];
	size_t input_n[n_range->res];
	long double n_ratios[];


	return tc_clas;
}
