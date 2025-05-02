#ifndef _STRING_TPP_
#define _STRING_TPP_

// Dependencies
#include <asserts.hpp>

namespace pix::adt
{
	template <unsigned long MAX_LENGTH>
	string<MAX_LENGTH>::string(void)
	{
		assert_not_nulldim(MAX_LENGTH);

		this->_data[0] = '\0';
		this->_length = 0;
	}

	template <unsigned long MAX_LENGTH>
	string<MAX_LENGTH>::string(const char c_str[]) noexcept(false) : string<MAX_LENGTH>::string()
	{
		*this = c_str;
	}

	template <unsigned long MAX_LENGTH>
	string<MAX_LENGTH>::string(const string<MAX_LENGTH>& str) noexcept(false)
	{
		*this = str.data();
	}

	template <unsigned long MAX_LENGTH>
	const char* string<MAX_LENGTH>::data(void) const
	{
		return this->_data;
	}

	template <unsigned long MAX_LENGTH>
	char string<MAX_LENGTH>::operator [] (const unsigned long INDEX) noexcept(false)
	{
		if (INDEX >= this->_length) throw "Index is out of bounds";

		return this->_data[INDEX];
	}

	template <unsigned long MAX_LENGTH>
	unsigned long string<MAX_LENGTH>::length(void) const
	{
		return this->_length;
	}

	template <unsigned long MAX_LENGTH>
	constexpr unsigned long string<MAX_LENGTH>::max_length(void) const
	{
		return MAX_LENGTH;
	}

	template <unsigned long MAX_LENGTH>
	void string<MAX_LENGTH>::operator = (const char c_str[]) noexcept(false)
	{
		if (c_str == nullptr) throw "Pointer to C styled string is null";

		for (this->_length = 0; this->_length < MAX_LENGTH; ++this->_length)
		{
			this->_data[this->_length] = c_str[this->_length];

			if (c_str[this->_length] == '\0')
				break;
		}

		++this->_length;
	}

	template <unsigned long MAX_LENGTH>
	void string<MAX_LENGTH>::operator = (const string<MAX_LENGTH>& str) noexcept(false)
	{
		*this = str.data();
	}

	template <unsigned long MAX_LENGTH>
	void string<MAX_LENGTH>::operator += (const char c_str[]) noexcept(false)
	{
		if (c_str == nullptr) throw "Pointer to C styled string is null";

		--this->_length;

		for (unsigned long i = 0; this->_length < MAX_LENGTH; ++i)
		{
			this->_data[this->_length++] = c_str[i];

			if (c_str[i] == '\0')
				break;
		}
	}

	template <unsigned long MAX_LENGTH>
	void string<MAX_LENGTH>::operator += (const string<MAX_LENGTH>& str) noexcept(false)
	{
		*this += str.data();
	}

	template <unsigned long MAX_LENGTH>
	bool string<MAX_LENGTH>::operator == (const char c_str[]) const noexcept(false)
	{
		if (c_str == nullptr) throw "Pointer to C styled string is null";

		for (unsigned long i = 0; i < this->_length; ++i)
		{
			if (this->_data[i] != c_str[i])
				return false;
		}

		return true;
	}

	template <unsigned long MAX_LENGTH>
	bool string<MAX_LENGTH>::operator == (const string<MAX_LENGTH>& str) const noexcept(false)
	{
		return *this == str.data();
	}

	template <unsigned long MAX_LENGTH>
	bool string<MAX_LENGTH>::operator != (const char c_str[]) const noexcept(false)
	{
		return !(*this == c_str);
	}

	template <unsigned long MAX_LENGTH>
	bool string<MAX_LENGTH>::operator != (const string<MAX_LENGTH>& str) const noexcept(false)
	{
		return !(*this == str.data());
	}

	template <unsigned long MAX_LENGTH>
	string<MAX_LENGTH>::operator const char*() const
	{
		return this->_data;
	}
}

#endif // _STRING_TPP_
