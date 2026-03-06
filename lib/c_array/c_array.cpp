// Header file
#include "c_array.hpp"

namespace pix::c_array
{
	unsigned long strlen(const char str[]) noexcept(false)
	{
		DEBUG_TRACEBACK_INIT;

		if (str == nullptr)
		{
			DEBUG_TRACEBACK_TRIG;
			throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
		}

		unsigned long length = 0;
		
		while (str[length++] != '\0');

		return length;
	}
}
