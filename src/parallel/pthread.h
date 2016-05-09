#ifndef PARALLEL_PTHREAD_H_
#define PARALLEL_PTHREAD_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <pthread.h>		/* pthead API */
#include <utils/utils.h>	/* EXIT_ON_FAILURE */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* <parallel/pthread.h>
 *
 * defines macros, convenience functions for accessing the pthread API */


/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* error handlers
 * exit the calling program and print an error message on failure */

/* pthread_t
 * ========================================================================== */
/* pthread_create */
#define HANDLE_PTHREAD_CREATE(THREAD, ATTR, ROUTINE, ARG)		\
do {									\
	int status = pthread_create(THREAD, ATTR, ROUTINE, ARG);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to create pthread"		\
				"\e24m]\n\n{\n"				\
				"\tthread:        '" #THREAD  "',\n"	\
				"\tattr:          '" #ATTR    "',\n"	\
				"\tstart_routine: '" #ROUTINE "',\n"	\
				"\targ:           '" #ARG     "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_CREATE_FAILURE(status));		\
} while (0)
#define PT_CREATE_FAILURE(STATUS)					\
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
				"\tthread:    '" #THREAD    "',\n"	\
				"\tvalue_ptr: '" #VALUE_PTR "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_JOIN_FAILURE(status));		\
} while (0)
#define PT_JOIN_FAILURE(STATUS)					\
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


/* pthread_kill */
#define HANDLE_PTHREAD_KILL(THREAD, SIG)				\
do {									\
	int status = pthread_kill(THREAD, SIG);				\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to kill pthread"		\
				"\e24m]\n\n{\n"				\
				"\tthread: '" #THREAD "',\n"		\
				"\sig:     '" #SIG    "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_KILL_FAILURE(status));		\
} while (0)
#define PT_KILL_FAILURE(STATUS)						\
((STATUS == EINVAL)							\
? "'sig' is an invalid or unsupported signal number."
: ((STATUS == ESRCH)							\
? "'thread' is an invalid thread ID."
: "unknown"))



/* pthread_attr_t
 * ========================================================================== */
/* pthread_attr_init */
#define HANDLE_PTHREAD_ATTR_INIT(ATTR)					\
do {									\
	int status = pthread_attr_init(ATTR);				\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread "		\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_INIT_FAILURE(status));		\
} while (0)
#define PT_A_INIT_FAILURE(STATUS)					\
((STATUS == ENOMEM)							\
? "Out of memory."							\
: "unknown")


/* pthread_attr_destroy */
#define HANDLE_PTHREAD_ATTR_DESTROY(ATTR)				\
do {									\
	int status = pthread_attr_destroy(ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to destroy pthread attribute"	\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_DESTROY_FAILURE(status));		\
} while (0)
#define PT_A_DESTROY_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_attr_setstacksize */
#define HANDLE_PTHREAD_ATTR_SETSTACKSIZE(ATTR, STACKSIZE)		\
do {									\
	int status = pthread_attr_setstacksize(ATTR, STACKSIZE);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'stacksize' for "	\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:      '" #ATTR      ",'\n"	\
				"\tstacksize: '" #STACKSIZE "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETSTACKSIZE_FAILURE(status));	\
} while (0)
#define PT_A_SETSTACKSIZE_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr', 'stacksize' is less than "			\
  "'PTHREAD_STACK_MIN', or 'stacksize' is not a multipple of the "	\
  "system page size."							\
: "unknown")


/* pthread_attr_setdetachstate */
#define HANDLE_PTHREAD_ATTR_SETDETACHSTATE(ATTR, DETACHSTATE)		\
do {									\
	int status = pthread_attr_setdetachstate(ATTR, DETACHSTATE);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'detachstate' for "	\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:        '" #ATTR        ",'\n"	\
				"\tdetachstate: '" #DETACHSTATE "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETDETACHSTATE_FAILURE(status));	\
} while (0)
#define PT_A_SETDETACHSTATE_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr' or 'detachstate'."				\
: "unknown")


/* pthread_attr_setinheritsched */
#define HANDLE_PTHREAD_ATTR_SETINHERITSCHED(ATTR, INHERITSCHED)		\
do {									\
	int status = pthread_attr_setinheritsched(ATTR, INHERITSCHED);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'inheritsched' for "	\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:         '" #ATTR        ",'\n"	\
				"\tinheritsched: '" #INHERITSCHED "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETINHERITSCHED_FAILURE(status));	\
} while (0)
#define PT_A_SETINHERITSCHED_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_attr_setschedparam */
#define HANDLE_PTHREAD_ATTR_SETSCHEDPARAM(ATTR, PARAM)			\
do {									\
	int status = pthread_attr_setschedparam(ATTR, PARAM);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'sched_param' for "	\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:  '" #ATTR  ",'\n"		\
				"\tparam: '" #PARAM "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETSCHEDPARAM_FAILURE(status));	\
} while (0)
#define PT_A_SETSCHEDPARAM_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: ((STATUS == ENOTSUP)							\
? "Invalid value for 'param'."						\
: "unknown"))


/* pthread_attr_setschedpolicy */
#define HANDLE_PTHREAD_ATTR_SETSCHEDPOLICY(ATTR, POLICY)		\
do {									\
	int status = pthread_attr_setschedpolicy(ATTR, POLICY);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'policy' for "		\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:   '" #ATTR   ",'\n"		\
				"\tpolicy: '" #POLICY "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETSCHEDPOLICY_FAILURE(status));	\
} while (0)
#define PT_A_SETSCHEDPOLICY_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: ((STATUS == ENOTSUP)							\
? "Invalid or unsupported value for value for 'policy'."		\
: "unknown"))


/* pthread_attr_setschedscope */
#define HANDLE_PTHREAD_ATTR_SETSCHEDSCOPE(ATTR, CONTENTIONSCOPE)	\
do {									\
	int status = pthread_attr_setschedscope(ATTR, CONTENTIONSCOPE);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'contentionscope' for "	\
				"pthread attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:            '" #ATTR ",'\n"	\
				"\tcontentionscope: '" #CONTENTIONSCOPE	\
				"'\n"			                \
				"}\n\n"					\
				"reason: %s",				\
				PT_A_SETSCHEDSCOPE_FAILURE(status));	\
} while (0)
#define PT_A_SETSCHEDSCOPE_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: ((STATUS == ENOTSUP)							\
? "Invalid or unsupported value for value for 'contentionscope'."	\
: "unknown"))



/* pthread_mutex_t
 * ========================================================================== */
/* pthread_mutex_init */
#define HANDLE_PTHREAD_MUTEX_INIT(MUTEX, ATTR)				\
do {									\
	int status = pthread_mutex_init(MUTEX, ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread mutex"	\
				"\e24m]\n\n{\n"				\
				"\tmutex: '" #MUTEX "',\n"		\
				"\tattr:  '" #ATTR  "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_M_INIT_FAILURE(status));		\
} while (0)
#define PT_M_INIT_FAILURE(STATUS)					\
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
				PT_M_LOCK_FAILURE(status));		\
} while (0)
#define PT_M_LOCK_FAILURE(STATUS)					\
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
				PT_M_UNLOCK_FAILURE(status));		\
} while (0)
#define PT_M_UNLOCK_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "The value specified by 'mutex' is invalid."				\
: ((STATUS == EPERM)							\
? "The current thread does not hold a lock on 'mutex'."			\
: "unknown")



/* pthread_mutexattr_t
 * ========================================================================== */
/* pthread_mutexattr_init */
#define HANDLE_PTHREAD_MUTEXATTR_INIT(ATTR)				\
do {									\
	int status = pthread_mutexattr_init(ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread mutex "	\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_INIT_FAILURE(status));		\
} while (0)
#define PT_MA_INIT_FAILURE(STATUS)					\
((STATUS == EAGAIN)							\
? "Out of memory."							\
: "unknown")


/* pthread_mutexattr_destroy */
#define HANDLE_PTHREAD_MUTEXATTR_DESTROY(ATTR)				\
do {									\
	int status = pthread_mutexattr_destroy(ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to destroy pthread mutex "	\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_DESTROY_FAILURE(status));		\
} while (0)
#define PT_MA_DESTROY_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_mutexattr_setprioceiling */
#define HANDLE_PTHREAD_MUTEXATTR_SETPRIOCEILING(ATTR, PRIOCEILING)	\
do {									\
	int status = pthread_mutexattr_setprioceiling(ATTR,		\
						      PRIOCEILING);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set priority ceiling for "	\
				"pthread mutex attribute"		\
				"\e24m]\n\n{\n"				\
				"\tattr:        '" #ATTR        "',\n"	\
				"\tprioceiling: '" #PRIOCEILING "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_SETPRIOCEILING_FAILURE(status));	\
} while (0)
#define PT_MA_SETPRIOCEILING_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr', or invalid value for 'prioceiling'."	\
: "unknown")


/* pthread_mutexattr_getprioceiling */
#define HANDLE_PTHREAD_MUTEXATTR_GETPRIOCEILING(ATTR, PRIOCEILING)	\
do {									\
	int status = pthread_mutexattr_getprioceiling(ATTR,		\
						      PRIOCEILING);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to get priority ceiling for "	\
				"pthread mutex attribute"		\
				"\e24m]\n\n{\n"				\
				"\tattr:        '" #ATTR        "',\n"	\
				"\tprioceiling: '" #PRIOCEILING "'\n"	\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_GETPRIOCEILING_FAILURE(status));	\
} while (0)
#define PT_MA_GETPRIOCEILING_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_mutexattr_setprotocol */
#define HANDLE_PTHREAD_MUTEXATTR_SETPROTOCOL(ATTR, PROTOCOL)		\
do {									\
	int status = pthread_mutexattr_setprotocol(ATTR, PROTOCOL);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set protocol for pthread "	\
				"mutex attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:     '" #ATTR     "',\n"	\
				"\tprotocol: '" #PROTOCOL "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_SETPROTOCOL_FAILURE(status));	\
} while (0)
#define PT_MA_SETPROTOCOL_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr', or invalid value for 'protocol'."		\
: "unknown")


/* pthread_mutexattr_getprotocol */
#define HANDLE_PTHREAD_MUTEXATTR_GETPROTOCOL(ATTR, PROTOCOL)		\
do {									\
	int status = pthread_mutexattr_getprotocol(ATTR,		\
						   PROTOCOL);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to get protocol for pthread "	\
				"mutex attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr:     '" #ATTR     "',\n"	\
				"\tprotocol: '" #PROTOCOL "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_GETPROTOCOL_FAILURE(status));	\
} while (0)
#define PT_MA_GETPROTOCOL_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_mutexattr_settype */
#define HANDLE_PTHREAD_MUTEXATTR_SETTYPE(ATTR, TYPE)			\
do {									\
	int status = pthread_mutexattr_settype(ATTR, TYPE);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set type for pthread mutex "	\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "',\n"		\
				"\ttype: '" #TYPE "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_SETTYPE_FAILURE(status));		\
} while (0)
#define PT_MA_SETTYPE_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "Invalid value for 'attr', or invalid value for 'type'."		\
: "unknown")


/* pthread_mutexattr_gettype */
#define HANDLE_PTHREAD_MUTEXATTR_GETTYPE(ATTR, TYPE)			\
do {									\
	int status = pthread_mutexattr_gettype(ATTR, TYPE);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to get type for pthread mutex "	\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "',\n"		\
				"\ttype: '" #TYPE "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_GETTYPE_FAILURE(status));		\
} while (0)
#define PT_MA_GETTYPE_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* if system supports the 'process-shared/pshared' attribute */
#ifdef _POSIX_THREAD_PROCESS_SHARED

/* pthread_mutexattr_getpshared */
#define HANDLE_PTHREAD_MUTEXATTR_GETPSHARED(ATTR, PSHARED)		\
do {									\
	int status = pthread_mutexattr_getpshared(ATTR, PSHARED);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to get 'process-shared' "	\
				"for pthread mutex attribute"		\
				"\e24m]\n\n{\n"				\
				"\tattr:    '" #ATTR    "',\n"		\
				"\tpshared: '" #PSHARED "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_GETPSHARED_FAILURE(status));	\
} while (0)
#define PT_MA_GETPSHARED_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_mutexattr_setpshared */
#define HANDLE_PTHREAD_MUTEXATTR_SETPSHARED(ATTR, PSHARED)		\
do {									\
	int status = pthread_mutexattr_setpshared(ATTR, PSHARED);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'process-shared' "	\
				"for pthread mutex attribute"		\
				"\e24m]\n\n{\n"				\
				"\tattr:    '" #ATTR    "',\n"		\
				"\tpshared: '" #PSHARED "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_MA_SETPSHARED_FAILURE(status));	\
} while (0)
#define PT_MA_SETPSHARED_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The new value specified for the attribute is outside the range of "	\
  "legal values for that attribute."					\
: "unknown")

#endif	/* ifdef _POSIX_THREAD_PROCESS_SHARED */


/* pthread_cond_t
 * ========================================================================== */
/* pthread_cond_init */
#define HANDLE_PTHREAD_COND_INIT(COND, ATTR)				\
do {									\
	int status = pthread_cond_init(COND, ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread "		\
				"condition"				\
				"\e24m]\n\n{\n"				\
				"\tcond: '" #COND "',\n"		\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_INIT_FAILURE(status));		\
} while (0)
#define PT_COND_INIT_FAILURE(STATUS)					\
((STATUS == EAGAIN)							\
? "The system temporarily lacks the resources to create another "	\
  "condition variable."							\
: ((STATUS == EINVAL)							\
? "The value specified by 'attr' is invalid."				\
: ((STATUS == ENOMEM)							\
? "The process cannot allocate enough memory to create another "	\
  "condition variable."							\
: "unknown")))


/* pthread_cond_destroy */
#define HANDLE_PTHREAD_COND_DESTROY(COND)				\
do {									\
	int status = pthread_cond_destroy(COND);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to destroy pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond: '" #COND "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_DESTROY_FAILURE(status));	\
} while (0)
#define PT_COND_DESTROY_FAILURE(STATUS)					\
((STATUS == EBUSY)							\
? "The variable 'cond' is locked by another thread."			\
: ((STATUS == EINVAL)							\
? "The value specified by 'cond' is invalid."				\
: "unknown"))


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
				PT_COND_SIGNAL_FAILURE(status));	\
} while (0)
#define PT_COND_SIGNAL_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "The value specified by 'cond' is invalid."				\
: "unknown")


/* pthread_cond_broadcast */
#define HANDLE_PTHREAD_COND_BROADCAST(COND)				\
do {									\
	int status = pthread_cond_broadcast(COND);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to broadcast pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond: '" #COND "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_BROADCAST_FAILURE(status));	\
} while (0)
#define PT_COND_BROADCAST_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The value specified by 'cond' is invalid."				\
: "unknown")


/* pthread_cond_wait */
#define HANDLE_PTHREAD_COND_WAIT(COND, MUTEX)				\
do {									\
	int status = pthread_cond_wait(COND, MUTEX);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to signal pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond:    '" #COND "',\n"		\
				"\tmutex:   '" #MUTEX "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_WAIT_FAILURE(status));		\
} while (0)
#define PT_COND_WAIT_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "The value specified by 'cond' or the value specified by 'mutex' is "	\
 "invalid."								\
: "unknown")


/* pthread_cond_timedwait */
#define HANDLE_PTHREAD_COND_TIMEDWAIT(COND, MUTEX, ABSTIME)		\
do {									\
	int status = pthread_cond_timedwait(COND, MUTEX, ABSTIME);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to signal pthread condition"	\
				"\e24m]\n\n{\n"				\
				"\tcond:    '" #COND    "',\n"		\
				"\tmutex:   '" #MUTEX   "',\n"		\
				"\tabstime: '" #ABSTIME "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_COND_TIMEDWAIT_FAILURE(status));	\
} while (0)
#define PT_COND_TIMEDWAIT_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The value specified by 'cond', 'mutex' or 'abstime' is invalid."	\
: ((STATUS == ETIMEDOUT)						\
? "The system time has reached or exceeded the time specified in "	\
  "'abstime'."
: "unknown"))


/* pthread_condattr_t
 * ========================================================================== */
/* pthread_condattr_init */
#define HANDLE_PTHREAD_CONDATTR_INIT(ATTR)				\
do {									\
	int status = pthread_condattr_init(ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to initialize pthread "		\
				"condition attribute"			\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_CA_INIT_FAILURE(status));		\
} while (0)
#define PT_CA_INIT_FAILURE(STATUS)					\
((STATUS == EAGAIN)							\
? "Out of memory."							\
: "unknown")


/* pthread_condattr_destroy */
#define HANDLE_PTHREAD_CONDATTR_DESTROY(ATTR)				\
do {									\
	int status = pthread_condattr_destroy(ATTR);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to destroy pthread condition "	\
				"attribute"				\
				"\e24m]\n\n{\n"				\
				"\tattr: '" #ATTR "'\n"			\
				"}\n\n"					\
				"reason: %s",				\
				PT_CA_DESTROY_FAILURE(status));		\
} while (0)
#define PT_CA_DESTROY_FAILURE(STATUS)					\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* if system supports the 'process-shared' or 'pshared' attribute */
#ifdef _POSIX_THREAD_PROCESS_SHARED

/* pthread_condattr_getpshared */
#define HANDLE_PTHREAD_CONDATTR_GETPSHARED(ATTR, PSHARED)		\
do {									\
	int status = pthread_condattr_getpshared(ATTR, PSHARED);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to get 'process-shared' "	\
				"for pthread condtion attribute"	\
				"\e24m]\n\n{\n"				\
				"\tattr:    '" #ATTR "'\n"		\
				"\tpshared: '" #PSHARED "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_CA_GETPSHARED_FAILURE(status));	\
} while (0)
#define PT_CA_GETPSHARED_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "Invalid value for 'attr'."						\
: "unknown")


/* pthread_condattr_setpshared */
#define HANDLE_PTHREAD_CONDATTR_SETPSHARED(ATTR, PSHARED)		\
do {									\
	int status = pthread_condattr_setpshared(ATTR, PSHARED);	\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set 'process-shared' "	\
				"for pthread condition attribute"	\
				"\e24m]\n\n{\n"				\
				"\tattr:    '" #ATTR "'\n"		\
				"\tpshared: '" #PSHARED "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_CA_SETPSHARED_FAILURE(status));	\
} while (0)
#define PT_CA_SETPSHARED_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The new value specified for the attribute is outside the range of "	\
  "legal values for that attribute."					\
: "unknown")

#endif	/* ifdef _POSIX_THREAD_PROCESS_SHARED */


/* cancelability
 * ========================================================================== */
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
				PT_SETCANCELTYPE_FAILURE(status));	\
} while (0)
#define PT_SETCANCELTYPE_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The specified state is not 'PTHREAD_CANCEL_DEFERRED' or "		\
  "'PTHREAD_CANCEL_ASYNCHRONOUS'."					\
: "unknown")



/* pthread_setcancelstate */
#define HANDLE_PTHREAD_SETCANCELSTATE(TYPE, OLDSTATE)			\
do {									\
	int status = pthread_setcancelstate(TYPE, OLDSTATE);		\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to set pthread cancel state"	\
				"\e24m]\n\n{\n"				\
				"\ttype:     '" #TYPE	"'\n"		\
				"\toldstate: '" #OLDSTATE "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				PT_SETCANCELSTATE_FAILURE(status));	\
} while (0)
#define PT_SETCANCELSTATE_FAILURE(STATUS)				\
((STATUS == EINVAL)							\
? "The specified state is not 'PTHREAD_CANCEL_ENABLE' or "		\
  "'PTHREAD_CANCEL_ASYNCHRONOUS'."					\
: "unknown")

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef PARALLEL_PTHREAD_H_ */
