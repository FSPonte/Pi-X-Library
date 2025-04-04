#ifndef _DYN_ARRAY_TPP_
#define _DYN_ARRAY_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	dyn_array<type_t, BLOCK_ALLOC_SIZE>::dyn_array(void)
	{
		this->_index = 0;
		this->_next = nullptr;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	dyn_array<type_t, BLOCK_ALLOC_SIZE>::~dyn_array(void)
	{
		delete this->_next;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	void dyn_array<type_t, BLOCK_ALLOC_SIZE>::push_back(const type_t element)
	{
		if (this->_index < BLOCK_ALLOC_SIZE)
		{
			this->_data[this->_index] = element;
			++this->_index;

			return;
		}

		if (this->_next == nullptr)
			this->_next = new dyn_array<type_t, BLOCK_ALLOC_SIZE>;

		this->_next->push_back(element);
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	type_t dyn_array<type_t, BLOCK_ALLOC_SIZE>::pop(const unsigned long index) noexcept(false)
	{
		if (index / BLOCK_ALLOC_SIZE != 0)
		{
			if (this->_next == nullptr)
				throw "Index is out of bounds";

			return this->_next->pop(index - BLOCK_ALLOC_SIZE);
		}

		if (index >= this->_index)
			throw "Index is out of bounds";

		const type_t ret = this->_data[index]; // Return value

		for (unsigned long i = index; i < this->_index - 1; ++i)
			this->_data[i] = this->_data[i + 1];

		if (this->_next == nullptr)
			--this->_index;
		else
		{
			this->_data[BLOCK_ALLOC_SIZE - 1] = this->_next->pop(0);

			if (this->_next->_index == 0)
			{
				delete this->_next;
				this->_next = nullptr;
			}
		}

		return ret;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	type_t& dyn_array<type_t, BLOCK_ALLOC_SIZE>::operator [] (const unsigned long index) noexcept(false)
	{
		if (index < this->_index)
			return this->_data[index];

		if (this->_index != BLOCK_ALLOC_SIZE)
			throw "Index is out of bounds";
		
		return (*this->_next)[index - BLOCK_ALLOC_SIZE];
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	const unsigned long dyn_array<type_t, BLOCK_ALLOC_SIZE>::size(void) const
	{
		if (this->_next == nullptr)
			return this->_index;

		return BLOCK_ALLOC_SIZE + this->_next->size();
	}
}

#endif // _DYN_ARRAY_TPP_
