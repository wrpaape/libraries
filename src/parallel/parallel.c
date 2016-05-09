#include <parallel/parallel.h>


void *execute_spawned_thread(void *arg)
{
	struct SpawnArg *const spawn_arg = (struct SpawnArg *) arg;

	HANDLE_PTHREAD_SETCANCELTYPE(PTHREAD_CANCEL_ASYNCHRONOUS,
				     &spawn_arg->prev_cancel_type);

	(*(spawn_arg->task->fun))(spawn_arg->task->arg);

	HANDLE_PTHREAD_COND_SIGNAL(spawn_arg->task_complete);

	return NULL;
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
	pthread_t thread;
	pthread_cond_t task_complete;
	pthread_mutex_t processing_task;
	struct timespec time_limit;
	struct SpawnArg spawn_arg;

	HANDLE_PTHREAD_COND_INIT(&task_complete,
				 NULL);

	HANDLE_PTHREAD_MUTEX_INIT(&processing_task,
				  NULL);

	set_time_limit(&time_limit, timeout);

	spawn_arg.task = task;
	spawn_arg.task_complete = &task_complete;

	HANDLE_PTHREAD_MUTEX_LOCK(&processing_task);

	HANDLE_PTHREAD_CREATE(&thread,
			      NULL,
			      &execute_spawned_thread,
			      (void *) &spawn_arg);

	HANDLE_PTHREAD_COND_TIMEDWAIT(&task_complete,
				      &processing_task,
				      &time_limit);

	HANDLE_PTHREAD_MUTEX_UNLOCK(&processing_task);
}
