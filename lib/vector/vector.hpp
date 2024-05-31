#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

// Dependencies
#include <types.hpp>

using namespace pix::types;

namespace pix::adt
{
    /**
     * @brief Vector
     * @tparam type_t Data type
     * @tparam DIM Number of components
    */
    template <typename type_t, size_t DIM>
    class vector
    {
    private:

        type_t arr[DIM];

    public:

        /**
         * @brief Default constructor
        */
        vector(void);

        /**
         * @brief Parameterized constructor
         * @param arr Array of components
        */
        vector(const type_t[]);

        /**
         * @brief Copy constructor
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
        */
        template <typename _type_t, size_t _DIM>
        vector(vector<_type_t, _DIM>&);

        /**
         * @brief Get component
         * @param ind Index
         * @return Reference to component
         * @note Index is congruent to DIM
        */
        type_t& operator [] (size_t);

        /**
         * @brief Get size
         * @return Number of components
        */
        constexpr const size_t dim(void) const;

        /**
         * @brief Assignment operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
        */
        template <typename _type_t, size_t _DIM>
        void operator = (vector<_type_t, _DIM>&);

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
         * @return true if vectors are equal
        */
        template <typename _type_t, size_t _DIM>
        const bool operator == (vector<_type_t, _DIM>&);

        /**
         * @brief Equality operator
         * @param vec Vector
         * @return true if vectors are equal
        */
        const bool operator == (vector<type_t, DIM>&);

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
         * @return true if vectors are different
        */
        template <typename _type_t, size_t _DIM>
        const bool operator != (vector<_type_t, _DIM>&);

        /**
         * @brief Inequality operator
         * @param vec Vector
         * @return true if vectors are different
        */
        const bool operator != (vector<type_t, DIM>&);

        /**
         * @brief Addition operator
         * @tparam _type_t Data type
         * @param vec Vector
         * @return Addition
        */
        template <typename _type_t>
        vector<type_t, DIM> operator + (vector<_type_t, DIM>&) const;

        /**
         * @brief Subtraction operator
         * @tparam _type_t Data type
         * @param vec Vector
         * @return Subtraction
        */
        template <typename _type_t>
        vector<type_t, DIM> operator - (vector<_type_t, DIM>&) const;

        /**
         * @brief Scalar multiplication
         * @tparam _type_t Data type
         * @param scl Scalar
         * @return Scaled vector
        */
        template <typename _type_t>
        vector<type_t, DIM> operator * (_type_t) const;

        /**
         * @brief Scalar division
         * @tparam _type_t Data type
         * @param scl Scalar
         * @return Scaled vector
        */
        template <typename _type_t>
        vector<type_t, DIM> operator / (_type_t) const;

        /**
         * @brief Scalar product operator
         * @tparam _type_t Data type
         * @param vec Vector
         * @return Dot product
        */
        template <typename _type_t>
        type_t operator ^ (vector<_type_t, DIM>&) const;

        /**
         * @brief Vector product operator
         * @tparam _type_t Data type
         * @param vec Vector
         * @return Cross product
        */
        template <typename _type_t>
        vector<type_t, DIM> operator * (vector<_type_t, DIM>&) const;

        /**
         * @brief Get norm
         * @return Norm
        */
        operator type_t() const;
    };
}

// Implementation file
#include "vector.ipp"

#endif // _VECTOR_HPP_