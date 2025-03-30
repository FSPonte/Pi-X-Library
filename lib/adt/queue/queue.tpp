#ifndef _QUEUE_TPP_
#define _QUEUE_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long MAX_SIZE>
	queue<type_t, MAX_SIZE>::queue(void)
	{
		static_assert
		(
			MAX_SIZE != 0,
			"Queue object cannot have a maximum of zero elements"
		);

		this->_data[0] = type_t();
		this->_index = 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const bool queue<type_t, MAX_SIZE>::queue_up(const type_t& element)
	{
		if (this->_index == MAX_SIZE)
			return false;

		this->_data[this->_index++] = element;

		return true;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const type_t& queue<type_t, MAX_SIZE>::unqueue(void)
	{
		if (this->_index == 0)
			return type_t();

		type_t temp = this->_data[0];
		--this->_index;

		for (unsigned long i = 0; i < this->_index; ++i)
			this->_data[i] = this->_data[i + 1];

		return temp;
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
	const unsigned long queue<type_t, MAX_SIZE>::size(void) const
	{
		return this->_index;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	constexpr const unsigned long queue<type_t, MAX_SIZE>::max_size(void) const
	{
		return MAX_SIZE;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const bool queue<type_t, MAX_SIZE>::is_empty(void) const
	{
		return this->_index == 0;
	}

	template <typename type_t, unsigned long MAX_SIZE>
	const bool queue<type_t, MAX_SIZE>::is_full(void) const
	{
		return this->_index == MAX_SIZE;
	}
}

#endif // _QUEUE_TPP_
