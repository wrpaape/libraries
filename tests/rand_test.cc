#include <gtest/gtest.h>
/* #include <ctime> */

/* hide main */
#define TESTING
#include "bheap/bheap.c"



class BHeapTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			init_rng();
		}

		virtual void TearDown() {
		}
};

/* Tests 'put_token' function */
TEST_F(BHeapTest, PutColorToken) {

	const char *literal = ANSI_CYAN "(" ANSI_RESET ANSI_BRIGHT;

	char buffer[16ul];

	char *ptr = &buffer[0ul];

	char parenths = '(';

	struct Token token = {
		.parenths   = &parenths,
		.put_prefix = &put_CYAN_prefix
	};

	put_token(&ptr, &token);

	*ptr = '\0';

	EXPECT_EQ(0, strcmp(literal, buffer));
}
