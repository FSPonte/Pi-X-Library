#ifndef _OS_HPP_
#define _OS_HPP_

#define OS_LINUX defined(__linux__) // Linux
#define OS_WIN (defined(_WIN32) || defined(_WIN64)) // Windows
#define OS_APPLE defined(__APPLE__) // MacOS

#endif // _OS_HPP_