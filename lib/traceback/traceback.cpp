// Header file
#include "traceback.hpp"

// Dependencies
#include <iostream>

namespace pix
{
	void traceback<true>::init(const std::string& file_path, const std::string& fn_name) noexcept(true)
	{
		this->_file_path = file_path;
		this->_fn_name = fn_name;
	}

	void traceback<true>::trigger(const unsigned long line_number) noexcept(true)
	{
		this->_line_number = line_number;
	}

	std::string traceback<true>::get(void) const noexcept(true)
	{
		return std::string(
			"\tFile path   : " + this->_file_path + '\n' +
			"\tFunction    : " + this->_fn_name + '\n' +
			"\tLine number : " + std::to_string(this->_line_number) + "\n\n"
		);
	}

	void traceback<true>::display(void) const noexcept(true)
	{
		std::cout
			<< "File path   : " << this->_file_path << '\n'
			<< "Function    : " << this->_fn_name << '\n'
			<< "Line number : " << this->_line_number << '\n'
			<< std::endl;
	}

	void traceback<true>::operator = (const traceback& route) noexcept(true)
	{
		this->_file_path = route._file_path;
		this->_fn_name = route._fn_name;
		this->_line_number = route._line_number;
	}
}
