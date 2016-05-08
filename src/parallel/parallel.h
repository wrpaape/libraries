#ifndef PARALLEL_PARALLEL_H
#define PARALLEL_PARALLEL_H

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* error handling, misc convenience functions */
#include <time.h>		/* time types, structs, functions */
#include <pthread.h>		/* pthead API */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* error handlers
 * ========================================================================== */
/* pthread_create */
#define HANDLE_PTHREAD_CREATE(THREAD, ATTR, ROUTINE, ARG)		\
do {									\
	int code = pthread_create(THREAD, ATTR, ROUTINE, ARG);		\
	if (code != 0)							\
		EXIT_ON_FAILURE("failed to create pthread\e24m]\n\n{\n"	\
				"\tthread:        '" #THREAD "'\n"	\
				"\tattr:          '" #ATTR "'\n"	\
				"\tstart_routine: '" #ROUTINE "'\n"	\
				"\targ:           '" #ARG "'\n}\n\n"	\
				"reason: %s",				\
				PT_CREATE_FAILURE_REASON(code));	\
} while (0)
#define PT_CREATE_FAILURE_REASON(CODE)				\
((CODE == EAGAIN)							\
? "The system lacked the necessary resources to create another thread"	\
  ", or the system-imposed limit on the total number of threads in a "	\
  "process [PTHREAD_THREADS_MAX] would be exceeded."			\
: ((CODE == EINVAL)							\
? "The value specified by attr is invalid."				\
: "unknown"))

/* pthread_join */
#define HANDLE_PTHREAD_JOIN(THREAD, VALUE_PTR)				\
do {									\
	int code = pthread_join(THREAD, VALUE_PTR);			\
	if (code != 0)							\
		EXIT_ON_FAILURE("failed to join pthread\e24m]\n\n{\n"	\
				"\tthread:    '" #THREAD "'\n"		\
				"\tvalue_ptr: '" #VALUE_PTR "'\n}\n\n"	\
				"reason: %s",				\
				PT_JOIN_FAILURE_REASON(code));		\
} while (0)
#define PT_JOIN_FAILURE_REASON(CODE)				\
((CODE == EDEADLK)							\
? "A deadlock was detected or the value of thread specifies the "	\
  "calling thread."							\
: ((CODE == EINVAL)							\
? "The implementation has detected that the value specified by thread "	\
  "does not refer to a joinable thread."				\
: ((CODE == ESRCH)							\
? "No thread could be found corresponding to that specified by the "	\
  "given thread ID, thread."						\
: "unknown")))


/* pthread_setcanceltype */
#define HANDLE_PTHREAD_SETCANCELTYPE(TYPE, OLDTYPE)			\
do {									\
	int code = pthread_setcanceltype(TYPE, OLDTYPE);		\
	if (code != 0)							\
		EXIT_ON_FAILURE("failed to set pthread cancel type"	\
				"\e24m]\n\n{\n"				\
				"\ttype:    '" #TYPE "'\n"		\
				"\toldtype: '" #OLDTYPE "'\n}\n\n"	\
				"reason: %s",				\
				PT_SETCANCELTYPE_FAILURE_REASON(code));	\
} while (0)
#define PT_SETCANCELTYPE_FAILURE_REASON(CODE)				\
((CODE == EINVAL)							\
? "The specified state is not 'PTHREAD_CANCEL_DEFERRED' or "		\
  "'PTHREAD_CANCEL_ASYNCHRONOUS'."					\
: "unknown")))

/* #define HANDLE_TIMEOUT(FORMAT, ...) */

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */


inline void *parallel_timeout(void *timeout)
{
	return (void *) nanosleep((struct timespec *) timeout, NULL);
}



#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef PARALLEL_PARALLEL_H */