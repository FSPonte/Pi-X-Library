#ifndef _UTILS_TPP_
#define _UTILS_TPP_

// Dependencies
#include <iostream>

namespace utils
{
	template <typename type_t, unsigned long DIM>
	void print(type_t (&arr)[DIM]) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM; ++i)
			std::cout << arr[i] << ' ';

		std::cout << '\n';
	}
	
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void print(type_t (&arr)[N_LIN][N_COL]) noexcept(true)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
				std::cout << arr[i][j] << ' ';

			std::cout << '\n';
		}
	}
}

#endif // _UTILS_TPP_
