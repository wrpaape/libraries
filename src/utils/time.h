#ifndef UTILS_TIME_H_
#define UTILS_TIME_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

/* taken from stackoverflow user 'jbenet''s answer to
 * https://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x
 * https://gist.github.com/jbenet/1087739A (source) */


inline void get_real_time(struct timespec *restrict time)
{
#ifdef __MACH__ /* OS X does not have clock_gettime, use clock_get_time */
	clock_serv_t calendar_clock;
	mach_timespec_t mach_time;

	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &calendar_clock);

	clock_get_time(calendar_clock, &mach_time);

	mach_port_deallocate(mach_task_self(), calendar_clock);

	time->tv_sec  = mach_time.tv_sec;
	time->tv_nsec = mach_time.tv_nsec;
#else
	clock_gettime(CLOCK_REALTIME, time);
#endif
}


inline void set_time_limit(struct timespec *restrict time_limit,
			   const struct timespec *restrict timeout)
{
	get_real_time(time_limit);

	time_limit->tv_sec  += timeout->tv_sec;
	time_limit->tv_nsec += timeout->tv_nsec;
}



#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_TIME_H_ */
