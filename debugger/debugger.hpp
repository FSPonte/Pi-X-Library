#ifndef __DEBUGGER_HPP__
#define __DEBUGGER_HPP__

// Dependencies
#include <traceback.hpp>
#include <logger.hpp>
#include <tester.hpp>

namespace debugger
{
	extern pix::traceback<TRACEBACK_ENABLED> __route__;
	extern pix::logger<LOGGER_ENABLED> __logger__;
	extern pix::tester __tester__;
}

#define DEBUG_TRACEBACK_INIT debugger::__route__.init(__FUNCTION__, __FILE__, __LINE__)
#define DEBUG_TRACEBACK_TRIG debugger::__route__.trigger(__LINE__)
#define DEBUG_TRACEBACK_RT debugger::__route__

#define DEBUG_TESTER_INIT debugger::__tester__.init(__FUNCTION__)
#define DEBUG_TESTER_START debugger::__tester__.start(__FUNCTION__, __FILE__)
#define DEBUG_TESTER_PASS debugger::__tester__.pass(__LINE__)
#define DEBUG_TESTER_FAIL debugger::__tester__.fail(__LINE__)

#endif // __DEBUGGER_HPP__
