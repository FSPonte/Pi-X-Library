#ifndef _STRING_IPP_
#define _STRING_IPP_

namespace pix::adt
{
    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::string(void)
    {
        static_assert
        (
            BUFFER_SIZE != 0,
            "String object cannot have a maximum of zero characters"
        );

        this->_buffer[0] = '\0';
        this->_length = 0;
    }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const char c_str[]) noexcept(false) : string<BUFFER_SIZE>()
    {
        if (c_str == nullptr)
            throw "Pointer to array is null";

        *this = c_str;
    }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const char c_str[], const unsigned long length) noexcept(false) : string<BUFFER_SIZE>()
    {
        if (c_str == nullptr)
            throw "Pointer to array is null";
        
        if (length == 0)
            throw "Length is null";

        for (this->_length; this->_length < BUFFER_SIZE - 1 && this->_length < length && c_str[this->_length] != '\0'; ++this->_length)
            this->_buffer[this->_length] = c_str[this->_length];

        this->_buffer[this->_length] = '\0';
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const string<_BUFFER_SIZE>& str)
    { *this = str; }

    template <unsigned long BUFFER_SIZE>
    char& string<BUFFER_SIZE>::operator [] (const unsigned long index) noexcept(false)
    {
        if (index >= BUFFER_SIZE)
            throw "Index is out of bounds";

        return this->_buffer[index];
    }

    template <unsigned long BUFFER_SIZE>
    const char* string<BUFFER_SIZE>::buffer(void) const
    { return this->_buffer; }

    template <unsigned long BUFFER_SIZE>
    const unsigned long string<BUFFER_SIZE>::length(void) const
    { return this->_length; }

    template <unsigned long BUFFER_SIZE>
    constexpr const unsigned long string<BUFFER_SIZE>::buffer_size(void) const
    { return BUFFER_SIZE; }

    template <unsigned long BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator = (const char c_str[]) noexcept(false)
    {
        if (c_str == nullptr)
            throw "Pointer to array is null";

        for (this->_length = 0; this->_length < BUFFER_SIZE - 1; ++this->_length)
        {
            this->_buffer[this->_length] = c_str[this->_length];

            if (c_str[this->_length] == '\0')
                break;
        }
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator = (string<_BUFFER_SIZE>& str)
    { *this = static_cast<const char*>(str); }

    template <unsigned long BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator == (const char c_str[]) const noexcept(false)
    {
        if (c_str == nullptr)
            throw "Pointer to array is null";

        for (unsigned long i = 0; i < this->_length; ++i)
        {
            if (this->_buffer[i] != c_str[i])
                return false;
        }

        return true;
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator == (const string<_BUFFER_SIZE>& str) const
    {
        if (this->_length != str.length())
            return false;
        
        return *this == static_cast<const char*>(str);
    }

    template <unsigned long BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator != (const char c_str[]) const noexcept(false)
    { return !(*this == c_str); }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator != (const string<_BUFFER_SIZE>& str) const
    { return !(*this == static_cast<const char*>(str)); }

    template <unsigned long BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator += (const char c_str[]) noexcept(false)
    {
        if (c_str == nullptr)
            throw "Pointer to array is null";

        for (unsigned long i = 0; this->_length < BUFFER_SIZE - 1; ++i)
        {
            this->_buffer[this->_length++] = c_str[i];

            if (c_str[i] == '\0')
                break;
        }
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator += (const string<_BUFFER_SIZE>& str)
    { *this += static_cast<const char*>(str); }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::operator char*() const
    { return this->_buffer; }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::operator const char*() const
    { return this->_buffer; }
}

#endif // _STRING_IPP_