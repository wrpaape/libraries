#ifndef STRING_UTILS_ASCII_H_
#define STRING_UTILS_ASCII_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <stdint.h>	/* uint8_t */
#include <limits.h>	/* UINT8_MAX */
#include <stdbool.h>	/* bool */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

typedef uint8_t ascii_t;

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* ASCII limits, bounds
 * ========================================================================== */
#define ASCII_VALID_MAX 127
#define ASCII_MAX UINT8_MAX
#define ASCII_COUNT 128

#define ASCII_PRINTABLE_MIN ' '
#define ASCII_PRINTABLE_MAX '~'

/* ASCII group macros
 * ========================================================================== */
#define _ASCII_CONTROL_BLOCK						\
  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,	\
 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,	\
 28,  29,  30,  31

#define _ASCII_SYMBOL_BLOCK_A						\
' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'', '(',  ')',  '*',  '+',	\
',',  '-',  '.',  '/'

#define _ASCII_NUMBER_BLOCK						\
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'

#define _ASCII_SYMBOL_BLOCK_B						\
':',  ';',  '<',  '=',  '>',  '?',  '@'

#define _ASCII_UPPERCASE_BLOCK						\
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',	\
'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'

#define _ASCII_SYMBOL_BLOCK_C						\
'[', '\\', ']',  '^',  '_',  '`'

#define _ASCII_LOWERCASE_BLOCK						\
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',	\
'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'

#define _ASCII_SYMBOL_BLOCK_D						\
'{',  '|',  '}',  '~'

#define _ASCII_DELETE 127

#define _ASCII_INVALID_BLOCK						\
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


/* ASCII set macros
 * ========================================================================== */
#define _ASCII_X_RANGE_CC(I, J, X) [(I) ... (J)] = (X)
#define _ASCII_X_RANGE_OC(I, J, X) _ASCII_X_RANGE_CC((I) + 1, J,       X)
#define _ASCII_X_RANGE_CO(I, J, X) _ASCII_X_RANGE_CC(I,       (J) - 1, X)
#define _ASCII_X_RANGE_OO(I, J, X) _ASCII_X_RANGE_CC((I) + 1, (J) - 1, X)
#define _ASCII_T_RANGE_CC(I, J) _ASCII_X_RANGE_CC(I, J, true)
#define _ASCII_T_RANGE_OO(I, J) _ASCII_X_RANGE_OO(I, J, true)
#define _ASCII_F_RANGE_CC(I, J) _ASCII_X_RANGE_CC(I, J, false)
#define _ASCII_F_RANGE_OC(I, J) _ASCII_X_RANGE_OC(I, J, false)
#define _ASCII_F_RANGE_CO(I, J) _ASCII_X_RANGE_CO(I, J, false)
#define _ASCII_F_RANGE_OO(I, J) _ASCII_X_RANGE_OO(I, J, false)

#define _ASCII_RANGE_T_VOWEL(I, J) [I] = true, _ASCII_F_RANGE_OO(I, J)
#define _ASCII_RANGE_F_VOWEL(I, J) _ASCII_T_RANGE_OO(I, J), [J] = false

#define _ASCII_LETTER_SWEEP(B, A, E, I, O, U, Y)			\
	_ASCII_RANGE_ ## B ## _VOWEL(A, E),				\
	_ASCII_RANGE_ ## B ## _VOWEL(E, I),				\
	_ASCII_RANGE_ ## B ## _VOWEL(I, O),				\
	_ASCII_RANGE_ ## B ## _VOWEL(O, U),				\
	_ASCII_RANGE_ ## B ## _VOWEL(U, Y)

#define _ASCII_CONSONANT_SWEEP(A, E, I, O, U, Y, Z)			\
	_ASCII_LETTER_SWEEP(F, A, E, I, O, U, Y), [Z] = true

#define _ASCII_VOWEL_SWEEP(A, E, I, O, U, Y)				\
	_ASCII_LETTER_SWEEP(T, A, E, I, O, U, Y), [Y] = true


/* ASCII map macros
 * ========================================================================== */
#define _ASCII_PRINTABLE_CASE_BLOCK(UPPER_MAP, LOWER_MAP)		\
_ASCII_SYMBOL_BLOCK_A,							\
_ASCII_NUMBER_BLOCK,							\
_ASCII_SYMBOL_BLOCK_B,							\
_ASCII_ ## UPPER_MAP ## CASE_BLOCK,					\
_ASCII_SYMBOL_BLOCK_C,							\
_ASCII_ ## LOWER_MAP ## CASE_BLOCK,					\
_ASCII_SYMBOL_BLOCK_D

#define _ASCII_CASE_BLOCK(UPPER_MAP, LOWER_MAP)				\
_ASCII_CONTROL_BLOCK,							\
_ASCII_PRINTABLE_CASE_BLOCK(UPPER_MAP, LOWER_MAP),			\
_ASCII_DELETE

#define _ASCII_CASE_MAP(UPPER_MAP, LOWER_MAP)				\
{									\
	_ASCII_CASE_BLOCK(UPPER_MAP, LOWER_MAP),			\
	_ASCII_INVALID_BLOCK						\
}


/* ASCII lookup table initializers
 * ========================================================================== */
#define _ASCII_VALID_COUNT (ASCII_VALID_MAX + 1ul)
#define _ASCII_VALID_GROUP() { _ASCII_CASE_BLOCK(UPPER, LOWER) }

#define _ASCII_PRINTABLE_COUNT (ASCII_PRINTABLE_MAX + 1ul - ASCII_PRINTABLE_MIN)
#define _ASCII_PRINTABLE_COUNT 96ul
#define _ASCII_PRINTABLE_GROUP() { _ASCII_PRINTABLE_CASE_BLOCK(UPPER, LOWER) }

#define _ASCII_NUMBER_COUNT 10ul
#define _ASCII_NUMBER_GROUP() { _ASCII_NUMBER_BLOCK }

#define _ASCII_LETTER_COUNT (_ASCII_LOWERCASE_LETTER_COUNT * 2ul)
#define _ASCII_LETTER_GROUP() { _ASCII_UPPERCASE_BLOCK, _ASCII_LOWERCASE_BLOCK }

#define _ASCII_CONSONANT_COUNT (_ASCII_LOWERCASE_CONSONANT_COUNT * 2ul)
#define _ASCII_CONSONANT_GROUP()					\
{									\
	_ASCII_UPPERCASE_CONSONANTS,					\
	_ASCII_LOWERCASE_CONSONANTS					\
}
#define _ASCII_VOWEL_COUNT (_ASCII_LOWERCASE_VOWEL_COUNT * 2ul)
#define _ASCII_VOWEL_GROUP()						\
{									\
	_ASCII_UPPERCASE_VOWELS,					\
	_ASCII_LOWERCASE_VOWELS						\
}

#define _ASCII_UPPERCASE_LETTER_COUNT _ASCII_LOWERCASE_LETTER_COUNT
#define _ASCII_UPPERCASE_LETTER_GROUP() { _ASCII_UPPERCASE_BLOCK }

#define _ASCII_LOWERCASE_LETTER_COUNT (_ASCII_LOWERCASE_CONSONANT_COUNT \
				       + _ASCII_LOWERCASE_VOWEL_COUNT)
#define _ASCII_LOWERCASE_LETTER_GROUP() { _ASCII_LOWERCASE_BLOCK }

#define _ASCII_UPPERCASE_CONSONANT_COUNT _ASCII_LOWERCASE_CONSONANT_COUNT
#define _ASCII_UPPERCASE_CONSONANT_GROUP() { _ASCII_UPPERCASE_CONSONANTS }

#define _ASCII_LOWERCASE_CONSONANT_COUNT 20ul
#define _ASCII_LOWERCASE_CONSONANT_GROUP() { _ASCII_LOWERCASE_CONSONANTS }

#define _ASCII_UPPERCASE_VOWEL_COUNT _ASCII_LOWERCASE_VOWEL_COUNT
#define _ASCII_UPPERCASE_VOWEL_GROUP() { _ASCII_UPPERCASE_VOWELS }

#define _ASCII_LOWERCASE_VOWEL_COUNT 6ul
#define _ASCII_LOWERCASE_VOWEL_GROUP() { _ASCII_LOWERCASE_VOWELS }

#define _ASCII_PUNCTUATION_COUNT 18ul
#define _ASCII_PUNCTUATION_GROUP()					\
{									\
	' ',  '!', '"',  '\'', '(',  ')',  ',',  '-',  '.',  '/',	\
	':',  ';', '?',  '[', '\\',  ']',  '{',  '}'			\
}

#define _ASCII_MISC_SYMBOL_COUNT 15ul
#define _ASCII_MISC_SYMBOL_GROUP()					\
{									\
	'#', '$', '%', '&', '*', '+', '<', '=', '>', '@', '^', '_',	\
	'`', '|', '~'							\
}
#define _ASCII_CONTROL_COUNT 33ul
#define _ASCII_CONTROL_GROUP() { _ASCII_CONTROL_BLOCK, _ASCII_DELETE }

#define _ASCII_LOWERCASE_MAP() _ASCII_CASE_MAP(LOWER, LOWER)
#define _ASCII_UPPERCASE_MAP() _ASCII_CASE_MAP(UPPER, UPPER)
#define _ASCII_TOGGLECASE_MAP() _ASCII_CASE_MAP(LOWER, UPPER)
#define _ASCII_LETTER_SET()						\
{									\
	_ASCII_F_RANGE_CO(0,   'A'),					\
	_ASCII_T_RANGE_CC('A', 'Z'),					\
	_ASCII_F_RANGE_OO('Z', 'a'),					\
	_ASCII_T_RANGE_CC('a', 'z'),					\
	_ASCII_F_RANGE_OC('z', ASCII_MAX)				\
}
#define _ASCII_CONSONANT_SET()						\
{									\
	_ASCII_F_RANGE_CC(0,   'A'),					\
	_ASCII_CONSONANT_SWEEP('A', 'E', 'I', 'O', 'U', 'Y', 'Z'),	\
	_ASCII_F_RANGE_OC('Z', 'a'),					\
	_ASCII_CONSONANT_SWEEP('a', 'e', 'i', 'o', 'u', 'y', 'z'),	\
	_ASCII_F_RANGE_OC('z', ASCII_MAX)				\
}
#define _ASCII_VOWEL_SET()						\
{									\
	_ASCII_F_RANGE_CO(0, 'A'),					\
	_ASCII_VOWEL_SWEEP('A', 'E', 'I', 'O', 'U', 'Y'),		\
	_ASCII_F_RANGE_CO('Z', 'a'),					\
	_ASCII_VOWEL_SWEEP('a', 'e', 'i', 'o', 'u', 'y'),		\
	_ASCII_F_RANGE_CC('z', ASCII_MAX)				\
}


/* ASCII lookup tables
 * ========================================================================== */
/* ordered groups */
extern const ascii_t ASCII_VALID_GROUP[_ASCII_VALID_COUNT];
extern const ascii_t ASCII_PRINTABLE_GROUP[_ASCII_PRINTABLE_COUNT];
extern const ascii_t ASCII_NUMBER_GROUP[_ASCII_NUMBER_COUNT];
extern const ascii_t ASCII_LETTER_GROUP[_ASCII_LETTER_COUNT];
extern const ascii_t ASCII_CONSONANT_GROUP[_ASCII_CONSONANT_COUNT];
extern const ascii_t ASCII_VOWEL_GROUP[_ASCII_VOWEL_COUNT];
extern const ascii_t ASCII_UPPERCASE_LETTER_GROUP[_ASCII_UPPERCASE_LETTER_COUNT];
extern const ascii_t ASCII_LOWERCASE_LETTER_GROUP[_ASCII_LOWERCASE_LETTER_COUNT];
extern const ascii_t ASCII_UPPERCASE_CONSONANT_GROUP[_ASCII_UPPERCASE_CONSONANT_COUNT];
extern const ascii_t ASCII_LOWERCASE_CONSONANT_GROUP[_ASCII_LOWERCASE_CONSONANT_COUNT];
extern const ascii_t ASCII_UPPERCASE_VOWEL_GROUP[_ASCII_UPPERCASE_VOWEL_COUNT];
extern const ascii_t ASCII_LOWERCASE_VOWEL_GROUP[_ASCII_LOWERCASE_VOWEL_COUNT];
extern const ascii_t ASCII_PUNCTUATION_GROUP[_ASCII_PUNCTUATION_COUNT];
extern const ascii_t ASCII_MISC_SYMBOL_GROUP[_ASCII_MISC_SYMBOL_COUNT];
extern const ascii_t ASCII_CONTROL_GROUP[_ASCII_CONTROL_COUNT];

/* sets */
extern const bool ASCII_LETTER_SET[ASCII_COUNT];
extern const bool ASCII_CONSONANT_SET[ASCII_COUNT];
extern const bool ASCII_VOWEL_SET[ASCII_COUNT];

/* maps */
extern const ascii_t ASCII_LOWERCASE_MAP[ASCII_COUNT];
extern const ascii_t ASCII_UPPERCASE_MAP[ASCII_COUNT];
extern const ascii_t ASCII_TOGGLECASE_MAP[ASCII_COUNT];

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

/* undefine group macros */

/* undefine set macros */
/* #undef _ASCII_X_RANGE_CC */
/* #undef _ASCII_X_RANGE_OC */
/* #undef _ASCII_X_RANGE_CO */
/* #undef _ASCII_X_RANGE_OO */
/* #undef _ASCII_T_RANGE_CC */
/* #undef _ASCII_T_RANGE_OO */
/* #undef _ASCII_F_RANGE_CC */
/* #undef _ASCII_F_RANGE_OC */
/* #undef _ASCII_F_RANGE_CO */
/* #undef _ASCII_F_RANGE_OO */
/* #undef _ASCII_RANGE_T_VOWEL */
/* #undef _ASCII_RANGE_F_VOWEL */
/* #undef _ASCII_LETTER_SWEEP */
/* #undef _ASCII_CONSONANT_SWEEP */
/* #undef _ASCII_VOWEL_SWEEP */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef STRING_UTILS_ASCII_H_ */
