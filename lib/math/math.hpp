#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace pix::math
{
    const unsigned long MAX_ITER = 1E6; // Maximum number of iterations
    const long double PR_THRESHOLD = 1E-12; // Precision threshold

    /**
     * @brief Absolute value
     * @tparam type_t Data type
     * @param num Number
     * @return Postive number
    */
    template <typename type_t>
    type_t abs(type_t) noexcept(true);

    /**
     * @brief Factorial function
     * @tparam type_t Data type
     * @param num Number
     * @return Factorial value
     * @throw arg < 0
    */
    template <typename type_t>
    long double fat(type_t) noexcept(false);

    /**
     * @brief Natural logaritm function
     * @param arg Argument
     * @return Natural logaritm of argument
     * @throw arg <= 0
    */
    long double log(long double) noexcept(false);

    /**
     * @brief Logaritm of base function
     * @param arg Argument
     * @param b Base
     * @return Logaritm of base of argument
     * @throw arg <= 0
    */
    long double log(long double, long double) noexcept(false);

    /**
     * @brief Exponential function
     * @param arg Argument
     * @return Exponential of argument
    */
    long double exp(long double) noexcept(true);

    /**
     * @brief Power function
     * @tparam b_type_t Data type of base
     * @tparam e_type_t Data type of exponent
     * @param b Base
     * @param e Exponent
     * @return Base to the power of exponent
     * @throw 0^0
    */
    template <typename b_type_t, typename e_type_t>
    b_type_t pow(b_type_t, e_type_t) noexcept(false);

    /**
     * @brief Root function
     * @param arg Argument
     * @param ind Index
     * @return Root index of argument
     * @throw arg < 0
     * @throw ind = 0
    */
    long double root(long double, long double) noexcept(false);
}

// Implementation file
#include "math.ipp"

#endif // _MATH_HPP_