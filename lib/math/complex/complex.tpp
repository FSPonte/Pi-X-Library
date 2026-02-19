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
	complex<type_t>::complex(const type_t REAL, const type_t IMAG) : complex<type_t>()
	{
		this->_re = REAL;
		this->_im = IMAG;
	}

	template <typename type_t>
	void complex<type_t>::set_re(const type_t REAL)
	{
		this->_re = REAL;
	}

	template <typename type_t>
	type_t complex<type_t>::get_re(void) const
	{
		return this->_re;
	}

	template <typename type_t>
	void complex<type_t>::set_im(const type_t IMAG)
	{
		this->_im = IMAG;
	}

	template <typename type_t>
	type_t complex<type_t>::get_im(void) const
	{
		return this->_im;
	}

	template <typename type_t>
	void complex<type_t>::operator = (const complex<type_t>& CPX)
	{
		this->_re = CPX._re;
		this->_im = CPX._im;
	}

	template <typename type_t>
	bool complex<type_t>::operator == (const complex<type_t>& CPX) const
	{
		if (this->_re == CPX._re && this->_im == CPX._im)
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
		return complex<type_t>(this->_re * SCALAR, this->_im * SCALAR);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator + (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_re + CPX._re, this->_im + CPX._im);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator - (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_re - CPX._re, this->_im - CPX._im);
	}

	template <typename type_t>
	complex<type_t> complex<type_t>::operator * (const complex<type_t>& CPX) const
	{
		return complex<type_t>(this->_re * CPX._re - this->_im * CPX._im, this->_re * CPX._im + this->_im * CPX._re);
	}
}

#endif // _COMPLEX_TPP_