#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

// Dependencies
#include <vector.hpp>

// Mathematical matrix
namespace pix::math
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

		vector<type_t, N_COL> _data[N_LIN];

	public:

		/**
		 * @brief Default constructor
		*/
		matrix(void);

		/**
		 * @brief Parameterized constructor
		 * @param arr Array of components
		 * @throw Pointer to array is null
		*/
		matrix(const type_t[]) noexcept(false);

		/**
		 * @brief Parameterized constructor
		 * @param arr Array of vectors
		 * @throw Pointer to array is null
		*/
		matrix(const vector<type_t, N_COL>[]) noexcept(false);

		/**
		 * @brief Copy constructor
		 * @param mtx Matrix
		*/
		matrix(const matrix<type_t, N_LIN, N_COL>&);

		/**
		 * @brief Get buffer
		 * @return Pointer to data
		*/
		const vector<type_t, N_COL>* buffer(void) const;

		/**
		 * @brief Get line
		 * @param lin Line index
		 * @return Reference to line vector
		 * @throw Index is congruent to number of lines
		*/
		vector<type_t, N_COL>& operator [] (unsigned long) noexcept(false);

		/**
		 * @brief Get number of lines
		 * @return Number of lines
		*/
		constexpr unsigned long n_lin(void) const;

		/**
		 * @brief Get number of columns
		 * @return Number of columns
		*/
		constexpr unsigned long n_col(void) const;

		/**
		 * @brief Check upper
		 * @return True if matrix is upper triangular
		*/
		bool is_upper(void) const;

		/**
		 * @brief Check lower
		 * @return True if matrix is lower triangular
		*/
		bool is_lower(void) const;

		/**
		 * @brief Get upper
		 * @return Upper matrix
		*/
		matrix<type_t, N_LIN, N_COL> get_upper(void) const;

		/**
		 * @brief Get lower
		 * @return Lower matrix
		*/
		matrix<type_t, N_LIN, N_COL> get_lower(void) const;

		/**
		 * @brief Copy operator
		 * @param mtx Matrix
		*/
		void operator = (const matrix<type_t, N_LIN, N_COL>&);

		/**
		 * @brief Equality operator
		 * @param mtx Matrix
		 * @return True if matrices are equal
		*/
		bool operator == (const matrix<type_t, N_LIN, N_COL>&) const;

		/**
		 * @brief Equality operator
		 * @tparam _type_t Data type
		 * @tparam _N_LIN Number of lines
		 * @tparam _N_COL Number of columns
		 * @param mtx Matrix
		 * @return False
		*/
		template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
		constexpr bool operator == (const matrix<_type_t, _N_LIN, _N_COL>&) const;

		/**
		 * @brief Inequality operator
		 * @param mtx Matrix
		 * @return True if matrices are different
		*/
		bool operator != (const matrix<type_t, N_LIN, N_COL>&) const;

		/**
		 * @brief Inequality operator
		 * @tparam _type_t Data type
		 * @tparam _N_LIN Number of lines
		 * @tparam _N_COL Number of columns
		 * @param mtx Matrix
		 * @return True
		*/
		template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
		constexpr bool operator != (const matrix<_type_t, _N_LIN, _N_COL>&) const;

		/**
		 * @brief Addition operator
		 * @param mtx Matrix
		 * @return Addition
		*/
		matrix<type_t, N_LIN, N_COL> operator + (const matrix<type_t, N_LIN, N_COL>&) const;

		/**
		 * @brief Subtraction operator
		 * @param mtx Matrix
		 * @return Subtraction
		*/
		matrix<type_t, N_LIN, N_COL> operator - (const matrix<type_t, N_LIN, N_COL>&) const;

		/**
		 * @brief Scalar multiplication
		 * @param scl Scalar
		 * @return Scaled matrix
		*/
		matrix<type_t, N_LIN, N_COL> operator * (type_t) const;

		/**
		 * @brief Scalar division
		 * @param scl Scalar
		 * @return Scaled matrix
		*/
		matrix<type_t, N_LIN, N_COL> operator / (type_t) const;

		/**
		 * @brief Matrix multiplication operator
		 * @tparam _N_COL Number of columns
		 * @param mtx Matrix
		 * @return Multiplication
		*/
		template <unsigned long _N_COL>
		matrix<type_t, N_LIN, _N_COL> operator * (const matrix<type_t, N_COL, _N_COL>&) const;
	};
}

// Template file
#include "matrix.tpp"

#endif // _MATRX_HPP_
