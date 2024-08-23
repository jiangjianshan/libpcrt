# libpcrt
When you use Visual C++ Build Tools or Visual Studio to build some GNU or other open source libraries that are need some Posix functions, you may often have to do some patches on those libraries. And this is sometimes not easy.

The purpose of libpcrt is try to reduce the difficulty of the build work if you use MSVC toolchain. Most of code are ported from mingw-w64-crt and mingw-w64-headers in MinGW-w64 project, and use cmake as the build system.
