/*
 * Port from mingw-w64-headers/crt/sys/types.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#pragma once
#include "@NEXT_SYS_TYPES_H@"

#include <corecrt.h>
#include <time.h>

_CRT_BEGIN_C_HEADER

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
  typedef __int64 ssize_t;
#else
  typedef int ssize_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
typedef int	_pid_t;
#else
typedef __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
#undef pid_t
typedef _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
typedef unsigned short _mode_t;

#ifndef	NO_OLDNAMES
typedef _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifdef _MSC_VER
#if !defined(NO_OLDNAMES) || defined(_POSIX)
typedef long off32_t;
typedef long long _off64_t;
typedef long long off64_t;
#endif
#endif /* _MSC_VER */

#ifndef __NO_ISOCEXT
typedef unsigned int useconds_t;
#endif
#ifndef _TIMESPEC_DEFINED

struct itimerspec {
  struct timespec  it_interval;	/* Timer period */
  struct timespec  it_value;	/* Timer expiration */
};
#endif	/* _TIMESPEC_DEFINED */

#ifndef _SIGSET_T_
#define _SIGSET_T_
#ifdef _WIN64
typedef unsigned long long _sigset_t;
#else
typedef unsigned long	_sigset_t;
#endif

#ifdef _POSIX
typedef _sigset_t	sigset_t;
#endif
#endif	/* Not _SIGSET_T_ */

_CRT_END_C_HEADER
