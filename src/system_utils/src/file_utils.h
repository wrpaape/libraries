#ifndef SYSTEM_UTILS_FILE_UTILS_H_
#define SYSTEM_UTILS_FILE_UTILS_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#	ifndef restrict /* use c++ compatible '__restrict__' */
#		define restrict __restrict__
#	endif
#	ifndef NULL_POINTER /* use c++ null pointer macro */
#		define NULL_POINTER nullptr
#	endif
#else
#	ifndef NULL_POINTER /* use traditional c null pointer macro */
#		define NULL_POINTER NULL
#	endif
#endif

/* EXTERNAL DEPENDENCIES ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <utils/utils.h>	/* EXIT_ON_FAILURE */
#include <unistd.h>		/* getcwd */
#include <sys/param.h>		/* MAXPATHLEN */
#include <sys/stat.h>		/* mkdir */

/* EXTERNAL DEPENDENCIES ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

/* CONSTANTS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* CONSTANTS ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ */

/* FUNCTION-LIKE MACROS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define PUT_SLASH(PTR)	\
do {			\
	*PTR = '/';	\
	++PTR;		\
} while (0)


/* error handlers
 * ========================================================================== */
/* fopen */
#define HANDLE_FOPEN(STREAM, FILENAME, MODE)				\
do {									\
	STREAM = fopen(FILENAME, MODE);					\
	if (STREAM == NULL_POINTER)					\
		EXIT_ON_FAILURE("failed to open file"			\
				"\e24m]\n\n{\n"				\
				"\tstream:   '" #STREAM "',\n"		\
				"\tfilename: %s,\n"			\
				"\tmode:     %s\n"			\
				"}\n\n"					\
				"reason: %s",				\
				FILENAME,				\
				MODE,					\
				FOPEN_FAILURE(errno));			\
} while (0)
#define FOPEN_FAILURE(ERRNO)						\
  ((ERRNO == EINVAL)							\
? "invalid 'mode' argument"						\
: "unknown")


/* fgets */
#define HANDLE_FGETS(STR, SIZE, STREAM)					\
do {									\
	const char *const restrict _str_ptr = fgets(STR,		\
						    (int) SIZE,		\
						    STREAM);		\
	 if ((_str_ptr == NULL_POINTER) && (ferror(STREAM) != 0))	\
		EXIT_ON_FAILURE("failed to open file"			\
				"\e24m]\n\n{\n"				\
				"\tstr:    '" #STR    "',\n"		\
				"\tsize:   %d,\n"			\
				"\tstream: '" #STREAM "'\n"		\
				"}\n\n"					\
				"reason: %s",				\
				(int) SIZE,				\
				STREAM_GET_FAILURE(errno));		\
} while (0)
#define STREAM_GET_FAILURE(ERRNO)					\
  ((ERRNO == EBADF)							\
? "The given 'stream' is not a readable stream."			\
: "unknown")


#define STREAM_GETV_EXIT(GET_TYPE, FAIL_TYPE)				\
EXIT_ON_FAILURE("failed to get next " GET_TYPE " (" FAIL_TYPE " error)"	\
		"\e24m]\n\n{\n"						\
		"\tres:    '" #RES    "',\n"				\
		"\tstream: '" #STREAM "'\n"				\
		"}\n\n"							\
		"reason: %s",						\
		STREAM_GET_FAILURE(errno))				\

#define STREAM_GETV(GETV, TYPE, RES, STREAM)				\
do {									\
	RES = (__typeof__(RES)) GETV(STREAM);				\
	if (RES == EOF) {						\
		if (ferror(STREAM))					\
			STREAM_GETV_EXIT(GET_TYPE, "IO");		\
		if (!feof(STREAM))					\
			STREAM_GETV_EXIT(GET_TYPE, "format");		\
	}
} while (0)

/* fgetc, getc, getchar, getw */
/* getc */
#define HANDLE_FGETC(RES, STREAM) STREAM_GET(fgetc, "char",	   RES, STREAM)
#define HANDLE_GETC(RES, STREAM)  STREAM_GET(getc,  "char",	   RES, STREAM)
#define HANDLE_GETW(RES, STREAM)  STREAM_GET(getw,  "wchar (int)", RES, STREAM)
#define HANDLE_GETCHAR(RES) HANDLE_GETC(RES, stdin)

#define HANDLE_GETC_UNLOCKED(RES, STREAM)  STREAM_GET(getc_unlocked,  "char",	   RES, STREAM)

 The fgetc() function obtains the next input character (if present) from the stream pointed at by stream, or the next character pushed back on the stream via ungetc(3).

     The getc() function acts essentially identically to fgetc(), but is a macro that expands in-line.

     The getchar() function is equivalent to getc(stdin).

     The getw() function obtains the next int (if present) from the stream pointed at by stream.




/* getcwd */
#define HANDLE_GETCWD(BUF, SIZE)					\
do {									\
	const char *const restrict _buf_ptr = getcwd(BUF, SIZE);	\
	if (_buf_ptr == NULL_POINTER)					\
		EXIT_ON_FAILURE("failed to get current working"		\
				"directory",				\
				"\e24m]\n\n{\n"				\
				"\tbuf:  '" #BUF  "',\n"		\
				"\tsize: '" #SIZE "'\n"			\
				"}\n\n"					\
				"reason: %s\n\n"			\
				"buf contents: %s",			\
				GETCWD_FAILURE(status),			\
				BUF);					\
} while (0)
#define GETCWD_FAILURE(STATUS)						\
  ((STATUS == EACCES)							\
? "Read or search permission was denied for a component of the "	\
   "pathname."								\
: ((STATUS == EINVAL)							\
? "The 'size' argument is zero."					\
: ((STATUS == ENOENT)							\
? "A component of the pathname no longer exists."			\
: ((STATUS == ENOMEM)							\
? "Insufficient memory is available."					\
: ((STATUS == ERANGE)							\
? "The 'size' argument is greater than zero but smaller than the "	\
   "length of the pathname plus 1."					\
: "unknown")))))


/* mkdir */
#define HANDLE_MKDIR(FILENAME, MODE)					\
do {									\
	const int status = mkdir(FILENAME, MODE);			\
	if (status != 0)						\
		EXIT_ON_FAILURE("failed to make directory"		\
				"\e24m]\n\n{\n"				\
				"\tfilename: %s\n"			\
				"\tmode:     %s\n"			\
				"}\n\n"					\
				"reason: %s",				\
				FILENAME,				\
				PERMISSION(MODE),			\
				MKDIR_FAILURE(status));			\
} while (0)
#define MKDIR_FAILURE(STATUS)						\
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

#endif /* ifndef SYSTEM_UTILS_FILE_UTILS_H_ */
