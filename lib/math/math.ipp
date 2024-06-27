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

    unsigned long fat(const unsigned long number)
    {
        if (number == 0 || number == 1)
            return 1;

        unsigned long result = 2;

        for (unsigned long i = 3; i <= number; ++i)
            result *= i;

        return result;
    }
}

#endif // _MATH_IPP_