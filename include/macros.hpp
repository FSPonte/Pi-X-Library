#ifndef _MACROS_HPP_
#define _MACROS_HPP_

// Default buffer size
#define D_BUFFER_SIZE 20

// Default block allocation size
#define D_BLOCK_ALLOC_SIZE 1000

// Logger mode
#define LOGGER_MODE true

#if LOGGER_MODE

	#include <logger.hpp>

	#define LOGGER_INIT(file_path) logger _logger_(file_path)
	#define LOGGER_LOG_MSG(msg) _logger_.log_msg(msg)
	#define LOGGER_LOG_ARR(arr) _logger_.log_arr(arr)
	#define LOGGER_LOG_AUG(mtx, vec) _logger_.log_arr(mtx, vec)

#else

	#define LOGGER_INIT(file_path)
	#define LOGGER_LOG_MSG(msg)
	#define LOGGER_LOG_ARR(arr)
	#define LOGGER_LOG_AUG(mtx, vec)

#endif // LOGGER_MODE

#endif // _MACROS_HPP_
