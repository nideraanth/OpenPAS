#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32)
    #define PLATFORM_NAME "Windows"
    #define IS_WINDOWS 1
#elif defined(__linux__)
    #define PLATFORM_NAME "Linux"
    #define IS_LINUX 1
#elif defined(__APPLE__)
    #define PLATFORM_NAME "macOS"
    #define IS_MACOS 1
#endif

#endif