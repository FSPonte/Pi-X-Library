#ifndef _HYPER_IPP_
#define _HYPER_IPP_

namespace pix::math::hyper
{
    long double sinh(const long double arg) noexcept(true)
    { return 0.5 * (math::exp(arg) - math::exp(-arg)); }

    long double cosh(const long double arg) noexcept(true)
    { return 0.5 * (math::exp(arg) + math::exp(-arg)); }

    long double tanh(const long double arg) noexcept(true)
    { return hyper::sinh(arg) / hyper::cosh(arg); }

    long double sech(const long double arg) noexcept(true)
    { return 1 / hyper::cosh(arg); }

    long double csch(const long double arg) noexcept(true)
    { return 1 / hyper::sech(arg); }

    long double coth(const long double arg) noexcept(true)
    { return hyper::cosh(arg) / hyper::sinh(arg); }
}

#endif // _HYPER_IPP_