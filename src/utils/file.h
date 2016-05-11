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

/* CONSTANTS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define DEFAULT_PERMISSIONS S_IRWXU

/* CONSTANTS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

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
				"mode:\n%s\n\n%s", FILENAME,		\
				PERMISSION(MODE),			\
				HANDLE_MKDIR_FAILURE(status));		\
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



/* string description for permission bits 'MODE' */
#define PERMISSION(MODE)						\
  (((MODE == S_IRUSR) || (MODE == S_IREAD))				\
? "'S_ISRUSR' - Read permission bit for the owner of the file. On many"	\
  " systems this bit is 0400. 'S_IREAD' is an obsolete synonym "	\
  "provided for BSD compatibility."					\
: (((MODE == S_IWUSR) || (MODE == S_IWRITE))				\
? "'S_IWUSR' - Write permission bit for the owner of the file. Usually"	\
  " 0200. 'S_IWRITE' is an obsolete synonym provided for BSD "		\
  "compatibility."							\
: (((MODE == S_IXUSR) || (MODE == S_IEXEC))				\
? "'S_IXUSR' - Execute (for ordinary files) or search (for "		\
  "directories) permission bit for the owner of the file. Usually "	\
  "0100. 'S_IEXEC' is an obsolete synonym provided for BSD "		\
  "compatibility."							\
: ((MODE == S_IRWXU)							\
? "'S_IRWXU' - This is equivalent to ‘(S_IRUSR | S_IWUSR | S_IXUSR)’."	\
: ((MODE == S_IRGRP)							\
? "'S_IRGRP' - Read permission bit for the group owner of the file. "	\
  "Usually 040."							\
: ((MODE == S_IWGRP)							\
? "'S_IWGRP' - Write permission bit for the group owner of the file. "	\
  "Usually 020."							\
: ((MODE == S_IXGRP)							\
? "'S_IXGRP' - Execute or search permission bit for the group owner of"	\
" the file. Usually 010.)"						\
: ((MODE == S_IRWXG)							\
? "'S_IRWXG' - This is equivalent to ‘(S_IRGRP | S_IWGRP | S_IXGRP)’."	\
: ((MODE == S_IROTH)							\
? "'S_IROTH' - Read permission bit for other users. Usually 04."	\
: ((MODE == S_IWOTH)							\
? "'S_IWOTH' - Write permission bit for other users. Usually 02."	\
: ((MODE == S_IXOTH)							\
? "'S_IXOTH' - Execute or search permission bit for other users. "	\
   "Usually 01."							\
: ((MODE == S_IRWXO)							\
? "'S_IRWXO' - This is equivalent to ‘(S_IROTH | S_IWOTH | S_IXOTH)’."	\
: ((MODE == S_ISUID)							\
? "'S_ISUID' - This is the set-user-ID on execute bit, usually 04000."	\
: ((MODE == S_ISGID)							\
? "'S_ISGID' - This is the set-group-ID on execute bit, usually 02000."	\
: ((MODE == S_ISVTX)							\
? "'S_ISVTX' - This is the sticky bit, usually 01000."			\
: "unknown")))))))))))))))

/* FUNCTION-LIKE MACROS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef UTILS_FILE_H_ */
