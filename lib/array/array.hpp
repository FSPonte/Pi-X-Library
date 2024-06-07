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
        array(const array<_type_t, DIM>&);

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
         * @note Index is congruent to DIM
        */
        type_t& operator [] (unsigned long);

        /**
         * @brief Get dimension
         * @return Number of elements
        */
        constexpr const unsigned long dim(void) const;

        /**
         * @brief Copy operator
         * @tparam _type_t Data type
         * @param arr Array
         * @note Assumes same dimensions as object
        */
        template <typename _type_t>
        void operator = (const _type_t*);

        /**
         * @brief Copy operator
         * @param arr Array
         * @note Assumes same dimensions as object
        */
        void operator = (const type_t*);

        /**
         * @brief Copy operator
         * @tparam _type_t Data type
         * @param arr Array
        */
        template <typename _type_t>
        void operator = (const array<_type_t, DIM>&);

        /**
         * @brief Copy operator
         * @param arr Array
        */
        void operator = (const array<type_t, DIM>&);

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @param arr C styled array
         * @return True if arrays are equal
         * @note Assumes same dimensions as object
        */
        template <typename _type_t>
        constexpr const bool operator == (const _type_t*) const;

        /**
         * @brief Equality operator
         * @param arr C styled array
         * @return True if arrays are equal
         * @note Assumes same dimensions as object
        */
        const bool operator == (const type_t*) const;

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of elements
         * @param arr Array
         * @return True if arrays are equal
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator == (const array<_type_t, _DIM>&) const;

        /**
         * @brief Equality operator
         * @param arr Array
         * @return True if arrays are equal
        */
        const bool operator == (const array<type_t, DIM>&) const;

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @param arr C styled array
         * @return True if arrays are different
         * @note Assumes same dimensions as object
        */
        template <typename _type_t>
        constexpr const bool operator != (const _type_t*) const;

        /**
         * @brief Inequality operator
         * @param arr C styled array
         * @return True if arrays are different
         * @note Assumes same dimensions as object
        */
        const bool operator != (const type_t*) const;

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @param arr Array
         * @return True if arrays are different
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator != (const array<_type_t, _DIM>&) const;

        /**
         * @brief Inequality operator
         * @param arr Array
         * @return True if arrays are different
        */
        const bool operator != (const array<type_t, DIM>&) const;
    };
}

// Implementation file
#include "array.ipp"

#endif // _ARRAY_HPP_