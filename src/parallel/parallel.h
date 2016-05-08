#ifndef PARALLEL_PARALLEL_H
#define PARALLEL_PARALLEL_H

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* error handling, misc convenience fns */
#include <utils/time.h>		/* real time clock, time types, structs, fns */
#include <pthread.h>		/* pthead API */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* error handlers
 * ========================================================================== */
/* pthread_create */
#define HANDLE_PTHREAD_CREATE(THREAD, ATTR, ROUTINE, ARG)		\
do {									\
	int status = pthread_create(THREAD, ATTR, ROUTINE, ARG);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to create pthread"		\
				"\e24m]\n\n{\n"				\
				"\tthread:        '" #THREAD  "'\n"	\
				"\tattr:          '" #ATTR    "'\n"	\
				"\tstart_routine: '" #ROUTINE "'\n"	\
				"\targ:           '" #ARG     "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_CREATE_FAIL_RSN(status));		\
} while (0)
#define PT_CREATE_FAIL_RSN(STATUS)					\
((STATUS == EAGAIN)							\
? "The system lacked the necessary resources to create another thread"	\
  ", or the system-imposed limit on the total number of threads in a "	\
  "process [PTHREAD_THREADS_MAX] would be exceeded."			\
: ((STATUS == EINVAL)							\
? "The value specified by attr is invalid."				\
: "unknown"))


/* pthread_join */
#define HANDLE_PTHREAD_JOIN(THREAD, VALUE_PTR)				\
do {									\
	int status = pthread_join(THREAD, VALUE_PTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to join pthread"		\
				"\e24m]\n\n{\n"				\
				"\tthread:    '" #THREAD    "'\n"	\
				"\tvalue_ptr: '" #VALUE_PTR "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_JOIN_FAIL_RSN(status));		\
} while (0)
#define PT_JOIN_FAIL_RSN(STATUS)					\
((STATUS == EDEADLK)							\
? "A deadlock was detected or the value of thread specifies the "	\
  "calling thread."							\
: ((STATUS == EINVAL)							\
? "The implementation has detected that the value specified by thread "	\
  "does not refer to a joinable thread."				\
: ((STATUS == ESRCH)							\
? "No thread could be found corresponding to that specified by the "	\
  "given thread ID, thread."						\
: "unknown")))


/* pthread_mutex_init */
#define HANDLE_PTHREAD_MUTEX_INIT(MUTEX, ATTR)				\
do {									\
	int status = pthread_mutex_init(MUTEX, ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread mutex"	\
				"\e24m]\n\n{\n"				\
				"\tmutex: '" #MUTEX "'\n"		\
				"\tattr:  '" #ATTR "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MUTEX_INIT_FAIL_RSN(status));	\
} while (0)
#define PT_MUTEX_INIT_FAIL_RSN(STATUS)					\
((STATUS == EAGAIN)							\
? "The system temporarily lacks the resources to create another mutex."	\
: ((STATUS == EINVAL)							\
? "The value specified by 'attr' is invalid."				\
: ((STATUS == ENOMEM)							\
? "The process cannot allocate enough memory to create another mutex."	\
: "unknown")))


/* pthread_mutex_lock */
#define HANDLE_PTHREAD_MUTEX_LOCK(MUTEX)				\
do {									\
	int status = pthread_mutex_lock(MUTEX);				\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to lock pthread mutex"		\
				"\e24m]\n\n{\n"				\
				"\tmutex: '" #MUTEX "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MUTEX_LOCK_FAIL_RSN(status));	\
} while (0)
#define PT_MUTEX_LOCK_FAIL_RSN(STATUS)					\
((STATUS == EDEADLK)							\
? "A deadlock would occur if the thread is blocked waiting for mutex."	\
: ((STATUS == EINVAL)							\
? "The value specified by 'mutex' is invalid."				\
: "unknown"))


/* pthread_mutex_unlock */
#define HANDLE_PTHREAD_MUTEX_UNLOCK(MUTEX)				\
do {									\
	int status = pthread_mutex_unlock(MUTEX);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to unlock pthread mutex"	\
				"\e24m]\n\n{\n"				\
				"\tmutex: '" #MUTEX "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MUTEX_UNLOCK_FAIL_RSN(status));	\
} while (0)
#define PT_MUTEX_UNLOCK_FAIL_RSN(STATUS)				\
((STATUS == EINVAL)							\
? "The value specified by 'mutex' is invalid."				\
: ((STATUS == EPERM)							\
? "The current thread does not hold a lock on 'mutex'."			\
: "unknown")


/* pthread_cond_init */
#define HANDLE_PTHREAD_COND_INIT(COND, ATTR)				\
do {									\
	int status = pthread_cond_init(COND, ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set pthread cancel type"	\
				"\e24m]\n\n{\n"				\
				"\tcond: '" #COND "'\n"			\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_INIT_FAIL_RSN(status));		\
} while (0)
#define PT_COND_INIT_FAIL_RSN(STATUS)					\
((STATUS == EAGAIN)							\
? "The system temporarily lacks the resources to create another "	\
  "condition variable."							\
: ((STATUS == EINVAL)							\
? "The value specified by 'attr' is invalid."				\
: ((STATUS == ENOMEM)							\
? "The process cannot allocate enough memory to create another "	\
  "condition variable."							\
: "unknown")))


/* pthread_cond_signal */
#define HANDLE_PTHREAD_COND_SIGNAL(COND)				\
do {									\
	int status = pthread_cond_signal(COND);				\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to signal pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond: '" #COND "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_SIGNAL_FAIL_RSN(status));	\
} while (0)
#define PT_COND_SIGNAL_FAIL_RSN(STATUS)					\
((STATUS == EINVAL)							\
? "the value specified by 'cond' is invalid."				\
: "unknown")


/* pthread_cond_timedwait */
#define HANDLE_PTHREAD_COND_TIMEDWAIT(COND, MUTEX, ABSTIME)		\
do {									\
	int status = pthread_cond_timedwait(COND, MUTEX, ABSTIME);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to signal pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond:    '" #COND "'\n"		\
				"\tmutex:   '" #MUTEX "'\n"		\
				"\tabstime: '" #ABSTIME "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_TIMEDWAIT_FAIL_RSN(status));	\
} while (0)
#define PT_COND_TIMEDWAIT_FAIL_RSN(STATUS)				\
((STATUS == EINVAL)							\
? "The value specified by 'cond', 'mutex' or 'abstime' is invalid."	\
: ((STATUS == ETIMEDOUT)						\
? "The system time has reached or exceeded the time specified in "	\
  "'abstime'."
: "unknown"))


/* pthread_condattr_setpshared */
#define HANDLE_PTHREAD_CONDATTR_SETPSHARED(TYPE, OLDTYPE)		\
do {									\
	int status = pthread_setcanceltype(TYPE, OLDTYPE);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set pthread cancel type"	\
				"\e24m]\n\n{\n"				\
				"\ttype:    '" #TYPE	"'\n"		\
				"\toldtype: '" #OLDTYPE "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_SETCANCELTYPE_FAIL_RSN(status));	\
} while (0)
#define PT_SETCANCELTYPE_FAIL_RSN(STATUS)				\
((STATUS == EINVAL)							\
? "The specified state is not 'PTHREAD_CANCEL_DEFERRED' or "		\
  "'PTHREAD_CANCEL_ASYNCHRONOUS'."					\
: "unknown")


/* pthread_setcanceltype */
#define HANDLE_PTHREAD_SETCANCELTYPE(TYPE, OLDTYPE)			\
do {									\
	int status = pthread_setcanceltype(TYPE, OLDTYPE);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set pthread cancel type"	\
				"\e24m]\n\n{\n"				\
				"\ttype:    '" #TYPE	"'\n"		\
				"\toldtype: '" #OLDTYPE "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_SETCANCELTYPE_FAIL_RSN(status));	\
} while (0)
#define PT_SETCANCELTYPE_FAIL_RSN(STATUS)				\
((STATUS == EINVAL)							\
? "The specified state is not 'PTHREAD_CANCEL_DEFERRED' or "		\
  "'PTHREAD_CANCEL_ASYNCHRONOUS'."					\
: "unknown")


struct Task {
	void *(*start_routine)(void *);
	void *arg;
};

struct TimeoutArg {
	struct Task *task;
	pthread_cond_t task_complete;
	int oldtype;
};

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

void *timeout_task(pthread_t *restrict thread,
		   const pthread_attr_t *restrict attr,
		   const struct Task *restrict task,
		   const struct timespec *restrict timeout);



#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef PARALLEL_PARALLEL_H */
