#include <string/ascii.h> /* ascii_t, lookup tables */

/* character map case */
extern inline ascii_t lowercase_ascii(ascii_t ascii);
extern inline ascii_t uppercase_ascii(ascii_t ascii);
extern inline ascii_t togglecase_ascii(ascii_t ascii);

/* string map case */
extern inline void uppercase_ascii_string(ascii_t *restrict string);
extern inline void lowercase_ascii_string(ascii_t *restrict string);
extern inline void togglecase_ascii_string(ascii_t *restrict string);
