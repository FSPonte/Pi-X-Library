#ifndef __AUTO_POINTER_TPP__
#define __AUTO_POINTER_TPP__

namespace pix::smart_pointer
{
	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(void) noexcept(true)
	{
		this->_ptr = new type_t();
	}

	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(const type_t value) noexcept(true) : auto_pointer<type_t>()
	{
		*this->_ptr = value;
	}

	template <typename type_t>
	auto_pointer<type_t>::~auto_pointer(void) noexcept(true)
	{
		delete this->_ptr;
	}

	template <typename type_t>
	type_t& auto_pointer<type_t>::operator * (void) noexcept(true)
	{
		return *this->_ptr;
	}
}

#endif // __AUTO_POINTER_TPP__
