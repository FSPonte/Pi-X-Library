#ifndef _VECTOR_IPP_
#define _VECTOR_IPP_

// Dependencies
#include <type_info.hpp>

using namespace pix::adt;

template <typename type_t, size_t DIM>
vector<type_t, DIM>::vector(void)
{
    is_number_static_assert(type_t);

    static_assert
    (
        DIM != 0,
        "Array object cannot have zero elements"
    );

    for (size_t i = 0; i < DIM; ++i)
        this->arr[i] = type_t();
}

template <typename type_t, size_t DIM>
vector<type_t, DIM>::vector(const type_t arr[]) : vector<type_t, DIM>()
{
    if (arr == nullptr)
        return;

    for (size_t i = 0; i < DIM; ++i)
        this->arr[i] = arr[i];
}

template <typename type_t, size_t DIM>
template <typename _type_t, size_t _DIM>
vector<type_t, DIM>::vector(vector<_type_t, _DIM>& vec)
{ *this = vec; }

template <typename type_t, size_t DIM>
type_t& vector<type_t, DIM>::operator [] (const size_t ind)
{ return this->arr[ind % DIM]; }

template <typename type_t, size_t DIM>
constexpr const size_t vector<type_t, DIM>::dim(void) const
{ return DIM; }

template <typename type_t, size_t DIM>
template <typename _type_t, size_t _DIM>
void vector<type_t, DIM>::operator = (vector<_type_t, _DIM>& vec)
{
    for (size_t i = 0; i < DIM && i < _DIM; ++i)
        this->arr[i] = static_cast<type_t>(vec[i]);
}

template <typename type_t, size_t DIM>
template <typename _type_t, size_t _DIM>
const bool vector<type_t, DIM>::operator == (vector<_type_t, _DIM>& vec)
{ return false; }

template <typename type_t, size_t DIM>
const bool vector<type_t, DIM>::operator == (vector<type_t, DIM>& vec)
{
    for (size_t i = 0; i < DIM; ++i)
    {
        if (this->arr[i] != vec[i])
            return false;
    }

    return true;
}

template <typename type_t, size_t DIM>
template <typename _type_t, size_t _DIM>
const bool vector<type_t, DIM>::operator != (vector<_type_t, _DIM>& vec)
{ return true; }

template <typename type_t, size_t DIM>
const bool vector<type_t, DIM>::operator != (vector<type_t, DIM>& vec)
{ return !(*this == vec); }

template <typename type_t, size_t DIM>
template <typename _type_t>
vector<type_t, DIM> vector<type_t, DIM>::operator + (vector<_type_t, DIM>& vec) const
{
    type_t arr[DIM];

    for (size_t i = 0; i < DIM; ++i)
        arr[i] = this->arr[i] + static_cast<type_t>(vec[i]);

    return vector<type_t, DIM>(arr);
}

template <typename type_t, size_t DIM>
template <typename _type_t>
vector<type_t, DIM> vector<type_t, DIM>::operator - (vector<_type_t, DIM>& vec) const
{
    type_t arr[DIM];

    for (size_t i = 0; i < DIM; ++i)
        arr[i] = this->arr[i] - static_cast<type_t>(vec[i]);

    return vector<type_t, DIM>(arr);
}

template <typename type_t, size_t DIM>
template <typename _type_t>
vector<type_t, DIM> vector<type_t, DIM>::operator * (const _type_t scalar) const
{
    type_t arr[DIM];

    for (size_t i = 0; i < DIM; ++i)
        arr[i] = this->arr[i] * static_cast<type_t>(scalar);

    return vector<type_t, DIM>(arr);
}

template <typename type_t, size_t DIM>
template <typename _type_t>
vector<type_t, DIM> vector<type_t, DIM>::operator / (const _type_t scalar) const
{
    type_t arr[DIM];

    for (size_t i = 0; i < DIM; ++i)
        arr[i] = this->arr[i] / static_cast<type_t>(scalar);

    return vector<type_t, DIM>(arr);
}

template <typename type_t, size_t DIM>
template <typename _type_t>
type_t vector<type_t, DIM>::operator ^ (vector<_type_t, DIM>& vec) const
{
    type_t scalar = 0;

    for (size_t i = 0; i < DIM; ++i)
        scalar += this->arr[i] * static_cast<type_t>(vec[i]);

    return scalar;
}

template <typename type_t, size_t DIM>
template <typename _type_t>
vector<type_t, DIM> vector<type_t, DIM>::operator * (vector<_type_t, DIM>& vec) const
{
    type_t arr[DIM];

    for (size_t i = 0; i < DIM; ++i)
        arr[i] = this->arr[(i + 1) % DIM] * static_cast<type_t>(vec[(i + 2) % DIM]);

    return vector<type_t, DIM>(arr);
}

template <typename type_t, size_t DIM>
vector<type_t, DIM>::operator type_t() const
{
    type_t norm = 0;

    for (size_t i = 0; i < DIM; ++i)
        norm += this->arr[i];

    return norm;
}

#endif // _VECTOR_IPP_