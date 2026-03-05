// Header file
#include "traceback.hpp"

// Dependencies
#include <iostream>

static constexpr char
	RESET[] = "\033[0m",
	BLUE[] = "\033[34m";

namespace pix
{
	bool traceback<true>::trace_point::operator == (const trace_point& point) const noexcept(true)
	{
		if (
			this->_fn_name != point._fn_name ||
			this->_file_path != point._file_path ||
			this->_line_number != point._line_number
		) return false;

		return true;
	}

	traceback<true>::traceback(const traceback& route) noexcept(true)
	{
		this->_data = route._data;
	}

	traceback<true>::traceback(const std::string& fn_name, const std::string& file_path, const unsigned long line_number) noexcept(true)
	{
		this->_data.push_back(trace_point{fn_name, file_path, line_number});
	}

	void traceback<true>::init(const std::string& fn_name, const std::string& file_path, const unsigned long line_number) noexcept(true)
	{
		auto point = trace_point{fn_name, file_path, line_number};
		this->_data.push_back(point);
	}

	void traceback<true>::trigger(const unsigned long line_number) noexcept(true)
	{
		this->_data.back()._line_number = line_number;
	}

	bool traceback<true>::is_empty(void) const noexcept(true)
	{
		return (this->_data.size() == 0) ? true : false;
	}

	void traceback<true>::print(void) const noexcept(true)
	{
		std::cout
			<< '['
			<< BLUE
			<< "Traceback"
			<< RESET
			<< "]\n";

		for (auto point : this->_data)
		{
			std::cout
				<< '\t' << point._fn_name << " : "
				<< point._file_path << ':' << point._line_number
				<< '\n';
		}
	}

	void traceback<true>::operator = (const traceback& route) noexcept(true)
	{
		this->_data = route._data;
	}
}
