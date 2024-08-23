/*
 * Port from mingw-w64-headers/crt/unistd.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _UNISTD_H
#define _UNISTD_H
#define __UNISTD_H_SOURCED__ 1

#include <corecrt.h>
#include <io.h>
#include <process.h>
#include <getopt.h>

/* These are also defined in stdio.h. */
#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

/* These are also defined in stdio.h. */
#ifndef STDIN_FILENO
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif

/* Used by shutdown(2). */
#ifdef _POSIX_SOURCE

/* MySql connector already defined SHUT_RDWR. */
#ifndef SHUT_RDWR
#define SHUT_RD   0x00
#define SHUT_WR   0x01
#define SHUT_RDWR 0x02
#endif

#endif

_CRT_BEGIN_C_HEADER

#pragma push_macro("sleep")
#undef sleep
unsigned int __cdecl sleep (unsigned int);
#pragma pop_macro("sleep")

#if !defined __NO_ISOCEXT
#include <sys/types.h> /* For useconds_t. */

int __cdecl usleep(useconds_t);
#endif  /* Not __NO_ISOCEXT */

#ifndef FTRUNCATE_DEFINED
#define FTRUNCATE_DEFINED
/* This is defined as a real library function to allow autoconf
   to verify its existence. */
#if !defined(NO_OLDNAMES) || defined(_POSIX)
_CRTIMP int ftruncate(int, off32_t);
_CRTIMP int ftruncate64(int, off64_t);
_CRTIMP int truncate(const char *, off32_t);
_CRTIMP int truncate64(const char *, off64_t);
#else
_CRTIMP int ftruncate(int, _off_t);
_CRTIMP int ftruncate64(int, _off64_t);
_CRTIMP int truncate(const char *, _off_t);
_CRTIMP int truncate64(const char *, _off64_t);
#endif
#endif /* FTRUNCATE_DEFINED */

_CRT_END_C_HEADER

#if !defined(IN_WINPTHREAD) && \
	((!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	 (_POSIX_C_SOURCE > 2) || defined(__EXTENSIONS__))
#include <pthread_unistd.h>
#endif

#undef __UNISTD_H_SOURCED__
#endif /* _UNISTD_H */

