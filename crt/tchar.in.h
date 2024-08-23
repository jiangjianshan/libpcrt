/*
 * Port from mingw-w64-headers/crt/tchar.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#pragma once
#include "@NEXT_TCHAR_H@"

#include <corecrt.h>

#ifdef _STRSAFE_H_INCLUDED_
#error Need to include strsafe.h after tchar.h
#endif

_CRT_BEGIN_C_HEADER

#ifdef _UNICODE
#include <wchar.h>
/* dirent structures and functions */
# define _tdirent	_wdirent
# define _TDIR 		_WDIR
# define _topendir	_wopendir
# define _tclosedir	_wclosedir
# define _treaddir	_wreaddir
# define _trewinddir	_wrewinddir
# define _ttelldir	_wtelldir
# define _tseekdir	_wseekdir
#else
# include <string.h>
/* dirent structures and functions */
# define _tdirent	dirent
# define _TDIR 		DIR
# define _topendir	opendir
# define _tclosedir	closedir
# define _treaddir	readdir
# define _trewinddir	rewinddir
# define _ttelldir	telldir
# define _tseekdir	seekdir
#endif

_CRT_END_C_HEADER
