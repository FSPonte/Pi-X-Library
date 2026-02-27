#ifndef _MEMORY_TPP_
#define _MEMORY_TPP_

// Dependencies
#include <exception.hpp>

namespace pix::memory
{
	template <typename type_t>
	void realloc(type_t* buffer, const unsigned long size) noexcept(false)
	{
		if (buffer != nullptr)
			delete[] buffer;
		
		buffer = new type_t[size];
	}

	template <typename type_t>
	void extend(type_t* buffer, const unsigned long size, const unsigned long new_size) noexcept(false)
	{
		if (buffer == nullptr)
			throw pix::exception::null_ptr();

		type_t* temp = new type_t[size];
		memcpy(buffer, temp, size * sizeof(type_t));
		realloc(buffer, new_size);
		memcpy(temp, buffer, size * sizeof(type_t));
	}
}

#endif // _MEMORY_TPP_
