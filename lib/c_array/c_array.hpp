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
	 * @brief Invert order of elements
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array of elements
	 * @note Requires an array of a numerical data type
	*/
	template <typename type_t, unsigned long DIM>
	void invert(type_t (&)[DIM]) noexcept(true);

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
	void copy(const type_t[], type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Copy array
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @note Copies the elements from arr_o to arr_d
	*/
	template <typename type_t, unsigned long DIM>
	void copy(const type_t (&)[DIM], type_t (&)[DIM]) noexcept(true);

	/**
	 * @brief Copy 2D array
	 * @tparam type_t Data type
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @param dim_1 Number of elements in dimension 1
	 * @param dim_2 Number of elements in dimension 2
	 * @throw Pointer to origin array is null
	 * @throw Pointer to destination array is null
	 * @throw Dimension 1 is null
	 * @throw Dimension 2 is null
	 * @note Copies the elements from arr_o to arr_d
	*/
	template <typename type_t>
	void copy(const type_t*[], type_t*[], unsigned long, unsigned long) noexcept(false);

	/**
	 * @brief Copy 2D array
	 * @tparam type_t Data type
	 * @tparam DIM_1 Number of elements in dimension 1
	 * @tparam DIM_2 Number of elements in dimension 2
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @note Copies the elements from arr_o to arr_d
	*/
	template <typename type_t, unsigned long DIM_1, unsigned long DIM_2>
	void copy(const type_t (&)[DIM_1][DIM_2], type_t (&)[DIM_1][DIM_2]) noexcept(true);

	/**
	 * @brief Move array
	 * @tparam type_t Data type
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @param dim Number of elements
	 * @throw Pointer to origin array is null
	 * @throw Pointer to destination array is null
	 * @throw Dimension is null
	 * @note Moves the elements from arr_o to arr_d and resets arr_o
	*/
	template <typename type_t>
	void move(type_t[], type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Move array
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr_o Origin array of elements
	 * @param arr_d Destination array of elements
	 * @note Moves the elements from arr_o to arr_d and resets arr_o
	*/
	template <typename type_t, unsigned long DIM>
	void move(type_t (&)[DIM], type_t (&)[DIM]) noexcept(true);

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
	 * @brief Shift all elements to the left
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Pointer to array
	*/
	template <typename type_t, unsigned long DIM>
	void left_shift(type_t (&)[DIM]) noexcept(true);

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
	 * @brief Shift all elements to the right
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Pointer to array
	*/
	template <typename type_t, unsigned long DIM>
	void right_shift(type_t (&)[DIM]) noexcept(true);

	/**
	 * @brief Bit reversal
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	 * @throw Dimension must be a power of 2
	*/
	template <typename type_t>
	void bit_rev(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Bit reversal
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array of elements
	*/
	template <typename type_t, unsigned long DIM>
	void bit_rev(type_t (&)[DIM]) noexcept(true);
}

// Template file
#include "c_array.tpp"

#endif // _C_ARRAY_HPP_
