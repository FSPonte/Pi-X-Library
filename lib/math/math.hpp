#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace pix::math
{
    /**
     * @brief Absolute value
     * @tparam type_t Data type
     * @param num Number
     * @return Postive number
    */
    template <typename type_t>
    type_t abs(type_t);

    /**
     * @brief Factorial function
     * @param num Number
     * @return Factorial value
    */
    unsigned long fat(unsigned long);
}

// Implementation file
#include "math.ipp"

#endif // _MATH_HPP_