#ifndef _COMPLEX_TPP_
#define _COMPLEX_TPP_

namespace pix::math
{
	template <typename type_t>
	complex<type_t>::complex(void)
	{
		assert_is_number(type_t);
	}

	template <typename type_t>
	complex<type_t>::complex(const type_t real, const type_t imag) : complex<type_t>()
	{
		this->_real = real;
		this->_imag = imag;
	}

	template <typename type_t>
	void complex<type_t>::set_re(const type_t real)
	{
		this->_real = real;
	}

	template <typename type_t>
	type_t complex<type_t>::get_re(void) const
	{
		return this->_real;
	}

	template <typename type_t>
	void complex<type_t>::set_im(const type_t imag)
	{
		this->_imag = imag;
	}

	template <typename type_t>
	type_t complex<type_t>::get_im(void) const
	{
		return this->_imag;
	}

	template <typename type_t>
	void complex<type_t>::operator = (const complex<type_t>& CPX)
	{
		this->_real = CPX._real;
		this->_imag = CPX._imag;
	}

	template <typename type_t>
	bool complex<type_t>::operator == (const complex<type_t>& CPX) const
	{
		if (this->_real == CPX._real && this->_imag == CPX._imag)
			return true;

		return false;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool complex<type_t>::operator == (const complex<_type_t>& CPX) const
	{
		return false;
	}

	template <typename type_t>
	bool complex<type_t>::operator != (const complex<type_t>& CPX) const
	{
		return !(*this == CPX);
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool complex<type_t>::operator != (const complex<_type_t>& CPX) const
	{
		return true;
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator * (const type_t SCALAR) const
	{
		return complex<type_t>(this->_real * SCALAR, this->_imag * SCALAR);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator + (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_real + CPX._real, this->_imag + CPX._imag);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator - (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_real - CPX._real, this->_imag - CPX._imag);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator * (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_real * CPX._real - this->_imag * CPX._imag, this->_real * CPX._imag + this->_imag * CPX._real);
	}
}

#endif // _COMPLEX_TPP_
