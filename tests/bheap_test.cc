#include <gtest/gtest.h>
#include <ctime>

extern "C" {
#include <bheap/bheap.c>
}

class BHeapTest : public testing::Test
{
	protected:
		virtual void SetUp() {
			srand((int) time(NULL));
		}

		virtual void TearDown() {
		}
};

/* Tests 'bheap_sort' function */
int int_compare(const void *x,
		const void *y)
{
	return ((int) x) < ((int) y);
}
TEST_F(BHeapTest, BHeapSort) {

	int raw[]    = {4, 1, 5, 3, 2};
	int sorted[] = {1, 2, 3, 4, 5};

	bheap_sort(&raw[0l], 5l, sizeof(int), &int_compare);

	EXPECT_EQ(0, memcmp(raw, sorted, sizeof(raw)));
}
