#ifndef _MEMORY_MAP_IPP_
#define _MEMORY_MAP_IPP_

// Dependencies
#include <c_array.hpp>

namespace pix::memory
{
    template <unsigned long MAX_SIZE>
    mmap<MAX_SIZE>::mmap(void)
    {
        for (unsigned long i = 0; i < MAX_SIZE; ++i)
            this->_part[i] = mpart{nullptr, 0};

        this->_size = 0;
    }

    template <unsigned long MAX_SIZE>
    void mmap<MAX_SIZE>::add(mpart&& part) noexcept(false)
    {
        if (this->_size == MAX_SIZE)
            throw "Memory map is full";

        this->_part[this->_size] = part;
        ++this->_size;
    }

    template <unsigned long MAX_SIZE>
    void mmap<MAX_SIZE>::rm(const unsigned long index) noexcept(false)
    {
        if (index >= this->_size)
            throw "Index is out of bounds";

        pix::c_array::left_shift(this->_part[index], this->_size - index);
        --this->_size;
    }

    template <unsigned long MAX_SIZE>
    mpart mmap<MAX_SIZE>::operator [] (const unsigned long index) noexcept(false)
    {
        if (index >= this->_size)
            throw "Index is out of bounds";

        return this->_part[index];
    }

    template <unsigned long MAX_SIZE>
    const unsigned long mmap<MAX_SIZE>::size(void) const
    { return this->_size; }
}

#endif // _MEMORY_MAP_IPP_