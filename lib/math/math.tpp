#ifndef _MATH_TPP_
#define _MATH_TPP_

// Dependencies
#include <type_info.hpp>

static const unsigned long STD_NaN = 0x7ff8000000000000; // Standard representation for NaN

namespace pix::math
{
	constexpr double NaN(void) noexcept(true)
	{
		return *reinterpret_cast<const double*>(&STD_NaN);
	}

	template <typename type_t>
	type_t abs(const type_t number) noexcept(true)
	{
		is_number_static_assert(type_t);

		if (number < 0)
			return -number;

		return number;
	}

	template <typename type_t>
	type_t f_mod(type_t arg, const type_t mod) noexcept(false)
	{
		is_float_static_assert(type_t);

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
		is_float_static_assert(type_t);

		return static_cast<type_t>(static_cast<int>(arg));
	}

	template <typename type_t>
	type_t ceil(const type_t arg) noexcept(false)
	{
		is_float_static_assert(type_t);

		type_t int_part = static_cast<type_t>(static_cast<long>(arg));
		
		if (arg > int_part)
			int_part += 1;

		return int_part;
	}


	unsigned long fact(unsigned long arg) noexcept(true)
	{
		if (arg == 0 || arg == 1)
			return 1;

		for (unsigned long i = arg - 1; i > 0; --i)
			arg *= i;

		return arg;
	}

	template <typename type_t>
	type_t mod_diff(const type_t arg_1, const type_t arg_2) noexcept(true)
	{
		is_number_static_assert(type_t);

		return math::abs(arg_1 - arg_2);
	}

	template <unsigned long arg>
	struct factorial
	{
		static constexpr const unsigned long value = arg * math::factorial<arg - 1>::value;
	};

	template <>
	struct factorial<0>
	{
		static constexpr const unsigned long value = 1;
	};

	unsigned long fib(unsigned long arg) noexcept(true)
	{
		unsigned long arr[arg + 2];

		arr[0] = 0;
		arr[1] = 1;

		for (unsigned long i = 2; i <= arg; ++i)
			arr[i] = arr[i - 1] + arr[i - 2];

		return arr[arg];
	}

	template <unsigned long arg>
	struct fibonacci
	{
		static constexpr const int value = math::fibonacci<arg - 1>::value + math::fibonacci<arg - 2>::value;
	};

	template <>
	struct fibonacci<0>
	{
		static constexpr const unsigned long value = 0;
	};

	template <>
	struct fibonacci<1>
	{
		static constexpr const unsigned long value = 1;
	};

	long double log(const long double arg) noexcept(false)
	{
		if (arg <= 0) throw "Argument is a non positive number";

		long double
			result = 0,
			coef = (arg - 1) / (arg + 1),
			term = coef,
			term_sq = coef * coef;
		const unsigned long MAX_ITER = math::MAX_ITER + 1;

		for (unsigned long i = 1; i < MAX_ITER; i += 2)
		{
			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term / i;
			term *= term_sq;
		}

		return result * 2;
	}

	long double log(const long double arg, const long double base) noexcept(false)
	{
		return math::log(arg) / math::log(base);
	}

	long double exp(long double arg) noexcept(true)
	{
		const bool is_neg = arg < 0;
		arg = math::abs(arg);

		long double
			result = 1,
			term = 1;
		
		for (unsigned long i = 0; i < math::MAX_ITER; ++i)
		{
			term *= arg / (i + 1);

			if (math::abs(term) < math::PR_THRESHOLD)
				break;
			
			result += term;
		}

		if (is_neg)
			return 1 / result;
		
		return result;
	}

	long double pow(long double base, long double exponent) noexcept(false)
	{
		if (base == 0 && exponent == 0) throw "Indeterminate case of 0^0";

		if (base == 0)
			return 0;

		if (exponent == 0)
			return 1;

		if (exponent == 1)
			return base;

		if (exponent == 2)
			return base * base;

		const bool is_e_neg = exponent < 0;
		exponent = abs(exponent);

		if (base == -1 && floor(exponent) == exponent)
		{
			if (static_cast<long long>(exponent) % 2 == 0)
				return 1;
			else
				return -1;
		}

		long double result = exp(exponent * log(abs(base)));

		if (is_e_neg)
			result = 1 / result;

		if (base < 0 && floor(exponent) == exponent)
		{
			if (static_cast<long long>(exponent) % 2 != 0)
				result = -result;
		}
		else if (base < 0)
			return NaN();

		return result;
	}

	long double root(const long double arg, const long double index) noexcept(false)
	{
		if (arg < 0) throw "Argument is a negative number";
		if (index == 0) throw "Index is equal to zero";
		
		if (index == 1)
			return arg;

		return math::pow(arg, 1 / index);
	}

	unsigned long permut(const unsigned long n, const unsigned long k) noexcept(false)
	{
		if (k > n)
			return 0;

		return math::fact(n) / math::fact(n - k);
	}

	template <unsigned long n, unsigned long k>
	struct permutation
	{
		static constexpr const unsigned long value = math::factorial<n>::value / math::factorial<n - k>::value;
	};

	template <unsigned long n>
	struct permutation<n, 0>
	{
		static constexpr const unsigned long value = 1;
	};

	unsigned long comb(const unsigned long total_num, const unsigned long choosing_num) noexcept(false)
	{
		if (choosing_num > total_num)
			return 0;

		return math::fact(total_num) / (math::fact(choosing_num) * math::fact(total_num - choosing_num));
	}

	template <unsigned long n, unsigned long k>
	struct combination
	{
		static constexpr const unsigned long value = math::factorial<n>::value / (math::factorial<k>::value * math::factorial<n - k>::value);
	};

	unsigned long kron_delta(const unsigned long i, const unsigned long j) noexcept(true)
	{
		return static_cast<unsigned long>(i == j);
	}

	template <unsigned long i, unsigned long j>
	struct kronecker_delta
	{
		static constexpr const unsigned long value = 0;
	};

	template <unsigned long index>
	struct kronecker_delta<index, index>
	{
		static constexpr const unsigned long value = 1;
	};
}

#endif // _MATH_TPP_
