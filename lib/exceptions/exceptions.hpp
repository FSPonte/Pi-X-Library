#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

// Dependencies
#include <sys_vars.hpp>

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
		null_ptr, // Null pointer

		other // Other exception
	};

	/**
	 * @brief Exception
	 * @tparam excep Type of exception
	*/
	template <excep_t excep_type>
	class exception
	{
	private:

		char _msg[D_BUFFER_SIZE];

	public:

		/**
		 * @brief Constructor
		 * @param msg Message
		*/
		explicit exception(const char[]);

		/**
		 * @brief Get message
		 * @return Message
		*/
		const char* msg(void) const;
	};
}

// Template file
#include "exceptions.tpp"

#endif // _EXCEPTIONS_HPP_
