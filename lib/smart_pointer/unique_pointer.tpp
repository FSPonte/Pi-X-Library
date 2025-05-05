#ifndef _UNIQUE_POINTER_TPP_
#define _UNIQUE_POINTER_TPP_

namespace pix::smart_pointer
{
	template <typename type_t>
	unique_pointer<type_t>::unique_pointer(void)
	{
		this->_ptr = new type_t();
	}

	template <typename type_t>
	unique_pointer<type_t>::unique_pointer(const type_t VALUE) : unique_pointer<type_t>()
	{
		*this->_ptr = VALUE;
	}

	template <typename type_t>
	unique_pointer<type_t>::~unique_pointer(void)
	{
		delete this->_ptr;
	}

	template <typename type_t>
	type_t& unique_pointer<type_t>::operator * (void)
	{
		return *this->_ptr;
	}

	template <typename type_t>
	void unique_pointer<type_t>::operator << (unique_pointer<type_t>& u_ptr)
	{
		delete this->_ptr;
		this->_ptr = u_ptr._ptr;

		u_ptr._ptr = new type_t();
	}
}

#endif // _UNIQUE_POINTER_TPP_
