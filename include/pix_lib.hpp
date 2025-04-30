#ifndef _PIX_LIB_HPP_
#define _PIX_LIB_HPP_

#define LOGGER_MODE true

#if LOGGER_MODE

	#include <logger.hpp>

	#define LOGGER_INIT(file_path) logger _logger_(file_path)
	#define LOGGER_WRITE(msg) _logger_.log(msg)

#else

	#define LOGGER_INIT(file_path)
	#define LOGGER_WRITE(msg)

#endif // LOGGER_MODE

#include <sys_vars.hpp>
#include <types.hpp>
#include <constants.hpp>
#include <macros.hpp>
#include <asserts.hpp>
#include <type_info.hpp>
#include <memory.hpp>
#include <smart_pointer.hpp>
#include <c_array.hpp>
#include <sort.hpp>
#include <rand.hpp>
#include <array.hpp>
#include <tuple.hpp>
#include <stack.hpp>
#include <queue.hpp>
#include <deque.hpp>
#include <node.hpp>
#include <list.hpp>
#include <dyn_array.hpp>
#include <string.hpp>
#include <logic.hpp>
#include <math.hpp>
#include <trig.hpp>
#include <hyper.hpp>
#include <stat.hpp>
#include <complex.hpp>
#include <vector.hpp>
#include <matrix.hpp>
#include <sys_lin_equ.hpp>
#include <function.hpp>
#include <signal.hpp>
#include <rgb.hpp>
#include <image.hpp>

#endif // _PIX_LIB_HPP_
