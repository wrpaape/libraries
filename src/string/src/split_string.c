#include <string/split_string.h>

char **split_string(char *restrict string,
		    const char split)
{
	char **split_segment;

	const size_t seg_count = count_segments(string,
						split);

	HANDLE_MALLOC(split_segment,
		      sizeof(char *) * (seg_count + 1ul));

	char **const split_strings = split_segment;
	char **const null_segment  = split_strings + seg_count;

	while (1) {
		*split_segment = string;
		++split_segment;

		if (split_segment == null_segment) {
			*null_segment = NULL;
			return split_strings;
		}

		while (*string != split)
			++string;

		*string = '\0';
		++string;
	}
}


inline size_t count_segments(const char *restrict string,
			     const char split)
{
	size_t seg_count = 1ul;

	while (*string != '\0') {

		if (*string == split)
			++seg_count;

		++string;
	}

	return seg_count;
}
