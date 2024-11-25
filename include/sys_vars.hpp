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
#ifndef ERROR
#define ERROR -1
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

// Default buffer size
#ifndef D_BUFFER_SIZE
#define D_BUFFER_SIZE 20
#endif

#endif // _SYS_VARS_HPP_
