// Header file
#include "tester.hpp"

// Dependencies
#include <iostream>
#include <fstream>

void tester::init(const std::string& name) noexcept(true)
{
	this->_name = name;
}

void tester::start(const std::string& fn_name, const std::string& file_path) noexcept(true)
{
	auto results = test_results{fn_name, file_path, {}};
	this->_results.push_back(results);
}

void tester::pass(const unsigned long line_number) noexcept(true)
{
	auto loc = location{true, line_number};
	this->_results.back()._loc.push_back(loc);
}

void tester::fail(const unsigned long line_number) noexcept(true)
{
	auto loc = location{false, line_number};
	this->_results.back()._loc.push_back(loc);
}

void tester::print(void) const noexcept(true)
{
	static constexpr char
		TERMINAL_RESET_COLOR[] = "\033[0m",
		TERMINAL_RED_COLOR[] = "\033[31m",
		TERMINAL_GREEN_COLOR[] = "\033[32m",
		TERMINAL_BLUE_COLOR[] = "\033[34m";

	if (this->_name != "")
		std::cout << "[TESTER] " << this->_name << '\n';

	for (auto result : this->_results)
	{
		unsigned long index = 0;

		std::cout << '\t' << result._fn_name << '\n';

		for (auto test : result._loc)
		{
			std::cout << "\t\t";
		
			if (test._passed)
				std::cout << TERMINAL_GREEN_COLOR << "PASSED";
			else
				std::cout << TERMINAL_RED_COLOR << "FAILED";

			std::cout
				<< TERMINAL_RESET_COLOR
				<< " ("
				<< TERMINAL_BLUE_COLOR
				<< ++index
				<< TERMINAL_RESET_COLOR
				<< ") : "
				<< result._file_path
				<< ':'
				<< test._line_number
				<< std::endl;
		}
	}
}
