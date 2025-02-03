#ifndef _STAT_TPP_
#define _STAT_TPP_

namespace pix::math::stat
{
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
