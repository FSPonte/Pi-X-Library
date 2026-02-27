#ifndef _LOGGER_TPP_
#define _LOGGER_TPP_

// Dependencies
#include <iostream>

namespace pix
{
	template <typename type_t, unsigned long DIM>
	void logger<true>::log_list(const type_t (&arr)[DIM]) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";

		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << i << " : " << arr[i] << '\n';
	}

	template <typename type_t, unsigned long DIM>
	void logger<true>::log_array(const type_t (&arr)[DIM]) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";
		
		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << arr[i] << ' ';

		std::clog << '\n';
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void logger<true>::log_array(const type_t (&arr)[N_LIN][N_COL]) noexcept(false)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
			this->log_array(arr[i]);
	}
}

#endif // _LOGGER_TPP_
