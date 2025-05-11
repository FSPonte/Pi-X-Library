#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Exceptions
namespace pix::exceptions
{
	enum id
	{
		null_dim, // Null dimension
		null_ptr, // Null pointer
		bad_alloc, // Bad memory allocation
		underflow, // Numeric underflow
		overflow, // Numeric overflow
		bad_range, // Bad numeric range
		div_zero, // Division by zero
		inv_arg // Invalid argument
	};

	constexpr const char* msg[] =
	{
		"Null dimension",
		"Null pointer",
		"Bad memory allocation",
		"Numeric underflow",
		"Numeric overflow",
		"Bad numeric range",
		"Division by zero",
		"Invalid argument"
	};
}

#endif // _EXCEPTIONS_HPP_
