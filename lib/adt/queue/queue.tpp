#ifndef _QUEUE_TPP_
#define _QUEUE_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long MAX_SIZE>
	queue<type_t, MAX_SIZE>::queue(void)
	{
		assert_not_nulldim(MAX_SIZE);

		this->_data[0] = type_t();
		this->_index = 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool queue<type_t, MAX_SIZE>::queue_up(const type_t& ELEMENT)
	{
		if (this->_index == MAX_SIZE)
			return false;

		this->_data[this->_index++] = ELEMENT;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& queue<type_t, MAX_SIZE>::unqueue(void)
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
	const type_t& queue<type_t, MAX_SIZE>::last(void) const
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[this->_index - 1];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& queue<type_t, MAX_SIZE>::first(void) const
	{
		if (this->_index == 0)
			return type_t();

		return this->_data[0];
	}

	template <typename type_t, unsigned long MAX_SIZE>
	unsigned long queue<type_t, MAX_SIZE>::size(void) const
	{
		return this->_index;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	constexpr unsigned long queue<type_t, MAX_SIZE>::max_size(void) const
	{
		return MAX_SIZE;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool queue<type_t, MAX_SIZE>::is_empty(void) const
	{
		return (this->_index == 0);
	}

	template <typename type_t, unsigned long MAX_SIZE>
	bool queue<type_t, MAX_SIZE>::is_full(void) const
	{
		return (this->_index == MAX_SIZE);
	}
}

#endif // _QUEUE_TPP_