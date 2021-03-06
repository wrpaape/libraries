#include <gtest/gtest.h>
#include <ctime>

extern "C" {
#include <utils/utils.c>
}

class UtilsTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			srand((int) time(NULL));
		}

		virtual void TearDown() {
		}
};

/* Tests 'next_pow_two' function */
TEST_F(UtilsTest, NextPowTwo) {

	EXPECT_EQ(2ul, next_pow_two(0ul));
	EXPECT_EQ(4ul, next_pow_two(2ul));
	EXPECT_EQ(4ul, next_pow_two(3ul));
	EXPECT_EQ((1ul << 10), next_pow_two(1ul << 9));
}
