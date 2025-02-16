#ifndef _STAT_TPP_
#define _STAT_TPP_

namespace pix::math::stat
{
	template <typename type_t>
	type_t min(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim <= 1)
			throw "Dimension is null";

		type_t min = arr[0];

		for (unsigned long i = 1; i < dim; ++i)
		{
			if (arr[i] < min)
				min = arr[i];
		}

		return min;
	}
	
	template <typename type_t>
	type_t max(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim <= 1)
			throw "Dimension is null";

		type_t max = arr[0];

		for (unsigned long i = 1; i < dim; ++i)
		{
			if (arr[i] > max)
				max = arr[i];
		}

		return max;
	}

	template <typename type_t>
	type_t amp(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim <= 1)
			throw "Dimension is null";

		return abs(max(arr, dim) - min(arr, dim));
	}

	template <typename type_t>
	type_t abs_err(const type_t value_exact, const type_t value_approx) noexcept(true)
	{ return abs(value_exact - value_approx); }

	template <typename type_t>
	type_t rel_err(const type_t value_exact, const type_t value_approx) noexcept(true)
	{ return abs_err(value_exact, value_approx) / value_exact; }

	template <typename type_t>
	type_t sum(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		type_t result = 0;

		for (unsigned long i = 0; i < dim; ++i)
			result += arr[i];

		return result;
	}

	template <typename type_t>
	type_t mean(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		return stat::sum(arr, dim) / dim;
	}

	template <typename type_t>
	type_t median(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		if (dim % 2 == 0)
			return (arr[dim / 2] + arr[(dim / 2) - 1]) / 2;

		return arr[(dim + 1) / 2];
	}

	template <typename type_t>
	type_t var(const type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		const type_t mean = stat::mean(arr, dim);
		type_t result = 0;

		for (unsigned long i = 0; i < dim; ++i)
			result += (arr[i] - mean) * (arr[i] - mean);

		return result / dim;
	}

	template <typename type_t>
	type_t std_dev(const type_t arr[], const unsigned long dim) noexcept(false)
	{ return math::root(stat::var(arr, dim), 2); }

	template <typename type_t>
	type_t covar(const type_t input[], const type_t output[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (input == nullptr)
			throw "Pointer to input array is null";

		if (output == nullptr)
			throw "Pointer to output array is null";

		if (dim == 0)
			throw "Dimension is null";

		const type_t
			mean_input = stat::mean(input, dim),
			mean_output = stat::mean(output, dim);
		type_t result = 0;

		for (unsigned long i = 0; i < dim; ++i)
			result += (input[i] - mean_input) * (output[i] - mean_output);

		return result / dim;
	}

	template <typename type_t>
	type_t coeff_det(const type_t arr[], const type_t model[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (model == nullptr)
			throw "Pointer to model is null";

		if (dim == 0)
			throw "Dimension is null";

		const type_t mean = stat::mean(arr, dim);

		type_t
			sum_squared_errors = 0,
			total_sum_squares = 0;

		for (unsigned long i = 0; i < dim; ++i)
		{
			sum_squared_errors += (arr[i] - model[i]) * (arr[i] - model[i]);
			total_sum_squares += (arr[i] - mean) * (arr[i] - mean);
		}

		return 1 - sum_squared_errors / total_sum_squares;
	}
}

#endif // _STAT_TPP_
