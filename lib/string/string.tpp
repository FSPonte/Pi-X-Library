#ifndef _STRING_TPP_
#define _STRING_TPP_

// Dependencies
#include <types.hpp>

namespace pix
{
	template <typename type_t>
	pix::string to_string(type_t arg) noexcept(true)
	{
		pix::string ret = "";

		// Handle the zero case immediately
		if (arg == 0)
			return ret;

		bool isNegative = false;

		// Handle signed types if necessary
		if constexpr (is_number(type_t))
		{
			if (arg < 0)
			{
				isNegative = true;
				arg = -arg; 
			}
		}

		// Process digits from right to left
		while (arg > 0)
		{
			ret += static_cast<char>((arg % 10) + '0');
			arg /= 10;
		}

		if (isNegative)
			ret += '-';

		// Since we added digits backward (ones, tens, hundreds), reverse it
		ret.invert();

		return ret;
	}
}

#endif // _STRING_TPP_
