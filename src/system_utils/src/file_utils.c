#include "file_utils.h"

extern inline void fildes_write_all(const int fildes,
				    const char *restrict contents);

extern inline void filename_write_all(const char *restrict filename,
				      const char *restrict contents);
