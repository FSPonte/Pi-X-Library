#ifndef _STACK_TPP_
#define _STACK_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long MAX_SIZE>
	stack<type_t, MAX_SIZE>::stack(void)
	{
		static_assert
		(
			MAX_SIZE != 0,
			"Stack object cannot have a maximum of zero elements"
		);

		this->_arr[0] = type_t();
		this->_ind = 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const bool stack<type_t, MAX_SIZE>::add(const type_t& element)
	{
		if (this->_ind == MAX_SIZE)
			return false;

		this->_arr[this->_ind++] = element;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& stack<type_t, MAX_SIZE>::pop(void)
	{
		if (this->_ind == 0)
			return type_t();

		return this->_arr[--this->_ind];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& stack<type_t, MAX_SIZE>::top(void) const
	{
		if (this->_ind == 0)
			return type_t();

		return this->_arr[this->_ind - 1];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const unsigned long stack<type_t, MAX_SIZE>::size(void) const
	{ return this->_ind; }

	template <typename type_t, unsigned long MAX_SIZE>
	constexpr const unsigned long stack<type_t, MAX_SIZE>::max_size(void) const
	{ return MAX_SIZE; }

	template <typename type_t, unsigned long MAX_SIZE>
	const bool stack<type_t, MAX_SIZE>::is_empty(void) const
	{ return this->_ind == 0; }

	template <typename type_t, unsigned long MAX_SIZE>
	const bool stack<type_t, MAX_SIZE>::is_full(void) const
	{ return this->_ind == MAX_SIZE; }
}

#endif // _STACK_TPP_
