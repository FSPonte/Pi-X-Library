#ifndef _HYPER_TPP_
#define _HYPER_TPP_

// Dependencies
#include <type_info.hpp>

namespace pix::math::hyper
{
	long double sinh(long double arg) noexcept(true)
	{
		long double
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= arg / ((2 * i + 3) * (2 * i + 2));

			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	long double cosh(long double arg) noexcept(true)
	{
		long double
			term = 1,
			result = 1;

		arg *= arg;

		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= arg / ((2 * i + 2) * (2 * i + 1));

			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	long double tanh(const long double arg) noexcept(true)
	{
		return hyper::sinh(arg) / hyper::cosh(arg);
	}

	long double sech(const long double arg) noexcept(true)
	{
		return 1 / hyper::cosh(arg);
	}

	long double csch(const long double arg) noexcept(true)
	{
		return 1 / hyper::sech(arg);
	}

	long double coth(const long double arg) noexcept(true)
	{
		return hyper::cosh(arg) / hyper::sinh(arg);
	}
}

#endif // _HYPER_TPP_
