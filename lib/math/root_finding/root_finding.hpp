#ifndef _ROOT_FINDING_HPP_
#define _ROOT_FINDING_HPP_

// Numerical root finding
namespace pix::math::root_finding
{
	/**
	 * @brief Bissection method
	 * @tparam type_t Data type
	 * @tparam fn Function data type
	 * @param a Initial point
	 * @param b Final point
	 * @return First root found
	 * @throw Invalid interval (a >= b)
	 * @throw Invalid value for tolerance (TOL >= 1)
	 * @throw Invalid maximum number of iteration (MAX_ITER == 0)
	 * @throw Invalid convergence condition (f(a) * f(b) >= 0)
	*/
	template <typename function, typename type_t = float>
	type_t bissection(const function, type_t, type_t, type_t = pix::math::PR_THRESHOLD, unsigned long = pix::math::MAX_ITER) noexcept(false);

	/**
	 * @brief Newton method
	 * @tparam type_t Data type
	 * @tparam fn Function data type
	 * @param x0 Initial point
	 * @return First root found
	 * @throw Invalid value for tolerance (TOL >= 1)
	 * @throw Invalid maximum number of iteration (MAX_ITER == 0)
	 * @throw Null derivative (f'(x) == 0)
	*/
	template <typename function, typename type_t = float>
	type_t newton(const function, type_t, type_t = pix::math::PR_THRESHOLD, unsigned long = pix::math::MAX_ITER) noexcept(false);

	/**
	 * @brief Secant method
	 * @tparam type_t Data type
	 * @tparam fn Function data type
	 * @param a Initial point
	 * @param b Final point
	 * @return First root found
	 * @throw Invalid interval (a >= b)
	 * @throw Invalid value for tolerance (TOL >= 1)
	 * @throw Invalid maximum number of iteration (MAX_ITER == 0)
	 * @throw Division by zero (f(a) == f(b))
	*/
	template <typename function, typename type_t = float>
	type_t secant(const function, type_t, type_t, type_t = pix::math::PR_THRESHOLD, unsigned long = pix::math::MAX_ITER) noexcept(false);
}

// Template file
#include "root_finding.tpp"

#endif // _ROOT_FINDING_HPP_
