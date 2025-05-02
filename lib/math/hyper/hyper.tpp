#ifndef _HYPER_TPP_
#define _HYPER_TPP_

// Dependencies
#include <type_info.hpp>
#include <math.hpp>

namespace pix::math::hyper
{
	template <typename type_t>
	type_t sinh(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);

		type_t
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			term *= arg / ((2 * i + 3) * (2 * i + 2));

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	template <typename type_t>
	type_t cosh(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		type_t
			term = 1,
			result = 1;

		arg *= arg;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			term *= arg / ((2 * i + 2) * (2 * i + 1));

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	template <typename type_t>
	type_t tanh(const type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return pix::math::hyper::sinh(arg) / pix::math::hyper::cosh(arg);
	}

	template <typename type_t>
	type_t sech(const type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return 1 / pix::math::hyper::cosh(arg);
	}

	template <typename type_t>
	type_t csch(const type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return 1 / pix::math::hyper::sech(arg);
	}

	template <typename type_t>
	type_t coth(const type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return pix::math::hyper::cosh(arg) / pix::math::hyper::sinh(arg);
	}
}

#endif // _HYPER_TPP_
