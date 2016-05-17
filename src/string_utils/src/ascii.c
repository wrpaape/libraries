#include "ascii.h" /* ascii_t, lookup tables */

#define INIT_ASCIIS(GRP)					\
const ascii_t ASCII_ ## GRP ## S[_ASCII_ ## GRP ## _CNT] =	\
_ASCII_ ## GRP ## S()

/* ASCII groups (ordered by ascending ASCII value)
 * ========================================================================== */
/* valid codes */
/* INIT_ASCIIS(VALID); */
/* const ascii_t ASCII_VALIDS[] = _ASCII_VALIDS(); */

/* printable codes */
/* INIT_ASCIIS(PRINTABLE); */
/* const ascii_t ASCII_PRINTABLES[] = _ASCII_PRINTABLES(); */

/* numbers */
/* INIT_ASCIIS(NUMBER); */
/* const ascii_t ASCII_NUMBERS[] = _ASCII_NUMBERS(); */

/* letters */
/* INIT_ASCIIS(LETTER); */
/* const ascii_t ASCII_LETTERS[] = _ASCII_LETTERS(); */

/* consonants */
/* INIT_ASCIIS(CONSONANT); */
/* const ascii_t ASCII_CONSONANTS[] = _ASCII_CONSONANTS(); */

/* vowels */
/* INIT_ASCIIS(VOWEL); */
/* const ascii_t ASCII_VOWELS[] = _ASCII_VOWELS(); */

/* uppercase letters */
/* INIT_ASCIIS(UPPER_LETTER); */
/* const ascii_t ASCII_UPPER_LETTERS[] = _ASCII_UPPER_LETTERS(); */

/* lowercase letters */
/* INIT_ASCIIS(LOWER_LETTER); */
/* const ascii_t ASCII_LOWER_LETTERS[] = _ASCII_LOWER_LETTERS(); */

/* uppercase consonants */
/* INIT_ASCIIS(UPPER_CONSONANT); */
/* const ascii_t */
/* ASCII_UPPER_CONSONANTS[] = _ASCII_UPPER_CONSONANTS(); */

/* lowercase consonants */
/* INIT_ASCIIS(LOWER_CONSONANT); */
/* const ascii_t */
/* ASCII_LOWER_CONSONANTS[] = _ASCII_LOWER_CONSONANTS(); */

/* uppercase vowels */
/* INIT_ASCIIS(UPPER_VOWEL); */
/* const ascii_t ASCII_UPPER_VOWELS[] = _ASCII_UPPER_VOWELS(); */

/* lowercase vowels */
/* INIT_ASCIIS(LOWER_VOWEL); */
/* const ascii_t ASCII_LOWER_VOWELS[] = _ASCII_LOWER_VOWELS(); */

/* punctuation */
/* INIT_ASCIIS(PUNCTUATION); */
/* const ascii_t ASCII_PUNCTUATION[] = _ASCII_PUNCTUATION(); */

/* printable, non-letter, non-number, non-punctuation characters */
/* INIT_ASCIIS(MISC_SYMBOL); */
/* const ascii_t ASCII_MISC_SYMBOLS[] = _ASCII_MISC_SYMBOLS(); */

/* non-printable codes */
/* INIT_ASCIIS(CONTROL); */
/* const ascii_t ASCII_CONTROLS[] = _ASCII_CONTROLS(); */

const ascii_t ASCII_VALIDS[ASCII_VALID_CNT]				= _ASCII_VALIDS();
const ascii_t ASCII_PRINTABLES[ASCII_PRINTABLE_CNT]			= _ASCII_PRINTABLES();
const ascii_t ASCII_NUMBERS[ASCII_NUMBER_CNT]				= _ASCII_NUMBERS();
const ascii_t ASCII_LETTERS[ASCII_LETTER_CNT]				= _ASCII_LETTERS();
const ascii_t ASCII_CONSONANTS[ASCII_CONSONANT_CNT]			= _ASCII_CONSONANTS();
const ascii_t ASCII_VOWELS[ASCII_VOWEL_CNT]				= _ASCII_VOWELS();
const ascii_t ASCII_UPPER_LETTERS[ASCII_CASE_LETTER_CNT]	= _ASCII_UPPER_LETTERS();
const ascii_t ASCII_LOWER_LETTERS[ASCII_CASE_LETTER_CNT]	= _ASCII_LOWER_LETTERS();
const ascii_t ASCII_UPPER_CONSONANTS[ASCII_CASE_CONSONANT_CNT] = _ASCII_UPPER_CONSONANTS();
const ascii_t ASCII_LOWER_CONSONANTS[ASCII_CASE_CONSONANT_CNT] = _ASCII_LOWER_CONSONANTS();
const ascii_t ASCII_UPPER_VOWELS[ASCII_CASE_VOWEL_CNT]		= _ASCII_UPPER_VOWELS();
const ascii_t ASCII_LOWER_VOWELS[ASCII_CASE_VOWEL_CNT]		= _ASCII_LOWER_VOWELS();
const ascii_t ASCII_PUNCTUATION[ASCII_PUNCTUATION_CNT]			= _ASCII_PUNCTUATION();
const ascii_t ASCII_MISC_SYMBOLS[ASCII_MISC_SYMBOL_CNT]			= _ASCII_MISC_SYMBOLS();
const ascii_t ASCII_CONTROLS[ASCII_CONTROL_CNT]				= _ASCII_CONTROLS();

/* ASCII sets (boolean indicates membership)
 * ========================================================================== */
/* letters */
const bool ASCII_LETTER_SET[ASCII_CNT] = _ASCII_LETTER_SET();

/* consonants */
const bool ASCII_CONSONANT_SET[ASCII_CNT] = _ASCII_CONSONANT_SET();

/* vowels */
const bool ASCII_VOWEL_SET[ASCII_CNT] = _ASCII_VOWEL_SET();


/* ASCII maps ('code' maps to 'MAP[code]')
 * ========================================================================== */
const ascii_t ASCII_LOWER_MAP[ASCII_CNT]  = _ASCII_LOWER_MAP();

const ascii_t ASCII_UPPER_MAP[ASCII_CNT]  = _ASCII_UPPER_MAP();

const ascii_t ASCII_TOGGLE_MAP[ASCII_CNT] = _ASCII_TOGGLE_MAP();



/* printable characters */
/* const ascii_t ASCII_PRINTABLES[] = { */
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
