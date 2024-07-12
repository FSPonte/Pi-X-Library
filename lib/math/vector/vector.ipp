#ifndef _VECTOR_IPP_
#define _VECTOR_IPP_

// Dependencies
#include <type_info.hpp>

namespace pix::math
{
    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM>::vector(void)
    {
        is_number_static_assert(type_t);

        static_assert
        (
            DIM != 0,
            "Array object cannot have zero elements"
        );
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM>::vector(const type_t arr[]) : vector<type_t, DIM>()
    { *this = arr; }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM>::vector(const vector<type_t, DIM>& vec) : vector<type_t, DIM>()
    { *this = vec; }

    template <typename type_t, unsigned long DIM>
    const type_t* vector<type_t, DIM>::buffer(void) const
    { return this->_arr; }

    template <typename type_t, unsigned long DIM>
    type_t& vector<type_t, DIM>::operator [] (const unsigned long index) noexcept(false)
    {
        if (index >= DIM)
            throw "Index is out of bounds";

        return this->_arr[index];
    }

    template <typename type_t, unsigned long DIM>
    constexpr const unsigned long vector<type_t, DIM>::dim(void) const
    { return DIM; }

    template <typename type_t, unsigned long DIM>
    void vector<type_t, DIM>::operator = (const type_t arr[]) noexcept(false)
    {
        if (arr == nullptr)
            throw "Pointer to array is null";

        for (unsigned long i = 0; i < DIM; ++i)
            this->_arr[i] = arr[i];
    }

    template <typename type_t, unsigned long DIM>
    void vector<type_t, DIM>::operator = (const vector<type_t, DIM>& vec)
    { *this = vec.buffer(); }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    constexpr const bool vector<type_t, DIM>::operator == (const vector<_type_t, _DIM>& vec)
    { return false; }

    template <typename type_t, unsigned long DIM>
    const bool vector<type_t, DIM>::operator == (const vector<type_t, DIM>& vec)
    {
        for (unsigned long i = 0; i < DIM; ++i)
        {
            if (this->_arr[i] != vec._arr[i])
                return false;
        }

        return true;
    }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    constexpr const bool vector<type_t, DIM>::operator != (const vector<_type_t, _DIM>& vec)
    { return true; }

    template <typename type_t, unsigned long DIM>
    const bool vector<type_t, DIM>::operator != (const vector<type_t, DIM>& vec)
    { return !(*this == vec); }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM> vector<type_t, DIM>::operator + (const vector<type_t, DIM>& vec) const
    {
        type_t arr[DIM];

        for (unsigned long i = 0; i < DIM; ++i)
            arr[i] = this->_arr[i] + vec._arr[i];

        return vector<type_t, DIM>(arr);
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM> vector<type_t, DIM>::operator - (const vector<type_t, DIM>& vec) const
    {
        type_t arr[DIM];

        for (unsigned long i = 0; i < DIM; ++i)
            arr[i] = this->_arr[i] - vec._arr[i];

        return vector<type_t, DIM>(arr);
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM> vector<type_t, DIM>::operator * (const type_t scalar) const
    {
        type_t arr[DIM];

        for (unsigned long i = 0; i < DIM; ++i)
            arr[i] = this->_arr[i] * scalar;

        return vector<type_t, DIM>(arr);
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM> vector<type_t, DIM>::operator / (const type_t scalar) const
    {
        if (scalar == 0)
            return vector<type_t, DIM>();

        type_t arr[DIM];

        for (unsigned long i = 0; i < DIM; ++i)
            arr[i] = this->_arr[i] / scalar;

        return vector<type_t, DIM>(arr);
    }

    template <typename type_t, unsigned long DIM>
    type_t vector<type_t, DIM>::operator ^ (const vector<type_t, DIM>& vec) const
    {
        type_t result = 0;

        for (unsigned long i = 0; i < DIM; ++i)
            result += this->_arr[i] * vec._arr[i];

        return result;
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM> vector<type_t, DIM>::operator * (const vector<type_t, DIM>& vec) const
    {
        static_assert
        (
            DIM == 3,
            "Vector product is only valid for three dimensional vectors"
        );

        type_t arr[DIM];

        arr[0] = this->_arr[1] * vec._arr[2] - this->_arr[2] * vec._arr[1];
        arr[1] = this->_arr[2] * vec._arr[0] - this->_arr[0] * vec._arr[2];
        arr[2] = this->_arr[0] * vec._arr[1] - this->_arr[1] * vec._arr[0];

        return vector<type_t, DIM>(arr);
    }

    template <typename type_t, unsigned long DIM>
    vector<type_t, DIM>::operator type_t() const
    {
        type_t norm = 0;

        for (unsigned long i = 0; i < DIM; ++i)
            norm += this->_arr[i] * this->_arr[i];

        return norm;
    }
}

#endif // _VECTOR_IPP_