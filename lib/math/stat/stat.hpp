#ifndef _STAT_HPP_
#define _STAT_HPP_

// Statistics
namespace pix::math::stat
{
	/**
	 * @brief Get minimum
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Minimum value
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t min(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Get maximum
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Maximum value
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t max(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Calculate the amplitude
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Difference between maximum and minimum values
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t amp(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Absolute error
	 * @tparam type_t Data type
	 * @param ex Exact value
	 * @param aprox Approximate value
	 * @return Absolute error
	*/
	template <typename type_t>
	type_t abs_err(type_t, type_t) noexcept(true);

	/**
	 * @brief Relative error
	 * @tparam type_t Data type
	 * @param ex Exact value
	 * @param aprox Approximate value
	 * @return Relative error
	*/
	template <typename type_t>
	type_t rel_err(type_t, type_t) noexcept(true);

	/**
	 * @brief Sum of array
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Sum of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t sum(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Mean
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Mean of the elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t mean(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Median
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Median of the elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t median(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Variance
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Variance of the elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t var(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Standard deviation
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @return Standard deviation of the elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t std_dev(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Covariance
	 * @tparam type_t Data type
	 * @param in Array of input elements
	 * @param out Array of output elements
	 * @param dim Number of elements
	 * @return Covariance of the elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t covar(const type_t[], const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Coefficient of determination
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param model Array of predicted values
	 * @param dim Number of elements
	 * @return Coefficient of determination of the model
	 * @throw Pointer to array is null
	 * @throw Pointer to model is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	type_t coeff_det(const type_t[], const type_t[], unsigned long) noexcept(false);
}

// Template file
#include "stat.tpp"

#endif // _STAT_HPP_
