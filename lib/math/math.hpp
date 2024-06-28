#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace pix::math
{
    const unsigned long max_n_iter = 1E10; // Maximum number of iterations
    const double pr_threshold = 1E-9; // Precision threshold

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
     * @tparam type_t Data type
     * @param num Number
     * @return Factorial value
     * @note Returns 0 if number is negative
    */
    template <typename type_t>
    type_t fat(type_t);
}

// Implementation file
#include "math.ipp"

#endif // _MATH_HPP_