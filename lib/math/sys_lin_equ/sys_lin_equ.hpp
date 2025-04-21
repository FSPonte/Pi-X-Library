#ifndef _SYS_LIN_EQU_HPP_
#define _SYS_LIN_EQU_HPP_

namespace pix::math::sys_lin_equ
{
	/**
	 * @brief Gaussian elimination
	 * @tparam type_t Data type
	 * @param mtx Matrix
	 * @param vec Vector
	 * @param sol Solution
	 * @throw Singular matrix
	 * @throw NaN value encountered
	*/
	template <typename type_t, unsigned long DIM>
	void gauss_elim(type_t (&)[DIM][DIM], type_t (&)[DIM], type_t (&)[DIM]) noexcept(false);

	/**
	 * @brief LU decomposition
	 * @tparam type_t Data type
	 * @param mtx Matrix
	 * @param l Lower
	 * @param u Upper
	 * @throw Pivot encountered is equal to zero
	*/
	template <typename type_t, unsigned long DIM>
	void lu_decomp(type_t (&)[DIM][DIM], type_t (&)[DIM][DIM], type_t (&)[DIM][DIM]) noexcept(false);
}

// Template file
#include "sys_lin_equ.tpp"

#endif // _SYS_LIN_EQU_HPP_
