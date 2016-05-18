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

void test_queue(void)
{
	TEST_ASSERT_EQUAL(NULL, queue_pop(queue));

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
}
