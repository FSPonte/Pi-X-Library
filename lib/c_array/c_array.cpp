// Header file
#include "c_array.hpp"

// Dependencies
#include <exception.hpp>

namespace pix::c_array
{
	unsigned long strlen(const char str[]) noexcept(false)
	{
		if (str == nullptr)
			throw pix::exception::null_ptr();

		unsigned long length = 0;
		
		while (str[length++] != '\0');

		return length;
	}
}
