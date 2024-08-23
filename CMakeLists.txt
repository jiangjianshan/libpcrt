cmake_minimum_required(VERSION 3.9)

project(libpcrt C)

set(VERSION "0.0.1")

include(GNUInstallDirs)
add_subdirectory(crt)
add_subdirectory(misc)
add_subdirectory(stdio)

set(PCRT_PUBLIC_HEADERS
  ${CRT_SYS_HDRS} ${CRT_SYS_IN_HDRS} ${CRT_HDRS} ${CRT_IN_HDRS} 
)

set(PCRT_INCLUDE_DIRECTORIES
  ${CMAKE_CURRENT_BINARY_DIR}/crt
  ${PROJECT_SOURCE_DIR}/crt
  ${PROJECT_SOURCE_DIR}/misc
  ${PROJECT_SOURCE_DIR}/stdio
)
# The pcrt shared library.
add_library(pcrt_shared SHARED ${PCRT_PUBLIC_HEADERS} ${CRT_SRCS} ${MISC_SRCS} ${STDIO_SRCS})
target_compile_definitions(pcrt_shared PUBLIC -DCRTDLL -D_CRTBLD -DIN_WINPTHREAD)
target_compile_options(pcrt_shared PUBLIC /std:c11 /experimental:c11atomics)
target_include_directories(pcrt_shared PUBLIC ${PCRT_INCLUDE_DIRECTORIES})
set_target_properties(pcrt_shared PROPERTIES VERSION 0.0.1 SOVERSION 0 OUTPUT_NAME pcrt)

# The pcrt static library.
add_library(pcrt_static STATIC ${PCRT_PUBLIC_HEADERS} ${CRT_SRCS} ${MISC_SRCS} ${STDIO_SRCS})
target_compile_definitions(pcrt_static PUBLIC -DCRTDLL -D_CRTBLD -DIN_WINPTHREAD)
target_compile_options(pcrt_static PUBLIC /std:c11 /experimental:c11atomics)
target_include_directories(pcrt_static PUBLIC ${PCRT_INCLUDE_DIRECTORIES})
set_target_properties(pcrt_static PROPERTIES OUTPUT_NAME libpcrt)

install(TARGETS pcrt_shared pcrt_static RUNTIME DESTINATION "bin" ARCHIVE DESTINATION "lib")
# Install generated files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/sys/stat.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sys)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/sys/types.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sys)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/limits.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/search.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/signal.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/tchar.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt/time.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# Install header files from source directory
install(FILES ${CRT_SYS_HDRS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sys)
install(FILES ${CRT_HDRS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
