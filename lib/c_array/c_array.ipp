#ifndef _C_ARRAY_IPP_
#define _C_ARRAY_IPP_

namespace pix::c_array
{
    template <typename type_t>
    inline void swap(type_t& ref_1, type_t& ref_2) noexcept(true)
    {
        const type_t aux = ref_1;
        ref_1 = ref_2;
        ref_2 = aux;
    }

    template <typename type_t>
    void invert(type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "invert: arr == nullptr";

        if (dim == 0)
            throw "invert: dim == 0";

        unsigned long
            left_ind = 0,
            right_ind = dim - 1;
        type_t aux; // Auxiliar value

        while (left_ind < right_ind)
        {
            pix::c_array::swap(arr, left_ind, right_ind);

            ++left_ind;
            --right_ind;
        }
    }
}

#endif // _C_ARRAY_IPP_