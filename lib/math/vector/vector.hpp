#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

namespace pix::math
{
    /**
     * @brief Vector
     * @tparam type_t Data type
     * @tparam DIM Number of components
    */
    template <typename type_t, unsigned long DIM>
    class vector
    {
    private:

        type_t _arr[DIM];

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
         * @param vec Vector
        */
        vector(const vector<type_t, DIM>&);

        /**
         * @brief Get buffer
         * @return Array of components
        */
        const type_t* buffer(void) const;

        /**
         * @brief Get component
         * @param ind Index
         * @return Reference to component
         * @throw Index is out of bounds
        */
        type_t& operator [] (unsigned long) noexcept(false);

        /**
         * @brief Get size
         * @return Number of components
        */
        constexpr const unsigned long dim(void) const;

        /**
         * @brief Copy operator
         * @param arr Array of components
         * @throw Pointer to array is null
        */
        void operator = (const type_t[]) noexcept(false);

        /**
         * @brief Copy operator
         * @param vec Vector
        */
        void operator = (const vector<type_t, DIM>&);

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
         * @return False
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator == (const vector<_type_t, _DIM>&);

        /**
         * @brief Equality operator
         * @param vec Vector
         * @return True if vectors are equal
        */
        const bool operator == (const vector<type_t, DIM>&);

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @tparam _DIM Number of components
         * @param vec Vector
         * @return True
        */
        template <typename _type_t, unsigned long _DIM>
        constexpr const bool operator != (const vector<_type_t, _DIM>&);

        /**
         * @brief Inequality operator
         * @param vec Vector
         * @return True if vectors are different
        */
        const bool operator != (const vector<type_t, DIM>&);

        /**
         * @brief Addition operator
         * @param vec Vector
         * @return Addition
        */
        vector<type_t, DIM> operator + (const vector<type_t, DIM>&) const;

        /**
         * @brief Subtraction operator
         * @param vec Vector
         * @return Subtraction
        */
        vector<type_t, DIM> operator - (const vector<type_t, DIM>&) const;

        /**
         * @brief Scalar multiplication
         * @param scl Scalar
         * @return Scaled vector
        */
        vector<type_t, DIM> operator * (type_t) const;

        /**
         * @brief Scalar division
         * @param scl Scalar
         * @return Scaled vector
        */
        vector<type_t, DIM> operator / (type_t) const;

        /**
         * @brief Scalar product operator
         * @param vec Vector
         * @return Dot product
        */
        type_t operator ^ (const vector<type_t, DIM>&) const;

        /**
         * @brief Vector product operator
         * @param vec Vector
         * @return Cross product
         * @note Only valid for three dimensional vectors
        */
        vector<type_t, DIM> operator * (const vector<type_t, DIM>&) const;

        /**
         * @brief Get norm
         * @return Norm
        */
        operator type_t() const;
    };
}

// Template file
#include "vector.tpp"

#endif // _VECTOR_HPP_
