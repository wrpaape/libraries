#include <parallel/parallel.h>


void *timeout_task_thread(void *arg)

void *timeout_task(pthread_t *restrict thread,
		   const pthread_attr_t *restrict attr,
		   const struct Task *restrict task,
		   const struct timespec *restrict timeout);

void *new_timeout_task(const struct Task *restrict task,
		       const struct timespec *restrict timeout)
{
	/* pthread_cond_t task_complete; */
	pthread_mutex_t processing_task;

	HANDL_PTHREAD_MUTEX_INIt
	struct TimeoutArg timeout_arg;
	struct timespec time_limit;

	set_time_limit(&time_limit, timeout);

	HANDLE_PTHREAD_CREATE(thread,
			      attr,
			      &timeout_task_thread,
			      task->arg);

	return (void *) nanosleep((struct timespec *) timeout, NULL);
}
