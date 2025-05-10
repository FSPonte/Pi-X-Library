#ifndef _SYS_LIN_EQU_TPP_
#define _SYS_LIN_EQU_TPP_

// Dependencies
#include <asserts.hpp>
#include <macros.hpp>
#include <c_array.hpp>
#include <math.hpp>

namespace pix::math::sys_lin_equ
{
	template <typename type_t, unsigned long DIM>
	void gauss_elim(const type_t (&MTX)[DIM][DIM], const type_t (&VEC)[DIM], type_t (&sol)[DIM]) noexcept(false)
	{
		assert_is_number(type_t);

		type_t
			A_[DIM][DIM], // Mutable copy of matrix A
			b_[DIM]; // Mutable copy of vector b

		pix::c_array::copy(MTX, A_);
		pix::c_array::copy(VEC, b_);
		
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
			sol[i] = b_[i];

			for (unsigned long j = i + 1; j < DIM; ++j)
				sol[i] -= A_[i][j] * sol[j];
			
			sol[i] /= A_[i][i];
			
			if (sol[i] == pix::math::NaN) throw "NaN value encountered";
		}

		// Logger
		{
			LOGGER_LOG_MSG("\nRegressive substitution:");

			for (unsigned long i = 0; i < DIM; ++i)
				LOGGER_LOG_MSG("\tx[" + std::to_string(i + 1) + "] = " + std::to_string(sol[i]));
		}

    	return;
	}

	template <typename type_t, unsigned long DIM>
	void lu_decomp(const type_t (&MTX)[DIM][DIM], type_t (&lower)[DIM][DIM], type_t (&upper)[DIM][DIM])
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

		// Logger
		LOGGER_INIT("logs/lu_decomp.log");
		{
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_ARR(MTX);
		}

		for (unsigned long k = 0; k < DIM; ++k)
		{
			// Compute U[k][j]
			for (unsigned long j = k; j < DIM; ++j)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += lower[k][s] * upper[s][j];
			
				upper[k][j] = MTX[k][j] - sum;

				// Logger
				{
					LOGGER_LOG_MSG("\nU[" + std::to_string(k + 1) + "][" + std::to_string(j + 1) + "] = " + std::to_string(upper[k][j]));
					LOGGER_LOG_ARR(upper);
				}
			}

			if (pix::math::abs(upper[k][k]) == 0) throw "Pivot encountered is equal to zero";

			// Compute L[i][k]
			for (unsigned long i = k + 1; i < DIM; ++i)
			{
				sum = 0;
			
				for (unsigned long s = 0; s < k; ++s)
					sum += lower[i][s] * upper[s][k];
			
				lower[i][k] = (MTX[i][k] - sum) / upper[k][k];

				// Logger
				{
					LOGGER_LOG_MSG("\nL[" + std::to_string(i + 1) + "][" + std::to_string(k + 1) + "] = " + std::to_string(lower[i][k]));
					LOGGER_LOG_ARR(lower);
				}
			}
		}
	}
}

#endif // _SYS_LIN_EQU_TPP_
