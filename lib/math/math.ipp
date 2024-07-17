#ifndef _MATH_IPP_
#define _MATH_IPP_

static const unsigned long STD_NaN = 0x7ff8000000000000; // Standard representation for NaN

namespace pix::math
{
    constexpr const double NaN(void) noexcept(true)
    { return *reinterpret_cast<const double*>(&STD_NaN); }

    template <typename type_t>
    type_t abs(const type_t number) noexcept(true)
    {
        is_number_static_assert(type_t);

        if (number < 0)
            return -number;

        return number;
    }

    template <typename type_t>
    type_t f_mod(type_t arg, const type_t mod) noexcept(false)
    {
        is_float_static_assert(type_t);

        if (arg < 0)
            throw "Argument is a negative number";

        if (mod <= 0)
            throw "Modulus is a non positive number";

        if (arg < mod)
            return arg;

        if (arg == mod)
            return type_t(0);

        while (arg >= mod)
            arg -= mod;

        return arg;
    }

    template <typename type_t>
    type_t floor(const type_t arg) noexcept(true)
    {
        return static_cast<type_t>(static_cast<int>(arg));
    }

    template <typename type_t>
    long double fact(const type_t arg) noexcept(false)
    {
        is_integer_static_assert(type_t);

        if (arg < 0)
            throw "Argument is a negative number";

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
            throw "Argument is a non positive number";

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
        const bool is_neg = arg < 0;
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

    long double pow(long double base, long double exponent) noexcept(false)
    {
        if (base == 0 && exponent == 0)
            throw "Indeterminate case of 0^0";

        if (base == 0)
            return 0;

        if (exponent == 0)
            return 1;

        if (exponent == 1)
            return base;

        const bool is_e_neg = exponent < 0; // Is exponent negative
        exponent = abs(exponent);

        // Handle the case of (-1)^exponent separately for integer exponents
        if (base == -1 && floor(exponent) == exponent)
        {
            if (static_cast<long long>(exponent) % 2 == 0)
                return 1;
            else
                return -1;
        }

        // For non-integer exponents or other cases, proceed with the calculation
        long double result = exp(exponent * log(abs(base)));

        if (is_e_neg)
            result = 1 / result;

        // Restore the sign for negative bases
        if (base < 0 && floor(exponent) == exponent)
        {
            if (static_cast<long long>(exponent) % 2 != 0)
                result = -result;
        }
        else if (base < 0)
            return NaN();

        return result;
    }

    long double root(const long double arg, const long double ind) noexcept(false)
    {
        if (arg < 0)
            throw "Argument is a negative number";

        if (ind == 0)
            throw "Index is equal to zero";
        
        if (ind == 1)
            return arg;

        return math::pow(arg, 1 / ind);
    }
}

#endif // _MATH_IPP_