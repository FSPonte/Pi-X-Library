#ifndef _C_ARRAY_HPP_
#define _C_ARRAY_HPP_

namespace pix::c_array
{
	/**
	 * @brief Swap values
	 * @tparam type_t Data type
	 * @param ref_1 Reference to first element
	 * @param ref_2 Reference to second element
	*/
	template <typename type_t>
	inline void swap(type_t&, type_t&) noexcept(true);

	/**
	 * @brief Swap pointers
	 * @tparam type_t Data type
	 * @param arr_1 Pointer to first array
	 * @param arr_2 Pointer to second array
	 * @throw Pointer to first array is null
	 * @throw Pointer to second array is null
	*/
	template <typename type_t>
	void swap(type_t*, type_t*) noexcept(false);

	/**
	 * @brief Invert order of elements
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	 * @note Requires an array of a numerical data type
	*/
	template <typename type_t>
	void invert(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Copy array
	 * @tparam type_t Data type
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @param dim Number of elements
	 * @throw Pointer to origin array is null
	 * @throw Pointer to destination array is null
	 * @throw Dimension is null
	 * @note Copies the elements from arr_o to arr_d
	*/
	template <typename type_t>
	void copy(type_t[], type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Move array
	 * @tparam type_t Data type
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @param dim Number of elements
	 * @throw Pointer to origin array is null
	 * @throw Pointer to destination array is null
	 * @throw Dimension is null
	 * @note Moves the elements from arr_o to arr_d
	*/
	template <typename type_t>
	void move(type_t[], type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Shift all elements to the left
	 * @tparam type_t Data type
	 * @param arr Pointer to array
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void left_shift(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Shift all elements to the right
	 * @tparam type_t Data type
	 * @param arr Pointer to array
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void right_shift(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Bit reversal
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void bit_rev(type_t[], unsigned long) noexcept(false);
}

// Template file
#include "c_array.tpp"

#endif // _C_ARRAY_HPP_
