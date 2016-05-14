#ifndef ASCII_ASCII_LOOKUP_H_
#define ASCII_ASCII_LOOKUP_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif

/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <ascii/ascii.h>	/* ascii_t, limits */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* ASCII group macros
 * ========================================================================== */
#define _ASCII_BEFORE_UPPERCASE						\
  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,	\
 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,	\
 28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,	\
 42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,	\
 56,  57,  58,  59,  60,  61,  62,  63,  64

#define _ASCII_UPPERCASE						\
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',	\
'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'

#define _ASCII_BETWEEN_CASES						\
 91,  92,  93,  94,  95,  96

#define _ASCII_LOWERCASE						\
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',	\
'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'

#define _ASCII_AFTER_LOWERCASE						\
123, 124, 125, 126, 127

#define _ASCII_INVALID							\
128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141,	\
142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155,	\
156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169,	\
170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183,	\
184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197,	\
198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211,	\
212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225,	\
226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,	\
240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253,	\
254, 255

#define _ASCII_UPPERCASE_CONSONANTS					\
'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R',	\
'S', 'T', 'V', 'W', 'X', 'Z'

#define _ASCII_LOWERCASE_CONSONANTS					\
'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r',	\
's', 't', 'v', 'w', 'x', 'z'

#define _ASCII_UPPERCASE_VOWELS						\
'A', 'E', 'I', 'O', 'U', 'Y'

#define _ASCII_LOWERCASE_VOWELS						\
'a', 'e', 'i', 'o', 'u', 'y'


/* ASCII groups (ordered by ascending ASCII value)
 * ========================================================================== */
/* valid codes */
static const ascii_t ASCII_VALID_GROUP[] = {
	_ASCII_BEFORE_UPPERCASE,
	_ASCII_UPPERCASE,
	_ASCII_BETWEEN_CASES,
	_ASCII_LOWERCASE,
	_ASCII_AFTER_LOWERCASE
};

/* printable characters */
static const ascii_t ASCII_PRINTABLE_GROUP[] = {
	' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'', '(',  ')',  '*',  '+',
	',',  '-',  '.',  '/',  '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',
	'8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',  '@',  'A',  'B',  'C',
	'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
	'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '[',
	'\\', ']',  '^',  '_',  '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',
	'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',  'q',  'r',  's',
	't',  'u',  'v',  'w',  'x',  'y',  'z',  '{',  '|',  '}',  '~'
};

/* letters */
static const ascii_t ASCII_LETTER_GROUP[] = {
	_ASCII_UPPERCASE,
	_ASCII_LOWERCASE
};

/* numbers */
static const ascii_t ASCII_NUMBER_GROUP[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

/* punctuation */
static const ascii_t ASCII_PUNCTUATION_GROUP[] = {
	' ',  '!',  '"',  '\'', '(',  ')',  ',',  '-',  '.',  '/',  ':',  ';',
	'?',  '[', '\\',  ']',  '{',  '}'
};

/* printable, non-letter, non-number, non-punctuation characters */
static const ascii_t ASCII_MISC_SYMBOL_GROUP[] = {
	'#', '$', '%', '&', '*', '+', '<', '=', '>', '@', '^', '_', '`', '|',
	'~',
};

/* non-printable codes */
static const ascii_t ASCII_CONTROL_GROUP[] = {
	  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,
	 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
	 28,  29,  30,  31, 127
};



/* uppercase letters */
static const ascii_t ASCII_UPPERCASE_LETTER_GROUP[] = {
	_ASCII_UPPERCASE
};

/* lowercase letters */
static const ascii_t ASCII_LOWERCASE_LETTER_GROUP[] = {
	_ASCII_LOWERCASE
};

/* consonants */
static const ascii_t ASCII_CONSONANT_GROUP[] = {
	_ASCII_UPPERCASE_CONSONANTS,
	_ASCII_LOWERCASE_CONSONANTS
};

/* uppercase consonants */
static const ascii_t ASCII_UPPERCASE_CONSONANT_GROUP[] = {
	_ASCII_UPPERCASE_CONSONANTS
};

/* lowercase consonants */
static const ascii_t ASCII_LOWERCASE_CONSONANT_GROUP[] = {
	_ASCII_LOWERCASE_CONSONANTS
};

/* vowels */
static const ascii_t ASCII_VOWEL_GROUP[] = {
	_ASCII_UPPERCASE_VOWELS,
	_ASCII_LOWERCASE_VOWELS
};

/* uppercase vowels */
static const ascii_t ASCII_UPPERCASE_VOWEL_GROUP[] = {
	_ASCII_UPPERCASE_VOWELS
};

/* lowercase vowels */
static const ascii_t ASCII_LOWERCASE_VOWEL_GROUP[] = {
	_ASCII_LOWERCASE_VOWELS
};


/* ASCII group sets (boolean indicates membership)
 * ========================================================================== */
/* letters */
static const bool ASCII_LETTER_SET[] = {
	[	 0 ... ('A' - 1)] = false,
	[      'A' ...	     'Z'] = true,
	[('Z' + 1) ... ('a' - 1)] = false,
	[      'a' ...	     'z'] = true,
	[('z' + 1) ... ASCII_MAX] = false
};

/* consonants */
static const bool ASCII_CONSONANT_SET[] = {
	[	 0 ... ('A' - 1)] = true, ['A'] = false,
	[('A' + 1) ... ('E' - 1)] = true, ['E'] = false,
	[('E' + 1) ... ('I' - 1)] = true, ['I'] = false,
	[('I' + 1) ... ('O' - 1)] = true, ['O'] = false,
	[('O' + 1) ... ('U' - 1)] = true, ['U'] = false,
	[('U' + 1) ... ('Y' - 1)] = true, ['Y'] = false,
	[('Y' + 1) ... ('a' - 1)] = true, ['a'] = false,
	[('a' + 1) ... ('e' - 1)] = true, ['e'] = false,
	[('e' + 1) ... ('i' - 1)] = true, ['i'] = false,
	[('i' + 1) ... ('o' - 1)] = true, ['o'] = false,
	[('o' + 1) ... ('u' - 1)] = true, ['u'] = false,
	[('u' + 1) ... ('y' - 1)] = true, ['y'] = false,
	[('y' + 1) ... ASCII_MAX] = true
};

/* vowels */
static const bool ASCII_VOWEL_SET[] = {
	[	 0 ... ('A' - 1)] = false, ['A'] = true,
	[('A' + 1) ... ('E' - 1)] = false, ['E'] = true,
	[('E' + 1) ... ('I' - 1)] = false, ['I'] = true,
	[('I' + 1) ... ('O' - 1)] = false, ['O'] = true,
	[('O' + 1) ... ('U' - 1)] = false, ['U'] = true,
	[('U' + 1) ... ('Y' - 1)] = false, ['Y'] = true,
	[('Y' + 1) ... ('a' - 1)] = false, ['a'] = true,
	[('a' + 1) ... ('e' - 1)] = false, ['e'] = true,
	[('e' + 1) ... ('i' - 1)] = false, ['i'] = true,
	[('i' + 1) ... ('o' - 1)] = false, ['o'] = true,
	[('o' + 1) ... ('u' - 1)] = false, ['u'] = true,
	[('u' + 1) ... ('y' - 1)] = false, ['y'] = true,
	[('y' + 1) ... ASCII_MAX] = false
};


/* ASCII maps ('code' maps to 'MAP[code]')
 * ========================================================================== */
#define _ASCII_CASE_MAP(LOWER_MAP, UPPER_MAP)				\
{									\
	_ASCII_BEFORE_UPPERCASE,					\
	_ASCII_ ## LOWER_MAP ## CASE,					\
	_ASCII_BETWEEN_CASES,						\
	_ASCII_ ## UPPER_MAP ## CASE,					\
	_ASCII_AFTER_LOWERCASE						\
}

static const ascii_t ASCII_LOWERCASE_MAP[]  = _ASCII_CASE_MAP(LOWER, LOWER);

static const ascii_t ASCII_UPPERCASE_MAP[]  = _ASCII_CASE_MAP(UPPER, UPPER);

static const ascii_t ASCII_TOGGLECASE_MAP[] = _ASCII_CASE_MAP(LOWER, UPPER);

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* character map case */
inline ascii_t lowercase_ascii(ascii_t ascii)
{
	return ASCII_LOWERCASE_MAP[ascii];
}

inline ascii_t uppercase_ascii(ascii_t ascii)
{
	return ASCII_UPPERCASE_MAP[ascii];
}

inline ascii_t togglecase_ascii(ascii_t ascii)
{
	return ASCII_TOGGLECASE_MAP[ascii];
}

inline void uppercase_ascii_string(ascii_t *restrict string)
{
	while (*string != '\0') {
		*string = uppercase_ascii(*string);
		++string;
	}
}

/* string map case */
inline void lowercase_ascii_string(ascii_t *restrict string)
{
	while (*string != '\0') {
		*string = lowercase_ascii(*string);
		++string;
	}
}

inline void togglecase_ascii_string(ascii_t *restrict string)
{
	while (*string != '\0') {
		*string = togglecase_ascii(*string);
		++string;
	}
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef ASCII_ASCII_LOOKUP_H_ */
