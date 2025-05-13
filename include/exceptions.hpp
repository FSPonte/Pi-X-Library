#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Exceptions
namespace pix::exceptions
{
	constexpr const char
		null_dim[] = "Null dimension",
		null_ptr[] = "Null pointer",
		bad_alloc[] = "Bad memory allocation",
		underflow[] = "Numeric underflow",
		overflow[] = "Numeric overflow",
		bad_range[] = "Bad numeric range",
		div_zero[] = "Division by zero",
		inv_arg[] = "Invalid argument";
}

#endif // _EXCEPTIONS_HPP_
