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

        char arr[BUFFER_SIZE + 1];
        unsigned long len;

    public:

        /**
         * @brief Default constructor
        */
        string(void);

        /**
         * @brief Parameterized constructor
         * @param c_str C styled string
        */
        string(const char*);

        /**
         * @brief Parameterized constructor
         * @param c_str C styled string
         * @param len Number of characters to copy
        */
        string(const char*, unsigned long);

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
         * @return Character
         * @note Index parameter is congruent to the buffer
        */
        char operator [] (unsigned long) const;

        /**
         * @brief Get buffer
         * @return Pointer to C styled string
        */
        const char* buffer(void) const;

        /**
         * @brief Length of string
         * @return Number of characters
         * @note Doesn't include the end byte
        */
        const unsigned long length(void) const;

        /**
         * @brief Buffer of string
         * @return Number of characters
         * @note Doesn't include the end byte
        */
        constexpr const unsigned long buffer_size(void) const;

        /**
         * @brief Copy operator
         * @param c_str C styled string
        */
        void operator = (const char*);

        /**
         * @brief Copy operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
        */
        template <unsigned long _BUFFER_SIZE>
        void operator = (const string<_BUFFER_SIZE>&);

        /**
         * @brief Comparison operator
         * @param c_str C styled string
         * @return true if strings are equal
        */
        const bool operator == (const char*) const;

        /**
         * @brief Comparison operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
         * @return true if strings are equal
        */
        template <unsigned long _BUFFER_SIZE>
        const bool operator == (const string<_BUFFER_SIZE>&) const;

        /**
         * @brief Comparison operator
         * @param c_str C styled string
         * @return true if strings are different
        */
        const bool operator != (const char*) const;

        /**
         * @brief Comparison operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
         * @return true if strings are different
        */
        template <unsigned long _BUFFER_SIZE>
        const bool operator != (const string<_BUFFER_SIZE>&) const;

        /**
         * @brief Addition assignment operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param c_str C styled string
        */
        template <unsigned long _BUFFER_SIZE>
        void operator += (const char*);

        /**
         * @brief Copy operator
         * @tparam _BUFFER_SIZE Maximum number of characters
         * @param str String
        */
        template <unsigned long _BUFFER_SIZE>
        void operator += (const string<_BUFFER_SIZE>&);

        /**
         * @brief Type casting
         * @return C styled string
        */
        operator char*();

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