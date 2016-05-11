#ifndef UTILS_FILE_H_
#define UTILS_FILE_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* EXIT_ON_FAILURE */
#include <unistd.h>		/* getcwd */
#include <sys/param.h>		/* MAXPATHLEN */
#include <sys/stat.h>		/* mkdir */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define PUT_SLASH(PTR)	\
do {			\
	*PTR = '/';	\
	++PTR;		\
} while (0)


/* error handlers
 * ========================================================================== */
#ifdef __cplusplus /* for c++ files */
/* fopen */
#define HANDLE_FOPEN(FILE_PTR, FILENAME, MODE)				\
do {									\
	FILE_PTR = fopen(FILENAME, MODE);				\
	if (FILE_PTR == nullptr)					\
		EXIT_ON_FAILURE("failed to open file \"%s\" for '"	\
				#FILE_PTR "' in mode \"%s\"", FILENAME,	\
				MODE);					\
} while (0)

/* getcwd */
#define HANDLE_GETCWD(CWD)						\
do {									\
	char buf[MAXPATHLEN];						\
	CWD = getcwd(&buf[0], sizeof(buf));				\
	if (CWD == nullptr)						\
		EXIT_ON_FAILURE("failed to get current working "	\
				"directory:\n%s",			\
				&buf[0]);				\
} while (0)

#else	/* for c files */

/* fopen */
#define HANDLE_FOPEN(FILE_PTR, FILENAME, MODE)				\
do {									\
	FILE_PTR = fopen(FILENAME, MODE);				\
	if (FILE_PTR == NULL)						\
		EXIT_ON_FAILURE("failed to open file \"%s\" for '"	\
				#FILE_PTR "' in mode \"%s\"", FILENAME,	\
				MODE);					\
} while (0)

/* getcwd */
#define HANDLE_GETCWD(CWD)						\
do {									\
	char buf[MAXPATHLEN];						\
	CWD = getcwd(&buf[0], sizeof(buf));				\
	if (CWD == NULL)						\
		EXIT_ON_FAILURE("failed to get current working "	\
				"directory:\n%s",			\
				&buf[0]);				\
} while (0)
#endif	/* ifdef __cplusplus */


/* mkdir */
#define HANDLE_MKDIR(FILENAME, MODE)					\
do {									\
	int status = mkdir(FILENAME, MODE);				\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to make directory \"%s\" in "	\
				"mode \"%s\":\n%s", FILENAME, MODE,	\
				HANDLE_MKDIR_FAILURE(STATUS));		\
} while (0)
#define HANDLE_MKDIR_FAILURE(STATUS)					\
  ((STATUS == EACCES)							\
? "Write permission is denied for the parent directory in which the "	\
  "new directory is to be added."					\
: ((STATUS == EEXIST)							\
? "A file named 'filename' already exists."				\
: ((STATUS == EMLINK)							\
? "The parent directory has too many links (entries).\n\n "		\
  "Well-designed file systems never report this error, because they "	\
  "permit more links than your disk could possibly hold. However, you "	\
  "must still take account of the possibility of this error, as it "	\
  "could result from network access to a file system on another "	\
  "machine."								\
: ((STATUS == ENOSPC)							\
? "The file system doesn’t have enough room to create the new "		\
  "directory."								\
: ((STATUS == EROFS)							\
? "The parent directory of the directory being created is on a "	\
  "read-only file system and cannot be modified."			\
: "unknown")))))

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_FILE_H_ */
