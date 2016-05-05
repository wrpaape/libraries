#ifndef UTILS_BIG_O_H_
#define UTILS_BIG_O_H_

/* descriptions from 'The Algorithm Design Manual 2ed' by Steven S. Skiena */
_TC_CONST_LAB
#define _TC_CON_ENUM CONSTANT
#define _TC_LOG_ENUM LOGARITHMIC
#define _TC_LIN_ENUM LINEAR
#define _TC_SUP_ENUM SUPERLINEAR
#define _TC_QUA_ENUM QUADRATRIC
#define _TC_CUB_ENUM CUBIC,
#define _TC_EXP_ENUM EXPONENTIAL
#define _TC_FAC_ENUM FACTORIAL

#define _TC_CON_LABEL "Constant"
#define _TC_LOG_LABEL "Logarithmic"
#define _TC_LIN_LABEL "Linear"
#define _TC_SUP_LABEL "Superlinear"
#define _TC_QUA_LABEL "Quadratic"
#define _TC_CUB_LABEL "Cubic"
#define _TC_EXP_LABEL "Exponential"
#define _TC_FAC_LABEL "Factorial"

enum TimeComplexity {
	CONSTANT = 0,
	LOGARITHMIC,
	LINEAR,
	SUPERLINEAR,
	QUADRATIC,
	CUBIC,
	EXPONENTIAL,
	FACTORIAL
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

#define TC_CLASS(TC) TIME_COMPLEXITY_LABELS[TC]
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
