#ifndef _HYPER_HPP_
#define _HYPER_HPP_

// Hyperbolic functions
namespace pix::math::hyper
{
	/**
	 * @brief Hyperbolic sine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic sine of argument
	*/
	template <typename type_t>
	type_t sinh(type_t) noexcept(true);

	/**
	 * @brief Hyperbolic cosine function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic cosine of argument
	*/
	template <typename type_t>
	type_t cosh(type_t) noexcept(true);

	/**
	 * @brief Hyperbolic tangent function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic tangent of argument
	*/
	template <typename type_t>
	type_t tanh(type_t) noexcept(true);

	/**
	 * @brief Hyperbolic secant function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic secant of argument
	*/
	template <typename type_t>
	type_t sech(type_t) noexcept(true);

	/**
	 * @brief Hyperbolic cosecant function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic cosecant of argument
	*/
	template <typename type_t>
	type_t csch(type_t) noexcept(true);

	/**
	 * @brief Hyperbolic cotangent function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Hyperbolic cotangent of argument
	*/
	template <typename type_t>
	type_t coth(type_t) noexcept(true);
}

// Template file
#include "hyper.tpp"

#endif // _HYPER_HPP_
