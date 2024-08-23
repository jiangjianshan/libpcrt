/*
 * Port from mingw-w64-headers/crt/search.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#pragma once

#include "@NEXT_SEARCH_H@"

#include <corecrt.h>
#include <stddef.h>

_CRT_BEGIN_C_HEADER

/*
Documentation for these POSIX definitions and prototypes can be found in 
The Open Group Base Specifications Issue 6
IEEE Std 1003.1, 2004 Edition.
eg:  http://www.opengroup.org/onlinepubs/009695399/functions/twalk.html
*/

typedef struct entry {
	char *key;
	void *data;
} ENTRY;

typedef enum {
	FIND,
	ENTER
} ACTION;

typedef enum {
	preorder,
	postorder,
	endorder,
	leaf
} VISIT;

#ifdef _SEARCH_PRIVATE
typedef struct node {
	char         *key;
	struct node  *llink, *rlink;
} node_t;
#endif

_CRTIMP void * __cdecl tdelete (const void * __restrict, void ** __restrict, int (*)(const void *, const void *));
_CRTIMP void * __cdecl tfind (const void *, void * const *, int (*)(const void *, const void *));
_CRTIMP void * __cdecl tsearch (const void *, void **, int (*)(const void *, const void *));
_CRTIMP void __cdecl twalk (const void *, void (*)(const void *, VISIT, int));

#ifdef _GNU_SOURCE
_CRTIMP void __cdecl tdestroy(void *, void (*)(void *));
#endif

_CRT_END_C_HEADER
