#ifndef _DEQUE_TPP_
#define _DEQUE_TPP_

// Dependencies
#include <asserts.hpp>

namespace pix::adt
{
	template <typename type_t, unsigned long MAX_SIZE>
	deque<type_t, MAX_SIZE>::deque(void)
	{
		assert_not_nulldim(MAX_SIZE);

		this->_data[0] = type_t();
		this->_index = 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool deque<type_t, MAX_SIZE>::push_back(const type_t& ELEMENT)
	{
		if (this->_index == MAX_SIZE)
			return false;

		this->_data[this->_index++] = ELEMENT;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& deque<type_t, MAX_SIZE>::pop_back(void)
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[--this->_index];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool deque<type_t, MAX_SIZE>::push_front(const type_t& ELEMENT)
	{
		if (this->_index == MAX_SIZE)
			return false;

		for (unsigned long i = 0; i < this->_index; ++i)
			this->_data[i + 1] = this->_data[i];

		++this->_index;
		this->_data[0] = ELEMENT;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& deque<type_t, MAX_SIZE>::pop_front(void)
	{
		if (this->_index == 0)
			return type_t();

		const type_t RET = this->_data[0]; // Return value
		--this->_index;

		for (unsigned long i = 0; i < this->_index; ++i)
			this->_data[i] = this->_data[i + 1];

		return RET;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& deque<type_t, MAX_SIZE>::back(void) const
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[this->_index - 1];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& deque<type_t, MAX_SIZE>::front(void) const
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[0];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	unsigned long deque<type_t, MAX_SIZE>::size(void) const
	{
		return this->_index;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	constexpr unsigned long deque<type_t, MAX_SIZE>::max_size(void) const
	{
		return MAX_SIZE;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool deque<type_t, MAX_SIZE>::is_empty(void) const
	{
		return (this->_index == 0);
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool deque<type_t, MAX_SIZE>::is_full(void) const
	{
		return (this->_index == MAX_SIZE);
	}
}

#endif // _DEQUE_TPP_
