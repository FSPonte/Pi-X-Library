#ifndef _STAT_TPP_
#define _STAT_TPP_

namespace pix::math::stat
{
	template <typename type_t>
	type_t min(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		type_t min = arr[0];

		for (unsigned long i = 1; i < DIM; ++i)
		{
			if (arr[i] < min)
				min = arr[i];
		}

		return min;
	}
	
	template <typename type_t>
	type_t max(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		type_t max = arr[0];

		for (unsigned long i = 1; i < DIM; ++i)
		{
			if (arr[i] > max)
				max = arr[i];
		}

		return max;
	}

	template <typename type_t>
	type_t amp(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM <= 1) throw "Dimension is null";

		return pix::math::abs(pix::math::stat::max(arr, DIM) - pix::math::stat::min(arr, DIM));
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
	type_t sum(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += arr[i];

		return result;
	}

	template <typename type_t>
	type_t mean(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		return pix::math::stat::sum(arr, DIM) / DIM;
	}

	template <typename type_t>
	type_t median(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		if (DIM % 2 == 0)
			return (arr[DIM / 2] + arr[(DIM / 2) - 1]) / 2;

		return arr[(DIM + 1) / 2];
	}

	template <typename type_t>
	type_t var(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t mean = pix::math::stat::mean(arr, DIM);
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += (arr[i] - mean) * (arr[i] - mean);

		return result / DIM;
	}

	template <typename type_t>
	type_t std_dev(const type_t arr[], const unsigned long DIM) noexcept(false)
	{
		return pix::math::root(pix::math::stat::var(arr, DIM), 2);
	}

	template <typename type_t>
	type_t covar(const type_t input[], const type_t output[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (input == nullptr) throw "Pointer to input array is null";
		if (output == nullptr) throw "Pointer to output array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t
			mean_input = pix::math::stat::mean(input, DIM),
			mean_output = pix::math::stat::mean(output, DIM);
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += (input[i] - mean_input) * (output[i] - mean_output);

		return result / DIM;
	}

	template <typename type_t>
	type_t coeff_det(const type_t arr[], const type_t model[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (model == nullptr) throw "Pointer to model is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t mean = pix::math::stat::mean(arr, DIM);

		type_t
			sum_squared_errors = 0,
			total_sum_squares = 0;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			sum_squared_errors += (arr[i] - model[i]) * (arr[i] - model[i]);
			total_sum_squares += (arr[i] - mean) * (arr[i] - mean);
		}

		return 1 - sum_squared_errors / total_sum_squares;
	}
}

#endif // _STAT_TPP_
