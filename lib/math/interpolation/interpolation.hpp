#ifndef _INTERPOLATION_HPP_
#define _INTERPOLATION_HPP_

// Numeric interpolation
namespace pix::math::interpolation
{
	/**
	 * @brief Linear interpolation
	 * @tparam type_t Data type
	 * @tparam DIM Number of entries
	 * @param in Input values
	 * @param out Output values
	 * @param trg Target value
	 * @return Interpolated value
	 * @throw Out of bounds
	 * @note Assumes the input array is sorted
	*/
	template <typename type_t, unsigned long DIM>
	type_t linear(type_t (&)[DIM], type_t (&)[DIM], type_t) noexcept(false);

	/**
	 * @brief Newton interpolation
	 * @tparam type_t Data type
	 * @tparam DIM Number of entries
	 * @param in Input values
	 * @param out Output values
	 * @param trg Target value
	 * @return Interpolated value
	 * @note Assumes the input array is sorted
	*/
	template <typename type_t, unsigned long DIM>
	type_t newton(type_t (&)[DIM], type_t (&)[DIM], type_t) noexcept(false);

	/**
	 * @brief Spline interpolation
	 * @tparam type_t Data type
	 * @tparam DIM Number of entries
	 * @param in Input values
	 * @param out Output values
	 * @param trg Target value
	 * @return Interpolated value
	 * @throw Out of bounds
	 * @note Assumes the input array is sorted
	*/
	template <typename type_t, unsigned long DIM>
	type_t spline(type_t (&)[DIM], type_t (&)[DIM], type_t, unsigned long) noexcept(false);

	/**
	 * @brief Lagrange interpolation
	 * @tparam type_t Data type
	 * @tparam DIM Number of entries
	 * @param in Input values
	 * @param out Output values
	 * @param trg Target value
	 * @param ord Order of the polynomial
	 * @return Interpolated value
	 * @throw Out of bounds
	 * @throw Invalid order value
	 * @note Assumes the input array is sorted
	*/
	template <typename type_t, unsigned long DIM>
	type_t lagrange(type_t (&)[DIM], type_t (&)[DIM], type_t, unsigned long) noexcept(false);
}

// Template file
#include "interpolation.tpp"

#endif // _INTERPOLATION_HPP_
