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
	heap = bheap_create(sizeof(int),
			    &int_less_than);

	TEST_ASSERT_NULL(bheap_extract(heap));
}

void test_bheap_min_heap(void)
{
	heap = bheap_create(sizeof(char),
			    &char_less_than);

	char insert[] = "JCFGBIADHE";
	char extract[sizeof(insert)];

	char *pointer = &insert[0];

	/* for (i = 0ul; i < (sizeof(insert) - 1ul); ++i) */

	do {
		bheap_insert(heap, pointer);
		++pointer;
	} while (*pointer != '\0');

	size_t i = 0ul;

	while (1) {
		pointer = (char *) bheap_extract(heap);

		if (pointer == NULL)
			break;

		extract[i] = *pointer;
		++i;
	}
	extract[i] = '\0';



	TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJ", &extract[0]);
}
