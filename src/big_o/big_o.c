#include <big_o/big_o.h>

/* input size cutoffs for testing extreme growth rates */
#define EXP_MAX_N 40ul
#define FACT_MAX_N 19ul

/* upper limit of pthread create */
#define MAX_WORKERS 4ul

extern inline char *time_complexity_class(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_order(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_rating(const enum TimeComplexityClass tcc);


inline void set_time_ratios_upto_n_cubed(long double *ratios,
					 const long double time,
					 const size_t n)
{

	const long double n_ld     = (long double) n;
	const long double lg_n     = (long double) log_base_two(n);
	const size_t n_sq = n * n;

	ratios[0l] = time;
	ratios[1l] = time / lg_n;
	ratios[2l] = time / n_ld;
	ratios[3l] = time / (n_ld * lg_n);
	ratios[4l] = time / ((long double) n_sq);
	ratios[5l] = time / ((long double) (n_sq * n));
}

inline void set_time_ratios_upto_exp_n(long double *ratios,
				       const long double time,
				       const size_t n)
{
	set_time_ratios_upto_n_cubed(ratios, time, n);
	ratios[6l] = time / ((long double) (1ul << n));
}

inline void set_time_ratios_upto_n_fact(long double *ratios,
					const long double time,
					const size_t n)
{
	set_time_ratios_upto_exp_n(ratios, time, n);
	ratios[7l] = time / FACTORIAL_MAP[n];
}


enum TimeComplexityClass approximate_time_complexity(struct SizeStream *restrict n_range,
						     struct timeval *restrict timeout,
						     clock_t (*function_timer)(const size_t))
{
	const size_t n_min = n_range->min;
	const size_t n_max = n_range->max;

	if (n_max < n_min)
		EXIT_ON_FAILURE("maximum input 'n' ( %zu ) exceeds minimum ( %zu )",
				n_max, n_min);

	const size_t n_res = n_range->res;

	pthread_t timeout_thread;
	size_t output_depth;
	void (*set_time_ratios)(long double *,
				const long double,
				const size_t);

	if (n_max > EXP_MAX_N) {
		output_depth = 6ul;
		set_time_ratios = &set_time_ratios_upto_n_cubed;

	} else if (n_max > FACT_MAX_N) {
		output_depth = 7ul;
		set_time_ratios = &set_time_ratios_upto_exp_n;

	} else {
		output_depth = 8ul;
		set_time_ratios = &set_time_ratios_upto_exp_n;
	}


	size_t input_n[n_res];
	long double time_ratios[n_res][output_depth];


	/* generate range of input 'n' */
	(*(n_range->generator))(&input_n[0l],
				n_min,
				n_max,
				n_res);

	const size_t num_workers = MIN(n_res, MAX_WORKERS);

	pthread_t workers[num_workers];


	for (ptrdiff_t i = 0l; i < num_workers; ++i) {
		spawn_timeout_task

	}


	return LOGARITHMIC;
}
