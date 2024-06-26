#ifndef _MATH_HPP_
#define _MATH_HPP_

// Mathematical functions
namespace pix::math
{
    const unsigned long MAX_ITER = 1E6; // Maximum number of iterations
    const long double PR_THRESHOLD = 1E-30; // Precision threshold

    /**
     * @brief Absolute value
     * @tparam type_t Data type
     * @param num Number
     * @return Postive number
    */
    template <typename type_t>
    type_t abs(type_t) noexcept(true);

    /**
     * @brief Float modulus
     * @tparam type_t Data type
     * @param arg Argument
     * @param mod Modulus
     * @return Number congruent to arg
     * @throw arg < 0
     * @throw mod <= 0
    */
    template <typename type_t>
    type_t f_mod(type_t, type_t) noexcept(false);

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
     * @throw ind == 0
    */
    long double root(long double, long double) noexcept(false);
}

// Implementation file
#include "math.ipp"

#ifndef _STAT_
#define _STAT_

namespace pix::math::stat
{
    /**
     * @brief Sum of array
     * @tparam type_t Data type
     * @param arr Array of elements
     * @param dim Number of elements
     * @return Sum of elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    type_t sum(const type_t[], unsigned long) noexcept(false);

    /**
     * @brief Mean
     * @tparam type_t Data type
     * @param arr Array of elements
     * @param dim Number of elements
     * @return Mean of the elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    type_t mean(const type_t[], unsigned long) noexcept(false);

    /**
     * @brief Median
     * @tparam type_t Data type
     * @param arr Array of elements
     * @param dim Number of elements
     * @return Median of the elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    type_t median(const type_t[], unsigned long) noexcept(false);

    /**
     * @brief Standard deviation
     * @tparam type_t Data type
     * @param arr Array of elements
     * @param dim Number of elements
     * @return Standard deviation of the elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    type_t std_dev(const type_t[], unsigned long) noexcept(false);
}

// Implementation file
#include "stat.ipp"

#endif // _STAT_

#ifndef _TRIG_
#define _TRIG_

// Trigonometric functions
namespace pix::math::trig
{
    /**
     * @brief Sine function
     * @param arg Argument
     * @return Sine of argument
    */
    long double sin(long double) noexcept(true);

    /**
     * @brief Cosine function
     * @param arg Argument
     * @return Cosine of argument
    */
    long double cos(long double) noexcept(true);

    /**
     * @brief Tangent function
     * @param arg Argument
     * @return Tangent of argument
    */
    long double tan(long double) noexcept(true);

    /**
     * @brief Secant function
     * @param arg Argument
     * @return Secant of argument
    */
    long double sec(long double) noexcept(true);

    /**
     * @brief Cosecant function
     * @param arg Argument
     * @return Cosecant of argument
    */
    long double csc(long double) noexcept(true);

    /**
     * @brief Cotangent function
     * @param arg Argument
     * @return Cotangent of argument
    */
    long double cot(long double) noexcept(true);
}

// Implementation file
#include "trig.ipp"

#endif // _TRIG_

#ifndef _HYPER_
#define _HYPER_

// Hyperbolic functions
namespace pix::math::hyper
{
    /**
     * @brief Hyperbolic sine function
     * @param arg Argument
     * @return Hyperbolic sine of argument
    */
    long double sinh(long double) noexcept(true);

    /**
     * @brief Hyperbolic cosine function
     * @param arg Argument
     * @return Hyperbolic cosine of argument
    */
    long double cosh(long double) noexcept(true);

    /**
     * @brief Hyperbolic tangent function
     * @param arg Argument
     * @return Hyperbolic tangent of argument
    */
    long double tanh(long double) noexcept(true);

    /**
     * @brief Hyperbolic secant function
     * @param arg Argument
     * @return Hyperbolic secant of argument
    */
    long double sech(long double) noexcept(true);

    /**
     * @brief Hyperbolic cosecant function
     * @param arg Argument
     * @return Hyperbolic cosecant of argument
    */
    long double csch(long double) noexcept(true);

    /**
     * @brief Hyperbolic cotangent function
     * @param arg Argument
     * @return Hyperbolic cotangent of argument
    */
    long double coth(long double) noexcept(true);
}

// Implementation file
#include "hyper.ipp"

#endif // _HYPER_

#endif // _MATH_HPP_