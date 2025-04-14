#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_

namespace pix::math
{
	template<typename type_in, typename type_out, typename callable>
	class function
	{
	private:

		callable _callable;

	public:
	
		/**
		 * @brief Constructor
		 * @param f Function
		*/
		explicit function(const callable& func);

		/**
		 * @brief Evaluation
		 * @param in Input
		 * @return Output
		*/
		type_out operator()(const type_in& x) const;

		/**
		 * @brief Bissection method
		 * @param a Initial point
		 * @param b Final point
		 * @param TOL Tolerance
		 * @return First root found
		 * @throw Invalid tolerance (TOL <= 0)
		 * @throw Invalid range (a > b)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		template <typename type_t = float>
		type_out bissection(type_in, type_in, type_t = 1E-3) const noexcept(false);

		/**
		 * @brief Newton method
		 * @param x0 Initial point
		 * @param TOL Tolerance
		 * @return First root found
		 * @throw Invalid tolerance (TOL <= 0)
		 * @throw Invalid range (a > b)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		template <typename type_t = float>
		type_out newton(type_in, type_t = 1E-3) const noexcept(false);

		/**
		 * @brief Secant method
		 * @param a Initial point
		 * @param b Final point
		 * @param TOL Tolerance
		 * @return First root found
		 * @throw Invalid tolerance (TOL <= 0)
		 * @throw Invalid range (a > b)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		template <typename type_t = float>
		type_out secant(type_in, type_in, type_t = 1E-3) const noexcept(false);

		/**
		 * @brief Golden ratio method
		 * @param a Initial point
		 * @param b Final point
		 * @param TOL Tolerance
		 * @return First root found
		 * @throw Invalid tolerance (TOL <= 0)
		 * @throw Invalid range (a > b)
		 * @note Assumes type_in and type_out have the necessary operators
		 * (arithmetic, assignment, relational)
		*/
		template <typename type_t = float>
		type_out golden_root(type_in, type_in, type_t = 1E-3) const noexcept(false);

		/**
		 * @brief Derivative
		 * @param p Point
		 * @param TOL Tolerance
		 * @return Derivative in point p
		 * @throw Invalid tolerance (TOL <= 0)
		*/
		template <typename type_t = float>
		type_out derivative(type_in, type_t = 1E-3) const noexcept(false);
	};
}

// Template file
#include "function.tpp"

#endif // _FUNCTION_HPP_
