#ifndef _OS_HPP_
#define _OS_HPP_

#define LINUX_DEFINED defined(__linux__) // Linux
#define WIN_DEFINED (defined(_WIN32) || defined(_WIN64)) // Windows
#define APPLE_DEFINED defined(__APPLE__) // MacOS

#endif // _OS_HPP_