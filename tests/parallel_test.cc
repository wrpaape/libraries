#include <gtest/gtest.h>
#include <ctime>

/* extern "C" { */
#include <parallel/parallel.c>
/* } */

class ParallelTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			srand((int) time(NULL));
		}

		virtual void TearDown() {
		}
};

/* Tests 'bheap_sort' function */
/* TEST_F(ParallelTest, BigOSort) { */

/* } */
