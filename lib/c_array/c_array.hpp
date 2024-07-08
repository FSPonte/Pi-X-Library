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
     * @brief Invert order of elements
     * @param arr Array of elements
     * @param dim Number of elements
     * @throw arr == nullptr
     * @throw dim == 0
    */
    template <typename type_t>
    void invert(type_t[], unsigned long) noexcept(false);
}

// Implementation file
#include "c_array.ipp"

#endif // _C_ARRAY_HPP_