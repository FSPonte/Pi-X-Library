#ifndef _SORT_HPP_
#define _SORT_HPP_

// Sorting algorithms
namespace pix::sort
{
	/**
	 * @brief Bubble sort
	 * @tparam type_t Data type
	 * @param arr Pointer to array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void bubble_sort(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Selection sort
	 * @tparam type_t Data type
	 * @param arr Pointer to array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void selection_sort(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Insertion sort
	 * @tparam type_t Data type
	 * @param arr Pointer to array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void insertion_sort(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Quick sort
	 * @tparam type_t Data type
	 * @param arr Pointer to array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void quick_sort(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Merge sort
	 * @tparam type_t Data type
	 * @param arr Pointer to array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void merge_sort(type_t[], unsigned long) noexcept(false);
}

// Template file
#include "sort.tpp"

#endif // _SORT_HPP_
