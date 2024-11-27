#ifndef _ARRAY_TPP_
#define _ARRAY_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long DIM>
	array<type_t, DIM>::array(void)
	{
		static_assert
		(
			DIM != 0,
			"Array object cannot have zero elements"
		);
	}

	template <typename type_t, unsigned long DIM>
	array<type_t, DIM>::array(const type_t arr[]) : array<type_t, DIM>()
	{ *this = arr; }

	template <typename type_t, unsigned long DIM>
	array<type_t, DIM>::array(const array<type_t, DIM>& arr) : array<type_t, DIM>()
	{ *this = arr; }

	template <typename type_t, unsigned long DIM>
	const type_t* array<type_t, DIM>::buffer(void) const
	{ return this->_data; }

	template <typename type_t, unsigned long DIM>
	type_t& array<type_t, DIM>::operator [] (unsigned long index) noexcept(false)
	{
		if (index >= DIM)
			throw "Index is out of bounds";

		return this->_data[index];
	}

	template <typename type_t, unsigned long DIM>
	constexpr const unsigned long array<type_t, DIM>::dim(void) const
	{ return DIM; }

	template <typename type_t, unsigned long DIM>
	void array<type_t, DIM>::operator = (const type_t arr[]) noexcept(false)
	{
		if (arr == nullptr)
			throw "Pointer to array is null";

		for (unsigned long i = 0; i < DIM; ++i)
			this->_data[i] = arr[i];
	}

	template <typename type_t, unsigned long DIM>
	void array<type_t, DIM>::operator = (const array<type_t, DIM>& arr)
	{ *this = arr.buffer(); }

	template <typename type_t, unsigned long DIM>
	const bool array<type_t, DIM>::operator == (const type_t arr[]) const
	{
		if (arr == nullptr)
			return false;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (this->_data[i] != arr[i])
				return false;
		}

		return true;
	}

	template <typename type_t, unsigned long DIM>
	template <typename _type_t>
	constexpr const bool array<type_t, DIM>::operator == (const _type_t arr[]) const
	{ return false; }

	template <typename type_t, unsigned long DIM>
	const bool array<type_t, DIM>::operator == (const array<type_t, DIM>& arr) const
	{ return *this == arr.buffer(); }

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr const bool array<type_t, DIM>::operator == (const array<_type_t, _DIM>& arr) const
	{ return false; }

	template <typename type_t, unsigned long DIM>
	const bool array<type_t, DIM>::operator != (const type_t arr[]) const
	{ return !(*this == arr); }

	template <typename type_t, unsigned long DIM>
	template <typename _type_t>
	constexpr const bool array<type_t, DIM>::operator != (const _type_t arr[]) const
	{ return true; }

	template <typename type_t, unsigned long DIM>
	const bool array<type_t, DIM>::operator != (const array<type_t, DIM>& arr) const
	{ return !(*this == arr.buffer()); }

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr const bool array<type_t, DIM>::operator != (const array<_type_t, _DIM>& arr) const
	{ return true; }
}

#endif // _ARRAY_TPP_
