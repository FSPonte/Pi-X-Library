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
		out_of_bounds, // Index is out of bounds
		bad_alloc, // Bad memory allocation
		null_ptr // Null pointer
	};

	// Exception message
	constexpr const char* msg[] =
	{
		"Underflow",
		"Overflow",
		"Dimension is equal to zero",
		"Index is out of bounds",
		"Bad memory allocation",
		"Dereferencing a null pointer"
	};
}

#endif // _EXCEPTIONS_HPP_
