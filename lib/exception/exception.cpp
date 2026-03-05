// Header file
#include "exception.hpp"

// Dependencies
#include <iostream>

static constexpr char
	RESET[] = "\033[0m",
	BLUE[] = "\033[34m";

namespace pix::exception
{
	excep::excep(const std::string& name, traceback<TRACEBACK_ENABLED>* const route) noexcept(true) : _name(name), _route(route)
	{}

	std::string excep::what(void) const noexcept(true)
	{
		return std::string(
			"\n[" + std::string(BLUE) + "Exception" + RESET + "] " +
			this->_name + '\n'
		);
	}

	void excep::print(void) const noexcept(true)
	{
		std::cout
			<< "\n["
			<< BLUE
			<< "Exception"
			<< RESET
			<< "] "
			<< this->_name
			<< '\n';

		if (this->_route != nullptr)
			this->_route->print();
	}

	null_dim::null_dim(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Null dimension", route) {}
	null_ptr::null_ptr(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Null pointer", route) {}
	bad_alloc::bad_alloc(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Bad memory allocation", route) {}
	underflow::underflow(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Numeric underflow", route) {}
	overflow::overflow(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Numerica overflow", route) {}
	bad_range::bad_range(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Bad numeric range", route) {}
	div_zero::div_zero(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Division by zero", route) {}
	invalid_argument::invalid_argument(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Invalid argument", route) {}
	out_of_bounds::out_of_bounds(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("Out of bounds", route) {}
	os_not_supported::os_not_supported(traceback<TRACEBACK_ENABLED>* route) noexcept(true) : excep("OS is not supported", route) {}
}
