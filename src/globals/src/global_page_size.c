#include "global_page_size.h"

size_t global_page_size = 0ul; /* zero indicates unset */

extern inline void set_global_page_size(void);
