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

#include <utils/utils.h>	/* EXIT_ON_FAILURE, FILE/stream API */
#include <unistd.h>		/* getcwd, STDOUT/IN/ERR_FILENO */
#include <sys/stat.h>		/* mkdir */
#include <sys/param.h>		/* MAXPATHLEN */

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
     /* The flags specified for the oflag argument are formed by or'ing the following values: */

     /*       O_RDONLY        open for reading only */
     /*       O_WRONLY        open for writing only */
     /*       O_RDWR          open for reading and writing */
     /*       O_NONBLOCK      do not block on open or for data to become available */
     /*       O_APPEND        append on each write */
     /*       O_CREAT         create file if it does not exist */
     /*       O_TRUNC         truncate size to 0 */
     /*       O_EXCL          error if O_CREAT and the file exists */
     /*       O_SHLOCK        atomically obtain a shared lock */
     /*       O_EXLOCK        atomically obtain an exclusive lock */
     /*       O_NOFOLLOW      do not follow symlinks */
     /*       O_SYMLINK       allow open of symlinks */
     /*       O_EVTONLY       descriptor requested for event notifications only */
     /*       O_CLOEXEC       mark as close-on-exec */
/* open */
#define OPEN_FAILURE(ERRNO)						\
  ((ERRNO == EACCES)							\
? "(one of the following)\n"						\
  "\t- Search permission is denied for a component of the path prefix."	\
  "\t- The required permissions (for reading and/or writing) are "	\
  "denied for the given flags."
  "\t- 'O_CREAT' is specified, the file does not exist, and the directory in which it is to be created does not permit writing."
  
  ((ERRNO == EACCES]           O_TRUNC is specified and write permission is denied.
  
  ((ERRNO == EAGAIN]           path specifies the slave side of a locked pseudo-terminal device.
  
  ((ERRNO == EDQUOT]           O_CREAT is specified, the file does not exist, and the directory in which the entry for the new file is being placed cannot be extended because the user's quota of disk blocks on the file system containing the directory
  		has been exhausted.
  
: ((ERRNO == EDQUOT]           O_CREAT is specified, the file does not exist, and the user's quota of inodes on the file system on which the file is being created has been exhausted.
  
: ((ERRNO == EEXIST]           O_CREAT and O_EXCL are specified and the file exists.
  
: ((ERRNO == EFAULT]           Path points outside the process's allocated address space.
  
: ((ERRNO == EINTR]            The open() operation is interrupted by a signal.
  
: ((ERRNO == EINVAL]           The value of oflag is not valid.
  
: ((ERRNO == EIO]              An I/O error occurs while making the directory entry or allocating the inode for O_CREAT.
  
: ((ERRNO == EISDIR]           The named file is a directory, and the arguments specify that it is to be opened for writing.
  
: ((ERRNO == ELOOP]            Too many symbolic links are encountered in translating the pathname.  This is taken to be indicative of a looping symbolic link.
  
: ((ERRNO == EMFILE]           The process has already reached its limit for open file descriptors.
  
: ((ERRNO == ENAMETOOLONG]     A component of a pathname exceeds {NAME_MAX} characters, or an entire path name exceeded {PATH_MAX} characters.
  
: ((ERRNO == ENFILE]           The system file table is full.
  
: ((ERRNO == ELOOP]            O_NOFOLLOW was specified and the target is a symbolic link.
  
: ((ERRNO == ENOENT]           O_CREAT is not set and the named file does not exist.
  
: ((ERRNO == ENOENT]           A component of the path name that must exist does not exist.
  
: ((ERRNO == ENOSPC]           O_CREAT is specified, the file does not exist, and the directory in which the entry for the new file is being placed cannot be extended because there is no space left on the file system containing the directory.
  
: ((ERRNO == ENOSPC]           O_CREAT is specified, the file does not exist, and there are no free inodes on the file system on which the file is being created.
  
: ((ERRNO == ENOTDIR]          A component of the path prefix is not a directory.
  
: ((ERRNO == ENXIO]            The named file is a character-special or block-special file and the device associated with this special file does not exist.
  
: ((ERRNO == ENXIO]            O_NONBLOCK and O_WRONLY are set, the file is a FIFO, and no process has it open for reading.
  
: ((ERRNO == EOPNOTSUPP]       O_SHLOCK or O_EXLOCK is specified, but the underlying filesystem does not support locking.
  
: ((ERRNO == EOPNOTSUPP]       An attempt is made to open a socket (not currently implemented).
  
: ((ERRNO == EOVERFLOW]        The named file is a regular file and its size does not fit in an object of type off_t.
  
: ((ERRNO == EROFS]            The named file resides on a read-only file system, and the file is to be modified.
  
: ((ERRNO == ETXTBSY]          The file is a pure procedure (shared text) file that is being executed and the open() call requests write access.
  
: ((ERRNO == EBADF]            The path argument does not specify an absolute path and the fd argument is neither AT_FDCWD nor a valid file descriptor open for searching.
  
: ((ERRNO == ENOTDIR]          The path argument is not an absolute path and fd is neither AT_FDCWD nor a file descriptor associated with a directory.

/* close */
#define HANDLE_CLOSE(FILDES)
do {									\
	if (close(FILDES) == -1)					\
		EXIT_ON_FAILURE("failed to close file"			\
				"\e24m]\n\n{\n"				\
				"\tfildes: '" #FILDES "',\n"		\
				"}\n\n"					\
				"reason: %s",				\
				CLOSE_FAILURE(errno));			\
} while (0)
#define CLOSE_FAILURE(ERRNO)						\
  ((ERRNO == EBADF)							\
? "'fildes' is not a valid, active file descriptor."			\
: ((ERRNO == EINTR)							\
? "Execution was interrupted by a signal."				\
: ((ERRNO == EIO)							\
? "A previously-uncommitted write(2) encountered an input/output "	\
  "error."								\
: "unknown")))


/* fopen */
#define HANDLE_FOPEN(STREAM, FILENAME, MODE)				\
do {									\
	STREAM = fopen(FILENAME, MODE);					\
	if (STREAM == NULL_POINTER)					\
		EXIT_ON_FAILURE("failed to open file"			\
				"\e24m]\n\n{\n"				\
				"\tstream:   '" #STREAM   "' (%p),\n"	\
				"\tfilename: '" #FILENAME "' (%s),\n"	\
				"\tmode:     '" #MODE     "' (%s)\n"	\
				"}\n\n"					\
				"reason: %s",				\
				STREAM,					\
				FILENAME,				\
				MODE,					\
				FOPEN_FAILURE(errno));			\
} while (0)
#define FOPEN_FAILURE(ERRNO)						\
  ((ERRNO == EINVAL)							\
? "invalid 'mode' argument"						\
: OPEN_FAILURE(ERRNO))

/* fdopen */
#define HANDLE_FDOPEN(STREAM, FILENAME, MODE)				\
do {									\
	STREAM = fdopen(FILENAME, MODE);				\
	if (STREAM == NULL_POINTER)					\
		EXIT_ON_FAILURE("failed to open file"			\
				"\e24m]\n\n{\n"				\
				"\tstream: '" #STREAM "' (%p),\n"	\
				"\tfildes: '" #FILDES "' (%d),\n"	\
				"\tmode:   '" #MODE   "' (%s)\n"	\
				"}\n\n"					\
				"reason: %s",				\
				STREAM,					\
				FILDES,					\
				MODE,					\
				FDOPEN_FAILURE(errno));			\
} while (0)
#define FDOPEN_FAILURE(ERRNO) FOPEN_FAILURE(ERRNO)

/* freopen */
#define HANDLE_FREOPEN(STREAM, FILENAME, MODE)				\
do {									\
	STREAM = freopen(FILENAME, MODE, STREAM);			\
	if (STREAM == NULL_POINTER)					\
		EXIT_ON_FAILURE("failed to reopen file"			\
				"\e24m]\n\n{\n"				\
				"\tstream:   '" #STREAM   "' (%p),\n"	\
				"\tfilename: '" #FILENAME "' (%s),\n"	\
				"\tmode:     '" #MODE     "' (%s)\n"	\
				"}\n\n"					\
				"reason: %s",				\
				STREAM,					\
				FILENAME,				\
				MODE,					\
				FOPEN_FAILURE(errno));			\
} while (0)
#define FREOPEN_FAILURE(ERRNO) FOPEN_FAILURE(ERRNO)


/* fclose */
#define HANDLE_FCLOSE(STREAM)						\
do {									\
	if (fclose(STREAM) == NULL_POINTER)				\
		EXIT_ON_FAILURE("failed to close file"			\
				"\e24m]\n\n{\n"				\
				"\tstream: '" #STREAM "' (%p),\n"	\
				"}\n\n"					\
				"reason: %s",				\
				STREAM,					\
				FCLOSE_FAILURE(errno));			\
} while (0)
#define FCLOSE_FAILURE(ERRNO) CLOSE_FAILURE(ERRNO)


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


#define STREAM_GETV(GETV, GET_TYPE, RES, STREAM)			\
do {									\
	RES = (__typeof__(RES)) GETV(STREAM);				\
	if (RES == EOF) {						\
		if (ferror(STREAM))					\
			STREAM_GETV_EXIT(GET_TYPE, "IO");		\
		if (!feof(STREAM))					\
			STREAM_GETV_EXIT(GET_TYPE, "format");		\
	}
} while (0)

/* fgetc, getc, getw */
#define HANDLE_FGETC(RES, STREAM) STREAM_GETV(fgetc, "char",	    RES, STREAM)
#define HANDLE_GETC(RES,  STREAM) STREAM_GETV(getc,  "char",	    RES, STREAM)
#define HANDLE_GETW(RES,  STREAM) STREAM_GETV(getw,  "wchar (int)", RES, STREAM)

/* getc_unlocked */
#define HANDLE_GETC_UNLOCKED(RES, STREAM) STREAM_GETV(getc_unlocked,	\
						      "char",		\
						      RES,		\
						      STREAM)

/* getchar, getchar_unlocked */
#define HANDLE_GETCHAR(RES)	     HANDLE_GETC(RES, stdin)
#define HANDLE_GETCHAR_UNLOCKED(RES) HANDLE_GETC_UNLOCKED(RES, stdin)



/* getcwd */
#define HANDLE_GETCWD(BUF, SIZE)					\
do {									\
	if (getcwd(BUF, SIZE) == NULL_POINTER)				\
		EXIT_ON_FAILURE("failed to get current working"		\
				"directory",				\
				"\e24m]\n\n{\n"				\
				"\tbuf:  '" #BUF  "',\n"		\
				"\tsize: '" #SIZE "'\n"			\
				"}\n\n"					\
				"reason: %s\n\n"			\
				"buf contents: %s",			\
				GETCWD_FAILURE(errno),			\
				BUF);					\
} while (0)
#define GETCWD_FAILURE(ERRNO)						\
  ((ERRNO == EACCES)							\
? "Read or search permission was denied for a component of the "	\
   "pathname."								\
: ((ERRNO == EINVAL)							\
? "The 'size' argument is zero."					\
: ((ERRNO == ENOENT)							\
? "A component of the pathname no longer exists."			\
: ((ERRNO == ENOMEM)							\
? "Insufficient memory is available."					\
: ((ERRNO == ERANGE)							\
? "The 'size' argument is greater than zero but smaller than the "	\
   "length of the pathname plus 1."					\
: "unknown")))))


/* mkdir */
#define HANDLE_MKDIR(FILENAME, MODE)					\
do {									\
	if (mkdir(FILENAME, MODE) == -1)				\
		EXIT_ON_FAILURE("failed to make directory"		\
				"\e24m]\n\n{\n"				\
				"\tfilename: %s\n"			\
				"\tmode:     %s\n"			\
				"}\n\n"					\
				"reason: %s",				\
				FILENAME,				\
				PERMISSION(MODE),			\
				MKDIR_FAILURE(errno));			\
} while (0)
#define MKDIR_FAILURE(ERRNO)						\
  ((ERRNO == EACCES)							\
? "Write permission is denied for the parent directory in which the "	\
  "new directory is to be added."					\
: ((ERRNO == EEXIST)							\
? "A file named 'filename' already exists."				\
: ((ERRNO == EMLINK)							\
? "The parent directory has too many links (entries).\n\n "		\
  "Well-designed file systems never report this error, because they "	\
  "permit more links than your disk could possibly hold. However, you "	\
  "must still take account of the possibility of this error, as it "	\
  "could result from network access to a file system on another "	\
  "machine."								\
: ((ERRNO == ENOSPC)							\
? "The file system doesn’t have enough room to create the new "		\
  "directory."								\
: ((ERRNO == EROFS)							\
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




/* compound macros
 * ========================================================================== */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

inline void fildes_write_all(const int fildes,
			     const char *restrict contents)
{
	FILE *restrict file;
	HANDLE_FDOPEN(file, fildes, "w");
	HANDLE_FPUTS(contents, file);
	HANDLE_FCLOSE(file);
}

inline void filename_write_all(const char *restrict filename,
			       const char *restrict contents)
{
	FILE *restrict file;
	HANDLE_FOPEN(file, filename, "w");
	HANDLE_FPUTS(contents, file);
	HANDLE_FCLOSE(file);
}

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS */



#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef SYSTEM_UTILS_FILE_UTILS_H_ */
