#ifndef _COMPLEX_TPP_
#define _COMPLEX_TPP_

namespace pix::math
{
    template <typename type_t>
    complex<type_t>::complex(void)
    { is_number_static_assert(type_t); }

    template <typename type_t>
    complex<type_t>::complex(const type_t re, const type_t im) : complex<type_t>()
    {
        this->_re = re;
        this->_im = im;
    }

    template <typename type_t>
    void complex<type_t>::set_re(const type_t re)
    { this->_re = re; }

    template <typename type_t>
    type_t complex<type_t>::get_re(void) const
    { return this->_re; }

    template <typename type_t>
    void complex<type_t>::set_im(const type_t im)
    { this->_im = im; }

    template <typename type_t>
    type_t complex<type_t>::get_im(void) const
    { return this->_im; }

    template <typename type_t>
    void complex<type_t>::operator = (const complex<type_t>& cpx)
    {
        this->_re = cpx._re;
        this->_im = cpx._im;
    }

    template <typename type_t>
    const bool complex<type_t>::operator == (const complex<type_t>& cpx) const
    {
        if (this->_re == cpx._re && this->_im == cpx._im)
            return true;

        return false;
    }

    template <typename type_t>
    template <typename _type_t>
    constexpr const bool complex<type_t>::operator == (const complex<_type_t>& cpx) const
    { return false; }

    template <typename type_t>
    const bool complex<type_t>::operator != (const complex<type_t>& cpx) const
    { return !(*this == cpx); }

    template <typename type_t>
    template <typename _type_t>
    constexpr const bool complex<type_t>::operator != (const complex<_type_t>& cpx) const
    { return true; }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator * (const type_t scalar) const
    { return complex<type_t>(this->_re * scalar, this->_im * scalar); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator + (const complex<type_t>& cpx) const
    { return complex<type_t>(this->_re + cpx._re, this->_im + cpx._im); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator - (const complex<type_t>& cpx) const
    { return complex<type_t>(this->_re - cpx._re, this->_im - cpx._im); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator * (const complex<type_t>& cpx) const
    {
        return complex<type_t>
        (
            this->_re * cpx._re - this->_im * cpx._im,
            this->_re * cpx._im + this->_im * cpx._re
        );
    }
}

#endif // _COMPLEX_TPP_
