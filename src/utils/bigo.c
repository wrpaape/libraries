#include <utils/bigo.h>

extern inline char *time_complexity_class(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_order(const enum TimeComplexityClass tcc);
extern inline char *time_complexity_rating(const enum TimeComplexityClass tcc);

#define DEFINE_TEST_PARAMS(FN, COUNT, INPUT...)

struct FnInput {
	void *input;
	clock_t ticks;
	size_t n;
};

struct FnInputPool {
	struct FnInput *inputs;
	size_t count;
};

inline struct FnInputPool *
