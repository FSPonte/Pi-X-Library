#ifndef _STAT_TPP_
#define _STAT_TPP_

// Dependencies
#include <asserts.hpp>
#include <math.hpp>

namespace pix::math::stat
{
	template <typename type_t>
	type_t min(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		type_t min = ARR[0];

		for (unsigned long i = 1; i < DIM; ++i)
		{
			if (ARR[i] < min)
				min = ARR[i];
		}

		return min;
	}
	
	template <typename type_t>
	type_t max(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		type_t max = ARR[0];

		for (unsigned long i = 1; i < DIM; ++i)
		{
			if (ARR[i] > max)
				max = ARR[i];
		}

		return max;
	}

	template <typename type_t>
	type_t amp(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		return pix::math::abs(pix::math::stat::max(ARR, DIM) - pix::math::stat::min(ARR, DIM));
	}

	template <typename type_t>
	type_t abs_err(const type_t VALUE_EXACT, const type_t VALUE_APPROX) noexcept(true)
	{
		return pix::math::abs(VALUE_EXACT - VALUE_APPROX);
	}

	template <typename type_t>
	type_t rel_err(const type_t VALUE_EXACT, const type_t VALUE_APPROX) noexcept(true)
	{
		return pix::math::stat::abs_err(VALUE_EXACT, VALUE_APPROX) / VALUE_EXACT;
	}

	template <typename type_t>
	type_t sum(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += ARR[i];

		return result;
	}

	template <typename type_t>
	type_t mean(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		return pix::math::stat::sum(ARR, DIM) / DIM;
	}

	template <typename type_t>
	type_t median(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		if (DIM % 2 == 0)
			return (ARR[DIM / 2] + ARR[(DIM / 2) - 1]) / 2;

		return ARR[(DIM + 1) / 2];
	}

	template <typename type_t>
	type_t var(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t mean = pix::math::stat::mean(ARR, DIM);
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += (ARR[i] - mean) * (ARR[i] - mean);

		return result / DIM;
	}

	template <typename type_t>
	type_t std_dev(const type_t ARR[], const unsigned long DIM) noexcept(false)
	{
		return pix::math::root(pix::math::stat::var(ARR, DIM), 2);
	}

	template <typename type_t>
	type_t covar(const type_t INPUT[], const type_t OUTPUT[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (INPUT == nullptr) throw "Pointer to input array is null";
		if (OUTPUT == nullptr) throw "Pointer to output array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t
			mean_input = pix::math::stat::mean(INPUT, DIM),
			mean_output = pix::math::stat::mean(OUTPUT, DIM);
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += (INPUT[i] - mean_input) * (OUTPUT[i] - mean_output);

		return result / DIM;
	}

	template <typename type_t>
	type_t coeff_det(const type_t ARR[], const type_t MODEL[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (ARR == nullptr) throw "Pointer to array is null";
		if (MODEL == nullptr) throw "Pointer to model is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t mean = pix::math::stat::mean(ARR, DIM);

		type_t
			sum_squared_errors = 0,
			total_sum_squares = 0;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			sum_squared_errors += (ARR[i] - MODEL[i]) * (ARR[i] - MODEL[i]);
			total_sum_squares += (ARR[i] - mean) * (ARR[i] - mean);
		}

		return 1 - sum_squared_errors / total_sum_squares;
	}
}

#endif // _STAT_TPP_
