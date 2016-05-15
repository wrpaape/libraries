#include <gtest/gtest.h>
#include <ctime>

/* extern "C" { */
#include <big_o/big_o.c>
/* } */

class BigOTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			srand((int) time(NULL));
		}

		virtual void TearDown() {
		}
};

/* Tests 'bheap_sort' function */
/* TEST_F(BigOTest, BigOSort) { */

/* } */
