#ifndef _DYN_ARRAY_HPP_
#define _DYN_ARRAY_HPP_

namespace pix::adt
{
	/**
	 * @brief Dynamic array
	 * @tparam type_t Data type
	*/
	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE = 1000>
	class dyn_array
	{
	private:

		type_t _data[BLOCK_ALLOC_SIZE];
		unsigned long _index;
		dyn_array<type_t, BLOCK_ALLOC_SIZE>* _next;

	public:

		/**
		 * @brief Constructor
		*/
		dyn_array(void);

		/**
		 * @brief Destructor
		*/
		~dyn_array(void);

		/**
		 * @brief Add a element
		 * @param ele Element
		*/
		void push_back(type_t);

		/**
		 * @brief Get a element
		 * @param ind Index
		 * @return Reference to element
		 * @throw Index is out of bounds
		*/
		type_t& operator [] (unsigned long) noexcept(false);

		/**
		 * @brief Get size
		 * @return Number of elements
		*/
		const unsigned long size(void) const;
	};
}

// Template file
#include "dyn_array.tpp"

#endif // _DYN_ARRAY_HPP_
