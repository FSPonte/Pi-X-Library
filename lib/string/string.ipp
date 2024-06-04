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

        this->arr[0] = '\0';
        this->arr[BUFFER_SIZE] = '\0';
        this->len = 0;
    }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const char* c_str) : string<BUFFER_SIZE>()
    {
        if (c_str == nullptr)
            return;

        for (this->len; this->len < BUFFER_SIZE && c_str[this->len] != '\0'; ++this->len)
            this->arr[this->len] = c_str[this->len];

        this->arr[this->len] = '\0';
    }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const char* c_str, const unsigned long len) : string<BUFFER_SIZE>()
    {
        if (c_str == nullptr || len == 0)
            return;

        for (this->len; this->len < BUFFER_SIZE && this->len < len && c_str[this->len] != '\0'; ++this->len)
            this->arr[this->len] = c_str[this->len];

        this->arr[this->len + 1] = '\0';
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    string<BUFFER_SIZE>::string(const string<_BUFFER_SIZE>& str)
    {
        for (unsigned long i = 0; i < BUFFER_SIZE && i < _BUFFER_SIZE; ++i)
            this->arr[i] = str.arr[i];

        this->len = str.len;
    }

    template <unsigned long BUFFER_SIZE>
    char string<BUFFER_SIZE>::operator [] (const unsigned long ind) const
    { return this->arr[ind % BUFFER_SIZE]; }

    template <unsigned long BUFFER_SIZE>
    const char* string<BUFFER_SIZE>::buffer(void) const
    { return this->arr; }

    template <unsigned long BUFFER_SIZE>
    const unsigned long string<BUFFER_SIZE>::length(void) const
    { return this->len; }

    template <unsigned long BUFFER_SIZE>
    constexpr const unsigned long string<BUFFER_SIZE>::buffer_size(void) const
    { return BUFFER_SIZE; }

    template <unsigned long BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator = (const char* c_str)
    {
        for (this->len = 0; this->len < BUFFER_SIZE && c_str[this->len] != '\0'; ++this->len)
            this->arr[this->len] = c_str[this->len];
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator = (const string<_BUFFER_SIZE>& str)
    {
        (str.length() < BUFFER_SIZE) ? this->len = str.length() : this->len = BUFFER_SIZE;

        for (unsigned long i = 0; i < this->len; ++i)
            this->arr[i] = str[i];
    }

    template <unsigned long BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator == (const char* c_str) const
    {
        if (c_str == nullptr)
            return false;

        for (unsigned long i = 0; i < BUFFER_SIZE && c_str[i] != '\0'; ++i)
        {
            if (this->arr[i] != c_str[i])
                return false;
        }

        return true;
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator == (const string<_BUFFER_SIZE>& str) const
    { return *this == static_cast<const char*>(str); }

    template <unsigned long BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator != (const char* c_str) const
    { return !(*this == c_str); }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    const bool string<BUFFER_SIZE>::operator != (const string<_BUFFER_SIZE>& str) const
    { return !(*this == static_cast<const char*>(str)); }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator += (const char* c_str)
    {
        for (unsigned long i = 0; this->len < BUFFER_SIZE && i < _BUFFER_SIZE && c_str[i] != '\0'; ++i)
            this->arr[this->len++] = c_str[i];
    }

    template <unsigned long BUFFER_SIZE>
    template <unsigned long _BUFFER_SIZE>
    void string<BUFFER_SIZE>::operator += (const string<_BUFFER_SIZE>& str)
    {
        unsigned long _len = str.length();

        for (unsigned long i = 0; this->len < BUFFER_SIZE && i < _BUFFER_SIZE; ++i)
            this->arr[this->len++] = str[i];
    }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::operator char*()
    { return this->arr; }

    template <unsigned long BUFFER_SIZE>
    string<BUFFER_SIZE>::operator const char*() const
    { return this->arr; }
}

#endif // _STRING_IPP_