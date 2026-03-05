// Header file
#include "debugger.hpp"

namespace debugger
{
	pix::traceback<TRACEBACK_ENABLED> __route__;
	pix::logger<LOGGER_ENABLED> __logger__;
	pix::tester __tester__;
}
