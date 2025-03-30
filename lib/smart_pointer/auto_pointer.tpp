#ifndef _AUTO_POINTER_TPP_
#define _AUTO_POINTER_TPP_

namespace pix::smart_pointer
{
	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(void)
	{
		this->_ptr = new type_t();
	}

	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(const type_t value) : auto_pointer<type_t>()
	{
		*this->_ptr = value;
	}

	template <typename type_t>
	auto_pointer<type_t>::~auto_pointer(void)
	{
		delete this->_ptr;
	}

	template <typename type_t>
	type_t& auto_pointer<type_t>::operator * (void)
	{
		return *this->_ptr;
	}
}

#endif // _AUTO_POINTER_TPP_
