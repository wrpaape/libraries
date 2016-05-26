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
	bheap_free(heap);
}

void test_bheap_extract_empty(void)
{
	int buffer;
	heap = bheap_create(sizeof(int),
			    &int_less_than);

	TEST_ASSERT_FALSE(bheap_extract(heap,
					&buffer));
}

void test_bheap_min_heap(void)
{
	heap = bheap_create(sizeof(char),
			    &char_less_than);

	char insert[] = "JCFGBIADHE";
	char extract[sizeof(insert)];

	char *pointer;

	for (pointer = &insert[0]; *pointer != '\0'; ++pointer)
		bheap_insert(heap, pointer);

	for (pointer = &extract[0]; bheap_extract(heap, pointer); ++pointer);

	TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJ", &extract[0]);
}
