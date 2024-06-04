#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

// Dependencies
#include <vector.hpp>

namespace pix::adt
{
    /**
     * @brief Matrix
     * @tparam type_t Data type
     * @tparam N_LIN Number of lines
     * @tparam N_COL Number of columns
    */
    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    class matrix
    {
    private:

        vector<type_t, N_COL> arr[N_LIN];

    public:

        /**
         * @brief Default constructor
        */
        matrix(void);

        /**
         * @brief Parameterized constructor
         * @param arr Array of components
        */
        matrix(const type_t[]);

        /**
         * @brief Parameterized constructor
         * @param arr Array of vectors
        */
        matrix(vector<type_t, N_COL>[]);

        /**
         * @brief Copy constructor
         * @tparam _type_t Data type
         * @tparam _N_LIN Number of lines
         * @tparam _N_COL Number of columns
         * @param mtx Matrix
        */
        template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
        matrix(matrix<_type_t, _N_LIN, _N_COL>&);

        /**
         * @brief Get line
         * @param lin Line index
         * @return Reference to line vector
         * @note Index is congruent to number of lines
        */
        vector<type_t, N_COL>& operator [] (unsigned long);

        /**
         * @brief Get number of lines
         * @return Number of lines
        */
        constexpr const unsigned long n_lin(void) const;

        /**
         * @brief Get number of columns
         * @return Number of columns
        */
        constexpr const unsigned long n_col(void) const;

        /**
         * @brief Assignment operator
         * @tparam _type_t Data type
         * @tparam _N_LIN Number of lines
         * @tparam _N_COL Number of columns
         * @param mtx Matrix
        */
        template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
        void operator = (matrix<_type_t, _N_LIN, _N_COL>&);

        /**
         * @brief Equality operator
         * @tparam _type_t Data type
         * @tparam _N_LIN Number of lines
         * @tparam _N_COL Number of columns
         * @param mtx Matrix
         * @return true if matrices are equal
        */
        template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
        const bool operator == (matrix<_type_t, _N_LIN, _N_COL>&) const;

        /**
         * @brief Equality operator
         * @param mtx Matrix
         * @return true if matrices are equal
        */
        const bool operator == (matrix<type_t, N_LIN, N_COL>&) const;

        /**
         * @brief Inequality operator
         * @tparam _type_t Data type
         * @tparam _N_LIN Number of lines
         * @tparam _N_COL Number of columns
         * @param mtx Matrix
         * @return true if matrices are different
        */
        template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
        const bool operator != (matrix<_type_t, _N_LIN, _N_COL>&) const;

        /**
         * @brief Inequality operator
         * @param mtx Matrix
         * @return true if matrices are different
        */
        const bool operator != (matrix<type_t, N_LIN, N_COL>&) const;

        /**
         * @brief Addition operator
         * @tparam _type_t Data type
         * @param mtx Matrix
         * @return Addition
        */
        template <typename _type_t>
        matrix<type_t, N_LIN, N_COL> operator + (matrix<_type_t, N_LIN, N_COL>&) const;

        /**
         * @brief Subtraction operator
         * @tparam _type_t Data type
         * @param mtx Matrix
         * @return Subtraction
        */
        template <typename _type_t>
        matrix<type_t, N_LIN, N_COL> operator - (matrix<_type_t, N_LIN, N_COL>&) const;

        /**
         * @brief Scalar multiplication
         * @tparam _type_t Data type
         * @param scl Scalar
         * @return Scaled matrix
        */
        template <typename _type_t>
        matrix<type_t, N_LIN, N_COL> operator * (_type_t) const;

        /**
         * @brief Scalar division
         * @tparam _type_t Data type
         * @param scl Scalar
         * @return Scaled matrix
        */
        template <typename _type_t>
        matrix<type_t, N_LIN, N_COL> operator / (_type_t) const;

        /**
         * @brief Matrix multiplication operator
         * @tparam _type_t Data type
         * @tparam _N_COL Number of columns
         * @param mtx Matrix
         * @return Multiplication
        */
        template <typename _type_t, unsigned long _N_COL>
        matrix<type_t, N_LIN, _N_COL> operator * (matrix<_type_t, N_COL, _N_COL>&) const;
    };
}

// Implementation file
#include "matrix.ipp"

#endif // _MATRX_HPP_