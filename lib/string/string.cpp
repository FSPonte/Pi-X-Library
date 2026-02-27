// Header file
#include "string.hpp"

// Dependencies
#include <exception.hpp>
#include <c_array.hpp>
#include <memory.hpp>

namespace pix
{
	string::string(void)
	{
		this->_data = nullptr;
		this->_length = 0;
	}

	string::string(const char str[]) noexcept(false) : string::string()
	{
		*this = str;
	}

	string::string(const string& str) noexcept(false)
	{
		*this = str.data();
	}

	const char* string::data(void) const
	{
		return this->_data;
	}

	char string::operator [] (const unsigned long index) noexcept(false)
	{
		if (index >= this->_length)
			throw pix::exception::out_of_bounds();

		return this->_data[index];
	}

	unsigned long string::length(void) const
	{
		return this->_length;
	}

	void string::invert(void) noexcept(true)
	{
		--this->_length;
		char* buffer = new char[this->_length];

		for (unsigned long i = 0; i < this->_length - 1; ++i)
			buffer[i] = this->_data[this->_length - i];
	}

	void string::operator = (const char str[]) noexcept(false)
	{
		if (str == nullptr)
			throw pix::exception::null_ptr();

		this->_length = pix::c_array::strlen(str);
		pix::memory::realloc(this->_data, this->_length);

		for (unsigned long i = 0; i < this->_length; ++i)
			this->_data[i] = str[i];

		++this->_length;
	}

	void string::operator = (const string& str) noexcept(false)
	{
		*this = str.data();
	}

	void string::operator += (const char ch) noexcept(true)
	{
		pix::memory::extend(this->_data, this->_length, this->_length + 1);
		++this->_length;
		this->_data[this->_length] = ch;
	}

	void string::operator += (const char str[]) noexcept(false)
	{
		if (str == nullptr)
			throw pix::exception::null_ptr();

		--this->_length;
		const unsigned long length = pix::c_array::strlen(str);
		pix::memory::extend(this->_data, this->_length, this->_length + length);
		pix::memory::memcpy(str, this->_data + this->_length, length);
	}

	void string::operator += (const string& str) noexcept(false)
	{
		*this += str.data();
	}

	bool string::operator == (const char str[]) const noexcept(false)
	{
		if (str == nullptr)
			throw pix::exception::null_ptr();

		for (unsigned long i = 0; i < this->_length; ++i)
		{
			if (this->_data[i] != str[i])
				return false;
		}

		return true;
	}

	bool string::operator == (const string& str) const noexcept(false)
	{
		return *this == str.data();
	}

	bool string::operator != (const char str[]) const noexcept(false)
	{
		return !(*this == str);
	}

	bool string::operator != (const string& str) const noexcept(false)
	{
		return !(*this == str.data());
	}

	string::operator const char*() const
	{
		return this->_data;
	}
}
