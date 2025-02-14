#ifndef _TRIG_HPP_
#define _TRIG_HPP_

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

	/**
	 * @brief Arcsine function
	 * @param arg Argument
	 * @return Arcsine of argument
	 * @throw Argument is out of bounds
	 * @note Domain = [-1, 1]
	 * @note Codomain = [-pi/2, pi/2]
	*/
	long double arcsin(long double) noexcept(true);

	/**
	 * @brief Arccosine function
	 * @param arg Argument
	 * @return Arccosine of argument
	 * @throw Argument is out of bounds
	 * @note Domain = [-1, 1]
	 * @note Codomain = [0, pi]
	*/
	long double arccos(long double) noexcept(true);

	/**
	 * @brief Arctangent function
	 * @param arg Argument
	 * @return Arctangent of argument
	 * @note Codomain = ]-pi/2, pi/2[
	*/
	long double arctan(long double) noexcept(true);
}

// Template file
#include "trig.tpp"

#endif // _TRIG_HPP_
