#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

// Memory management
namespace pix::memory
{
	/**
	 * @brief Copy memory
	 * @param src Source
	 * @param dst Destination
	 * @param size Number of bytes
	 * @throw Pointer to source memory is null
	 * @throw Pointer to destination memory is null
	 * @throw Size is null
	*/
	void* memcpy(const void*, void*, unsigned long) noexcept(false);

	/**
	 * @brief Memory partition
	*/
	struct mpart
	{
		void* _addr; // Memory address
		unsigned long _size; // Number of bytes
	};

	/**
	 * @brief Memory map
	 * @tparam MAX_SIZE Maximum number of partitions
	*/
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
		unsigned long size(void) const;
	};
}

// Template file
#include "memory.tpp"
#include "mmap.tpp"

#endif // _MEMORY_HPP_
