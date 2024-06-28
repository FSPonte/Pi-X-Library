#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace pix::math
{
    const unsigned long max_n_iter = 1E3; // Maximum number of iterations
    const double pr_threshold = 1E-6; // Precision threshold

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
     * @throw Invalid case arg < 0
    */
    template <typename type_t>
    long double fat(type_t) noexcept(false);

    /**
     * @brief Power function
     * @tparam b_type_t Data type of base
     * @tparam e_type_t Data type of exponent
     * @param b Base
     * @param e Exponent
     * @return Base to the power of exponent
     * @throw Indeterminate case 0^0
    */
    template <typename b_type_t, typename e_type_t>
    b_type_t pow(b_type_t, e_type_t) noexcept(false);
}

// Implementation file
#include "math.ipp"

#endif // _MATH_HPP_