// Header file
#include "tester.hpp"

// Dependencies
#include <iostream>
#include <fstream>

static constexpr char
	RESET[] = "\033[0m",
	RED[] = "\033[31m",
	GREEN[] = "\033[32m",
	BLUE[] = "\033[34m",
	CYAN[] = "\033[0;36m";

namespace pix
{
	void tester::init(const std::string& target_name) noexcept(true)
	{
		this->_data.push_back(target_tests{target_name, {}});
	}

	void tester::start(const std::string& fn_name, const std::string& file_path) noexcept(true)
	{
		this->_data.back()._unit_tests.push_back(unit_tests{fn_name, file_path, {}});
	}

	void tester::pass(const unsigned long line_number) noexcept(true)
	{
		this->_data.back()._unit_tests.back()._single_tests.push_back(single_test{true, line_number});
	}

	void tester::fail(const unsigned long line_number) noexcept(true)
	{
		this->_data.back()._unit_tests.back()._single_tests.push_back(single_test{false, line_number});
	}

	void tester::print(void) const noexcept(true)
	{
		for (auto target : this->_data)
		{
			if (target._target_name != "")
			{
				std::cout
					<< '['
					<< BLUE
					<< "Tester"
					<< RESET
					<< "] "
					<< target._target_name
					<< '\n';
			}

			for (auto unit_test : target._unit_tests)
			{
				std::cout
					<< '\t'
					<< CYAN
					<< "@ " << unit_test._fn_name
					<< RESET
					<< '\n';

				for (auto single_test : unit_test._single_tests)
				{
					std::cout << "\t\t";
				
					if (single_test._passed)
						std::cout << GREEN << "PASSED";
					else
						std::cout << RED << "FAILED";

					std::cout
						<< RESET
						<< " : "
						<< unit_test._file_path
						<< ':'
						<< single_test._line_number
						<< std::endl;
				}
			}
		}
	}
}
