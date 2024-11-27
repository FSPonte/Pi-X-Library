#ifndef _SORT_TPP_
#define _SORT_TPP_

// Dependencies
#include <c_array.hpp>

template <typename type_t>
static const unsigned long _partition_(type_t[], unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _quick_sort_(type_t[], unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _merge_(type_t[], unsigned long, unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _merge_sort_(type_t[], unsigned long, unsigned long) noexcept(true);

namespace pix::sort
{
	template <typename type_t>
	void bubble_sort(type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		type_t aux; // Auxiliar value

		for (unsigned long i = 0; i < dim; ++i)
		{
			for (unsigned long j = 0; j < dim - 1; ++j)
			{
				if (arr[j] <= arr[j + 1])
					continue;

				pix::c_array::swap(arr, j, j + 1);
			}
		}
	}

	template <typename type_t>
	void selection_sort(type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		unsigned long min_ind; // Index of minimum value
		type_t aux; // Auxiliar value

		for (unsigned long i = 0; i < dim; ++i)
		{
			min_ind = i;

			for (unsigned long j = i + 1; j < dim; ++j)
			{
				if (arr[min_ind] <= arr[j])
					continue;

				min_ind = j;
			}

			pix::c_array::swap(arr, i,min_ind);
		}
	}

	template <typename type_t>
	void insertion_sort(type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		unsigned long j;
		type_t aux;

		for (unsigned long i = 1; i < dim; ++i)
		{
			aux = arr[i];

			for (j = i - 1; j >= 0 && arr[j] > aux; --j)
				arr[j + 1] = arr[j];

			arr[j + 1] = aux;
		}
	}

	template <typename type_t>
	void quick_sort(type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		_quick_sort_(arr, 0, dim - 1);
	}

	template <typename type_t>
	void merge_sort(type_t arr[], const unsigned long dim) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (dim == 0)
			throw "Dimension is null";

		_merge_sort_(arr, 0, dim - 1);
	}
}

template <typename type_t>
static const unsigned long _partition_(type_t arr[], const unsigned long start_ind, const unsigned long end_ind) noexcept(true)
{
	unsigned long count = 0;
	type_t pivot = arr[start_ind];

	for (unsigned long i = start_ind + 1; i <= end_ind; ++i)
	{
		if (arr[i] > pivot)
			continue;

		++count;
	}

	unsigned long pi_ind = start_ind + count;
	pix::c_array::swap(arr[pi_ind], arr[start_ind]);

	// Sorting left and right parts of the pivot element
	unsigned long
		left_ind = start_ind,
		right_ind = end_ind;

	while (left_ind < pi_ind && right_ind > pi_ind)
	{
		while (arr[left_ind] <= pivot)
			++left_ind;

		while (arr[right_ind] > pivot)
			--right_ind;

		if (left_ind < pi_ind && right_ind > pi_ind)
		{
			pix::c_array::swap(arr[left_ind], arr[right_ind]);
			++left_ind;
			--right_ind;
		}
	}
 
	return pi_ind;
}

template <typename type_t>
static void _quick_sort_(type_t arr[], const unsigned long start_ind, const unsigned long end_ind) noexcept(true)
{
	if (start_ind >= end_ind)
		return;

	const unsigned long part_ind = _partition_(arr, start_ind, end_ind); // Partition index

	_quick_sort_(arr, start_ind, part_ind - 1);
	_quick_sort_(arr, part_ind + 1, end_ind);
}

template <typename type_t>
static void _merge_(type_t arr[], const unsigned long start_ind, const unsigned long mid_ind, const unsigned long end_ind) noexcept(true)
{
	const unsigned long
		left_dim = mid_ind - start_ind + 1,
		right_dim = end_ind - mid_ind;

	auto
		*left_arr = new type_t[left_dim],
		*right_arr = new type_t[right_dim];

	for (unsigned long i = 0; i < left_dim; ++i)
		left_arr[i] = arr[start_ind + i];

	for (unsigned long i = 0; i < right_dim; ++i)
		right_arr[i] = arr[mid_ind + i + 1];

	unsigned long
		left_ind = 0,
		right_ind = 0,
		arr_ind;

	for (arr_ind = start_ind; left_ind < left_dim && right_ind < right_dim; ++arr_ind)
	{
		if (left_arr[left_ind] <= right_arr[right_ind])
		{
			arr[arr_ind] = left_arr[left_ind];
			++left_ind;
		}
		else
		{
			arr[arr_ind] = right_arr[right_ind];
			++right_ind;
		}
	}

	while (left_ind < left_dim)
	{
		arr[arr_ind] = left_arr[left_ind];
		++arr_ind;
		++left_ind;
	}

	while (right_ind < right_dim)
	{
		arr[arr_ind] = right_arr[right_ind];
		++arr_ind;
		++right_ind;
	}

	delete[] left_arr;
	delete[] right_arr;
}

template <typename type_t>
static void _merge_sort_(type_t arr[], const unsigned long start_ind, const unsigned long end_ind) noexcept(true)
{
	if (start_ind >= end_ind)
		return;

	const unsigned long mid_ind = start_ind + (end_ind - start_ind) / 2;

	_merge_sort_(arr, start_ind, mid_ind);
	_merge_sort_(arr, mid_ind + 1, end_ind);

	_merge_(arr, start_ind, mid_ind, end_ind);
}

#endif // _SORT_TPP_
