#include "screen_utils.h"

extern inline void stdio_get_winsize(struct winsize *const restrict window);

extern inline void stdio_get_command(char *restrict buffer,
				     const int size,
				     const char *const restrict command);