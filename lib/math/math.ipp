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
    type_t fat(const type_t arg)
    {
        is_integer_static_assert(type_t);

        if (arg < 0)
            return 0;

        if (arg == 0 || arg == 1)
            return 1;

        auto number = static_cast<unsigned long>(arg);

        unsigned long result = 2;

        for (unsigned long i = 3; i < math::max_n_iter && i <= number; ++i)
            result *= i;

        return result;
    }

    double ln(const double arg)
    {
        if (arg < 0)
            return 0;

        double result = 0;
        const double coef = (arg - 1) / (arg + 1);
        double term = coef;
        double term_sq = coef * coef;
        unsigned int n = 1;
        
        for (unsigned long i = 0; i < math::max_n_iter; ++i)
        {
            if(math::abs(term) <= pr_threshold)
                break;

            result += term / n;
            term *= term_sq;
            n += 2;
        }
        
        return 2 * result;
    }

    template <typename type_t>
    type_t pow(const type_t base, const type_t exponent)
    {
        if (base == 0 && exponent == 0)
            return 0;

        if (base == 0)
            return 0;

        if (exponent == 0)
            return 1;

        type_t result = 1;

        if (is_integer(type_t))
        {
            for (unsigned long i = 0; i < math::max_n_iter && i < exponent; ++i)
                result *= base;
        }

        return result;
    }
}

#endif // _MATH_IPP_