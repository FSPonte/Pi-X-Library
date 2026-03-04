#ifndef __TESTER_HPP__
#define __TESTER_HPP__

// Dependencies
#include <string>
#include <vector>

struct single_test
{
	bool _passed; // Result of the test
	unsigned long _line_number; // Number of the condition triggered
};

struct test_results
{
	std::string
		_fn_name, // Name of the test function
		_file_path; // Path to file
	std::vector<single_test> _tests; // Single tests
};

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

	std::string _name; // Name of the test
	std::vector<test_results> _results;
};

#endif // __TESTER_HPP__
