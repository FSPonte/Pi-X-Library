#ifndef _SYS_LIN_EQU_TPP_
#define _SYS_LIN_EQU_TPP_

// Dependencies
#include <type_info.hpp>
#include <c_array.hpp>
#include <math.hpp>

namespace pix::math::sys_lin_equ
{
	template <typename type_t, unsigned long DIM>
	void gauss_elim(const type_t (&A)[DIM][DIM], const type_t (&b)[DIM], type_t (&x)[DIM]) noexcept(false)
	{
		is_number_static_assert(type_t);

		type_t
			A_[DIM][DIM], // Mutable copy of matrix A
			b_[DIM]; // Mutable copy of vector b
		
		pix::c_array::copy(A, A_);
		pix::c_array::copy(b, b_);
		
		unsigned long i_max; // Partial pivot
		double factor;

		// Gaussian elimination with partial pivot
		for (unsigned long j = 0; j < DIM; ++j)
		{
			i_max = j;
			
			for (unsigned long i = j + 1; i < DIM; ++i)
			{
				if (pix::math::abs(A_[i][j]) > pix::math::abs(A_[i_max][j]))
					i_max = i;
			}

			if (j != i_max)
			{
				pix::c_array::swap(A_[j], A_[i_max]); // Swap lines in matrix
				pix::c_array::swap(b_[j], b_[i_max]); // Swap components in vector
			}
			
			if (pix::math::abs(A_[j][j]) == 0) throw "Singular matrix";
			
			// Elimination
			{	
				for (unsigned long i = j + 1; i < DIM; ++i)
				{
					factor = A_[i][j] / A_[j][j];
					
					if (factor == 0)
						continue;

					for (unsigned long k = j; k < DIM; ++k)
						A_[i][k] -= factor * A_[j][k];
					
					b_[i] -= factor * b_[j];
				}
			}
		}
		
		// Regressive substitution
		for (unsigned long i = DIM - 1; i > 0; --i)
		{
			x[i] = b_[i];

			for (unsigned long j = i + 1; j < DIM; ++j)
				x[i] -= A_[i][j] * x[j];
			
			x[i] /= A_[i][i];
			
			if (x[i] == pix::math::NaN()) throw "NaN value encountered";
		}
    
    	return;
	}

	template <typename type_t, unsigned long DIM>
	void lu_decomp(const type_t (&A)[DIM][DIM], type_t (&L)[DIM][DIM], type_t (&U)[DIM][DIM])
	{
		is_number_static_assert(type_t);

		// Initialize L to identity and U to zero
		for (unsigned long i = 0; i < DIM; ++i)
		{
			for (unsigned long j = 0; j < DIM; ++j)
			{
				L[i][j] = (i == j);
				U[i][j] = 0;
			}
		}

		type_t sum;

		for (unsigned long k = 0; k < DIM; ++k)
		{
			// Compute U[k][j]
			for (unsigned long j = k; j < DIM; ++j)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += L[k][s] * U[s][j];
			
				U[k][j] = A[k][j] - sum;
			}

			if (pix::math::abs(U[k][k]) == 0) throw "Pivot encountered is equal to zero";

			// Compute L[i][k]
			for (unsigned long i = k + 1; i < DIM; ++i)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += L[i][s] * U[s][k];
			
				L[i][k] = (A[i][k] - sum) / U[k][k];
			}
		}
	}
}

#endif // _SYS_LIN_EQU_TPP_
