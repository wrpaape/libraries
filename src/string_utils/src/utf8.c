#include "utf8.h"

extern inline size_t utf8_head_width(const byte_t head);
extern inline size_t utf8_width(const byte_t *bytes);
extern inline bool is_utf8(const byte_t *restrict bytes);

bool is_utf8_string(const byte_t *restrict string)
{
	size_t width;

	while (1) {
		width = utf8_width(string);

		if (width == 0ul)
			return false;

		if (*string == '\0')
			return true;

		string += width;
	}
}

/* returns pointer to '\0' terminator or NULL if error/immediate EOF */
char *fgets_utf8(char *const restrict char_buffer,
		 int count,
		 FILE *restrict stream)
{
	byte_t *restrict byte_buffer = (byte_t *) fgets(char_buffer,
							count
							* ((int) UTF8_MAX_SIZE),
							stream);

	if (byte_buffer == NULL) /* will catch case of 'count <= 0' */
		return NULL;

	size_t width;

	while (1) {
		width = utf8_width(byte_buffer);

		if (width == 0ul)
			return NULL;

		byte_buffer += width;

		if ((*((char *) byte_buffer)) == '\0')
			return (char *) byte_buffer;

		if (count < 2) {
			*((char *) byte_buffer) = '\0';
			return (char *) byte_buffer;
		}

		--count;
	}
}
