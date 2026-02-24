#ifndef _MACROS_HPP_
#define _MACROS_HPP_

#define LOGGER_MODE true // Logger mode

#if LOGGER_MODE

	#define LOGGER_INIT(file_path) \
		pix::logger _logger_(file_path); \
		_logger_.open_session()
	#define LOGGER_LOG_MSG(msg) _logger_.log_msg(msg)
	#define LOGGER_LOG_LST(lst, dim) _logger_.log_lst(lst, dim)
	#define LOGGER_LOG_ARR(arr) _logger_.log_arr(arr)
	#define LOGGER_LOG_AUG(mtx, vec) _logger_.log_arr(mtx, vec)

#else

	#define LOGGER_INIT(file_path)
	#define LOGGER_LOG_MSG(msg)
	#define LOGGER_LOG_LST(lst, dim)
	#define LOGGER_LOG_ARR(arr)
	#define LOGGER_LOG_AUG(mtx, vec)

#endif // LOGGER_MODE

#endif // _MACROS_HPP_
