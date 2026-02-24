#ifndef _VECTOR_TPP_
#define _VECTOR_TPP_

namespace pix::math
{
	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM>::vector(void)
	{
		assert_not_nulldim(DIM);
		assert_is_number(type_t);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM>::vector(const type_t arr[]) : vector<type_t, DIM>()
	{
		*this = arr;
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM>::vector(const vector<type_t, DIM>& vec) : vector<type_t, DIM>()
	{
		*this = vec;
	}

	template <typename type_t, unsigned long DIM>
	const type_t* vector<type_t, DIM>::buffer(void) const
	{
		return this->_data;
	}

	template <typename type_t, unsigned long DIM>
	type_t& vector<type_t, DIM>::operator [] (const unsigned long index) noexcept(false)
	{
		if (index >= DIM)
			throw pix::exceptions::out_of_bounds;

		return this->_data[index];
	}

	template <typename type_t, unsigned long DIM>
	constexpr unsigned long vector<type_t, DIM>::dim(void) const
	{
		return DIM;
	}

	template <typename type_t, unsigned long DIM>
	void vector<type_t, DIM>::operator = (const type_t arr[]) noexcept(false)
	{
		if (arr == nullptr)
			throw pix::exceptions::null_ptr;

		for (unsigned long i = 0; i < DIM; ++i)
			this->_data[i] = arr[i];
	}

	template <typename type_t, unsigned long DIM>
	void vector<type_t, DIM>::operator = (const vector<type_t, DIM>& vec)
	{
		*this = vec.buffer();
	}

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr bool vector<type_t, DIM>::operator == (const vector<_type_t, _DIM>& vec)
	{
		return false;
	}

	template <typename type_t, unsigned long DIM>
	bool vector<type_t, DIM>::operator == (const vector<type_t, DIM>& vec)
	{
		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (this->_data[i] != vec._data[i])
				return false;
		}

		return true;
	}

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr bool vector<type_t, DIM>::operator != (const vector<_type_t, _DIM>& vec)
	{
		return true;
	}

	template <typename type_t, unsigned long DIM>
	bool vector<type_t, DIM>::operator != (const vector<type_t, DIM>& vec)
	{
		return !(*this == vec);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator + (const vector<type_t, DIM>& vec) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] + vec._data[i];

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator - (const vector<type_t, DIM>& vec) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] - vec._data[i];

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator * (const type_t scalar) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] * scalar;

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator / (const type_t scalar) const
	{
		if (scalar == 0)
			return pix::math::vector<type_t, DIM>();

		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] / scalar;

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	type_t vector<type_t, DIM>::operator ^ (const vector<type_t, DIM>& vec) const
	{
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += this->_data[i] * vec._data[i];

		return result;
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator * (const vector<type_t, DIM>& vec) const
	{
		static_assert
		(
			DIM == 3,
			"Vector product is only valid for three dimensional vectors"
		);

		type_t arr[DIM];

		arr[0] = this->_data[1] * vec._data[2] - this->_data[2] * vec._data[1];
		arr[1] = this->_data[2] * vec._data[0] - this->_data[0] * vec._data[2];
		arr[2] = this->_data[0] * vec._data[1] - this->_data[1] * vec._data[0];

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM>::operator type_t() const
	{
		type_t norm = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			norm += this->_data[i] * this->_data[i];

		return norm;
	}
}

#endif // _VECTOR_TPP_
