#ifndef _MATH_HPP_
#define _MATH_HPP_

// Mathematical functions
namespace pix::math
{
	constexpr const unsigned long MAX_ITER = 1E3; // Maximum number of iterations
	constexpr const long double PR_THRESHOLD = 1E-3; // Precision threshold

	/**
	 * @brief Not a Number
	 * @return Get the nan value
	*/
	constexpr double NaN(void) noexcept(true);

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
	 * @return Number congruent to argument
	 * @throw Argument is a negative number
	 * @throw Modulus is a non positive number
	*/
	template <typename type_t>
	type_t f_mod(type_t, type_t) noexcept(false);

	/**
	 * @brief Round down a number
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Largest integer less than or equal to arg
	*/
	template <typename type_t>
	type_t floor(type_t) noexcept(false);

	/**
	 * @brief Round up a number
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Largest integer grater than or equal to arg
	*/
	template <typename type_t>
	type_t ceil(type_t) noexcept(false);

	/**
	 * @brief Modular difference
	 * @param arg_1 Argument 1
	 * @param arg_2 Argument 2
	 * @return Absolute difference
	*/
	template <typename type_t>
	type_t mod_diff(type_t, type_t) noexcept(true);

	/**
	 * @brief Factorial function
	 * @param arg Argument
	 * @return Factorial value
	*/
	unsigned long fact(unsigned long) noexcept(true);

	/**
	 * @brief Factorial
	 * @tparam arg Argument
	*/
	template <unsigned long arg>
	struct factorial;

	/**
	 * @brief Fibonacci sequence
	 * @param arg Argument
	 * @return Ind-th fibonacci number
	*/
	unsigned long fib(unsigned long) noexcept(true);

	/**
	 * @brief Fibonacci number
	 * @param arg Argument
	*/
	template <unsigned long arg>
	struct fibonacci;

	/**
	 * @brief Natural logaritm function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Natural logaritm of argument
	 * @throw Argument is a negative number
	*/
	template <typename type_t>
	type_t log(type_t) noexcept(false);

	/**
	 * @brief Logaritm of base function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @param b Base
	 * @return Logaritm of base of argument
	 * @throw Argument is a non positive number
	*/
	template <typename type_t>
	type_t log(type_t, type_t) noexcept(false);

	/**
	 * @brief Exponential function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @return Exponential of argument
	*/
	template <typename type_t>
	type_t exp(type_t) noexcept(true);

	/**
	 * @brief Power function
	 * @tparam type_t Data type
	 * @param b Base
	 * @param e Exponent
	 * @return Base to the power of exponent
	 * @throw Inderteminate case of 0^0
	 * @throw Division by zero
	*/
	template <typename type_t>
	type_t pow(type_t, type_t) noexcept(false);

	/**
	 * @brief Root function
	 * @tparam type_t Data type
	 * @param arg Argument
	 * @param ind Index
	 * @return Root index of argument
	 * @throw Argument is a negative number
	 * @throw Index is equal to zero
	*/
	template <typename type_t>
	type_t root(type_t, type_t) noexcept(false);

	/**
	 * @brief Permutation function
	 * @param n Total number of objects in the set
	 * @param k Number of choosing objects from the set
	 * @return k permutation of n
	*/
	unsigned long permut(unsigned long, unsigned long) noexcept(false);

	/**
	 * @brief Permutation
	 * @tparam n Total number of objects in the set
	 * @tparam k Number of choosing objects from the set
	*/
	template <unsigned long n, unsigned long k>
	struct permutation;

	/**
	 * @brief Combination function
	 * @param n Total number of objects in the set
	 * @param k Number of choosing objects from the set
	 * @return Number of combinations
	*/
	unsigned long comb(unsigned long, unsigned long) noexcept(false);

	/**
	 * @brief Combination
	 * @tparam n Total number of objects in the set
	 * @tparam k Number of choosing objects from the set
	*/
	template <unsigned long n, unsigned long k>
	struct combination;
	
	/**
	 * @brief Kronecker delta function
	 * @param ind_1 Index 1
	 * @param ind_2 Index 2
	 * @return 1 if indeces are equal
	*/
	unsigned long kron_delta(unsigned long, unsigned long) noexcept(true);

	/**
	 * @brief Kronecker delta
	 * @tparam ind_1 Index 1
	 * @tparam ind_2 Index 2
	*/
	template <unsigned long ind_1, unsigned long ind_2>
	struct kronecker_delta;
}

// Template file
#include "math.tpp"

#endif // _MATH_HPP_
