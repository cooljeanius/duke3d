dnl#                                               -*- Autoconf -*-
dnl# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.70])
AC_AUTOCONF_VERSION
AC_INIT([duke3d],[0.1])
AC_CONFIG_SRCDIR([_animlib.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AC_USE_SYSTEM_EXTENSIONS
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AX_CHECK_GNU_MAKE
AC_LANG([C])dnl

# Checks for programs.
AC_USE_SYSTEM_EXTENSIONS
AM_PROG_AR
AM_PROG_AS
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_GCC_TRADITIONAL
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AX_PERL_EXT
AX_SYS_PERLSHARPBANG
AC_PROG_RANLIB
AC_EXEEXT
AC_PATH_PROG([NASM],[nasm])
LT_INIT([win32-dll])dnl

# Checks for libraries.
AM_PATH_SDL
# FIXME: Replace `main' with a function in `-lSDL':
AC_CHECK_LIB([SDL],[main])
# FIXME: Replace `main' with a function in `-lSDL_mixer':
AC_CHECK_LIB([SDL_mixer],[main])
# FIXME: Replace `main' with a function in `-lSDLmain':
AC_CHECK_LIB([SDLmain],[main])
# FIXME: Replace `main' with a function in `-lnsl':
AC_CHECK_LIB([nsl],[main])
# FIXME: Replace `main' with a function in `-lphysfs':
AC_CHECK_LIB([physfs],[main])
# FIXME: Replace `main' with a function in `-lsocket':
AC_CHECK_LIB([socket],[main])dnl

# Checks for header files.
dnl# autoupdate says:
dnl# The preprocessor macro `STDC_HEADERS' is obsolete.
dnl# Except in unusual embedded environments, you can safely include all
dnl# ISO C90 headers unconditionally.
# Autoupdate added the next few lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
AC_CHECK_INCLUDES_DEFAULT
if test "x${EGREP}" = "x"; then
  test -z "${EGREP}"
  AC_PROG_EGREP
fi
AC_CHECK_HEADERS([arpa/inet.h endian.h fcntl.h limits.h machine/endian.h \
                  malloc.h malloc/malloc.h memory.h netdb.h netinet/in.h \
                  platform.h stddef.h stdio.h stdlib.h string.h sys/ioctl.h \
                  sys/param.h sys/socket.h sys/time.h unistd.h])dnl

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([atexit getcwd memmove memset mkdir pow putenv realpath socket \
                strcasecmp strchr strerror strncasecmp strrchr strstr \
                strtol])dnl

# Output.
AC_CONFIG_FILES([Makefile
                 Makefile_orig
                 audiolib/Makefile_orig
                 buildengine/Makefile_orig
                 buildengine/tests/Makefile_orig
                 buildengine/utils/Makefile_orig])
AC_OUTPUT
