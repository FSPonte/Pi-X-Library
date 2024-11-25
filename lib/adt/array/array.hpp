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

        type_t _data[DIM];

    public:

        /**
         * @brief Default constructor
        */
        array(void);

        /**
         * @brief Parameterized construtor
         * @param arr Pointer to array
        */
        array(const type_t[]);

        /**
         * @brief Copy constructor
         * @param arr Array
        */
        array(const array<type_t, DIM>&);

        /**
         * @brief Get buffer
         * @return Pointer to buffer
        */
        const type_t* buffer(void) const;

        /**
         * @brief Get operator
         * @param ind Index
         * @return Reference to element
         * @throw Index is out of bounds
        */
        type_t& operator [] (unsigned long) noexcept(false);

        /**
         * @brief Get dimension
         * @return Number of elements
        */
        constexpr const unsigned long dim(void) const;

        /**
         * @brief Copy operator
         * @param arr Array
         * @throw Pointer to array is null
         * @note Assumes same dimensions as object
        */
        void operator = (const type_t[]) noexcept(false);

        /**
         * @brief Copy operator
         * @param arr Array
        */
        void operator = (const array<type_t, DIM>&);

        /**
         * @brief Equality operator
         * @param arr C styled array
         * @return True if arrays are equal
         * @note Assumes same dimensions as object
        */
        const bool operator == (const type_t[]) const;

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @param arr C styled array
         * @return False
         * @note Assumes same dimensions as object
        */
        template <typename _type_t>
        constexpr const bool operator == (const _type_t[]) const;

        /**
         * @brief Equality operator
         * @param arr Array
         * @return True if arrays are equal
        */
        const bool operator == (const array<type_t, DIM>&) const;

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of elements
         * @param arr Array
         * @return False
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator == (const array<_type_t, _DIM>&) const;

        /**
         * @brief Inequality operator
         * @param arr C styled array
         * @return True if arrays are different
         * @note Assumes same dimensions as object
        */
        const bool operator != (const type_t[]) const;

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @param arr C styled array
         * @return True
         * @note Assumes same dimensions as object
        */
        template <typename _type_t>
        constexpr const bool operator != (const _type_t[]) const;

        /**
         * @brief Inequality operator
         * @param arr Array
         * @return True if arrays are different
        */
        const bool operator != (const array<type_t, DIM>&) const;

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @param arr Array
         * @return True
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator != (const array<_type_t, _DIM>&) const;
    };
}

// Template file
#include "array.tpp"

#endif // _ARRAY_HPP_
