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
	vector<type_t, DIM>::vector(const type_t ARR[]) : vector<type_t, DIM>()
	{
		*this = ARR;
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM>::vector(const vector<type_t, DIM>& VEC) : vector<type_t, DIM>()
	{
		*this = VEC;
	}

	template <typename type_t, unsigned long DIM>
	const type_t* vector<type_t, DIM>::buffer(void) const
	{
		return this->_data;
	}

	template <typename type_t, unsigned long DIM>
	type_t& vector<type_t, DIM>::operator [] (const unsigned long INDEX) noexcept(false)
	{
		if (INDEX >= DIM) throw pix::exceptions::out_of_bounds;

		return this->_data[INDEX];
	}

	template <typename type_t, unsigned long DIM>
	constexpr unsigned long vector<type_t, DIM>::dim(void) const
	{
		return DIM;
	}

	template <typename type_t, unsigned long DIM>
	void vector<type_t, DIM>::operator = (const type_t ARR[]) noexcept(false)
	{
		if (ARR == nullptr) throw pix::exceptions::null_ptr;

		for (unsigned long i = 0; i < DIM; ++i)
			this->_data[i] = ARR[i];
	}

	template <typename type_t, unsigned long DIM>
	void vector<type_t, DIM>::operator = (const vector<type_t, DIM>& VEC)
	{
		*this = VEC.buffer();
	}

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr bool vector<type_t, DIM>::operator == (const vector<_type_t, _DIM>& VEC)
	{
		return false;
	}

	template <typename type_t, unsigned long DIM>
	bool vector<type_t, DIM>::operator == (const vector<type_t, DIM>& VEC)
	{
		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (this->_data[i] != VEC._data[i])
				return false;
		}

		return true;
	}

	template <typename type_t, unsigned long DIM>
	template <typename _type_t, unsigned long _DIM>
	constexpr bool vector<type_t, DIM>::operator != (const vector<_type_t, _DIM>& VEC)
	{
		return true;
	}

	template <typename type_t, unsigned long DIM>
	bool vector<type_t, DIM>::operator != (const vector<type_t, DIM>& VEC)
	{
		return !(*this == VEC);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator + (const vector<type_t, DIM>& VEC) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] + VEC._data[i];

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator - (const vector<type_t, DIM>& VEC) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] - VEC._data[i];

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator * (const type_t SCALAR) const
	{
		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] * SCALAR;

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator / (const type_t SCALAR) const
	{
		if (SCALAR == 0)
			return pix::math::vector<type_t, DIM>();

		type_t arr[DIM];

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] = this->_data[i] / SCALAR;

		return pix::math::vector<type_t, DIM>(arr);
	}

	template <typename type_t, unsigned long DIM>
	type_t vector<type_t, DIM>::operator ^ (const vector<type_t, DIM>& VEC) const
	{
		type_t result = 0;

		for (unsigned long i = 0; i < DIM; ++i)
			result += this->_data[i] * VEC._data[i];

		return result;
	}

	template <typename type_t, unsigned long DIM>
	vector<type_t, DIM> vector<type_t, DIM>::operator * (const vector<type_t, DIM>& VEC) const
	{
		static_assert
		(
			DIM == 3,
			"Vector product is only valid for three dimensional vectors"
		);

		type_t arr[DIM];

		arr[0] = this->_data[1] * VEC._data[2] - this->_data[2] * VEC._data[1];
		arr[1] = this->_data[2] * VEC._data[0] - this->_data[0] * VEC._data[2];
		arr[2] = this->_data[0] * VEC._data[1] - this->_data[1] * VEC._data[0];

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