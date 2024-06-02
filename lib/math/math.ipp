#ifndef _MATH_IPP_
#define _MATH_IPP_

unsigned int pix::math::fat(const unsigned int number)
{
    if (number == 0 || number == 1)
        return 1;

    unsigned int result = 2;

    for (unsigned long i = 3; i <= number; ++i)
        result *= i;

    return result;
}

#endif // _MATH_IPP_