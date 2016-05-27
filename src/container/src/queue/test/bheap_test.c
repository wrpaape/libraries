#include <unity/unity.h>
#include "bheap.h"

#define DEF_COMP(SYMBOL, TYPE, COMPARE)		\
int SYMBOL(const void *x, const void *y)	\
{ return ((*((TYPE *) x)) COMPARE (*((TYPE *) y))); }

#define DEFINE_LESS_THAN(TYPE) DEF_COMP(TYPE ## _less_than, TYPE, <)
#define DEFINE_GREATER_THAN(TYPE) DEF_COMP(TYPE ## _greater_than, TYPE, >)
#define FOR_ALL_TYPES(MACRO)	\
	MACRO(char)		\
	MACRO(int)		\
	MACRO(float)		\
	MACRO(long)		\
	MACRO(double)		\
	MACRO(Width16)

FOR_ALL_TYPES(DEFINE_LESS_THAN)
FOR_ALL_TYPES(DEFINE_GREATER_THAN)



static struct BHeap *heap;


void setUp(void)
{
}

void tearDown(void)
{
}

void test_bheap_extract_empty(void)
{
	int buffer;
	heap = bheap_create(sizeof(int),
			    &int_less_than);

	TEST_ASSERT_FALSE(bheap_extract(heap,
					&buffer));
	bheap_free(heap);
}

void test_bheap_min_heap(void)
{
	heap = bheap_create(sizeof(char),
			    &char_less_than);

	char insert[] = "JCFGBIADHE";
	char extract[sizeof(insert) / sizeof(char)];

	char *pointer;

	for (pointer = &insert[0]; *pointer != '\0'; ++pointer)
		bheap_insert(heap, pointer);

	for (pointer = &extract[0]; bheap_extract(heap, pointer); ++pointer);

	*pointer = '\0';

	TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJ", &extract[0]);

	bheap_free(heap);
}

void test_bheap_max_heap(void)
{
	heap = bheap_create(sizeof(Width16),
			    &Width16_greater_than);
	Width16 buffer;
	Width16 insert[] = { 0xDEADBEEF, 0xCAFEBABE, 0xCAFEDEAD, 0xDEED00DAA };

	for (size_t i = 0ul; i < (sizeof(insert) / sizeof(Width16)); ++i)
		bheap_insert(heap, &insert[i]);


	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xDEED00DAA, buffer);
	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xDEADBEEF, buffer);
	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xCAFEDEAD, buffer);
	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xCAFEBABE, buffer);
	TEST_ASSERT_FALSE(bheap_extract(heap, &buffer));

	bheap_free(heap);
}

void test_bheap_heapify_min(void)
{
	struct BHeap heap;
	int array[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };
	bheap_heapify_min(&heap,
			  &array[0],
			  10ul,
			  sizeof(int),
			  &int_less_than);

	TEST_ASSERT((array[0] < array[1])); TEST_ASSERT((array[0] < array[2]));
	TEST_ASSERT((array[1] < array[3])); TEST_ASSERT((array[1] < array[4]));
	TEST_ASSERT((array[2] < array[5])); TEST_ASSERT((array[2] < array[6]));
	TEST_ASSERT((array[3] < array[7])); TEST_ASSERT((array[3] < array[8]));
	TEST_ASSERT((array[4] < array[9]));

}

void test_bheap_sort(void)
{
	TEST_IGNORE();

	int sorted[]   = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int shuffled[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };

	bheap_sort(&shuffled[0],
		   10ul,
		   sizeof(int),
		   &int_greater_than);

	PRINT_ARRAY(shuffled, 10ul, "%d");

	TEST_ASSERT_EQUAL_INT_ARRAY(&sorted[0], &shuffled[0], 10ul);
}
