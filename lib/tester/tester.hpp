#ifndef __TESTER_HPP__
#define __TESTER_HPP__

// Dependencies
#include <string>
#include <vector>

namespace pix
{
	class tester
	{
	public:

		/**
		 * @brief Constructor
		*/
		tester(void) noexcept(true) = default;

		/**
		 * @brief Initializer
		 * @param name Name of the test function
		 * @param path Path to the file
		*/
		void init(const std::string&) noexcept(true);

		/**
		 * @brief Start unit tests
		 * @param name Name of the unit test
		 * @param path Path to the file
		*/

		void start(const std::string&, const std::string&) noexcept(true);

		/**
		 * @brief Pass a test
		 * @param lin Line number
		*/
		void pass(unsigned long) noexcept(true);

		/**
		 * @brief Fail a test
		 * @param lin Line number
		*/
		void fail(unsigned long) noexcept(true);

		/**
		 * @brief Display to the terminal
		*/
		void print(void) const noexcept(true);

	private:

		struct single_test
		{
			bool _passed; // Result of the test
			unsigned long _line_number; // Line number of the condition triggered
		};

		struct unit_tests
		{
			std::string
				_fn_name, // Name of the test function
				_file_path; // Path to file
			std::vector<single_test> _single_tests; // Single tests
		};

		struct target_tests
		{
			std::string _target_name; // Name of the test target
			std::vector<unit_tests> _unit_tests; // Unit tests
		};

		std::vector<target_tests> _data;
	};
}

#endif // __TESTER_HPP__
