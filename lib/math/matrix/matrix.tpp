#ifndef _MATRIX_TPP_
#define _MATRIX_TPP_

// Dependencies
#include <asserts.hpp>
#include <type_info.hpp>

namespace pix::math
{
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL>::matrix(void)
	{
		assert_not_nulldim(N_LIN);
		assert_not_nulldim(N_COL);
		is_number_static_assert(type_t);

		static_assert
		(
			N_LIN != 0 && N_COL != 0,
			"Array object cannot have zero lines or columns"
		);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL>::matrix(const type_t arr[]) noexcept(false) : matrix<type_t, N_LIN, N_COL>()
	{
		if (arr == nullptr) throw "Pointer to array is null";

		for (unsigned long i = 0; i < N_LIN; ++i)
			this->_data[i] = vector<type_t, N_COL>(arr + i * N_LIN);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL>::matrix(const vector<type_t, N_COL> arr[]) noexcept(false) : matrix<type_t, N_LIN, N_COL>()
	{
		if (arr == nullptr) throw "Pointer to array is null";

		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
				this->_data[i][j] = arr[i].buffer()[j];
		}
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL>::matrix(const matrix<type_t, N_LIN, N_COL>& mtx) : matrix<type_t, N_LIN, N_COL>()
	{
		*this = mtx;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	const vector<type_t, N_COL>* matrix<type_t, N_LIN, N_COL>::buffer(void) const
	{
		return this->_data;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	vector<type_t, N_COL>& matrix<type_t, N_LIN, N_COL>::operator [] (const unsigned long index) noexcept(false)
	{
		if (index >= N_LIN) throw "Index is out bounds";

		return this->_data[index % N_LIN];
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	constexpr unsigned long matrix<type_t, N_LIN, N_COL>::n_lin(void) const
	{
		return N_LIN;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	constexpr unsigned long matrix<type_t, N_LIN, N_COL>::n_col(void) const
	{
		return N_COL;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	bool matrix<type_t, N_LIN, N_COL>::is_upper(void) const
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < i; ++j)
			{
				if (this->_data[i].buffer()[j] != 0)
					return false;
			}
		}

		return true;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	bool matrix<type_t, N_LIN, N_COL>::is_lower(void) const
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = i + 1; j < N_COL; ++j)
			{
				if (this->_data[i].buffer()[j] != 0)
					return false;
			}
		}

		return true;
	}

	
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::get_upper(void) const
	{
		type_t arr[N_LIN][N_COL];

		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
			{
				if (i > j)
				{
					arr[i][j] = 0;

					continue;
				}

				arr[i][j] = this->_data[i].buffer()[j];
			}
		}

		return pix::math::matrix<type_t, N_LIN, N_COL>(&arr[0][0]);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::get_lower(void) const
	{
		type_t arr[N_LIN][N_COL];

		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
			{
				if (i < j)
				{
					arr[i][j] = 0;

					continue;
				}

				arr[i][j] = this->_data[i].buffer()[j];
			}
		}

		return pix::math::matrix<type_t, N_LIN, N_COL>(&arr[0][0]);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void matrix<type_t, N_LIN, N_COL>::operator = (const matrix<type_t, N_LIN, N_COL>& mtx)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
			this->_data[i] = mtx._data[i];
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	bool matrix<type_t, N_LIN, N_COL>::operator == (const matrix<type_t, N_LIN, N_COL>& mtx) const
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			if (this->_data[i] != mtx[i])
				return false;
		}

		return true;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
	constexpr bool matrix<type_t, N_LIN, N_COL>::operator == (const matrix<_type_t, _N_LIN, _N_COL>& mtx) const
	{
		return false;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	bool matrix<type_t, N_LIN, N_COL>::operator != (const matrix<type_t, N_LIN, N_COL>& mtx) const
	{
		return !(*this == mtx);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
	constexpr bool matrix<type_t, N_LIN, N_COL>::operator != (const matrix<_type_t, _N_LIN, _N_COL>& mtx) const
	{
		return true;
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator + (const matrix<type_t, N_LIN, N_COL>& mtx) const
	{
		pix::math::vector<type_t, N_COL> arr[N_LIN];

		for (unsigned long i = 0; i < N_LIN; ++i)
			arr[i] = this->_data[i] + mtx._data[i];

		return pix::math::matrix<type_t, N_LIN, N_COL>(arr);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator - (const matrix<type_t, N_LIN, N_COL>& mtx) const
	{
		pix::math::vector<type_t, N_COL> arr[N_LIN];

		for (unsigned long i = 0; i < N_LIN; ++i)
			arr[i] = this->_data[i] - mtx._data[i];

		return pix::math::matrix<type_t, N_LIN, N_COL>(arr);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator * (const type_t scalar) const
	{
		pix::math::vector<type_t, N_COL> arr[N_LIN];

		for (unsigned long i = 0; i < N_LIN; ++i)
			arr[i] = this->_data[i] * scalar;

		return pix::math::matrix<type_t, N_LIN, N_COL>(arr);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator / (const type_t scalar) const
	{
		pix::math::vector<type_t, N_COL> arr[N_LIN];

		for (unsigned long i = 0; i < N_LIN; ++i)
			arr[i] = this->_data[i] / scalar;

		return pix::math::matrix<type_t, N_LIN, N_COL>(arr);
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	template <unsigned long _N_COL>
	matrix<type_t, N_LIN, _N_COL> matrix<type_t, N_LIN, N_COL>::operator * (const matrix<type_t, N_COL, _N_COL>& mtx) const
	{
		pix::math::vector<type_t, _N_COL> arr[N_LIN];

		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < _N_COL; ++j)
			{
				arr[i][j] = 0;

				for (unsigned long k = 0; k < N_COL; ++k)
					arr[i][j] += this->_data[i].buffer()[j] * mtx._data[k].buffer()[j];
			}
		}

		return pix::math::matrix<type_t, N_LIN, _N_COL>(arr);
	}
}

#endif // _MATRIX_TPP_
