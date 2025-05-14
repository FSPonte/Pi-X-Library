#ifndef _MMAP_TPP_
#define _MMAP_TPP_

namespace pix::memory
{
	template <unsigned long MAX_SIZE>
	mmap<MAX_SIZE>::mmap(void)
	{
		assert_not_nulldim(MAX_SIZE);
		
		this->_size = 0;
	}

	template <unsigned long MAX_SIZE>
	void mmap<MAX_SIZE>::add(mpart&& part) noexcept(false)
	{
		if (this->_size == MAX_SIZE) throw "Memory map is full";

		this->_part[this->_size] = part;
		++this->_size;
	}

	template <unsigned long MAX_SIZE>
	void mmap<MAX_SIZE>::rm(const unsigned long INDEX) noexcept(false)
	{
		if (INDEX >= this->_size) throw "Index is out of bounds";

		pix::c_array::left_shift(this->_part[INDEX], this->_size - INDEX);
		--this->_size;
	}

	template <unsigned long MAX_SIZE>
	mpart mmap<MAX_SIZE>::operator [] (const unsigned long INDEX) noexcept(false)
	{
		if (INDEX >= this->_size) throw "Index is out of bounds";

		return this->_part[INDEX];
	}

	template <unsigned long MAX_SIZE>
	unsigned long mmap<MAX_SIZE>::size(void) const
	{
		return this->_size;
	}
}

#endif // _MMAP_TPP_
