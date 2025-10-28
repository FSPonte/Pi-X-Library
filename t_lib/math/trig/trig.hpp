#ifndef _TRIG_HPP_
#define _TRIG_HPP_

// Trigonometric functions
namespace pix::math::trig
{
	/**
	 * @brief Sine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Sine of argument
	*/
	template <typename type_t>
	type_t sin(type_t) noexcept(true);

	/**
	 * @brief Cosine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Cosine of argument
	*/
	template <typename type_t>
	type_t cos(type_t) noexcept(true);

	/**
	 * @brief Tangent function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Tangent of argument
	*/
	template <typename type_t>
	type_t tan(type_t) noexcept(true);

	/**
	 * @brief Secant function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Secant of argument
	*/
	template <typename type_t>
	type_t sec(type_t) noexcept(true);

	/**
	 * @brief Cosecant function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Cosecant of argument
	*/
	template <typename type_t>
	type_t csc(type_t) noexcept(true);

	/**
	 * @brief Cotangent function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Cotangent of argument
	*/
	template <typename type_t>
	type_t cot(type_t) noexcept(true);

	/**
	 * @brief Arcsine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Arcsine of argument
	 * @throw Argument is out of bounds
	 * @note Domain = [-1, 1]
	 * @note Codomain = [-pi/2, pi/2]
	*/
	template <typename type_t>
	type_t arcsin(type_t) noexcept(false);

	/**
	 * @brief Arccosine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Arccosine of argument
	 * @throw Argument is out of bounds
	 * @note Domain = [-1, 1]
	 * @note Codomain = [0, pi]
	*/
	template <typename type_t>
	type_t arccos(type_t) noexcept(false);

	/**
	 * @brief Arctangent function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Arctangent of argument
	 * @note Codomain = ]-pi/2, pi/2[
	*/
	template <typename type_t>
	type_t arctan(type_t) noexcept(true);
}

// Template file
#include "trig.tpp"

#endif // _TRIG_HPP_
