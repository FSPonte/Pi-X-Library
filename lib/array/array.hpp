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
         * @tparam _type_t Data type
         * @param arr Pointer to array
        */
        template <typename _type_t>
        array(const _type_t*);

        /**
         * @brief Parameterized construtor
         * @param arr Pointer to array
        */
        array(const type_t*);

        /**
         * @brief Copy constructor
         * @tparam _type_t Data type
         * @param arr Array
        */
        template <typename _type_t>
        array(array<_type_t, DIM>&);

        /**
         * @brief Copy constructor
         * @param arr Array
        */
        array(array<type_t, DIM>&);

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

        /**
         * @brief Assignment operator
         * @param arr Array
        */
        void operator = (array<type_t, DIM>&);

        /**
         * @brief Assignment operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of elements
         * @param arr Array
        */
        template <typename _type_t, unsigned long _DIM>
        void operator = (array<_type_t, _DIM>&);

        /**
         * @brief Comparisson operator
         * @param arr Array
         * @return True if arrays are equal
        */
        const bool operator == (array<type_t, DIM>&) const;

        /**
         * @brief Comparisson operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of elements
         * @param arr Array
         * @return True if arrays are equal
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator == (array<_type_t, _DIM>&) const;

        /**
         * @brief Comparisson operator
         * @param arr Array
         * @return True if arrays are different
        */
        const bool operator != (array<type_t, DIM>&) const;

        /**
         * @brief Comparisson operator
         * @tparam _type_t Data type
         * @param arr Array
         * @return True if arrays are different
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator != (array<_type_t, _DIM>&) const;
    };
}

// Implementation file
#include "array.ipp"

#endif // _ARRAY_HPP_