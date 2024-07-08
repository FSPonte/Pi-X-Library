#ifndef _HYPER_HPP_
#define _HYPER_HPP_

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

#endif // _HYPER_HPP_