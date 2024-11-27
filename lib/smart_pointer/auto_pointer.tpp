#ifndef _AUTO_POINTER_TPP_
#define _AUTO_POINTER_TPP_

namespace pix::smart_pointer
{
	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(void)
	{ this->ptr = new type_t(); }

	template <typename type_t>
	auto_pointer<type_t>::auto_pointer(const type_t val) : auto_pointer<type_t>()
	{ *this->ptr = val; }

	template <typename type_t>
	auto_pointer<type_t>::~auto_pointer(void)
	{ delete this->ptr; }

	template <typename type_t>
	type_t& auto_pointer<type_t>::operator * (void)
	{ return *this->ptr; }
}

#endif // _AUTO_POINTER_TPP_
