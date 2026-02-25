#ifndef _SYS_LIN_EQU_TPP_
#define _SYS_LIN_EQU_TPP_

namespace pix::math::sys_lin_equ
{
	template <typename type_t, unsigned long DIM>
	void gauss_elim(const type_t (&mtx)[DIM][DIM], const type_t (&vec)[DIM], type_t (&sol)[DIM]) noexcept(false)
	{
		assert_is_number(type_t);

		type_t
			A_[DIM][DIM], // Mutable copy of matrix A
			b_[DIM]; // Mutable copy of vector b

		pix::c_array::copy(mtx, A_);
		pix::c_array::copy(vec, b_);
		
		unsigned long i_max; // Partial pivot
		type_t factor;

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
				// Swap lines in matrix
				for (unsigned long k = 0; k < DIM; ++k)
					pix::c_array::swap(A_[i_max][k], A_[j][k]); // Swap rows in matrix

				pix::c_array::swap(b_[j], b_[i_max]); // Swap components in vector
			}
			
			if (pix::math::abs(A_[j][j]) == 0)
				throw "Singular matrix";
			
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

		for (unsigned long i = DIM - 1; i + 1 != 0; --i)
		{
			sol[i] = b_[i];

			for (unsigned long j = i + 1; j < DIM; ++j)
				sol[i] -= A_[i][j] * sol[j];
			
			sol[i] /= A_[i][i];
			
			if (sol[i] == pix::math::NaN)
				throw "NaN value encountered";
		}

    	return;
	}

	template <typename type_t, unsigned long DIM>
	void lu_decomp(const type_t (&mtx)[DIM][DIM], type_t (&lower)[DIM][DIM], type_t (&upper)[DIM][DIM])
	{
		assert_is_number(type_t);

		// Initialize L to identity and U to zero
		for (unsigned long i = 0; i < DIM; ++i)
		{
			for (unsigned long j = 0; j < DIM; ++j)
			{
				lower[i][j] = (i == j);
				upper[i][j] = 0;
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
					sum += lower[k][s] * upper[s][j];
			
				upper[k][j] = mtx[k][j] - sum;
			}

			if (pix::math::abs(upper[k][k]) == 0)
				throw "Pivot encountered is equal to zero";

			// Compute L[i][k]
			for (unsigned long i = k + 1; i < DIM; ++i)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += lower[i][s] * upper[s][k];
			
				lower[i][k] = (mtx[i][k] - sum) / upper[k][k];
			}
		}
	}
}

#endif // _SYS_LIN_EQU_TPP_
