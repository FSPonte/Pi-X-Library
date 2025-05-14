#ifndef _DYN_ARRAY_TPP_
#define _DYN_ARRAY_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	dyn_array<type_t, BLOCK_ALLOC_SIZE>::dyn_array(void)
	{
		assert_not_nulldim(BLOCK_ALLOC_SIZE);
		
		this->_index = 0;
		this->_next = nullptr;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	dyn_array<type_t, BLOCK_ALLOC_SIZE>::~dyn_array(void)
	{
		delete this->_next;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	void dyn_array<type_t, BLOCK_ALLOC_SIZE>::push_back(const type_t ELEMENT)
	{
		if (this->_index < BLOCK_ALLOC_SIZE)
		{
			this->_data[this->_index] = ELEMENT;
			++this->_index;

			return;
		}

		if (this->_next == nullptr)
			this->_next = new dyn_array<type_t, BLOCK_ALLOC_SIZE>;

		this->_next->push_back(ELEMENT);
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	type_t dyn_array<type_t, BLOCK_ALLOC_SIZE>::pop(const unsigned long INDEX) noexcept(false)
	{
		if (INDEX / BLOCK_ALLOC_SIZE != 0)
		{
			if (this->_next == nullptr) throw "Index is out of bounds";

			return this->_next->pop(INDEX - BLOCK_ALLOC_SIZE);
		}

		if (INDEX >= this->_index) throw "Index is out of bounds";

		const type_t RET = this->_data[INDEX]; // Return value

		for (unsigned long i = INDEX; i < this->_index - 1; ++i)
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

		return RET;
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	type_t& dyn_array<type_t, BLOCK_ALLOC_SIZE>::operator [] (const unsigned long INDEX) noexcept(false)
	{
		if (INDEX < this->_index)
			return this->_data[INDEX];

		if (this->_index != BLOCK_ALLOC_SIZE) throw "Index is out of bounds";
		
		return (*this->_next)[INDEX - BLOCK_ALLOC_SIZE];
	}

	template <typename type_t, unsigned long BLOCK_ALLOC_SIZE>
	unsigned long dyn_array<type_t, BLOCK_ALLOC_SIZE>::size(void) const
	{
		if (this->_next == nullptr)
			return this->_index;

		return BLOCK_ALLOC_SIZE + this->_next->size();
	}
}

#endif // _DYN_ARRAY_TPP_
