#ifndef __DEBUGGER_HPP__
#define __DEBUGGER_HPP__

// Dependencies
#include <pix_lib.hpp>

namespace debugger
{
	extern pix::traceback<TRACEBACK_ENABLED> __route__;
	extern pix::logger<LOGGER_ENABLED> __logger__;
	extern pix::tester __tester__;
}

#endif // __DEBUGGER_HPP__
