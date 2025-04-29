#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

namespace pix::adt
{
	/**
	 * @brief Deque
	 * @tparam type_t Data type
	 * @tparam MAX_SIZE Maximum number of elements
	*/
	template <typename type_t, unsigned long MAX_SIZE>
	class deque
	{
	private:

		type_t _data[MAX_SIZE];
		unsigned long _index;

	public:

		/**
		 * @brief Constructor
		*/
		deque(void);

		/**
		 * @brief Queue up a element in the back
		 * @param ele Element
		 * @return True if the element was added
		*/
		bool push_back(const type_t&);

		/**
		 * @brief Unqueue the back element
		 * @return Eliminated element
		*/
		const type_t& pop_back(void);

		/**
		 * @brief Queue up a element in the front
		 * @param ele Element
		 * @return True if the element was added
		*/
		bool push_front(const type_t&);

		/**
		 * @brief Unqueue the front element
		 * @return Eliminated element
		*/
		const type_t& pop_front(void);

		/**
		 * @brief Back element
		 * @return See the back element
		*/
		const type_t& back(void) const;

		/**
		 * @brief Front element
		 * @return See the front element
		*/
		const type_t& front(void) const;

		/**
		 * @brief Size of queue
		 * @return Number of elements
		*/
		unsigned long size(void) const;

		/**
		 * @brief Maximum size
		 * @return Maximum number of elements
		*/
		constexpr unsigned long max_size(void) const;

		/**
		 * @brief Is empty
		 * @return true if deque is empty
		*/
		bool is_empty(void) const;

		/**
		 * @brief Is Full
		 * @return true if deque is full
		*/
		bool is_full(void) const;
	};
}

// Template file
#include "deque.tpp"

#endif // _DEQUE_HPP_
