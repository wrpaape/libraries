#include <parallel/parallel.h>


void *execute_temp_thread(void *arg)
{
	struct TempThreadArg thread_arg = (struct TempThreadArg *) arg;

	HANDLE_PTHREAD_SETCANCELTYPE(PTHREAD_CANCEL_ASYNCHRONOUS,
				     &thread_arg->cancelability);

	thread_arg->task->start_routine
}

void *assign_timeout_task(pthread_t *restrict thread,
			  const pthread_attr_t *restrict attr,
			  const struct Task *restrict task,
			  const struct timespec *restrict timeout)
{
	return NULL;
}

void spawn_timeout_task(const struct Task *restrict task,
			const struct timespec *restrict timeout)
{
	pthread_t task_thread;
	pthread_cond_t task_complete;
	pthread_mutex_t processing_task;
	struct timespec time_limit;
	struct TimeoutArg timeout_arg;

	HANDLE_PTHREAD_COND_INIT(&task_complete, NULL);

	HANDLE_PTHREAD_MUTEX_INIT(&processing_task, NULL);




	set_time_limit(&time_limit, timeout);

	HANDLE_PTHREAD_MUTEX_LOCK(&processing_task);

	HANDLE_PTHREAD_CREATE(&task_thread, );


	HANDLE_PTHREAD_CREATE(thread,
			      attr,
			      &timeout_task_thread,
			      task->arg);

	return (void *) nanosleep((struct timespec *) timeout, NULL);
}
