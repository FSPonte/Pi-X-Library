// Header file
#include "exception.hpp"

// Dependencies
#include <iostream>

static constexpr char
	RESET[] = "\033[0m",
	BLUE[] = "\033[34m";

namespace pix::exception
{
	excep::excep(const std::string& name) noexcept(true) : _name(name) {}
	excep::excep(const std::string& name, const traceback<TRACEBACK_ENABLED> route) noexcept(true) : _name(name), _route(route) {}

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

		if (!this->_route.is_empty())
			this->_route.print();
	}

	null_dim::null_dim(void) noexcept(true) : excep("Null dimension") {}
	null_dim::null_dim(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Null dimension", route) {}

	null_ptr::null_ptr(void) noexcept(true) : excep("Null pointer") {}
	null_ptr::null_ptr(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Null pointer", route) {}
	
	bad_alloc::bad_alloc(void) noexcept(true) : excep("Bad memory allocation") {}
	bad_alloc::bad_alloc(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Bad memory allocation", route) {}
	
	underflow::underflow(void) noexcept(true) : excep("Numeric underflow") {}
	underflow::underflow(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Numeric underflow", route) {}
	
	overflow::overflow(void) noexcept(true) : excep("Numerica overflow") {}
	overflow::overflow(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Numerica overflow", route) {}
	
	bad_range::bad_range(void) noexcept(true) : excep("Bad numeric range") {}
	bad_range::bad_range(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Bad numeric range", route) {}
	
	div_zero::div_zero(void) noexcept(true) : excep("Division by zero") {}
	div_zero::div_zero(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Division by zero", route) {}
	
	invalid_argument::invalid_argument(void) noexcept(true) : excep("Invalid argument") {}
	invalid_argument::invalid_argument(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Invalid argument", route) {}
	
	out_of_bounds::out_of_bounds(void) noexcept(true) : excep("Out of bounds") {}
	out_of_bounds::out_of_bounds(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("Out of bounds", route) {}
	
	os_not_supported::os_not_supported(void) noexcept(true) : excep("OS is not supported") {}
	os_not_supported::os_not_supported(const traceback<TRACEBACK_ENABLED> route) noexcept(true) : excep("OS is not supported", route) {}
}
