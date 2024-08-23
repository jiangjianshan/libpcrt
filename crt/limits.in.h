/*
 * Port from mingw-w64-headers/crt/limits.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#pragma once
#include "@NEXT_LIMITS_H@"

#include <vcruntime.h>

/*
 * File system limits
 *
 * NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
 *       required for the NUL. TODO: Test?
 * NOTE: PATH_MAX is the POSIX equivalent for Microsoft's MAX_PATH; the two
 *       are semantically identical, with a limit of 259 characters for the
 *       path name, plus one for a terminating NUL, for a total of 260.
 */
#define PATH_MAX	260

#if defined(__GNUC__)
#undef LONG_LONG_MAX
#define LONG_LONG_MAX 9223372036854775807ll
#undef LONG_LONG_MIN
#define LONG_LONG_MIN (-LONG_LONG_MAX-1)
#undef ULONG_LONG_MAX
#define ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#endif

#ifndef SSIZE_MAX
#ifdef _WIN64
#define SSIZE_MAX _I64_MAX
#else
#define SSIZE_MAX INT_MAX
#endif
#endif

#ifdef _POSIX_
#define _POSIX_ARG_MAX 4096
#define _POSIX_CHILD_MAX 6
#define _POSIX_LINK_MAX 8
#define _POSIX_MAX_CANON 255
#define _POSIX_MAX_INPUT 255
#define _POSIX_NAME_MAX 14
#define _POSIX_NGROUPS_MAX 0
#define _POSIX_OPEN_MAX 16
#define _POSIX_PATH_MAX 255
#define _POSIX_PIPE_BUF 512
#define _POSIX_SSIZE_MAX 32767
#define _POSIX_STREAM_MAX 8
#define _POSIX_TZNAME_MAX 3
#define ARG_MAX 14500
#define LINK_MAX 1024
#define MAX_CANON _POSIX_MAX_CANON
#define MAX_INPUT _POSIX_MAX_INPUT
#define NAME_MAX 255
#define NGROUPS_MAX 16
#define OPEN_MAX 32
#undef PATH_MAX
#define PATH_MAX 512
#define PIPE_BUF _POSIX_PIPE_BUF
/*#define SSIZE_MAX _POSIX_SSIZE_MAX*/
#define STREAM_MAX 20
#define TZNAME_MAX 10
#endif

