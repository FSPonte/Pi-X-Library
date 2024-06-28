#ifndef _MATH_IPP_
#define _MATH_IPP_

namespace pix::math
{
    template <typename type_t>
    type_t abs(const type_t number)
    {
        is_number_static_assert(type_t);

        if (number < 0)
            return -number;

        return number;
    }

    template <typename type_t>
    long double fat(const type_t arg) noexcept(false)
    {
        is_integer_static_assert(type_t);

        if (arg < 0)
            throw "Invalid case arg < 0";

        if (arg == 0 || arg == 1)
            return 1;

        auto number = static_cast<unsigned long>(arg);
        long double result = 2;

        for (unsigned long i = 3; i < math::max_n_iter + 3 && i <= number; ++i)
            result *= i;

        return result;
    }

    template <typename b_type_t, typename e_type_t>
    b_type_t pow(const b_type_t base, e_type_t exponent) noexcept(false)
    {
        is_number_static_assert(b_type_t);
        is_number_static_assert(e_type_t);

        if (base == 0 && exponent == 0)
            throw "Indeterminate case 0^0";

        if (base == 0)
            return b_type_t(0);

        if (exponent == 0)
            return b_type_t(1);

        bool is_neg = exponent < 0;
        exponent = math::abs(exponent);

        b_type_t result = 1;

        if (is_integer(e_type_t))
        {
            for (unsigned long i = 0; i < exponent; ++i)
                result *= base;
        }

        if (is_neg)
            return 1 / result;
        
        return result;
    }
}

#endif // _MATH_IPP_