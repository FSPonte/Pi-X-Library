#ifndef _UNIQUE_POINTER_TPP_
#define _UNIQUE_POINTER_TPP_

namespace pix::smart_pointer
{
	template <typename type_t>
	unique_pointer<type_t>::unique_pointer(void) noexcept(true)
	{
		this->_ptr = new type_t();
	}

	template <typename type_t>
	unique_pointer<type_t>::unique_pointer(const type_t value) noexcept(true) : unique_pointer<type_t>()
	{
		*this->_ptr = value;
	}

	template <typename type_t>
	unique_pointer<type_t>::~unique_pointer(void) noexcept(true)
	{
		delete this->_ptr;
	}

	template <typename type_t>
	type_t& unique_pointer<type_t>::operator * (void) noexcept(true)
	{
		return *this->_ptr;
	}

	template <typename type_t>
	void unique_pointer<type_t>::operator << (unique_pointer<type_t>& u_ptr) noexcept(true)
	{
		delete this->_ptr;
		this->_ptr = u_ptr._ptr;

		u_ptr._ptr = new type_t();
	}
}

#endif // _UNIQUE_POINTER_TPP_
