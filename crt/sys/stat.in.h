/*
 * Port from mingw-w64-headers/crt/sys/stat.h
 */
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#pragma once
#include "@NEXT_SYS_STAT_H@"

#include <corecrt.h>
#include <io.h>
#include <sys/types.h>

#define	_S_IFBLK	0x3000

#define	S_IFIFO		_S_IFIFO
#define	S_IFBLK		_S_IFBLK

#define	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#define	_S_IXUSR	_S_IEXEC
#define	_S_IWUSR	_S_IWRITE

#define	S_IRWXU		_S_IRWXU
#define	S_IXUSR		_S_IXUSR
#define	S_IWUSR		_S_IWUSR
#define	S_IRUSR		_S_IRUSR
#define	_S_IRUSR	_S_IREAD

#define S_IRGRP    (S_IRUSR >> 3)
#define S_IWGRP    (S_IWUSR >> 3)
#define S_IXGRP    (S_IXUSR >> 3)
#define S_IRWXG    (S_IRWXU >> 3)

#define S_IROTH    (S_IRGRP >> 3)
#define S_IWOTH    (S_IWGRP >> 3)
#define S_IXOTH    (S_IXGRP >> 3)
#define S_IRWXO    (S_IRWXG >> 3)

#define	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

