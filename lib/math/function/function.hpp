#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_

// Dependencies
#include <math.hpp>

// Mathematics
namespace pix::math
{
	template <typename type_in, typename type_out, typename callable>
	class function
	{
	private:

		double _TOL; // Tolerance
		unsigned long _MAX_ITER; // Maximum number of iterations
		callable _callable;

	public:
	
		/**
		 * @brief Constructor
		 * @param f Function
		 * @param TOL Tolerance
		 * @param MAX_ITER Maximum number of iterations
		 * @throw Invalid tolerance (TOL <= 0)
		 * @throw Invalid maximum number of iterations (MAX_ITER == 0)
		*/
		explicit function(const callable&, double = pix::math::PR_THRESHOLD, unsigned long = pix::math::MAX_ITER) noexcept(false);

		/**
		 * @brief Evaluation
		 * @param x Input
		 * @return Output
		*/
		type_out operator()(const type_in&) const;

		/**
		 * @brief Bissection method
		 * @param a Initial point
		 * @param b Final point
		 * @return First root found
		 * @throw Invalid interval (a >= b)
		 * @throw Invalid convergence condition (f(a) * f(b) >= 0)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		type_out bissection(type_in, type_in) const noexcept(false);

		/**
		 * @brief Newton method
		 * @param x0 Initial point
		 * @return First root found
		 * @throw Null derivative (f'(x) == 0)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		type_out newton(type_in) const noexcept(false);

		/**
		 * @brief Secant method
		 * @param a Initial point
		 * @param b Final point
		 * @return First root found
		 * @throw Invalid interval (a >= b)
		 * @throw Division by zero (f(a) == f(b))
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		type_out secant(type_in, type_in) const noexcept(false);

		/**
		 * @brief Golden ratio method
		 * @param a Initial point
		 * @param b Final point
		 * @return First root found
		 * @throw Invalid interval (a >= b)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		type_out golden_root(type_in, type_in) const noexcept(false);

		/**
		 * @brief Derivative
		 * @param x Point
		 * @return Derivative in point x
		*/
		type_out derivative(type_in) const;
	};
}

// Template file
#include "function.tpp"

#endif // _FUNCTION_HPP_
