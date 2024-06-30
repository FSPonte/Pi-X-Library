#ifndef _TRIG_IPP_
#define _TRIG_IPP_

namespace pix::math::trig
{
    long double sin(long double arg) noexcept(true)
    {
        const bool is_neg = arg < 0;
        arg = math::f_mod(math::abs(arg), 2 * constants::mathematics::pi);

        long double
            result = arg,
            term = arg;

        for (unsigned long i = 0; i < math::MAX_ITER; ++i)
        {
            term *= -arg * arg / ((2 * i + 2) * (2 * i + 3));

            if (math::abs(term) < math::PR_THRESHOLD)
                break;
            
            result += term;
        }

        if (is_neg)
            return -result;

        return result;
    }

    long double cos(long double arg) noexcept(true)
    {
        arg = math::f_mod(math::abs(arg), 2 * constants::mathematics::pi);

        long double
            result = 1,
            term = 1;

        for (unsigned long i = 1; i <= math::MAX_ITER; ++i)
        {
            term *= -arg * arg / ((2 * i - 1) * (2 * i));

            if (math::abs(term) < math::PR_THRESHOLD)
                break;
            
            result += term;
        }

        return result;
    }

    long double tan(const long double arg) noexcept(true)
    { return trig::sin(arg) / trig::cos(arg); }

    long double sec(const long double arg) noexcept(true)
    { return 1 / trig::cos(arg); }

    long double csc(const long double arg) noexcept(true)
    { return 1 / trig::sin(arg); }

    long double cot(const long double arg) noexcept(true)
    { return trig::cos(arg) / trig::sin(arg); }
}

#endif // _TRIG_IPP_