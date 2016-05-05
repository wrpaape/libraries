#ifndef UTILS_BIG_O_H_
#define UTILS_BIG_O_H_

/* descriptions from 'The Algorithm Design Manual 2ed' by Steven S. Skiena */
#define _TC_CON_ENUM1 CONSTANT
#define _TC_CON_ENUM2 TC_1
#define _TC_CON_ENUM3 TC_N_0

#define _TC_LOG_ENUM1 LOGARITHMIC
#define _TC_LOG_ENUM2 TC_LOG_N
#define _TC_LOG_ENUM3 TC_LOG

#define _TC_LIN_ENUM1 LINEAR
#define _TC_LIN_ENUM2 TC_N
#define _TC_LIN_ENUM3 TC_N_1

#define _TC_SUP_ENUM1 SUPERLINEAR
#define _TC_SUP_ENUM2 TC_N_LOG_N
#define _TC_SUP_ENUM3 TC_N_LOG

#define _TC_QUA_ENUM1 QUADRATRIC
#define _TC_QUA_ENUM2 TC_N_SQUARED
#define _TC_QUA_ENUM3 TC_N_2

#define _TC_CUB_ENUM1 CUBIC,
#define _TC_CUB_ENUM2 TC_N_CUBED
#define _TC_CUB_ENUM3 TC_N_3

#define _TC_EXP_ENUM1 EXPONENTIAL
#define _TC_EXP_ENUM2 TC_EXP_N
#define _TC_EXP_ENUM3 TC_C_N

#define _TC_FAC_ENUM1 FACTORIAL
#define _TC_FAC_ENUM2 TC_FACT_N
#define _TC_FAC_ENUM3 TC_N_!


#define _TC_CON_LABEL "Constant"
#define _TC_LOG_LABEL "Logarithmic"
#define _TC_LIN_LABEL "Linear"
#define _TC_SUP_LABEL "Superlinear"
#define _TC_QUA_LABEL "Quadratic"
#define _TC_CUB_LABEL "Cubic"
#define _TC_EXP_LABEL "Exponential"
#define _TC_FAC_LABEL "Factorial"

#define _TC_CON_EXPR "𝙏 ( 𝒏 )"
#define _TC_LOG_EXPR "𝙏 ( 𝒍𝒐𝒈(𝒏) )"
#define _TC_LIN_EXPR "𝙏 ( 𝒏 )"
#define _TC_SUP_EXPR "𝙏 ( 𝒏 𝒍𝒐𝒈(𝒏) )"
#define _TC_QUA_EXPR "𝙏 ( 𝒏² )"
#define _TC_CUB_EXPR "𝙏 ( 𝒏³ )"
#define _TC_EXP_EXPR "𝙏 ( 𝒄ⁿ )"
#define _TC_FAC_EXPR "𝙏 ( 𝒏! )"

#define _TC_CON_DESC "Such functions might measure the cost of adding "	\
                     "two numbers, printing out “The Star Spangled "	\
		     "Banner,” or the growth realized by functions "	\
		     "such as 𝒇(𝒏) = min(𝒏, 100). In the big picture, "	\
		     "there is no dependence on the parameter 𝒏."

#define _TC_LOG_DESC "Logarithmic time-complexity shows up in "		\
		     "algorithms such as binary search. Such functions"	\
		     " grow quite slowly as 𝒏 gets big, but faster "	\
		     "than the constant function (which is standing "	\
		     "still, after all)."

#define _TC_LIN_DESC "Such functions measure the cost of looking at "	\
		     "each item once (or twice, or ten times) in an "	\
		     "𝒏-element array, say to identify the biggest "	\
		     "item, the smallest item, or compute the average "	\
		     "value."
#define _TC_SUP_DESC "This important class of functions arises in such algorithms as Quicksort and Mergesort. They grow just a little faster than linear (see Figure 2.4), just enough to be a different dominance class."
#define _TC_QUA_DESC "Such functions measure the cost of looking at most or all pairs of items in an n-element universe. This arises in algorithms such as insertion sort and selection sort."
#define _TC_CUB_DESC "Such functions enumerate through all triples of items in an n-element universe. These also arise in certain dynamic program- ming algorithms developed in Chapter 8."
#define _TC_EXP_DESC "cn for a given constant c > 1 – Functions like 2n arise when enumerating all subsets of n items. As we have seen, exponential algorithms become useless fast, but not as fast as. . ."
#define _TC_FAC_DESC "Functions like n! arise when generating all permutations or orderings of n items."

#define _TC_ENUM(TOKEN, ID) _TC_ ## TOKEN ## _ENUM ## ID
#define _TC_DEF_ENUMS(TOKEN) _TC_ENUM(TOKEN, 1),	\
			     _TC_ENUM(TOKEN, 2),	\
			     _TC_ENUM(TOKEN, 3)

enum TimeComplexity {
	_TC_DEF_ENUMS(CON),
	_TC_DEF_ENUMS(LOG),
	_TC_DEF_ENUMS(LIN),
	_TC_DEF_ENUMS(SUP),
	_TC_DEF_ENUMS(QUA),
	_TC_DEF_ENUMS(CUB),
	_TC_DEF_ENUMS(EXP),
	_TC_DEF_ENUMS(FAC)
};

static const char *TIME_COMPLEXITY_LABELS[] = {
	[CONSTANT]    = "Constant",
	[LOGARITHMIC] = "Logarithmic",
	[LINEAR]      = "Linear",
	[SUPERLINEAR] = "Superlinear",
	[QUADRATIC]   = "Quadratic",
	[CUBIC]	      = "Cubic",
	[EXPONENTIAL] = "Exponential",
	[FACTORIAL]   = "Factorial"
};

static const char *TIME_COMPLEXITY_EXPRESSIONS[] = {
	[CONSTANT]    = "𝙏 ( 𝒏 )",
	[LOGARITHMIC] = "𝙏 ( 𝒍𝒐𝒈(𝒏) )",
	[LINEAR]      = "𝙏 ( 𝒏 )",
	[SUPERLINEAR] = "𝙏 ( 𝒏 𝒍𝒐𝒈(𝒏) )",
	[QUADRATIC]   = "𝙏 ( 𝒏² )",
	[CUBIC]	      = "𝙏 ( 𝒏³ )",
	[EXPONENTIAL] = "𝙏 ( 𝒄ⁿ )",
	[FACTORIAL]   = "𝙏 ( 𝒏! )"
};

static const char *TIME_COMPLEXITY_RATINGS[] = {
	[CONSTANT]    = "Such functions might measure the cost of adding two "
			"numbers, printing out “The Star Spangled Banner,” or "
			"the growth realized by functions such as 𝒇 (𝒏) = "
			"min(𝒏, 100). In the big picture, there is no "
			"dependence on the parameter 𝒏",
	[LOGARITHMIC] = "𝙏 ( 𝒍𝒐𝒈(𝒏) )",
	[LINEAR]      = "𝙏 ( 𝒏 )",
	[SUPERLINEAR] = "𝙏 ( 𝒏 𝒍𝒐𝒈(𝒏) )",
	[QUADRATIC]   = "𝙏 ( 𝒏² )",
	[CUBIC]	      = "𝙏 ( 𝒏³ )",
	[EXPONENTIAL] = "𝙏 ( 𝒄ⁿ )",
	[FACTORIAL]   = "𝙏 ( 𝒏! )"
};

inline char *time_complexity_to_string(enum TimeComplexity *tc)
{

}

#endif /* ifndef UTILS_BIG_O_H_ */
