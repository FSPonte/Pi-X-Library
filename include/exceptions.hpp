#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Exceptions
namespace pix::exceptions
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
		"Null dimension",
		"Out of bounds memory access",
		"Bad memory allocation",
		"Null pointer"
	};
}

#endif // _EXCEPTIONS_HPP_
