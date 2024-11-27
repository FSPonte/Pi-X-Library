#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

namespace pix::adt
{
	/**
	 * @brief Queue
	 * @tparam type_t Data type
	 * @tparam MAX_SIZE Maximum number of elements
	*/
	template <typename type_t, unsigned long MAX_SIZE>
	class queue
	{
	private:

		type_t _arr[MAX_SIZE];
		unsigned long _ind;

	public:

		/**
		 * @brief Constructor
		*/
		queue(void);

		/**
		 * @brief Queue up a element
		 * @param ele Element
		 * @return True if the element was added
		*/
		const bool queue_up(const type_t&);

		/**
		 * @brief Unqueue a element
		 * @return Eliminated element
		*/
		const type_t& unqueue(void);

		/**
		 * @brief Last element
		 * @return See the last element
		*/
		const type_t& last(void) const;

		/**
		 * @brief First element
		 * @return See the first element
		*/
		const type_t& first(void) const;

		/**
		 * @brief Size of queue
		 * @return Number of elements
		*/
		const unsigned long size(void) const;

		/**
		 * @brief Maximum size
		 * @return Maximum number of elements
		*/
		constexpr const unsigned long max_size(void) const;

		/**
		 * @brief Is empty
		 * @return True if queue is empty
		*/
		const bool is_empty(void) const;

		/**
		 * @brief Is Full
		 * @return True if queue is full
		*/
		const bool is_full(void) const;
	};
}

// Template file
#include "queue.tpp"

#endif // _QUEUE_HPP_
