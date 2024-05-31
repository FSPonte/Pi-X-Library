#ifndef _ARRAY_IPP_
#define _ARRAY_IPP_

using namespace pix::adt;

template <typename type_t, size_t DIM>
array<type_t, DIM>::array(void)
{
    static_assert
    (
        DIM != 0,
        "Array object cannot have zero elements"
    );

    for (size_t i = 0; i < DIM; ++i)
        this->data[i] = type_t();
}

template <typename type_t, size_t DIM>
array<type_t, DIM>::array(const type_t* arr) : array<type_t, DIM>()
{
    if (arr == nullptr)
        return;

    for (size_t i = 0; i < DIM; ++i)
        this->data[i] = arr[i];
}

template <typename type_t, size_t DIM>
template <typename _type_t, size_t _DIM>
array<type_t, DIM>::array(const array<_type_t, _DIM>& arr) : array<type_t, DIM>()
{
    for (size_t i = 0; i < DIM && i < _DIM; ++i)
        this->data[i] = arr[i];
}

template <typename type_t, size_t DIM>
type_t& array<type_t, DIM>::operator [] (const size_t ind)
{ return this->data[ind % DIM]; }

template <typename type_t, size_t DIM>
constexpr const size_t array<type_t, DIM>::dim() const
{ return DIM; }

#endif // _ARRAY_IPP_