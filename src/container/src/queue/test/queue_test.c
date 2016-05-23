#include <unity/unity.h>
#include "queue.h"

static struct Queue *queue;

void setUp(void)
{
	queue = queue_create();
}

void tearDown(void)
{
	queue_free(queue);
}

void test_queue_pop_empty(void)
{
	TEST_ASSERT_NULL(queue_pop(queue));
}

void test_queue_push_peek(void)
{
	queue_push(queue, "ah, push it");
	TEST_ASSERT_EQUAL_STRING("ah, push it", queue_peek(queue));
}

void test_queue_push_peek_pop(void)
{
	queue_push(queue, "ah, push it");

	char *next = queue_peek(queue);

	TEST_ASSERT_EQUAL_STRING(next, queue_pop(queue));
	TEST_ASSERT_NULL(queue_peek(queue));
}

void test_queue_fifo_load_then_traverse(void)
{
	int i;
	for (i = 0; i < 5; ++i)
		queue_push(queue, (void *) (intptr_t) i);

	for (i = 0; i < 5; ++i)
		TEST_ASSERT_EQUAL_INT(i, queue_pop(queue));

	TEST_ASSERT_NULL(queue_peek(queue));
}

void test_queue_fifo_load_with_traverse(void)
{
	queue_push(queue, (void *) 42);
	queue_push(queue, "ooga booga");
	queue_push(queue, &queue_push);

	TEST_ASSERT_EQUAL_INT(42,	       queue_pop(queue));
	TEST_ASSERT_EQUAL_STRING("ooga booga", queue_pop(queue));

	queue_push(queue, (void *) 13);
	queue_push(queue, "bar");

	TEST_ASSERT_EQUAL((void *) &queue_push, queue_pop(queue));
	TEST_ASSERT_EQUAL_INT(13,		queue_pop(queue));
	TEST_ASSERT_EQUAL_STRING("bar",		queue_pop(queue));

	TEST_ASSERT_NULL(queue_peek(queue));
}
