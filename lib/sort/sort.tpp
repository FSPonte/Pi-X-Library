#ifndef _SORT_TPP_
#define _SORT_TPP_

template <typename type_t>
static unsigned long _partition_(type_t[], unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _quick_sort_(type_t[], unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _merge_(type_t[], unsigned long, unsigned long, unsigned long) noexcept(true);

template <typename type_t>
static void _merge_sort_(type_t[], unsigned long, unsigned long) noexcept(true);

namespace pix::sort
{
	template <typename type_t>
	void bubble_sort(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			for (unsigned long j = 0; j < DIM - 1; ++j)
			{
				if (arr[j] <= arr[j + 1])
					continue;

				pix::c_array::swap(arr[j], arr[j + 1]);
			}
		}
	}

	template <typename type_t, unsigned long DIM>
	void bubble_sort(type_t (&arr)[DIM])
	{
		assert_is_number(type_t);

		pix::sort::bubble_sort(arr, DIM);
	}

	template <typename type_t>
	void selection_sort(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		unsigned long min_ind; // Index of minimum value

		for (unsigned long i = 0; i < DIM; ++i)
		{
			min_ind = i;

			for (unsigned long j = i + 1; j < DIM; ++j)
			{
				if (arr[min_ind] <= arr[j])
					continue;

				min_ind = j;
			}

			pix::c_array::swap(arr[i], arr[min_ind]);
		}
	}

	template <typename type_t, unsigned long DIM>
	void selection_sort(type_t (&arr)[DIM])
	{
		assert_is_number(type_t);

		pix::sort::selection_sort(arr, DIM);
	}

	template <typename type_t>
	void insertion_sort(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		unsigned long j;
		type_t aux;

		for (unsigned long i = 1; i < DIM; ++i)
		{
			aux = arr[i];

			for (j = i - 1; j > 0 && arr[j] > aux; --j)
				arr[j + 1] = arr[j];

			arr[j + 1] = aux;
		}
	}

	template <typename type_t, unsigned long DIM>
	void insertion_sort(type_t (&arr)[DIM])
	{
		assert_is_number(type_t);

		pix::sort::insertion_sort(arr, DIM);
	}

	template <typename type_t>
	void quick_sort(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		_quick_sort_(arr, 0, DIM - 1);
	}

	template <typename type_t, unsigned long DIM>
	void quick_sort(type_t (&arr)[DIM])
	{
		assert_is_number(type_t);

		pix::sort::quick_sort(arr, DIM);
	}

	template <typename type_t>
	void merge_sort(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		_merge_sort_(arr, 0, DIM - 1);
	}

	template <typename type_t, unsigned long DIM>
	void merge_sort(type_t (&arr)[DIM])
	{
		assert_is_number(type_t);

		pix::sort::merge_sort(arr, DIM);
	}
}

template <typename type_t>
static unsigned long _partition_(type_t arr[], unsigned long start_ind, unsigned long end_ind) noexcept(true)
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

	for (unsigned long i = 0; start_ind < pi_ind && end_ind > pi_ind; ++i)
	{
		while (arr[start_ind] <= pivot)
			++start_ind;

		while (arr[end_ind] > pivot)
			--end_ind;

		if (start_ind < pi_ind && end_ind > pi_ind)
		{
			pix::c_array::swap(arr[start_ind], arr[end_ind]);
			++start_ind;
			--end_ind;
		}
	}
 
	return pi_ind;
}

template <typename type_t>
static void _quick_sort_(type_t arr[], const unsigned long START_IND, const unsigned long END_IND) noexcept(true)
{
	if (START_IND >= END_IND)
		return;

	const unsigned long part_ind = _partition_(arr, START_IND, END_IND); // Partition index

	_quick_sort_(arr, START_IND, part_ind);
	_quick_sort_(arr, part_ind + 1, END_IND);
}

template <typename type_t>
static void _merge_(type_t arr[], const unsigned long START_IND, const unsigned long MID_IND, const unsigned long END_IND) noexcept(true)
{
	const unsigned long
		LEFT_DIM = MID_IND - START_IND + 1,
		RIGHT_DIM = END_IND - MID_IND;

	auto
		left_arr = new type_t[LEFT_DIM],
		right_arr = new type_t[RIGHT_DIM];

	for (unsigned long i = 0; i < LEFT_DIM; ++i)
		left_arr[i] = arr[START_IND + i];

	for (unsigned long i = 0; i < RIGHT_DIM; ++i)
		right_arr[i] = arr[MID_IND + i + 1];

	unsigned long
		left_ind = 0,
		right_ind = 0,
		arr_ind;

	for (arr_ind = START_IND; left_ind < LEFT_DIM && right_ind < RIGHT_DIM; ++arr_ind)
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

	while (left_ind < LEFT_DIM)
	{
		arr[arr_ind] = left_arr[left_ind];
		++arr_ind;
		++left_ind;
	}

	while (right_ind < RIGHT_DIM)
	{
		arr[arr_ind] = right_arr[right_ind];
		++arr_ind;
		++right_ind;
	}

	delete[] left_arr;
	delete[] right_arr;
}

template <typename type_t>
static void _merge_sort_(type_t arr[], const unsigned long START_IND, const unsigned long END_IND) noexcept(true)
{
	if (START_IND >= END_IND)
		return;

	const unsigned long MID_IND = START_IND + (END_IND - START_IND) / 2;

	_merge_sort_(arr, START_IND, MID_IND);
	_merge_sort_(arr, MID_IND + 1, END_IND);

	_merge_(arr, START_IND, MID_IND, END_IND);
}

#endif // _SORT_TPP_