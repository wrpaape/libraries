#include "ascii.h" /* ascii_t, lookup tables */

#define INIT_ASCII_GROUP(GRP)					\
const ascii_t ASCII_ ## GRP ## _GROUP[_ASCII_ ## GRP ## _COUNT] =	\
_ASCII_ ## GRP ## _GROUP()

/* ASCII groups (ordered by ascending ASCII value)
 * ========================================================================== */
/* valid codes */
/* INIT_ASCII_GROUP(VALID); */
/* const ascii_t ASCII_VALID_GROUP[] = _ASCII_VALID_GROUP(); */

/* printable codes */
/* INIT_ASCII_GROUP(PRINTABLE); */
/* const ascii_t ASCII_PRINTABLE_GROUP[] = _ASCII_PRINTABLE_GROUP(); */

/* numbers */
/* INIT_ASCII_GROUP(NUMBER); */
/* const ascii_t ASCII_NUMBER_GROUP[] = _ASCII_NUMBER_GROUP(); */

/* letters */
/* INIT_ASCII_GROUP(LETTER); */
/* const ascii_t ASCII_LETTER_GROUP[] = _ASCII_LETTER_GROUP(); */

/* consonants */
/* INIT_ASCII_GROUP(CONSONANT); */
/* const ascii_t ASCII_CONSONANT_GROUP[] = _ASCII_CONSONANT_GROUP(); */

/* vowels */
/* INIT_ASCII_GROUP(VOWEL); */
/* const ascii_t ASCII_VOWEL_GROUP[] = _ASCII_VOWEL_GROUP(); */

/* uppercase letters */
/* INIT_ASCII_GROUP(UPPERCASE_LETTER); */
/* const ascii_t ASCII_UPPERCASE_LETTER_GROUP[] = _ASCII_UPPERCASE_LETTER_GROUP(); */

/* lowercase letters */
/* INIT_ASCII_GROUP(LOWERCASE_LETTER); */
/* const ascii_t ASCII_LOWERCASE_LETTER_GROUP[] = _ASCII_LOWERCASE_LETTER_GROUP(); */

/* uppercase consonants */
/* INIT_ASCII_GROUP(UPPERCASE_CONSONANT); */
/* const ascii_t */
/* ASCII_UPPERCASE_CONSONANT_GROUP[] = _ASCII_UPPERCASE_CONSONANT_GROUP(); */

/* lowercase consonants */
/* INIT_ASCII_GROUP(LOWERCASE_CONSONANT); */
/* const ascii_t */
/* ASCII_LOWERCASE_CONSONANT_GROUP[] = _ASCII_LOWERCASE_CONSONANT_GROUP(); */

/* uppercase vowels */
/* INIT_ASCII_GROUP(UPPERCASE_VOWEL); */
/* const ascii_t ASCII_UPPERCASE_VOWEL_GROUP[] = _ASCII_UPPERCASE_VOWEL_GROUP(); */

/* lowercase vowels */
/* INIT_ASCII_GROUP(LOWERCASE_VOWEL); */
/* const ascii_t ASCII_LOWERCASE_VOWEL_GROUP[] = _ASCII_LOWERCASE_VOWEL_GROUP(); */

/* punctuation */
/* INIT_ASCII_GROUP(PUNCTUATION); */
/* const ascii_t ASCII_PUNCTUATION_GROUP[] = _ASCII_PUNCTUATION_GROUP(); */

/* printable, non-letter, non-number, non-punctuation characters */
/* INIT_ASCII_GROUP(MISC_SYMBOL); */
/* const ascii_t ASCII_MISC_SYMBOL_GROUP[] = _ASCII_MISC_SYMBOL_GROUP(); */

/* non-printable codes */
/* INIT_ASCII_GROUP(CONTROL); */
/* const ascii_t ASCII_CONTROL_GROUP[] = _ASCII_CONTROL_GROUP(); */

const ascii_t ASCII_VALID_GROUP[_ASCII_VALID_COUNT]=				= _ASCII_VALID_GROUP();
const ascii_t ASCII_PRINTABLE_GROUP[_ASCII_PRINTABLE_COUNT]			= _ASCII_PRINTABLE_GROUP();
const ascii_t ASCII_NUMBER_GROUP[_ASCII_NUMBER_COUNT]				= _ASCII_NUMBER_GROUP();
const ascii_t ASCII_LETTER_GROUP[_ASCII_LETTER_COUNT]				= _ASCII_LETTER_GROUP();
const ascii_t ASCII_CONSONANT_GROUP[_ASCII_CONSONANT_COUNT]			= _ASCII_CONSONANT_GROUP();
const ascii_t ASCII_VOWEL_GROUP[_ASCII_VOWEL_COUNT]				= _ASCII_VOWEL_GROUP();
const ascii_t ASCII_UPPERCASE_LETTER_GROUP[_ASCII_UPPERCASE_LETTER_COUNT]	= _ASCII_UPPERCASE_LETTER_GROUP();
const ascii_t ASCII_LOWERCASE_LETTER_GROUP[_ASCII_LOWERCASE_LETTER_COUNT]	= _ASCII_LOWERCASE_LETTER_GROUP();
const ascii_t ASCII_UPPERCASE_CONSONANT_GROUP[_ASCII_UPPERCASE_CONSONANT_COUNT] = _ASCII_UPPERCASE_CONSONANT_GROUP();
const ascii_t ASCII_LOWERCASE_CONSONANT_GROUP[_ASCII_LOWERCASE_CONSONANT_COUNT] = _ASCII_LOWERCASE_CONSONANT_GROUP();
const ascii_t ASCII_UPPERCASE_VOWEL_GROUP[_ASCII_UPPERCASE_VOWEL_COUNT]		= _ASCII_UPPERCASE_VOWEL_GROUP();
const ascii_t ASCII_LOWERCASE_VOWEL_GROUP[_ASCII_LOWERCASE_VOWEL_COUNT]		= _ASCII_LOWERCASE_VOWEL_GROUP();
const ascii_t ASCII_PUNCTUATION_GROUP[_ASCII_PUNCTUATION_COUNT]			= _ASCII_PUNCTUATION_GROUP();
const ascii_t ASCII_MISC_SYMBOL_GROUP[_ASCII_MISC_SYMBOL_COUNT]			= _ASCII_MISC_SYMBOL_GROUP();
const ascii_t ASCII_CONTROL_GROUP[_ASCII_CONTROL_COUNT]				= _ASCII_CONTROL_GROUP();

/* ASCII sets (boolean indicates membership)
 * ========================================================================== */
/* letters */
const bool ASCII_LETTER_SET[ASCII_COUNT] = _ASCII_LETTER_SET();

/* consonants */
const bool ASCII_CONSONANT_SET[ASCII_COUNT] = _ASCII_CONSONANT_SET();

/* vowels */
const bool ASCII_VOWEL_SET[ASCII_COUNT] = _ASCII_VOWEL_SET();


/* ASCII maps ('code' maps to 'MAP[code]')
 * ========================================================================== */
const ascii_t ASCII_LOWERCASE_MAP[ASCII_COUNT]  = _ASCII_LOWERCASE_MAP();

const ascii_t ASCII_UPPERCASE_MAP[ASCII_COUNT]  = _ASCII_UPPERCASE_MAP();

const ascii_t ASCII_TOGGLECASE_MAP[ASCII_COUNT] = _ASCII_TOGGLECASE_MAP();



/* printable characters */
/* const ascii_t ASCII_PRINTABLE_GROUP[] = { */
	/* ' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'', '(',  ')',  '*',  '+', */
	/* ',',  '-',  '.',  '/',  '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7', */
	/* '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',  '@',  'A',  'B',  'C', */
	/* 'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O', */
	/* 'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '[', */
	/* '\\', ']',  '^',  '_',  '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g', */
	/* 'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',  'q',  'r',  's', */
	/* 't',  'u',  'v',  'w',  'x',  'y',  'z',  '{',  '|',  '}',  '~' */
/* }; */

/* character map case */
extern inline ascii_t lowercase_ascii(ascii_t ascii);
extern inline ascii_t uppercase_ascii(ascii_t ascii);
extern inline ascii_t togglecase_ascii(ascii_t ascii);

/* string map case */
extern inline void uppercase_ascii_string(ascii_t *restrict string);
extern inline void lowercase_ascii_string(ascii_t *restrict string);
extern inline void togglecase_ascii_string(ascii_t *restrict string);
