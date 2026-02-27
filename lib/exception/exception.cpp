// Header file
#include "exception.hpp"

namespace pix::exception
{
	excep::excep(const std::string& name, traceback<true>* const route) noexcept(true) : _name(name), _route(route)
	{}

	std::string excep::what(void) const noexcept(true)
	{
		std::string ret = "[Exception] " + this->_name;

		if (this->_route != nullptr)
			ret += this->_route->get();

		return ret;
	}

	null_dim::null_dim(traceback<true>* route) noexcept(true) : excep("Null dimension", route) {}
	null_ptr::null_ptr(traceback<true>* route) noexcept(true) : excep("Null pointer", route) {}
	bad_alloc::bad_alloc(traceback<true>* route) noexcept(true) : excep("Bad memory allocation", route) {}
	underflow::underflow(traceback<true>* route) noexcept(true) : excep("Numeric underflow", route) {}
	overflow::overflow(traceback<true>* route) noexcept(true) : excep("Numerica overflow", route) {}
	bad_range::bad_range(traceback<true>* route) noexcept(true) : excep("Bad numeric range", route) {}
	div_zero::div_zero(traceback<true>* route) noexcept(true) : excep("Division by zero", route) {}
	invalid_argument::invalid_argument(traceback<true>* route) noexcept(true) : excep("Invalid argument", route) {}
	out_of_bounds::out_of_bounds(traceback<true>* route) noexcept(true) : excep("Out of bounds", route) {}
	os_not_supported::os_not_supported(traceback<true>* route) noexcept(true) : excep("OS is not supported", route) {}
}
