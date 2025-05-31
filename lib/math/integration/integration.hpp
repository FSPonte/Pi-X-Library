#ifndef _INTEGRATION_HPP_
#define _INTEGRATION_HPP_

// Numerical integration
namespace pix::math::integration
{
	/**
	 * @brief Trapezoid method
	 * @tparam type_t Data type
	 * @tparam fn Function type
	 * @param f Function pointer
	 * @param a Initial point
	 * @param b Final point
	 * @param TOL Tolerance
	 * @return Integral
	 * @throw Invalid interval for integration (a >= b)
	 * @throw Invalid value for tolerance (TOL >= 1)
	*/
	template <typename function, typename type_t = float>
	type_t trapezoid(const function, type_t, type_t, type_t) noexcept(false);

	/**
	 * @brief Romberg method
	 * @tparam type_t Data type
	 * @tparam fn Function type
	 * @param f Function pointer
	 * @param a Initial point
	 * @param b Final point
	 * @param TOL Tolerance
	 * @param MAX_STEPS Maximum number of steps
	 * @return Integral
	 * @throw Invalid interval for integration (a >= b)
	 * @throw Invalid value for tolerance (TOL >= 1)
	 * @throw Invalid number of steps (MAX_STEPS == 0)
	*/
	template <typename function, typename type_t = float>
	type_t romberg(const function, type_t, type_t, type_t, unsigned long) noexcept(false);
}

// Template file
#include "integration.tpp"

#endif // _INTEGRATION_HPP_
