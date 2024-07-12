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
            throw "Pointer to array is null";

        if (dim == 0)
            throw "Dimension is null";

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

    template <typename type_t>
    void copy(type_t arr_o[], type_t arr_d[], const unsigned long dim) noexcept(false)
    {
        if (arr_o == nullptr)
            throw "Pointer to origin array is null";

        if (arr_d == nullptr)
            throw "Pointer to destination array is null";

        if (dim == 0)
            throw "Dimension is null";

        for (unsigned long i = 0; i < dim; ++i)
            arr_d[i] = arr_o[i];
    }

    template <typename type_t>
    void left_shift(type_t arr[], unsigned long dim) noexcept(false)
    {
        if (arr == nullptr)
            throw "Pointer to array is null";

        if (dim == 0)
            throw "Dimension is null";

        --dim;

        for (unsigned long i = 0; i < dim; ++i)
            arr[i] = arr[i + 1];
    }

    template <typename type_t>
    void right_shift(type_t arr[], const unsigned long dim) noexcept(false)
    {
        if (arr == nullptr)
            throw "Pointer to array is null";

        if (dim == 0)
            throw "Dimension is null";

        for (unsigned long i = 1; i < dim; ++i)
            arr[i] = arr[i - 1];
    }
}

#endif // _C_ARRAY_IPP_