#ifndef _SORT_IPP_
#define _SORT_IPP_

template <typename type_t>
static unsigned long _partition_(type_t arr[], const unsigned long start, const unsigned long end) noexcept(true)
{
    unsigned long ind = start - 1; // Index of smaller element
    type_t
        pivot = arr[end],
        aux;

    for (unsigned long i = start; i < end; ++i)
    {
        if (arr[i] <= pivot)
        {
            ++ind;
            aux = arr[ind];
            arr[ind] = arr[i];
            arr[i] = aux;
        }
    }
    
    aux = arr[ind + 1];
    arr[ind + 1] = arr[end];
    arr[end] = aux;
    
    return ind + 1;
}

template <typename type_t>
static void _quick_sort_(type_t arr[], const unsigned long start, const unsigned long end) noexcept(true)
{
    if(start >= end)
        return;

    const unsigned long ind = _partition_(arr, start, end);

    _quick_sort_(arr, start, ind - 1);
    _quick_sort_(arr, ind + 1, end);
}

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

    template <typename type_t>
    void insertion_sort(type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "insertion_sort: arr == nullptr";

        if (dim == 0)
            throw "insertion_sort: dim == 0";

        unsigned long j;
        type_t aux; // Auxiliar value

        for (unsigned long i = 1; i < dim; ++i)
        {
            aux = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > aux)
            {
                arr[j + 1] = arr[j];
                --j;
            }

            arr[j + 1] = aux;
        }
    }

    template <typename type_t>
    void selection_sort(type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "selection_sort: arr == nullptr";

        if (dim == 0)
            throw "selection_sort: dim == 0";

        unsigned long ind; // Index of minimum value
        type_t aux; // Auxiliar value

        for (unsigned long i = 0; i < dim; ++i)
        {
            ind = i;

            for (unsigned long j = i + 1; j < dim; ++j)
            {
                if (arr[ind] < arr[j])
                    continue;

                ind = j;
            }

            aux = arr[i];
            arr[i] = arr[ind];
            arr[ind] = aux;
        }
    }

    template <typename type_t>
    void quick_sort(type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "quick_sort: arr == nullptr";

        if (dim == 0)
            throw "quick_sort: dim == 0";

        _quick_sort_(arr, 0, dim - 1);
    }
}

#endif // _SORT_IPP_