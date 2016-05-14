#ifndef STRING_ASCII_H_
#define STRING_ASCII_H_

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

#define ASCII_VALID_MAX 127
#define ASCII_MAX UINT8_MAX

#define PRINTABLE_MIN ' '
#define PRINTABLE_MAX '~'


static const unsigned char ASCII_BANK[] = {
	  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,
	 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
	 28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
	 42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,
	 56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
	 70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,
	 84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,
	 98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
	112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
	126, 127
};

static const unsigned char ASCII_PRINTABLE_BANK[] = {
	' ',  '!',  ''',  '#',  '$',  '%',  '&',  ''',  '(',  ')',  '*',  '+',
	',',  '-',  '.',  '/',  '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',
	'8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',  '@',  'A',  'B',  'C',
	'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
	'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '[',
	'\\', ']',  '^',  '_',  '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',
	'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',  'q',  'r',  's',
	't',  'u',  'v',  'w',  'x',  'y',  'z',  '{',  '|',  '}',  '~'
};

static const unsigned char ASCII_MISC_SYMBOL_BANK[] = {
	'#', '$', '%', '&', '*', '+', '<', '=', '>', '@', '^', '_', '`', '|',
	'~',
};

static const unsigned char ASCII_NUMBER_BANK[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

static const unsigned char ASCII_PUNCTUATION_BANK[] = {
	' ',  '!',  '"',  ''',  '(',  ')',  ',',  '-',  '.',  '/',  ':',  ';',
	'?',  '[', '\\',  ']',  '{',  '}'
};

static const unsigned char ASCII_CONTROL_BANK[] = {
	  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,
	 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
	 28,  29,  30,  31, 127
};

static const unsigned char ASCII_LETTER_BANK[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

static const unsigned char ASCII_UPPERCASE_LETTER_BANK[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

static const unsigned char ASCII_LOWERCASE_LETTER_BANK[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

static const unsigned char ASCII_CONSONANT_BANK[] = {
	'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R',
	'S', 'T', 'V', 'W', 'X', 'Z',
	'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r',
	's', 't', 'v', 'w', 'x', 'z'
};

static const unsigned char ASCII_UPPERCASE_CONSONANT_BANK[] = {
	'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R',
	'S', 'T', 'V', 'W', 'X', 'Z'
};

static const unsigned char ASCII_LOWERCASE_CONSONANT_BANK[] = {
	'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r',
	's', 't', 'v', 'w', 'x', 'z'
};

static const unsigned char ASCII_VOWEL_BANK[] = {
	'A', 'E', 'I', 'O', 'U', 'Y',
	'a', 'e', 'i', 'o', 'u', 'y'
};

static const unsigned char ASCII_UPPERCASE_VOWEL_BANK[] = {
	'A', 'E', 'I', 'O', 'U', 'Y'
};

static const unsigned char ASCII_LOWERCASE_VOWEL_BANK[] = {
	'a', 'e', 'i', 'o', 'u', 'y'
};

/* boolean membership sets */
static const bool ASCII_LETTER_SET[] = {
	[0	   ... ('A' - 1)] = false,
	['A'	   ...	     'Z'] = true,
	[('Z' + 1) ... ('a' - 1)] = false
	['a'	   ...	     'z'] = true,
	[('z' + 1) ... ASCII_MAX] = false
};

static const bool ASCII_CONSONANT_SET[] = {
	[0	   ... ('A' - 1)] = true, ['A'] = false,
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

static const bool ASCII_VOWEL_SET[] = {
	[0	   ... ('A' - 1)] = false, ['A'] = true,
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

static const unsigned char ASCII_TO_UPPERCASE_MAP[] = {
	  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,
	 14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
	 28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
	 42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,
	 56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
	 70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,
	 84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,
	 98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
	112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
	126, 127
};

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

#endif /* ifndef STRING_ASCII_H_ */

