#ifndef _MATH_IPP_
#define _MATH_IPP_

namespace pix::math
{
    template <typename type_t>
    type_t abs(const type_t number) noexcept(true)
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
            throw "fat: arg < 0";

        if (arg == 0 || arg == 1)
            return 1;

        auto number = static_cast<unsigned long>(arg);
        long double result = 2;
        const unsigned long MAX_ITER = math::MAX_ITER + 3;

        for (unsigned long i = 3; i < MAX_ITER; ++i)
        {
            if (i <= number)
                break;

            result *= i;
        }

        return result;
    }

    long double log(const long double arg) noexcept(false)
    {
        if (arg <= 0)
            throw "log: arg <= 0";

        long double
            result = 0,
            coef = (arg - 1) / (arg + 1),
            term = coef,
            term_sq = coef * coef;
        const unsigned long MAX_ITER = math::MAX_ITER + 1;

        for (unsigned long i = 1; i < MAX_ITER; i += 2)
        {
            if (math::abs(term) < math::PR_THRESHOLD)
                break;
            
            result += term / i;
            term *= term_sq;
        }

        return 2 * result;
    }

    long double log(const long double arg, const long double base) noexcept(false)
    { return math::log(arg) / math::log(base); }

    long double exp(long double arg) noexcept(true)
    {
        bool is_neg = arg < 0;
        arg = math::abs(arg);

        long double
            result = 1,
            term = 1;
        const unsigned long MAX_ITER = math::MAX_ITER + 1;
        
        for (unsigned long i = 1; i < MAX_ITER; ++i)
        {
            term *= arg / i;

            if (math::abs(term) < math::PR_THRESHOLD)
                break;
            
            result += term;
        }

        if (is_neg)
            return 1 / result;
        
        return result;
    }

    template <typename b_type_t, typename e_type_t>
    b_type_t pow(const b_type_t base, e_type_t exponent) noexcept(false)
    {
        is_number_static_assert(b_type_t);
        is_number_static_assert(e_type_t);

        if (base == 0 && exponent == 0)
            throw "pow: 0^0";

        if (base == 0)
            return b_type_t(0);

        if (exponent == 0)
            return b_type_t(1);

        bool is_e_neg = exponent < 0; // Is exponent negative
        exponent = math::abs(exponent);

        auto result = b_type_t(1);

        if (is_integer(e_type_t))
        {
            for (unsigned long i = 0; i < math::MAX_ITER; ++i)
            {
                if (i < exponent)
                    break;

                result *= base;
            }
        }
        else
            result = math::exp(exponent * math::log(base));

        if (is_e_neg)
            return 1 / result;
        
        return result;
    }

    long double root(const long double arg, const long double ind) noexcept(false)
    {
        if (arg < 0)
            throw "root: arg < 0";

        if (arg == 0)
            throw "root: ind == 0";
        
        if (ind == 1)
            return arg;

        return math::pow(arg, 1 / ind);
    }

    template <typename type_t>
    type_t sum(const type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "sum: arr == nullptr";

        if (dim == 0)
            throw "sum: dim == 0";

        type_t result = 0;

        for (unsigned long i = 0; i < dim; ++i)
            result += arr[i];

        return result;
    }
}

#endif // _MATH_IPP_