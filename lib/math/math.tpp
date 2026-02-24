#ifndef _MATH_TPP_
#define _MATH_TPP_

namespace pix::math
{
	template <typename type_t>
	type_t abs(const type_t number) noexcept(true)
	{
		assert_is_number(type_t);

		if (number < 0)
			return -number;

		return number;
	}

	template <typename type_t>
	type_t f_mod(type_t arg, const type_t mod) noexcept(false)
	{
		assert_is_float(type_t);

		if (arg < 0) throw "Argument is a negative number";
		if (mod <= 0) throw "Modulus is a non positive number";

		if (arg < mod)
			return arg;

		while (arg >= mod)
			arg -= mod;

		return arg;
	}

	template <typename type_t>
	type_t floor(const type_t arg) noexcept(false)
	{
		assert_is_float(type_t);

		return static_cast<type_t>(static_cast<int>(arg));
	}

	template <typename type_t>
	type_t ceil(const type_t arg) noexcept(false)
	{
		assert_is_float(type_t);

		type_t int_part = static_cast<type_t>(static_cast<long>(arg));
		
		if (arg > int_part)
			int_part += 1;

		return int_part;
	}

	template <typename type_t>
	type_t mod_diff(const type_t arg_1, const type_t arg_2) noexcept(true)
	{
		assert_is_number(type_t);

		return pix::math::abs(arg_1 - arg_2);
	}

	unsigned long fact(unsigned long arg) noexcept(true)
	{
		if (arg == 0 || arg == 1)
			return 1;

		for (unsigned long i = arg - 1; i > 0; --i)
			arg *= i;

		return arg;
	}

	template <unsigned long arg>
	struct factorial
	{
		static constexpr const unsigned long VALUE = arg * pix::math::factorial<arg - 1>::VALUE;
	};

	template <>
	struct factorial<0>
	{
		static constexpr const unsigned long VALUE = 1;
	};

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

	template <unsigned long arg>
	struct fibonacci
	{
		static constexpr const int VALUE = pix::math::fibonacci<arg - 1>::VALUE + pix::math::fibonacci<arg - 2>::VALUE;
	};

	template <>
	struct fibonacci<0>
	{
		static constexpr const unsigned long VALUE = 0;
	};

	template <>
	struct fibonacci<1>
	{
		static constexpr const unsigned long VALUE = 1;
	};

	template <typename type_t>
	type_t log(const type_t arg) noexcept(false)
	{
		assert_is_float(type_t);

		if (arg <= 0)
			throw "Argument is a non positive number";

		unsigned long index = 1;
		type_t
			result = 0,
			coef = (arg - 1) / (arg + 1),
			term = coef,
			term_sq = coef * coef;

		for (unsigned long i = 1; i <= pix::math::MAX_ITER; ++i)
		{
			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term / index;
			index += 2;
			term *= term_sq;
		}

		return result * 2;
	}

	template <typename type_t>
	type_t log(const type_t arg, const type_t base) noexcept(false)
	{
		assert_is_float(type_t);

		return pix::math::log(arg) / pix::math::log(base);
	}

	template <typename type_t>
	type_t exp(type_t arg) noexcept(true)
	{
		assert_is_float(type_t);

		const bool is_neg = arg < 0;
		arg = pix::math::abs(arg);

		type_t
			result = 1,
			term = 1;

		for (unsigned long i = 1; i <= pix::math::MAX_ITER; ++i)
		{
			term *= arg / i;

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		if (is_neg)
			return 1 / result;
		
		return result;
	}

	template <typename type_t>
	type_t pow(type_t base, type_t exponent) noexcept(false)
	{
		assert_is_float(type_t);

		if (base == 0 && exponent == 0)
			throw "Indeterminate case of 0^0";

		if (base == 0) return 0;
		if (exponent == 0) return 1;
		if (exponent == 1) return base;
		if (exponent == 2) return base * base;

		const bool is_e_neg = exponent < 0;
		exponent = pix::math::abs(exponent);

		if (base == -1 && pix::math::floor(exponent) == exponent)
		{
			if (static_cast<long long>(exponent) % 2 == 0)
				return 1;
			else
				return -1;
		}

		type_t result = pix::math::exp(exponent * pix::math::log(pix::math::abs(base)));

		if (is_e_neg)
			result = 1 / result;

		if (base < 0 && pix::math::floor(exponent) == exponent)
		{
			if (static_cast<long long>(exponent) % 2 != 0)
				result *= -1;
		}
		else if (base < 0)
			return pix::math::NaN;

		return result;
	}

	template <typename type_t>
	type_t root(const type_t arg, const type_t index) noexcept(false)
	{
		assert_is_float(type_t);
		
		if (arg < 0) throw "Argument is a negative number";
		if (index == 0) throw "Index is equal to zero";
		
		if (index == 1)
			return arg;

		return pix::math::pow(arg, 1 / index);
	}

	unsigned long permut(const unsigned long total_num, const unsigned long selected_num) noexcept(false)
	{
		if (selected_num > total_num)
			return 0;

		return pix::math::fact(total_num) / pix::math::fact(total_num - selected_num);
	}

	template <unsigned long TOTAL_NUM, unsigned long SELECTED_NUM>
	struct permutation
	{
		static constexpr const unsigned long VALUE = pix::math::factorial<TOTAL_NUM>::VALUE / pix::math::factorial<TOTAL_NUM - SELECTED_NUM>::VALUE;
	};

	template <unsigned long TOTAL_NUM>
	struct permutation<TOTAL_NUM, 0>
	{
		static constexpr const unsigned long VALUE = 1;
	};

	unsigned long comb(const unsigned long total_num, const unsigned long choosing_num) noexcept(false)
	{
		if (choosing_num > total_num)
			return 0;

		return pix::math::fact(total_num) / (pix::math::fact(choosing_num) * pix::math::fact(total_num - choosing_num));
	}

	template <unsigned long TOTAL_NUM, unsigned long SELECTED_NUM>
	struct combination
	{
		static constexpr const unsigned long VALUE = pix::math::factorial<TOTAL_NUM>::VALUE / (pix::math::factorial<SELECTED_NUM>::VALUE * pix::math::factorial<TOTAL_NUM - SELECTED_NUM>::VALUE);
	};

	unsigned long kron_delta(const unsigned long lin_index, const unsigned long col_index) noexcept(true)
	{
		return static_cast<unsigned long>(lin_index == col_index);
	}

	template <unsigned long LIN_INDEX, unsigned long COL_INDEX>
	struct kronecker_delta
	{
		static constexpr const unsigned long VALUE = 0;
	};

	template <unsigned long index>
	struct kronecker_delta<index, index>
	{
		static constexpr const unsigned long VALUE = 1;
	};
}

#endif // _MATH_TPP_
