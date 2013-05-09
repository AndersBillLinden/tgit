#ifndef __MSVC__HEAD
#define __MSVC__HEAD

#include <direct.h>
#include <process.h>
#include <malloc.h>
#include <io.h>

/* porting function */
#define inline __inline
#define __inline__ __inline
#define __attribute__(x)
#define strncasecmp  _strnicmp
#define ftruncate    _chsize

static __inline int strcasecmp (const char *s1, const char *s2)
{
	int size1 = strlen(s1);
	int sisz2 = strlen(s2);
	return _strnicmp(s1, s2, sisz2 > size1 ? sisz2 : size1);
}

#undef ERROR

/* Use mingw_lstat() instead of lstat()/stat() and mingw_fstat() instead
 * of fstat(). We add the declaration of these functions here, suppressing
 * the corresponding declarations in mingw.h, so that we can use the
 * appropriate structure type (and function) names from the msvc headers.
 */
#define stat _stat64
int mingw_lstat(const char *file_name, struct stat *buf);
int mingw_fstat(int fd, struct stat *buf);
#define fstat mingw_fstat
#define lstat mingw_lstat
#define _stat64(x,y) mingw_lstat(x,y)
#define ALREADY_DECLARED_STAT_FUNCS

#include "mingw.h"

#undef ALREADY_DECLARED_STAT_FUNCS

/* Git runtime infomation */
#define RUNTIME_PREFIX
#define PREFIX "."
#define BINDIR "bin"

#define SHA1_HEADER "block-sha1\\sha1.h"

#define ETC_GITCONFIG "etc\\config"
#define ETC_GITATTRIBUTES "etc\\gitattributes"
#define GIT_EXEC_PATH "bin"
#define GIT_MAN_PATH "man"
#define GIT_INFO_PATH "info"
#define GIT_HTML_PATH "doc\\git\\html"
#define DEFAULT_GIT_TEMPLATE_DIR "share\\git-core\\templates"
#endif

/* Git version infomation */
#ifndef __MSVC__VERSION
#define __MSVC__VERSION
#define GIT_VERSION "1.8.2.2"
#define GIT_USER_AGENT "git/" GIT_VERSION
#endif
