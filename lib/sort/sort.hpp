#ifndef _SORT_HPP_
#define _SORT_HPP_

namespace pix::sort
{
    /**
     * @brief Bubble sort
     * @tparam type_t Data type
     * @param arr Array of elements
     * @param dim Number of elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    void bubble_sort(type_t[], unsigned long) noexcept(false);
}

// Implementation file
#include "sort.ipp"

#endif // _SORT_HPP_