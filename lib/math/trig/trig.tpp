#ifndef _TRIG_TPP_
#define _TRIG_TPP_

// Dependencies
#include <constants.hpp>
#include <type_info.hpp>
#include <math.hpp>

namespace pix::math::trig
{
	template <typename type_t>
	type_t sin(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);

		const bool is_arg_neg = arg < 0;
		arg = pix::math::f_mod(pix::math::abs(arg), 2 * pix::constants::mathematics::PI);

		type_t
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			term *= -arg / ((2 * i + 3) * (2 * i + 2));

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		if (is_arg_neg)
			return -result;

		return result;
	}

	template <typename type_t>
	type_t cos(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		arg = pix::math::f_mod(pix::math::abs(arg), 2 * pix::constants::mathematics::PI);

		type_t
			term = 1,
			result = 1;

		arg *= arg;

		for (unsigned long i = 1; i <= pix::math::MAX_ITER; ++i)
		{
			term *= - arg / ((2 * i) * (2 * i - 1));

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	template <typename type_t>
	type_t tan(const type_t ARG) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return pix::math::trig::sin(ARG) / pix::math::trig::cos(ARG);
	}

	template <typename type_t>
	type_t sec(const type_t ARG) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return 1 / pix::math::trig::cos(ARG);
	}

	template <typename type_t>
	type_t csc(const type_t ARG) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return 1 / pix::math::trig::sin(ARG);
	}

	template <typename type_t>
	type_t cot(const type_t ARG) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		return pix::math::trig::cos(ARG) / pix::math::trig::sin(ARG);
	}

	template <typename type_t>
	type_t arcsin(type_t arg) noexcept(false)
	{
		is_float_static_assert(type_t);
		
		if (arg < -1 || arg > 1) throw "Argument is out of bounds";

		if (arg == -1)
			return - 0.5 * pix::constants::mathematics::PI;
		else if (arg == 1)
			return 0.5 * pix::constants::mathematics::PI;
		
		const bool is_arg_neg = arg < 0;
		arg = pix::math::abs(arg);

		type_t
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			term *= 0.25 * arg * (2 * i + 2) * (2 * i + 1) * (2 * i + 1) / ((2 * i + 3) * (i + 1) * (i + 1));

			if (term < pix::math::PR_THRESHOLD)
				break;

			result += term;
		}

		if (is_arg_neg)
			return -result;

		return result;
	}
	
	template <typename type_t>
	type_t arccos(const type_t ARG) noexcept(false)
	{
		is_float_static_assert(type_t);
		
		return 0.5 * pix::constants::mathematics::PI - trig::arcsin(ARG);
	}
	
	template <typename type_t>
	type_t arctan(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);
		
		if (pix::math::abs(arg) > 1)
			return 0.5 * pix::constants::mathematics::PI - pix::math::trig::arctan(1 / arg);

		const bool is_arg_neg = arg < 0;
		arg = pix::math::abs(arg);

		type_t
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			term *= - arg * (2 * i + 1) / (2 * i + 3);

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;

			result += term;
		}

		if (is_arg_neg)
			return -result;

		return result;
	}
}

#endif // _TRIG_TPP_
