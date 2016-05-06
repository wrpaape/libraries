#include <utils/bigo.h>

extern inline char *time_complexity_class(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_order(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_rating(const enum TimeComplexityClass tcc);

struct BenchmarkPoint {
	size_t n;
	clock_t ticks;
};

#define PUT_POINT(point, FN, N, INPUTS)
do {
	point->n = N;
	point->ticks = clock();
	FN INPUTS;
	point->ticks = clock() - point->ticks;
} while (0)

#define BENCHMARK_SETUP(RES, FN, TUP_CNT, INPUT_TUPS...)
do {
	struct BenchmarkPoint points[TUP_CNT];
	struct BenchmarkPoint *point = &points[0l];

	PUT_POINTS(point, FN, INPUT_TUPS);

	RES = approximate_time_complexity(&points[0l], TUP_CNT);
} while (0)
