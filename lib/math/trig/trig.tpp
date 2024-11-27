#ifndef _TRIG_TPP_
#define _TRIG_TPP_

namespace pix::math::trig
{
	long double sin(long double arg) noexcept(true)
	{
		const bool is_arg_neg = arg < 0;
		arg = math::f_mod(math::abs(arg), 2 * constants::mathematics::PI);

		long double
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= - arg / ((2 * i + 3) * (2 * i + 2));

			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		if (is_arg_neg)
			return - result;

		return result;
	}

	long double cos(long double arg) noexcept(true)
	{
		arg = math::f_mod(math::abs(arg), 2 * constants::mathematics::PI);

		long double
			term = 1,
			result = 1;

		arg *= arg;

		for (unsigned long i = 1; i <= math::MAX_ITER; ++i)
		{
			term *= - arg / ((2 * i) * (2 * i - 1));

			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		return result;
	}

	long double tan(const long double arg) noexcept(true)
	{ return trig::sin(arg) / trig::cos(arg); }

	long double sec(const long double arg) noexcept(true)
	{ return 1 / trig::cos(arg); }

	long double csc(const long double arg) noexcept(true)
	{ return 1 / trig::sin(arg); }

	long double cot(const long double arg) noexcept(true)
	{ return trig::cos(arg) / trig::sin(arg); }

	long double arcsin(long double arg) noexcept(false)
	{
		if (arg < -1 || arg > 1)
			throw "Argument is out of bounds";

		const bool is_arg_neg = arg < 0;
		arg = math::abs(arg);

		long double
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= 0.25 * arg * (2 * i + 2) * (2 * i + 1) * (2 * i + 1) / ((2 * i + 3) * (i + 1) * (i + 1));

			if (term < math::PR_THRESHOLD)
				break;

			result += term;
		}

		if (is_arg_neg)
			return - result;

		return result;
	}
	
	long double arccos(const long double arg) noexcept(false)
	{ return 0.5 * constants::mathematics::PI - trig::arcsin(arg); }
	
	long double arctan(long double arg) noexcept(true)
	{
		if (math::abs(arg) > 1)
			return 0.5 * constants::mathematics::PI - trig::arctan(1 / arg);

		const bool is_arg_neg = arg < 0;
		arg = math::abs(arg);

		long double
			term = arg,
			result = arg;

		arg *= arg;

		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= - arg * (2 * i + 1) / (2 * i + 3);

			if (math::abs(term) < math::PR_THRESHOLD)
				break;

			result += term;
		}

		if (is_arg_neg)
			return - result;

		return result;
	}
}

#endif // _TRIG_TPP_
