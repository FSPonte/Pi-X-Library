#ifndef _STACK_TPP_
#define _STACK_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long MAX_SIZE>
	stack<type_t, MAX_SIZE>::stack(void)
	{
		assert_not_nulldim(MAX_SIZE);

		this->_data[0] = type_t();
		this->_index = 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool stack<type_t, MAX_SIZE>::add(const type_t& element)
	{
		if (this->_index == MAX_SIZE)
			return false;

		this->_data[this->_index++] = element;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& stack<type_t, MAX_SIZE>::pop(void)
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[--this->_index];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& stack<type_t, MAX_SIZE>::top(void) const
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[this->_index - 1];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	unsigned long stack<type_t, MAX_SIZE>::size(void) const
	{
		return this->_index;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	constexpr unsigned long stack<type_t, MAX_SIZE>::max_size(void) const
	{
		return MAX_SIZE;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool stack<type_t, MAX_SIZE>::is_empty(void) const
	{
		return (this->_index == 0);
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool stack<type_t, MAX_SIZE>::is_full(void) const
	{
		return (this->_index == MAX_SIZE);
	}
}

#endif // _STACK_TPP_
