#ifndef _LIST_HPP_
#define _LIST_HPP_

// Abstract data types
namespace pix::adt
{
	/**
	 * @brief List
	 * @tparam type_t Data type
	*/
	template <typename type_t>
	class list
	{
	private:

		node<type_t>* _head;
		unsigned long _size;

	public:

		/**
		 * @brief Constructor
		*/
		list(void);

		/**
		 * @brief Destructor
		*/
		~list(void);

		/**
		 * @brief Append a element
		 * @param ele Element
		*/
		void append(type_t);

		/**
		 * @brief Eliminate a element
		 * @param ind Index
		 * @return Eliminated element
		 * @throw Index is out of bounds
		*/
		type_t pop(unsigned long) noexcept(false);

		/**
		 * @brief Get a element
		 * @param ind Index
		 * @return Reference to element
		 * @throw Index is out of bounds
		*/
		type_t& operator [] (unsigned long) noexcept(false);

		/**
		 * @brief Size of list
		 * @return Number of elements
		*/
		unsigned long size(void) const;
	};
}

// Template file
#include "list.tpp"

#endif // _LIST_HPP_
