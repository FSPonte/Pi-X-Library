#ifndef _STAT_HPP_
#define _STAT_HPP_

namespace pix::math::stat
{
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
}

// Implementation file
#include "stat.ipp"

#endif // _STAT_HPP_