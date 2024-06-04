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
    array<type_t, DIM>::array(const type_t* arr) : array<type_t, DIM>()
    {
        if (arr == nullptr)
            return;

        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = arr[i];
    }

    template <typename type_t, unsigned long DIM>
    template <typename _type_t, unsigned long _DIM>
    array<type_t, DIM>::array(const array<_type_t, _DIM>& arr) : array<type_t, DIM>()
    {
        for (unsigned long i = 0; i < DIM && i < _DIM; ++i)
            this->data[i] = arr[i];
    }

    template <typename type_t, unsigned long DIM>
    type_t& array<type_t, DIM>::operator [] (const unsigned long ind)
    { return this->data[ind % DIM]; }

    template <typename type_t, unsigned long DIM>
    constexpr const unsigned long array<type_t, DIM>::dim() const
    { return DIM; }
}

#endif // _ARRAY_IPP_