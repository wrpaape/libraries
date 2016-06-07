#include "utf8.h" /* utf8_t */

extern inline size_t utf8_header_size(const char byte);
extern inline size_t utf8_size(const char *bytes);
extern inline bool is_utf8(char *bytes);
extern inline bool is_utf8_string(char *string);
