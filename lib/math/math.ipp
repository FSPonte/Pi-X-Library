#ifndef _MATH_IPP_
#define _MATH_IPP_

namespace pix::math
{
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