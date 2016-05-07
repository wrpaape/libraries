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

inline void set_time_ratios_upto_n_cubed(long double *ratios,
					 const long double time,
					 const size_t n)
{

	const long double n_ld     = (long double) n;
	const long double lg_n     = log2l(n_ld);
	const size_t n_sq = n * n;

	ratios[0l] = time;
	ratios[1l] = time / lg_n;
	ratios[2l] = time / n_ld;
	ratios[3l] = time / ((long double) n_sq);
	ratios[4l] = time / ((long double) (n_sq * n));
}

inline void set_time_ratios_upto_exp_n(long double *ratios,
				       const long double time,
				       const size_t n)
{
	set_time_ratios_upto_n_cubed(ratios, time, n);
	ratios[5l] = time / ((long double) (1ul << n));
}

inline void set_time_ratios_upto_n_fact(long double *ratios,
					const long double time,
					const size_t n)
{
	set_time_ratios_upto_exp_n(ratios, time, n);
	ratios[6l] = time / FACTORIAL_MAP[n];
}


enum TimeComplexityClass approximate_time_complexity(struct SizeStream *restrict n_range,
						     struct timeval *restrict timeout,
						     clock_t (*function_timer)(const size_t))
{

	if (n_range->max < n_range->min)
		EXIT_ON_FAILURE("maximum input 'n' ( %zu ) exceeds minimum ( %zu )",
				n_range->max, n_range->min);

	size_t output_depth;
	void (*set_time_ratios)(long double *,
				const long double,
				const size_t);

	if (n_range->max > EXP_MAX_N) {
		output_depth = 5ul;
		set_time_ratios = &set_time_ratios_upto_n_cubed;

	} else if (n_range->max > FACT_MAX_N) {
		output_depth = 6ul;
		set_time_ratios = &set_time_ratios_upto_exp_n;

	} else {
		output_depth = 7ul;
		set_time_ratios = &set_time_ratios_upto_exp_n;
	}


	size_t input_n[n_range->res];
	long double time_ratios[output_depth][n_range->res];


	return tc_clas;
}
