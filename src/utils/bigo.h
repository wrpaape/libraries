#ifndef UTILS_BIGO_H_
#define UTILS_BIGO_H_

#include <time.h> /* clock_t */

/* class label strings */
#define _TC_CON_LABEL "Constant"
#define _TC_LOG_LABEL "Logarithmic"
#define _TC_LIN_LABEL "Linear"
#define _TC_SUP_LABEL "Superlinear"
#define _TC_QUA_LABEL "Quadratic"
#define _TC_CUB_LABEL "Cubic"
#define _TC_EXP_LABEL "Exponential"
#define _TC_FAC_LABEL "Factorial"

/* class order strings */
#define _TC_CON_ORDER "𝒏"
#define _TC_LOG_ORDER "𝒍𝒐𝒈(𝒏)"
#define _TC_LIN_ORDER "𝒏"
#define _TC_SUP_ORDER "𝒏 𝒍𝒐𝒈(𝒏)"
#define _TC_QUA_ORDER "𝒏²"
#define _TC_CUB_ORDER "𝒏³"
#define _TC_EXP_ORDER "𝒄ⁿ"
#define _TC_FAC_ORDER "𝒏!"

/* Bachmann–Landau notation macros */
#define _TC_T_OF(ORDER)			"𝙏 ( " ORDER " )"
#define _TC_BIG_O_OF(ORDER)		"𝙏 ( " ORDER " )"
#define _TC_LITTLE_O_OF(ORDER)		"𝙏 ( " ORDER " )"
#define _TC_BIG_OMEGA_OF(ORDER)		"𝙏 ( " ORDER " )"
#define _TC_LITTLE_OMEGA_OF(ORDER)	"𝙏 ( " ORDER " )"
#define _TC_BIG_THETA_OF(ORDER)		"𝙏 ( " ORDER " )"

/* descriptions from 'The Algorithm Design Manual 2ed' by Steven S. Skiena */

/* class description strings */
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

#define _TC_SUP_DESC "This important class of functions arises in such"	\
		     " algorithms as Quicksort and Mergesort. They "	\
		     "grow just a little faster than linear, just "	\
		     "enough to be a different dominance class."

#define _TC_QUA_DESC "Such functions measure the cost of looking at "	\
		     "most or all pairs of items in an 𝒏-element "	\
		     "universe. This arises in algorithms such as "	\
		     "insertion sort and selection sort."

#define _TC_CUB_DESC "Such functions enumerate through all triples of "	\
		     "items in an 𝒏-element universe. These also arise"	\
		     " in certain dynamic programming algorithms."

#define _TC_EXP_DESC "𝒄ⁿ for a given constant 𝒄 > 1 – Functions like "	\
		     "2𝒏 arise when enumerating all subsets of 𝒏 "	\
		     "items. As we have seen, exponential algorithms "	\
		     "become useless fast"

#define _TC_FAC_DESC "Functions like 𝒏! arise when generating all "	\
		     "permutations or orderings of 𝒏 items."


/* class enum id macros (ENUM1 == ENUM2 == ENUM3) */
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

#define _TC_CUB_ENUM1 CUBIC
#define _TC_CUB_ENUM2 TC_N_CUBED
#define _TC_CUB_ENUM3 TC_N_3

#define _TC_EXP_ENUM1 EXPONENTIAL
#define _TC_EXP_ENUM2 TC_EXP_N
#define _TC_EXP_ENUM3 TC_C_N

#define _TC_FAC_ENUM1 FACTORIAL
#define _TC_FAC_ENUM2 TC_FACT_N
#define _TC_FAC_ENUM3 TC_N_FACT

/* class macro shorthand */
#define _TC_CLASS_TYPE(CLASS, TYPE) _TC_ ## CLASS ## _ ## TYPE

/* class enum shorthand */
#define _TC_ENUM(CLASS, ID) _TC_CLASS_TYPE(CLASS, ENUM ## ID)

/* define classs enums */
#define _TC_DEF_ENUMS(CLASS) _TC_ENUM(CLASS, 1),			\
			     _TC_ENUM(CLASS, 2) = _TC_ENUM(CLASS, 1),	\
			     _TC_ENUM(CLASS, 3) = _TC_ENUM(CLASS, 2)

/* define class map element */
#define _TC_DEF(CLASS, DEF) [_TC_ENUM(CLASS, 1)] = DEF

/* define class map element identified by 'CLASS' and 'TYPE' */
#define _TC_DEF_CLASS_TYPE(CLASS, TYPE) _TC_DEF(CLASS,			\
						_TC_CLASS_TYPE(CLASS,	\
							       TYPE))

/* define class label map element */
#define _TC_DEF_LABEL(CLASS) _TC_DEF_CLASS_TYPE(CLASS, LABEL)

/* define class order map element */
#define _TC_DEF_ORDER(CLASS) _TC_DEF_CLASS_TYPE(CLASS, ORDER)

/* define class rating map element */
#define _TC_DEF_RATING(CLASS) _TC_DEF(CLASS,				\
				      _TC_CLASS_TYPE(CLASS,		\
						     LABEL) "\t"	\
				      _TC_T_OF(_TC_CLASS_TYPE(CLASS,	\
							      ORDER))	\
				      "\n" _TC_CLASS_TYPE(CLASS,	\
							  DESC))

/* do for all classes */
#define _TC_FOR_ALL_CLASSES(MACRO) MACRO(CON),	\
				   MACRO(LOG),	\
				   MACRO(LIN),	\
				   MACRO(SUP),	\
				   MACRO(QUA),	\
				   MACRO(CUB),	\
				   MACRO(EXP),	\
				   MACRO(FAC)

/* stringify lookup maps */
enum TimeComplexityClass {
	_TC_FOR_ALL_CLASSES(_TC_DEF_ENUMS)
};

static const char *TIME_COMPLEXITY_CLASSES[] = {
	_TC_FOR_ALL_CLASSES(_TC_DEF_LABEL)
};

static const char *TIME_COMPLEXITY_ORDERS[] = {
	_TC_FOR_ALL_CLASSES(_TC_DEF_ORDER)
};

static const char *TIME_COMPLEXITY_RATINGS[] = {
	_TC_FOR_ALL_CLASSES(_TC_DEF_RATING)
};

typedef long long double ratio_t;

#define FACT_MAX_N ((long long double) SIZE_MAX)
static long long double FACTORIAL_MAP[] = {
	1.0l, 2.0l, 6.0l, 24.0l, 120.0l, 720.0l, 5040.0l, 40320.0l, 362880.0l,
	3628800.0l, 39916800.0l, 479001600.0l, 6227020800.0l, 87178291200.0l,
	1307674368000.0l, 20922789888000.0l, 355687428096000.0l,
	6402373705728000.0l, 121645100408832000.0l, 2432902008176640000.0l,
	51090942171709440000.0l, 1124000727777607680000.0l,
	25852016738884976640000.0l, 620448401733239439360000.0l,
	15511210043330985984000000.0l, 403291461126605635584000000.0l,
	10888869450418352160768000000.0l, 304888344611713860501504000000.0l,
	8841761993739701954543616000000.0l, 265252859812191058636308480000000
};


inline char *time_complexity_class(const enum TimeComplexityClass tcc)
{
	return TIME_COMPLEXITY_CLASSES[tcc];
}

inline char *time_complexity_order(const enum TimeComplexityClass tcc)
{
	return TIME_COMPLEXITY_ORDERS[tcc];
}

inline char *time_complexity_rating(const enum TimeComplexityClass tcc)
{
	return TIME_COMPLEXITY_RATINGS[tcc];
}


#endif /* ifndef UTILS_BIGO_H_ */
