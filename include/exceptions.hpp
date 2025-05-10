#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Exceptions
namespace pix
{
	// Exception type
	enum excep_t
	{
		underflow, // Numeric underflow
		overflow, // Numeric overflow
		null_dim, // Null dimension
		out_of_bounds, // Out of bounds memory access
		bad_alloc, // Bad memory allocation
		null_ptr // Null pointer
	};

	constexpr const char* excep_msg[] =
	{
		"Numeric underflow",
		"Numeric overflow",
		"Dimension is equal to zero",
		"Out of bounds memory access",
		"Bad memory allocation",
		"Pointer is null"
	};
}

#endif // _EXCEPTIONS_HPP_
