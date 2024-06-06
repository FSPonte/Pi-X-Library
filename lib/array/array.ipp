#ifndef _ARRAY_IPP_
#define _ARRAY_IPP_

namespace pix::adt
{
    template <typename type_t, unsigned long DIM>
    array<type_t, DIM>::array(void)
    {
        static_assert
        (
            DIM != 0,
            "Array object cannot have zero elements"
        );

        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = type_t();
    }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t>
    array<type_t, DIM>::array(const _type_t* arr) : array<type_t, DIM>()
    {
        if (arr == nullptr)
            return;

        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = static_cast<type_t>(arr[i]);
    }

    template <typename type_t, unsigned long DIM>
    array<type_t, DIM>::array(const type_t* arr) : array<type_t, DIM>()
    {
        if (arr == nullptr)
            return;

        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = arr[i];
    }

    template <typename type_t, unsigned long DIM>
    array<type_t, DIM>::array(array<type_t, DIM>& arr) : array<type_t, DIM>()
    { *this = arr; }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t>
    array<type_t, DIM>::array(array<_type_t, DIM>& arr) : array<type_t, DIM>()
    { *this = arr; }

    template <typename type_t, unsigned long DIM>
    type_t& array<type_t, DIM>::operator [] (const unsigned long ind)
    { return this->data[ind % DIM]; }

    template <typename type_t, unsigned long DIM>
    constexpr const unsigned long array<type_t, DIM>::dim() const
    { return DIM; }

    template <typename type_t, unsigned long DIM>
    void array<type_t, DIM>::operator = (array<type_t, DIM>& arr)
    {
        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = arr[i];
    }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    void array<type_t, DIM>::operator = (array<_type_t, _DIM>& arr)
    {
        for (unsigned long i = 0; i < DIM && i < _DIM; ++i)
            this->data[i] = static_cast<type_t>(arr[i]);
    }

    template <typename type_t, unsigned long DIM>
    const bool array<type_t, DIM>::operator == (array<type_t, DIM>& arr) const
    {
        for (unsigned long i = 0; i < DIM; ++i)
        {
            if (this->data[i] != arr[i])
                return false;
        }

        return true;
    }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    constexpr const bool array<type_t, DIM>::operator == (array<_type_t, _DIM>& arr) const
    { return false; }

    template <typename type_t, unsigned long DIM>
    const bool array<type_t, DIM>::operator != (array<type_t, DIM>& arr) const
    { return !(*this == arr); }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    constexpr const bool array<type_t, DIM>::operator != (array<_type_t, _DIM>& arr) const
    { return true; }
}

#endif // _ARRAY_IPP_