#ifndef _C_ARRAY_TPP_
#define _C_ARRAY_TPP_

namespace pix::c_array
{
	template <typename type_t>
	inline void swap(type_t& ref_1, type_t& ref_2) noexcept(true)
	{
		const type_t aux = ref_1; // Auxiliar value
		ref_1 = ref_2;
		ref_2 = aux;
	}

	template <typename type_t>
	void swap(type_t* ptr_1, type_t* ptr_2) noexcept(false)
	{
		if (ptr_1 == nullptr || ptr_2 == nullptr) throw pix::exceptions::null_ptr;

		type_t* aux = ptr_1; // Auxiliar pointer
		ptr_1 = ptr_2;
		ptr_2 = aux;
	}

	template <typename type_t>
	void invert(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		unsigned long
			left_ind = 0,
			right_ind = DIM - 1;

		while (left_ind < right_ind)
		{
			pix::c_array::swap(arr[left_ind], arr[right_ind]);

			++left_ind;
			--right_ind;
		}
	}

	template <typename type_t, unsigned long DIM>
	void invert(type_t (&arr)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		pix::c_array::invert<type_t>(arr, DIM);
	}

	template <typename type_t>
	void copy(const type_t ARR_O[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		if (ARR_O == nullptr || arr_d == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = 0; i < DIM; ++i)
			arr_d[i] = ARR_O[i];
	}

	template <typename type_t, unsigned long DIM>
	void copy(const type_t (&ARR_O)[DIM], type_t (&arr_d)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		pix::c_array::copy<type_t>(ARR_O, arr_d, DIM);
	}

	template <typename type_t>
	void copy(const type_t* ARR_O[], type_t* arr_d[], const unsigned long DIM_1, const unsigned long DIM_2) noexcept(false)
	{
		if (ARR_O == nullptr || arr_d == nullptr) throw pix::exceptions::null_ptr;
		if (DIM_1 == 0 || DIM_2 == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = 0; i < DIM_1; ++i)
			pix::c_array::copy<type_t>(ARR_O[i], arr_d[i], DIM_2);
	}

	template <typename type_t, unsigned long DIM_1, unsigned long DIM_2>
	void copy(const type_t (&ARR_O)[DIM_1][DIM_2], type_t (&arr_d)[DIM_1][DIM_2]) noexcept(true)
	{
		assert_not_nulldim(DIM_1);
		assert_not_nulldim(DIM_2);

		for (unsigned long i = 0; i < DIM_1; ++i)
			pix::c_array::copy<type_t>(ARR_O[i], arr_d[i], DIM_2);
	}

	template <typename type_t>
	void move(type_t arr_o[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		if (arr_o == nullptr || arr_d == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			arr_d[i] = arr_o[i];
			arr_o[i] = type_t();
		}
	}

	template <typename type_t, unsigned long DIM>
	void move(type_t (&arr_o)[DIM], type_t (&arr_d)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		pix::c_array::move<type_t>(arr_o, arr_d, DIM);
	}

	template <typename type_t>
	void left_shift(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = 1; i < DIM; ++i)
			arr[i - 1] = arr[i];

		arr[DIM - 1] = type_t();
	}

	template <typename type_t, unsigned long DIM>
	void left_shift(type_t (&arr)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		pix::c_array::left_shift<type_t>(arr, DIM);
	}

	template <typename type_t>
	void right_shift(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;

		for (unsigned long i = DIM - 1; i > 0; --i)
			arr[i] = arr[i - 1];

		arr[0] = type_t();
	}

	template <typename type_t, unsigned long DIM>
	void right_shift(type_t (&arr)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		pix::c_array::right_shift<type_t>(arr, DIM);
	}

	template <typename type_t>
	void bit_rev(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr) throw pix::exceptions::null_ptr;
		if (DIM == 0) throw pix::exceptions::null_dim;
		if ((DIM & (DIM - 1)) != 0) throw "Dimension must be a power of 2";

		unsigned long
			j = 0,
			bit;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (i < j)
				pix::c_array::swap(arr[i], arr[j]);

			bit = DIM >> 1;
			
			while (j & bit)
			{
				j ^= bit;
				bit >>= 1;
			}

			j ^= bit;
		}
	}

	template <typename type_t, unsigned long DIM>
	void bit_rev(type_t (&arr)[DIM]) noexcept(true)
	{
		static_assert
		(
			(DIM & (DIM - 1)) == 0,
			"Dimension must be a power of 2"
		);

		pix::c_array::bit_rev<type_t>(arr, DIM);
	}
}

#endif // _C_ARRAY_TPP_
