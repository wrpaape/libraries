#include <parallel/parallel.h>


/* processes a task in a cancellable thread */
void *execute_spawned_thread(void *restrict arg)
{
	struct SpawnArg *const spawn_arg = (struct SpawnArg *) arg;

	int prev_cancel_type; /* dummy */

	HANDLE_PTHREAD_SETCANCELTYPE(PTHREAD_CANCEL_ASYNCHRONOUS,
				     &prev_cancel_type);

	(*(spawn_arg->task->fun))(spawn_arg->task->arg);

	HANDLE_PTHREAD_COND_SIGNAL(spawn_arg->task_complete);

	return NULL;
}


void spawn_timeout_task(struct Task *const restrict task,
			const struct timespec *restrict timeout)
{
	pthread_t task_thread;
	pthread_cond_t task_complete;
	pthread_mutex_t processing_task;
	struct timespec time_limit;

	const struct SpawnArg spawn_arg = {
		.task	       = task,
		.task_complete = &task_complete
	};

	HANDLE_PTHREAD_COND_INIT(&task_complete,
				 NULL);

	HANDLE_PTHREAD_MUTEX_INIT(&processing_task,
				  NULL);

	HANDLE_PTHREAD_MUTEX_LOCK(&processing_task);

	set_time_limit(&time_limit,
		       timeout);

	HANDLE_PTHREAD_CREATE(&task_thread,
			      NULL,
			      &execute_spawned_thread,
			      (void *) &spawn_arg);

	HANDLE_PTHREAD_COND_TIMEDWAIT(&task_complete,
				      &processing_task,
				      &time_limit);

	HANDLE_PTHREAD_MUTEX_UNLOCK(&processing_task);
}
