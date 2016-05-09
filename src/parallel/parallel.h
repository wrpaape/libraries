#ifndef PARALLEL_PARALLEL_H
#define PARALLEL_PARALLEL_H

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/time.h>		/* real time clock, time types, structs, fns */
#include <parallel/pthread.h>	/* pthead API, error handler macros */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* TYPEDEFS, ENUM AND STRUCT DEFINITIONS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

struct Task {
	void (*fun)(void *);
	void *arg;
};

struct SpawnArg {
	int prev_cancel_type;
	struct Task *task;
	pthread_cond_t *task_complete;
};

/* TYPEDEFS, ENUM AND STRUCT DEFINITIONS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


void *assign_timeout_task(pthread_t *restrict thread,
			  const pthread_attr_t *restrict attr,
			  const struct Task *restrict task,
			  const struct timespec *restrict timeout);

void spawn_timeout_task(const struct Task *restrict task,
			const struct timespec *restrict timeout);


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef PARALLEL_PARALLEL_H */
