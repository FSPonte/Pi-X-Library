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
	void swap(type_t* arr_1, type_t* arr_2) noexcept(false)
	{
		if (arr_1 == nullptr)
			throw "Pointer to first array is null";

		if (arr_2 == nullptr)
			throw "Pointer to second array is null";

		type_t* aux = arr_1; // Auxiliar pointer
		arr_1 = arr_2;
		arr_2 = aux;
	}

	template <typename type_t>
	void invert(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		is_number_static_assert(type_t);

		if (arr == nullptr)
			throw "Pointer to array is null";

		if (DIM == 0)
			throw "Dimension is null";

		unsigned long
			left_ind = 0,
			right_ind = DIM - 1;
		type_t aux; // Auxiliar value

		while (left_ind < right_ind)
		{
			pix::c_array::swap(arr[left_ind], arr[right_ind]);

			++left_ind;
			--right_ind;
		}
	}

	template <typename type_t, unsigned long DIM>
	void copy(const type_t (&arr_o)[DIM], type_t (&arr_d)[DIM]) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM; ++i)
			arr_d[i] = arr_o[i];
	}

	template <typename type_t>
	void copy(const type_t arr_o[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		if (arr_o == nullptr)
			throw "Pointer to origin array is null";

		if (arr_d == nullptr)
			throw "Pointer to destination array is null";

		if (DIM == 0)
			throw "Dimension is null";

		pix::c_array::copy<type_t, DIM>(arr_o, arr_d);
	}

	template <typename type_t, unsigned long DIM_1, unsigned long DIM_2>
	void copy(const type_t (&arr_o)[DIM_1][DIM_2], type_t (&arr_d)[DIM_1][DIM_2]) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM_1; ++i)
			pix::c_array::copy(arr_o[i], arr_d[i]);
	}

	template <typename type_t>
	void copy(const type_t* arr_o[], type_t* arr_d[], const unsigned long DIM_1, const unsigned long DIM_2) noexcept(false)
	{
		if (arr_o == nullptr)
			throw "Pointer to origin array is null";

		if (arr_d == nullptr)
			throw "Pointer to destination array is null";

		if (DIM_1 == 0)
			throw "Dimension 1 is null";

		if (DIM_2 == 0)
			throw "Dimension 2 is null";

		pix::c_array::copy<type_t, DIM_1, DIM_2>(arr_o, arr_d);
	}

	template <typename type_t, unsigned long DIM>
	void move(type_t (&arr_o)[DIM], type_t (&arr_d)[DIM]) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM; ++i)
		{
			arr_d[i] = arr_o[i];
			arr_o[i] = type_t();
		}
	}

	template <typename type_t>
	void move(type_t arr_o[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		if (arr_o == nullptr)
			throw "Pointer to origin array is null";

		if (arr_d == nullptr)
			throw "Pointer to destination array is null";

		if (DIM == 0)
			throw "Dimension is null";

		pix::c_array::move<type_t, DIM>(arr_o, arr_d);
	}

	template <typename type_t>
	void left_shift(type_t arr[], unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr)
			throw "Pointer to array is null";

		if (DIM == 0)
			throw "Dimension is null";

		--DIM;

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = arr[i + 1];
	}

	template <typename type_t>
	void right_shift(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr)
			throw "Pointer to array is null";

		if (DIM == 0)
			throw "Dimension is null";

		for (unsigned long i = 1; i < DIM; ++i)
			arr[i] = arr[i - 1];
	}

	template <typename type_t>
	void bit_rev(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		unsigned long bit, j = 0;

		for (unsigned long i = 1; i < DIM; ++i)
		{
			bit = DIM >> 1;
			
			while (j >= bit)
			{
				j -= bit;
				bit >>= 1;
			}
			
			j += bit;
			
			if (i < j)
				swap(arr[i], arr[j]);
		}
	}
}

#endif // _C_ARRAY_TPP_
