#ifndef _SORT_IPP_
#define _SORT_IPP_

namespace pix::sort
{
    template <typename type_t>
    void bubble_sort(type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "bubble_sort: arr == nullptr";

        if (dim == 0)
            throw "bubble_sort: dim == 0";

        const unsigned long dim_j = dim - 1;
        type_t aux; // Auxiliar value

        for (unsigned long i = 0; i < dim; ++i)
        {
            for (unsigned long j = 0; j < dim - 1; ++j)
            {
                if (arr[j] < arr[j + 1])
                    continue;

                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

#endif // _SORT_IPP_