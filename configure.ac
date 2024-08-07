dnl#                                               -*- Autoconf -*-
dnl# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([duke3d], [1.5])
AC_CONFIG_SRCDIR([extras/_animlib.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_LIB([c],[printf])dnl

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h limits.h malloc.h stdlib.h string.h])dnl

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memmove memset sqrt strchr])dnl

# Output.
AC_CONFIG_FILES([Makefile])
AC_CONFIG_SUBDIRS([source])
AC_OUTPUT
