#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace pix::math
{
    const unsigned long max_n_iter = 1E6; // Maximum number of iterations
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

    /**
     * @brief Natural logaritm function
     * @param arg Argument
     * @return Natural logaritm of argument
    */
    double ln(double);

    /**
     * @brief Power function
     * @tparam type_t Data type
     * @param b Base
     * @param e Exponent
     * @return Base to the power of exponent
     * @note The case of 0^0 is set to return 1
    */
    template <typename type_t>
    type_t pow(type_t, type_t);
}

// Implementation file
#include "math.ipp"

#endif // _MATH_HPP_