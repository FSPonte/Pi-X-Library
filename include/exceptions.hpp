#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Exceptions
namespace pix::exception
{
	// Exception type
	enum type
	{
		underflow, // Numeric underflow
		overflow, // Numeric overflow
		null_dim, // Null dimension
		out_of_bounds, // Out of bounds memory access
		bad_alloc, // Bad memory allocation
		null_ptr // Null pointer
	};

	// Exception message
	constexpr const char* msg[] =
	{
		"Underflow",
		"Overflow",
		"Dimension is equal to zero",
		"Out of bounds memory access",
		"Bad memory allocation",
		"Dereference of a null pointer"
	};
}

#endif // _EXCEPTIONS_HPP_
