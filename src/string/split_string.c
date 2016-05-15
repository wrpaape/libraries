#include <string/split_string.h>

char **split_string(char *restrict string,
		    const char split)
{
	char **split_strings;

	const size_t seg_count = count_segments(string,
						split);

	HANDLE_MALLOC(split_strings,
		      sizeof(char *) * (seg_count + 1ul));

	split_strings[0] = string;

	for (size_t i = 1ul; i < seg_count; ++i) {

		while (*string != split)
			++string;

		*string = '\0';
		++string;

		split_strings[i] = string;
	}

	split_strings[seg_count] = NULL;

	return split_strings;
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
