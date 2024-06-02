#ifndef _UNIQUE_POINTER_IPP_
#define _UNIQUE_POINTER_IPP_

using namespace pix::adt;

template <typename type_t>
unique_pointer<type_t>::unique_pointer(void)
{ this->ptr = new type_t(); }

template <typename type_t>
unique_pointer<type_t>::unique_pointer(const type_t val) : unique_pointer<type_t>()
{ *this->ptr = val; }

template <typename type_t>
unique_pointer<type_t>::~unique_pointer(void)
{ delete this->ptr; }

template <typename type_t>
type_t& unique_pointer<type_t>::operator * (void)
{ return *this->ptr; }

template <typename type_t>
type_t* unique_pointer<type_t>::operator -> (void)
{ return this->ptr; }

template <typename type_t>
type_t& unique_pointer<type_t>::operator [] (const size_t ind)
{ return *(this->ptr + ind); }

template <typename type_t>
void unique_pointer<type_t>::operator << (unique_pointer<type_t>& u_ptr)
{
    delete this->ptr;
    this->ptr = u_ptr.ptr;

    u_ptr.ptr = new type_t();
}

#endif // _UNIQUE_POINTER_IPP_