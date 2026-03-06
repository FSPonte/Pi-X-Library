#ifndef __C_ARRAY_TPP__
#define __C_ARRAY_TPP__

// Dependencies
#include <asserts.hpp>
#include <exception.hpp>
#include <debugger.hpp>

namespace pix::c_array
{
	template <typename type_t>
	void swap(type_t& ref_1, type_t& ref_2) noexcept(true)
	{
		const type_t aux = ref_1; // Auxiliar value
		ref_1 = ref_2;
		ref_2 = aux;
	}

	template <typename type_t>
	void swap(type_t*& ptr_1, type_t*& ptr_2) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (ptr_1 == nullptr || ptr_2 == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
		}

		type_t* aux = ptr_1; // Auxiliar pointer
		ptr_1 = ptr_2;
		ptr_2 = aux;
	}

	template <typename type_t>
	void invert(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		unsigned long
			left_ind = 0,
			right_ind = DIM - 1;

		while (left_ind < right_ind)
		{
			DEBUG_TRACEBACK_TRIG;
			pix::c_array::swap(arr[left_ind], arr[right_ind]);

			++left_ind;
			--right_ind;
		}
	}

	template <typename type_t, unsigned long DIM>
	void invert(type_t (&arr)[DIM]) noexcept(false)
	{
		assert_not_nulldim(DIM);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::invert<type_t>(arr, DIM);
	}

	template <typename type_t>
	void copy(const type_t arr_o[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr_o == nullptr || arr_d == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		for (unsigned long i = 0; i < DIM; ++i)
			arr_d[i] = arr_o[i];
	}

	template <typename type_t, unsigned long DIM>
	void copy(const type_t (&arr_o)[DIM], type_t (&arr_d)[DIM]) noexcept(false)
	{
		assert_not_nulldim(DIM);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::copy<type_t>(arr_o, arr_d, DIM);
	}

	template <typename type_t>
	void move(type_t arr_o[], type_t arr_d[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr_o == nullptr || arr_d == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		for (unsigned long i = 0; i < DIM; ++i)
		{
			arr_d[i] = arr_o[i];
			arr_o[i] = type_t();
		}
	}

	template <typename type_t, unsigned long DIM>
	void move(type_t (&arr_o)[DIM], type_t (&arr_d)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::move<type_t>(arr_o, arr_d, DIM);
	}

	template <typename type_t>
	void left_shift(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		for (unsigned long i = 1; i < DIM; ++i)
			arr[i - 1] = arr[i];

		arr[DIM - 1] = type_t();
	}

	template <typename type_t, unsigned long DIM>
	void left_shift(type_t (&arr)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::left_shift<type_t>(arr, DIM);
	}

	template <typename type_t>
	void right_shift(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		for (unsigned long i = DIM - 1; i > 0; --i)
			arr[i] = arr[i - 1];

		arr[0] = type_t();
	}

	template <typename type_t, unsigned long DIM>
	void right_shift(type_t (&arr)[DIM]) noexcept(true)
	{
		assert_not_nulldim(DIM);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::right_shift<type_t>(arr, DIM);
	}

	template <typename type_t>
	void bit_rev(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
			if ((DIM & (DIM - 1)) != 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::excep("Dimension must be a power of 2", DEBUG_TRACEBACK_RT);
			}
		}

		unsigned long
			j = 0,
			bit;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (i < j)
			{
				DEBUG_TRACEBACK_TRIG;
				pix::c_array::swap(arr[i], arr[j]);
			}

			bit = DIM >> 1;
			
			while (j & bit)
			{
				j ^= bit;
				bit >>= 1;
			}

			j ^= bit;
		}
	}

	template <typename type_t, unsigned long DIM>
	void bit_rev(type_t (&arr)[DIM]) noexcept(false)
	{
		static_assert
		(
			(DIM & (DIM - 1)) == 0,
			"Dimension must be a power of 2"
		);

		// Debug
		DEBUG_TRACEBACK_INIT;

		pix::c_array::bit_rev<type_t>(arr, DIM);
	}

	template <typename type_t>
	unsigned long binary_search(type_t arr[], const unsigned long DIM, const type_t target) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		unsigned long
			left = 0,
			right = DIM - 1,
			mid;

		while (left <= right)
		{
			mid = left + 0.5 * (right - left);

			if (arr[mid] < target)
				left = mid + 1;
			else if (arr[mid] > target)
				right = mid - 1;
			else
				return mid;
		}

		// Debug
		{
			DEBUG_TRACEBACK_TRIG;
			throw pix::exception::excep("Element not found", DEBUG_TRACEBACK_RT);
		}
	}

	template <typename type_t, unsigned long DIM>
	unsigned long binary_search(type_t (&arr)[DIM], const type_t target) noexcept(false)
	{
		assert_is_number(type_t);

		// Debug
		DEBUG_TRACEBACK_INIT;

		return pix::c_array::binary_search<type_t>(arr, DIM, target);
	}

	template <typename type_t>
	unsigned long binary_approx(type_t arr[], const unsigned long DIM, const type_t target) noexcept(false)
	{
		// Debug
		{
			DEBUG_TRACEBACK_INIT;

			if (arr == nullptr)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_ptr(DEBUG_TRACEBACK_RT);
			}
			if (DIM == 0)
			{
				DEBUG_TRACEBACK_TRIG;
				throw pix::exception::null_dim(DEBUG_TRACEBACK_RT);
			}
		}

		unsigned long
			left = 0,
			right = DIM - 1,
			mid;

		if (target <= arr[left]) return left;
		if (target >= arr[right]) return right;

		while (left + 1 < right)
		{
			mid = left + 0.5 * (right - left);

			if (arr[mid] < target)
				left = mid;
			else if (arr[mid] > target)
				right = mid;
			else
				return mid;
		}

		return left;
	}

	template <typename type_t, unsigned long DIM>
	unsigned long binary_approx(type_t (&arr)[DIM], const type_t target) noexcept(false)
	{
		assert_is_number(type_t);

		// Debug
		DEBUG_TRACEBACK_INIT;

		return pix::c_array::binary_approx<type_t>(arr, DIM, target);
	}
}

#endif // __C_ARRAY_TPP__
