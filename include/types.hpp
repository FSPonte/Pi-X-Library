#ifndef _TYPES_HPP_
#define _TYPES_HPP_

namespace pix::types
{
    typedef unsigned char byte_t;
    typedef const char* c_str_t;
    typedef unsigned long int size_t;
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef short int16_t;
    typedef unsigned short uint16_t;
    typedef int int32_t;
    typedef unsigned int uint32_t;
    typedef long long int64_t;
    typedef unsigned long long uint64_t;
    typedef long double double_t;

    /**
     * @brief Function pointer to hashing function
     * @param key C styled string
     * @return Hash value
    */
    typedef unsigned long (*hash_func_ptr_t) (const char*);
}

#endif // _TYPES_HPP_