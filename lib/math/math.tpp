#ifndef _MATH_TPP_
#define _MATH_TPP_

// Dependencies
#include <macros.hpp>
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

	template <typename type_t>
	type_t mod_diff(const type_t arg_1, const type_t arg_2) noexcept(true)
	{
		is_number_static_assert(type_t);

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
		static constexpr const unsigned long value = arg * pix::math::factorial<arg - 1>::value;
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
		static constexpr const int value = pix::math::fibonacci<arg - 1>::value + pix::math::fibonacci<arg - 2>::value;
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

	template <typename type_t>
	type_t log(const type_t arg) noexcept(false)
	{
		is_float_static_assert(type_t);

		if (arg <= 0) throw "Argument is a non positive number";

		// Logger
		LOGGER_INIT("logs/math_log.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTHRESHOLD = " + std::to_string(pix::math::PR_THRESHOLD));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(pix::math::MAX_ITER));
			LOGGER_LOG_MSG("Initial value: " + std::to_string(arg));
		}

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

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\tTerm: " + std::to_string(term));
				LOGGER_LOG_MSG("\tResult: " + std::to_string(result));
			}
		}

		return result * 2;
	}

	template <typename type_t>
	type_t log(const type_t arg, const type_t base) noexcept(false)
	{
		is_float_static_assert(type_t);

		return pix::math::log(arg) / pix::math::log(base);
	}

	template <typename type_t>
	type_t exp(type_t arg) noexcept(true)
	{
		is_float_static_assert(type_t);

		const bool is_neg = arg < 0;
		arg = pix::math::abs(arg);

		type_t
			result = 1,
			term = 1;

		// Logger
		LOGGER_INIT("logs/math_exp.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTHRESHOLD = " + std::to_string(pix::math::PR_THRESHOLD));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(pix::math::MAX_ITER));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\targ = " + std::to_string(arg) + " | Result = " + std::to_string(result));
		}
		
		for (unsigned long i = 1; i <= pix::math::MAX_ITER; ++i)
		{
			term *= arg / i;

			if (pix::math::abs(term) < pix::math::PR_THRESHOLD)
				break;
			
			result += term;

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\tTerm: " + std::to_string(term));
				LOGGER_LOG_MSG("\tResult: " + std::to_string(result));
			}
		}

		if (is_neg)
			return 1 / result;
		
		return result;
	}

	template <typename type_t>
	type_t pow(type_t base, type_t exponent) noexcept(false)
	{
		is_float_static_assert(type_t);

		if (base == 0 && exponent == 0) throw "Indeterminate case of 0^0";

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
			return pix::math::NaN();

		return result;
	}

	template <typename type_t>
	type_t root(const type_t arg, const type_t index) noexcept(false)
	{
		is_float_static_assert(type_t);
		
		if (arg < 0) throw "Argument is a negative number";
		if (index == 0) throw "Index is equal to zero";
		
		if (index == 1)
			return arg;

		return pix::math::pow(arg, 1 / index);
	}

	unsigned long permut(const unsigned long n, const unsigned long k) noexcept(false)
	{
		if (k > n)
			return 0;

		return pix::math::fact(n) / pix::math::fact(n - k);
	}

	template <unsigned long n, unsigned long k>
	struct permutation
	{
		static constexpr const unsigned long value = pix::math::factorial<n>::value / pix::math::factorial<n - k>::value;
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

		return pix::math::fact(total_num) / (pix::math::fact(choosing_num) * pix::math::fact(total_num - choosing_num));
	}

	template <unsigned long n, unsigned long k>
	struct combination
	{
		static constexpr const unsigned long value = pix::math::factorial<n>::value / (pix::math::factorial<k>::value * pix::math::factorial<n - k>::value);
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
