// Header file
#include "math.hpp"

namespace pix::math
{
	unsigned long fact(unsigned long arg) noexcept(true)
	{
		if (arg == 0 || arg == 1)
			return 1;

		for (unsigned long i = arg - 1; i > 0; --i)
			arg *= i;

		return arg;
	}

	unsigned long fib(unsigned long arg) noexcept(true)
	{
		if (arg == 0) return 0;
		if (arg == 1) return 1;

		unsigned long 
			fib_1 = 0,
			fib_2 = 1,
			fib_n = 0;

		for (unsigned long i = 2; i <= arg; ++i)
		{
			fib_n = fib_1 + fib_2;
			fib_1 = fib_2;
			fib_2 = fib_n;
		}

		return fib_n;
	}

	unsigned long permut(const unsigned long total_num, const unsigned long selected_num) noexcept(false)
	{
		if (selected_num > total_num)
			return 0;

		return pix::math::fact(total_num) / pix::math::fact(total_num - selected_num);
	}

	unsigned long comb(const unsigned long total_num, const unsigned long choosing_num) noexcept(false)
	{
		if (choosing_num > total_num)
			return 0;

		return pix::math::fact(total_num) / (pix::math::fact(choosing_num) * pix::math::fact(total_num - choosing_num));
	}

	unsigned long kron_delta(const unsigned long lin_index, const unsigned long col_index) noexcept(true)
	{
		return static_cast<unsigned long>(lin_index == col_index);
	}
}
