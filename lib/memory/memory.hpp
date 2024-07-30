#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

namespace pix::memory
{
    struct mpart
    {
        void* addr; // Memory address
        unsigned long size; // Number of bytes
    };

    template <unsigned long MAX_SIZE>
    class mmap
    {
    private:

        mpart _part[MAX_SIZE]; // Memory partitions
        unsigned long _size; // Number of partitions

    public:

        /**
         * @brief Constructor
        */
        mmap(void);

        /**
         * @brief Add a partition
         * @param part Memory partition
         * @throw Memory map is full
        */
        void add(mpart&&) noexcept(false);

        /**
         * @brief Remove a partition
         * @param ind Index
         * @throw Index is out of bounds
        */
        void rm(unsigned long) noexcept(false);

        /**
         * @brief Get a partition
         * @param ind Index
         * @return Memory partition
         * @throw Index is out of bounds
        */
        mpart operator [] (unsigned long) noexcept(false);

        /**
         * @brief Get size
         * @return Number of partitions
        */
        const unsigned long size(void) const;
    };
}

// Implementation file
#include "mmap.ipp"

#endif // _MEMORY_HPP_