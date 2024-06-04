#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

namespace pix::adt
{
    /**
     * @brief Array
     * @tparam type_t Data type
     * @tparam DIM Number of elements
    */
    template <typename type_t, unsigned long DIM>
    class array
    {
    private:

        type_t data[DIM];

    public:

        /**
         * @brief Default constructor
        */
        array(void);

        /**
         * @brief Parameterized construtor
         * @param arr Pointer to array
        */
        array(const type_t*);

        /**
         * @brief Copy constructor
         * @param arr Array
        */
        template <typename _type_t, unsigned long _DIM>
        array(const array<_type_t, _DIM>&);

        /**
         * @brief Get operator
         * @param ind Index
         * @return Reference to element
         * @note Index is congruent to DIM
        */
        type_t& operator [] (unsigned long);

        /**
         * @brief Get dimension
         * @return Number of elements
        */
        constexpr const unsigned long dim() const;
    };
}

// Implementation file
#include "array.ipp"

#endif // _ARRAY_HPP_