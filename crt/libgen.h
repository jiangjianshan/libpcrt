/*
 * Port from mingw-w64-headers/crt/libgen.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#pragma once

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

_CRTIMP char * __cdecl basename (char *);
_CRTIMP char * __cdecl dirname (char *);

_CRT_END_C_HEADER

