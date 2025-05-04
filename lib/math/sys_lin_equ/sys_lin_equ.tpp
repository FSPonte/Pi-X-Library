#ifndef _SYS_LIN_EQU_TPP_
#define _SYS_LIN_EQU_TPP_

// Dependencies
#include <macros.hpp>
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
		type_t factor;

		// Logger
		LOGGER_INIT("logs/gauss_elim.log");
		{
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_AUG(A_, b_);
		}

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

				// Logger
				{
					LOGGER_LOG_MSG("\nLine swap (" + std::to_string(j + 1) + " <-> " + std::to_string(i_max + 1) + "):");
					LOGGER_LOG_AUG(A_, b_);
				}
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

					// Logger
					{
						LOGGER_LOG_MSG("\nLine elimination (" + std::to_string(j + 1) + " -> " + std::to_string(i + 1) + "):");
						LOGGER_LOG_MSG("\tFactor: " + std::to_string(factor));
						LOGGER_LOG_AUG(A_, b_);
					}
				}
			}
		}

		for (unsigned long i = DIM - 1; i + 1 != 0; --i)
		{
			x[i] = b_[i];

			for (unsigned long j = i + 1; j < DIM; ++j)
				x[i] -= A_[i][j] * x[j];
			
			x[i] /= A_[i][i];
			
			if (x[i] == pix::math::NaN) throw "NaN value encountered";
		}

		// Logger
		{
			LOGGER_LOG_MSG("\nRegressive substitution:");

			for (unsigned long i = 0; i < DIM; ++i)
				LOGGER_LOG_MSG("\tx[" + std::to_string(i + 1) + "] = " + std::to_string(x[i]));
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

		// Logger
		LOGGER_INIT("logs/lu_decomp.log");
		{
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_ARR(A);
		}

		for (unsigned long k = 0; k < DIM; ++k)
		{
			// Compute U[k][j]
			for (unsigned long j = k; j < DIM; ++j)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += L[k][s] * U[s][j];
			
				U[k][j] = A[k][j] - sum;

				// Logger
				{
					LOGGER_LOG_MSG("\nU[" + std::to_string(k + 1) + "][" + std::to_string(j + 1) + "] = " + std::to_string(U[k][j]));
					LOGGER_LOG_ARR(U);
				}
			}

			if (pix::math::abs(U[k][k]) == 0) throw "Pivot encountered is equal to zero";

			// Compute L[i][k]
			for (unsigned long i = k + 1; i < DIM; ++i)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += L[i][s] * U[s][k];
			
				L[i][k] = (A[i][k] - sum) / U[k][k];

				// Logger
				{
					LOGGER_LOG_MSG("\nL[" + std::to_string(i + 1) + "][" + std::to_string(k + 1) + "] = " + std::to_string(L[i][k]));
					LOGGER_LOG_ARR(L);
				}
			}
		}
	}
}

#endif // _SYS_LIN_EQU_TPP_
