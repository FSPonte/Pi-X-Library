#ifndef _OS_HPP_
#define _OS_HPP_

#if defined(__linux__)
    #define LINUX_DEFINED 1 // Linux
#else
    #define LINUX_DEFINED 0 // Linux
#endif

#if defined(_WIN32) || defined(_WIN64)
    #define WIN_DEFINED 1 // Windows
#else
    #define WIN_DEFINED 0 // Windows
#endif

#if defined(__APPLE__)
    #define APPLE_DEFINED 1 // MacOS
#else
    #define APPLE_DEFINED 0 // MacOS
#endif

#endif // _OS_HPP_
