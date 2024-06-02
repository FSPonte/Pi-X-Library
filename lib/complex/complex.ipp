#ifndef _COMPLEX_IPP_
#define _COMPLEX_IPP_

namespace pix::adt
{
    template <typename type_t>
    complex<type_t>::complex(void)
    { is_number_static_assert(type_t); }

    template <typename type_t>
    complex<type_t>::complex(const type_t re, const type_t im) : complex<type_t>()
    {
        this->re = re;
        this->im = im;
    }

    template <typename type_t>
    void complex<type_t>::set_re(const type_t re)
    { this->re = re; }

    template <typename type_t>
    type_t complex<type_t>::get_re(void) const
    { return this->re; }

    template <typename type_t>
    void complex<type_t>::set_im(const type_t im)
    { this->im = im; }

    template <typename type_t>
    type_t complex<type_t>::get_im(void) const
    { return this->im; }

    template <typename type_t>
    void complex<type_t>::operator = (const complex<type_t>& cpx)
    {
        this->re = cpx.re;
        this->im = cpx.im;
    }

    template <typename type_t>
    const bool complex<type_t>::operator == (const complex<type_t>& cpx) const
    {
        if (this->re == cpx.re && this->im == cpx.im)
            return true;

        return false;
    }

    template <typename type_t>
    const bool complex<type_t>::operator != (const complex<type_t>& cpx) const
    { return !(*this == cpx); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator * (const type_t scalar) const
    { return complex<type_t>(this->re * scalar, this->im * scalar); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator + (const complex<type_t>& cpx) const
    { return complex<type_t>(this->re + cpx.re, this->im + cpx.im); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator - (const complex<type_t>& cpx) const
    { return complex<type_t>(this->re - cpx.re, this->im - cpx.im); }

    template <typename type_t>
    complex<type_t> complex<type_t>::operator * (const complex<type_t>& cpx) const
    {
        return complex<type_t>
        (
            this->re * cpx.re - this->im * cpx.im,
            this->re * cpx.im + this->im * cpx.re
        );
    }
}

#endif // _COMPLEX_IPP_