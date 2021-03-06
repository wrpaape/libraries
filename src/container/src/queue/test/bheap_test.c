#include <unity/unity.h>
#include "bheap.h"

#define DEF_COMP(SYMBOL, TYPE, COMP)					\
int SYMBOL(const void *x, const void *y)				\
{									\
	return ((*((TYPE *) x)) COMP (*((TYPE *) y))) ? -1 :		\
	      (((*((TYPE *) x))  ==  (*((TYPE *) y))) ?  0 : 1);	\
}

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

int string_compare(const void *x, const void *y)
{
	return strcmp((const char *) x, (const char *) y);
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bheap_empty_peek_and_extract(void)
{
	int buffer;
	struct BHeap *heap = bheap_create(sizeof(int),
					  &int_less_than);

	TEST_ASSERT_FALSE(bheap_peek(heap,
				     &buffer));

	TEST_ASSERT_FALSE(bheap_extract(heap,
					&buffer));
	bheap_destroy(heap);
}

void test_bheap_peek_extract(void)
{
	long buffer;
	struct BHeap *heap = bheap_create(sizeof(long),
					  &long_greater_than);

	long large = 0xDEADBEA7;
	long small = 0xDEADBABE;

	bheap_insert(heap, &small);
	bheap_insert(heap, &large);

	TEST_ASSERT_TRUE(bheap_peek(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(large, buffer);

	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(large, buffer);

	TEST_ASSERT_TRUE(bheap_peek(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(small, buffer);

	TEST_ASSERT_TRUE(bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(small, buffer);

	TEST_ASSERT_FALSE(bheap_peek(heap, &buffer));
	bheap_destroy(heap);
}

void test_bheap_min_heap(void)
{
	struct BHeap *heap = bheap_create(sizeof(char),
					  &char_less_than);
	char insert[] = "JCFGBIADHE";
	char extract[sizeof(insert) / sizeof(char)];

	char *ptr;

	for (ptr = &insert[0]; *ptr != '\0'; ++ptr)
		bheap_insert(heap, ptr);

	for (ptr = &extract[0]; bheap_extract(heap, ptr); ++ptr);

	*ptr = '\0';

	TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJ", &extract[0]);

	/* inverted min heap */
	heap->count = 0ul;

	for (size_t i = 0ul; i < (sizeof(insert) / sizeof(char)); ++i)
		inv_bheap_insert(heap, &insert[i]);

	for (ptr = &extract[0]; inv_bheap_extract(heap, ptr); ++ptr);

	TEST_ASSERT_EQUAL_STRING("JIHGFEDCBA", &extract[0]);

	bheap_destroy(heap);
}

void test_bheap_max_heap(void)
{
	struct BHeap *heap = bheap_create(sizeof(Width16),
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


	/* inverted max heap */
	heap->count = 0ul;

	for (size_t i = 0ul; i < (sizeof(insert) / sizeof(Width16)); ++i)
		inv_bheap_insert(heap, &insert[i]);


	TEST_ASSERT_TRUE(inv_bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xCAFEBABE, buffer);
	TEST_ASSERT_TRUE(inv_bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xCAFEDEAD, buffer);
	TEST_ASSERT_TRUE(inv_bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xDEADBEEF, buffer);
	TEST_ASSERT_TRUE(inv_bheap_extract(heap, &buffer));
	TEST_ASSERT_EQUAL_HEX(0xDEED00DAA, buffer);
	TEST_ASSERT_FALSE(inv_bheap_extract(heap, &buffer));

	bheap_destroy(heap);
}

void heap_property_failure(const int *restrict array,
			   const size_t length,
			   const size_t i_parent,
			   const size_t i_child,
			   const char *restrict comparison)
{
	char failure[256];

	sprintf(&failure[0],
		"invalid heap, child node (array[%zu] = %d) is %s parent node "
		"(array[%zu] = %d)",
		i_child, array[i_child], comparison, i_parent, array[i_parent]);

	PRINT_ARRAY(array, 10, "%d");

	TEST_FAIL_MESSAGE(failure);
}


void test_int_array_is_valid_heap(const int *restrict array,
				  const size_t length,
				  int (*compare)(const void *,
						 const void *),
				  const char *restrict comparison)
{
	if (length < 2ul)
		return;

	size_t i_parent = 0ul;
	size_t i_child  = 1ul;
	size_t child_count;

	while (1) {
		for (child_count = 0ul; child_count < 2ul; ++child_count) {

			if (compare((void *) (array + i_child),
				    (void *) (array + i_parent)) < 0)
				heap_property_failure(array,
						      length,
						      i_parent,
						      i_child,
						      comparison);
			++i_child;

			if (i_child == length)
				return;
		}

		++i_parent;
	}
}



void test_bheap_heapify(void)
{
	struct BHeap heap;
	int min_heap[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };
	int max_heap[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };

	bheap_heapify(&heap,
		      &min_heap[0],
		      10ul,
		      sizeof(int),
		      &int_less_than);

	test_int_array_is_valid_heap(&min_heap[0],
				     10ul,
				     &int_less_than,
				     "less than");

	bheap_heapify(&heap,
		      &max_heap[0],
		      10ul,
		      sizeof(int),
		      &int_greater_than);

	test_int_array_is_valid_heap(&max_heap[0],
				     10ul,
				     &int_greater_than,
				     "greater than");
}


void test_inv_bheap_heapify(void)
{
	struct BHeap heap;
	int inv_min_heap[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };
	int inv_max_heap[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };

	inv_bheap_heapify(&heap,
			  &inv_min_heap[0],
			  10ul,
			  sizeof(int),
			  &int_less_than);

	test_int_array_is_valid_heap(&inv_min_heap[0],
				     10ul,
				     &int_greater_than,
				     "greater than");

	inv_bheap_heapify(&heap,
			  &inv_max_heap[0],
			  10ul,
			  sizeof(int),
			  &int_greater_than);

	test_int_array_is_valid_heap(&inv_max_heap[0],
				     10ul,
				     &int_less_than,
				     "less than");
}

void test_bheap_sort(void)
{
	int sorted_ints[]   = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int shuffled_ints[] = { 8, 2, 3, 1, 9, 5, 0, 4, 6, 7 };

	bheap_heapsort(&shuffled_ints[0],
		       10ul,
		       sizeof(int),
		       &int_less_than);

	TEST_ASSERT_EQUAL_INT_ARRAY(&sorted_ints[0],
				    &shuffled_ints[0], 10ul);


	char *sorted_strings[]   = { "bob", "bob", "jon", "moe", "tim", "tom" };
	char *shuffled_strings[] = { "tim", "tom", "bob", "moe", "bob", "jon" };

	bheap_heapsort(&shuffled_strings[0],
		       6ul,
		       sizeof(char *),
		       &string_compare);

	TEST_ASSERT_EQUAL_STRING_ARRAY(&sorted_strings[0],
				       &shuffled_strings[0], 6ul);
}
