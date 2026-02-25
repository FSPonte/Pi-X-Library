#ifndef _STRING_TPP_
#define _STRING_TPP_

namespace pix
{
	unsigned long strlen(const char str[]) noexcept(false)
	{
		if (str == nullptr)
			throw pix::exceptions::null_ptr;

		unsigned long length = 0;
		
		while (str[length++] != '\0');

		return length;
	}

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
			throw pix::exceptions::out_of_bounds;

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
			throw pix::exceptions::null_ptr;

		this->_length = strlen(str);
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
			throw pix::exceptions::null_ptr;

		--this->_length;
		const unsigned long length = strlen(str);
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
			throw pix::exceptions::null_ptr;

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

	template <typename type_t>
	pix::string to_string(type_t arg) noexcept(true)
	{
		pix::string ret = "";

		// Handle the zero case immediately
		if (arg == 0)
			return ret;

		bool isNegative = false;

		// Handle signed types if necessary
		if constexpr (is_number(type_t))
		{
			if (arg < 0)
			{
				isNegative = true;
				arg = -arg; 
			}
		}

		// Process digits from right to left
		while (arg > 0)
		{
			ret += static_cast<char>((arg % 10) + '0');
			arg /= 10;
		}

		if (isNegative)
			ret += '-';

		// Since we added digits backward (ones, tens, hundreds), reverse it
		ret.invert();

		return ret;
	}
}

#endif // _STRING_TPP_
