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
}

#endif // _MATH_IPP_