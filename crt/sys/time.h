/*
 * Port from mingw-w64-headers/crt/sys/time.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#pragma once

#include <corecrt.h>
#include <time.h>

_CRT_BEGIN_C_HEADER

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
/* On native Windows with MSVC, get the 'struct timeval' type.
   Also, on native Windows with a 64-bit time_t, where we are overriding the
   'struct timeval' type, get all declarations of system functions whose
   signature contains 'struct timeval'.  */
#if !defined _WINSOCK2API_ && !defined _WINSOCKAPI_
# include <winsock2.h>
#endif

#ifndef _TIMEZONE_DEFINED /* also in sys/time.h */
#define _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
struct timezone
{
  int tz_minuteswest; /* of Greenwich */
  int tz_dsttime;     /* type of dst correction to apply */
};

extern int __cdecl mingw_gettimeofday (struct timeval *p, struct timezone *z);

#endif /* _TIMEZONE_DEFINED */

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#ifndef _GETTIMEOFDAY_DEFINED
#define _GETTIMEOFDAY_DEFINED
_CRTIMP int __cdecl gettimeofday(struct timeval *__restrict,
                         void *__restrict /* tzp (unused) */);
#endif

_CRT_END_C_HEADER

/* Adding timespec definition.  */
#include <sys/timeb.h>
