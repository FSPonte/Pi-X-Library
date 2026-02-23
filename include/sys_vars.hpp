#ifndef _SYS_VARS_HPP_
#define _SYS_VARS_HPP_

// Successfull exit code
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

// Failed exit code
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

// Error code
#ifndef ERROR_CODE
#define ERROR_CODE -1
#endif

// End of file code
#ifndef EOF
#define EOF -1
#endif

// Maximum signed integer in 32-bit arquitecture
#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif

// Maximum unsigned integer in 32-bit arquitecture
#ifndef U_INT32_MAX
#define U_INT32_MAX 4294967295
#endif

// Maximum signed integer in 64-bit arquitecture
#ifndef INT64_MAX
#define INT64_MAX 9223372036854775807
#endif

// Maximum unsigned integer in 64-bit arquitecture
#ifndef U_INT64_MAX
#define U_INT64_MAX 18446744073709551615
#endif

#ifndef STDIN
#define STDIN 0
#endif

#ifndef STDOUT
#define STDOUT 1
#endif

#ifndef STDERR
#define STDERR 2
#endif

#ifndef STDLOG
#define STDLOG 2
#endif

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

// Default buffer size
#define D_BUFFER_SIZE 20

// Default block allocation size
#define D_BLOCK_ALLOC_SIZE 1000

#endif // _SYS_VARS_HPP_
