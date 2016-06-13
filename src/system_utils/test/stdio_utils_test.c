#include <unity/unity.h>
#include <stdlib.h>
#include "stdio_utils.h"

static char buffer[32];

void setUp(void)
{
}

void tearDown(void)
{
}

void test_shell_command_read(void)
{
	const size_t nread = shell_command_read(&buffer[0],
						sizeof("ooga booga"),
						"echo ooga booga");
	buffer[nread - 1lu] = '\0';

	TEST_ASSERT_EQUAL_STRING("ooga booga", &buffer[0]);
}

void test_shell_command_gets(void)
{
	shell_command_gets(&buffer[0],
			   sizeof(buffer),
			   "echo ooga booga");

	TEST_ASSERT_EQUAL_STRING("ooga booga\n", &buffer[0]);
}

void test_stdio_winsize(void)
{
	struct winsize dims;
	unsigned short rows, cols;

	shell_command_gets(&buffer[0],
			   sizeof(buffer),
			   "tput lines");

	rows = (unsigned short) strtoul(&buffer[0], NULL, 10);

	shell_command_gets(&buffer[0],
			   sizeof(buffer),
			   "tput cols");

	cols = (unsigned short) strtoul(&buffer[0], NULL, 10);

	stdio_winsize(&dims);

	TEST_ASSERT_EQUAL_UINT(rows, dims.ws_row);
	TEST_ASSERT_EQUAL_UINT(cols, dims.ws_col);
}
