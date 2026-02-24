#ifndef _STRING_TPP_
#define _STRING_TPP_

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
	string<MAX_LENGTH>::string(const char str[]) noexcept(false) : string<MAX_LENGTH>::string()
	{
		*this = str;
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
	char string<MAX_LENGTH>::operator [] (const unsigned long index) noexcept(false)
	{
		if (index >= this->_length) throw pix::exceptions::out_of_bounds;

		return this->_data[index];
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
	void string<MAX_LENGTH>::operator = (const char str[]) noexcept(false)
	{
		if (str == nullptr) throw pix::exceptions::null_ptr;

		for (this->_length = 0; this->_length < MAX_LENGTH; ++this->_length)
		{
			this->_data[this->_length] = str[this->_length];

			if (str[this->_length] == '\0')
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
	void string<MAX_LENGTH>::operator += (const char str[]) noexcept(false)
	{
		if (str == nullptr) throw pix::exceptions::null_ptr;

		--this->_length;

		for (unsigned long i = 0; this->_length < MAX_LENGTH; ++i)
		{
			this->_data[this->_length++] = str[i];

			if (str[i] == '\0')
				break;
		}
	}

	template <unsigned long MAX_LENGTH>
	void string<MAX_LENGTH>::operator += (const string<MAX_LENGTH>& str) noexcept(false)
	{
		*this += str.data();
	}

	template <unsigned long MAX_LENGTH>
	bool string<MAX_LENGTH>::operator == (const char str[]) const noexcept(false)
	{
		if (str == nullptr) throw pix::exceptions::null_ptr;

		for (unsigned long i = 0; i < this->_length; ++i)
		{
			if (this->_data[i] != str[i])
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
	bool string<MAX_LENGTH>::operator != (const char str[]) const noexcept(false)
	{
		return !(*this == str);
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
