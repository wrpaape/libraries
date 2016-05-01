#include <gtest/gtest.h>
#include <ctime>
#include <utils/rand.c>

class RandTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			init_rng();
		}

		virtual void TearDown() {
		}
};

/* Tests 'rand_uint_upto' function */
TEST_F(RandTest, RandUIntUpto) {

	uint32_t rand = rand_uint_upto(100u);

	EXPECT_TRUE(rand >= 0u);
	EXPECT_TRUE(rand <= 100u);
}
