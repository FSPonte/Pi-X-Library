#ifndef _STRING_HPP_
#define _STRING_HPP_

// Dependencies
#include <sys_vars.hpp>

namespace pix::adt
{
    /**
     * @brief String
     * @tparam BUFFER_SIZE Maximum number of characters
    */
    template <unsigned long BUFFER_SIZE = D_BUFFER_SIZE>
    class string
    {
    private:

        char _buffer[BUFFER_SIZE];
        unsigned long _length;

    public:

        /**
         * @brief Default constructor
        */
        string(void);

        /**
         * @brief Parameterized constructor
         * @param c_str C styled string
         * @throw Pointer to array is null
        */
        string(const char[]);

        /**
         * @brief Parameterized constructor
         * @param c_str C styled string
         * @param len Number of characters to copy
         * @throw Pointer to array is null
         * @throw Length is null
        */
        string(const char[], unsigned long);

        /**
         * @brief Copy constructor
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
        */
        template <unsigned long _BUFFER_SIZE>
        string(const string<_BUFFER_SIZE>&);

        /**
         * @brief Get operator
         * @param ind Index
         * @return Reference to character
         * @throw Index is out of bounds
        */
        char& operator [] (unsigned long);

        /**
         * @brief Get buffer
         * @return C styled string
        */
        const char* buffer(void) const;

        /**
         * @brief Length of string
         * @return Number of characters
        */
        const unsigned long length(void) const;

        /**
         * @brief Buffer of string
         * @return Number of characters
        */
        constexpr const unsigned long buffer_size(void) const;

        /**
         * @brief Copy operator
         * @param c_str C styled string
         * @throw Pointer to array is null
        */
        void operator = (const char[]) noexcept(false);

        /**
         * @brief Copy operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
        */
        template <unsigned long _BUFFER_SIZE>
        void operator = (string<_BUFFER_SIZE>&);

        /**
         * @brief Equality operator
         * @param c_str C styled string
         * @return True if strings are equal
         * @throw Pointer to array is null
        */
        const bool operator == (const char[]) const;

        /**
         * @brief Equality operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
         * @return True if strings are equal
        */
        template <unsigned long _BUFFER_SIZE>
        const bool operator == (const string<_BUFFER_SIZE>&) const;

        /**
         * @brief Inequality operator
         * @param c_str C styled string
         * @return True if strings are different
         * @throw Pointer to array is null
        */
        const bool operator != (const char[]) const;

        /**
         * @brief Inequality operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
         * @return True if strings are different
        */
        template <unsigned long _BUFFER_SIZE>
        const bool operator != (const string<_BUFFER_SIZE>&) const;

        /**
         * @brief Append operator
         * @param c_str C styled string
         * @throw Pointer to array is null
       */
        void operator += (const char[]);

        /**
         * @brief Append operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
        */
        template <unsigned long _BUFFER_SIZE>
        void operator += (const string<_BUFFER_SIZE>&);

        /**
         * @brief Type casting
         * @return Array of characters
        */
        operator char*() const;

        /**
         * @brief Type casting
         * @return C styled string
        */
        operator const char*() const;
    };
}

// Implementation file
#include "string.ipp"

#endif // _STRING_HPP_