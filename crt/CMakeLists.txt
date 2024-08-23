# sys/stat.in.h -> sys/stat.h
find_file(NEXT_SYS_STAT_H sys/stat.h)
if(NEXT_SYS_STAT_H)
  message(STATUS "Found sys/stat.h: ${NEXT_SYS_STAT_H}")
endif()
configure_file(sys/stat.in.h sys/stat.h)

# sys/types.in.h -> sys/types.h
find_file(NEXT_SYS_TYPES_H sys/types.h)
if(NEXT_SYS_TYPES_H)
  message(STATUS "Found sys/types.h: ${NEXT_SYS_TYPES_H}")
endif()
configure_file(sys/types.in.h sys/types.h)

# limits.in.h -> limits.h
find_file(NEXT_LIMITS_H limits.h)
if(NEXT_LIMITS_H)
  message(STATUS "Found limits.h: ${NEXT_LIMITS_H}")
endif()
configure_file(limits.in.h limits.h)


# search.in.h -> search.h
find_file(NEXT_SEARCH_H search.h)
if(NEXT_SEARCH_H)
  message(STATUS "Found search.h: ${NEXT_SEARCH_H}")
endif()
configure_file(search.in.h search.h)

# signal.in.h -> signal.h
find_file(NEXT_SIGNAL_H signal.h)
if(NEXT_SIGNAL_H)
  message(STATUS "Found signal.h: ${NEXT_SIGNAL_H}")
endif()
configure_file(signal.in.h signal.h)

# tchar.in.h -> tchar.h
find_file(NEXT_TCHAR_H tchar.h)
if(NEXT_TCHAR_H)
  message(STATUS "Found tchar.h: ${NEXT_TCHAR_H}")
endif()
configure_file(tchar.in.h tchar.h)

# time.in.h -> time.h
find_file(NEXT_TIME_H time.h)
if(NEXT_TIME_H)
  message(STATUS "Found time.h: ${NEXT_TIME_H}")
endif()
configure_file(time.in.h time.h)

set(CRT_SYS_HDRS
  crt/sys/param.h
  crt/sys/time.h
  crt/sys/unistd.h
  PARENT_SCOPE)

set(CRT_SYS_IN_HDRS
  crt/sys/stat.h
  crt/sys/types.h
  PARENT_SCOPE)

set(CRT_HDRS
  crt/dirent.h
  crt/getopt.h
  crt/libgen.h
  crt/unistd.h
  PARENT_SCOPE)

set(CRT_IN_HDRS
  crt/limits.h
  crt/search.h
  crt/signal.h
  crt/tchar.h
  crt/time.h
  PARENT_SCOPE)

set(CRT_SRCS
  misc/dirname.c
  misc/ftruncate.c
  misc/gettimeofday.c
  stdio/ftruncate64.c
  PARENT_SCOPE)
