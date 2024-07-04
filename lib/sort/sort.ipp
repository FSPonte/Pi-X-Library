#ifndef _SORT_IPP_
#define _SORT_IPP_

template <typename type_t>
static inline void _swap_(type_t arr[], const unsigned long ind_1, const unsigned long ind_2) noexcept(true)
{
    type_t aux = arr[ind_1];
    arr[ind_1] = arr[ind_2];
    arr[ind_2] = aux;
}

template <typename type_t>
static const unsigned long _partition_(type_t arr[], const unsigned long start_ind, const unsigned long end_ind) noexcept(true)
{
    type_t pivot = arr[end_ind]; // Pivot value
    unsigned long min_ind = start_ind - 1; // Index of smaller element

    for (unsigned long i = start_ind; i <= end_ind - 1; ++i)
    {
        if (arr[i] > pivot)
            continue;
        
        _swap_(arr, ++min_ind, i);
    }
    
    _swap_(arr, min_ind + 1, end_ind);
    
    return min_ind + 1;
}

template <typename type_t>
static void _quick_sort_(type_t arr[], const unsigned long start_ind, const unsigned long end_ind) noexcept(true)
{
    if (start_ind >= end_ind)
        return;

    const unsigned long part_ind = _partition_(arr, start_ind, end_ind); // Partition index

    _quick_sort_(arr, start_ind, part_ind - 1);
    _quick_sort_(arr, part_ind + 1, end_ind);
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
                if (arr[j] <= arr[j + 1])
                    continue;

                _swap_(arr, j, j + 1);
            }
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

        unsigned long min_ind; // Index of minimum value
        type_t aux; // Auxiliar value

        for (unsigned long i = 0; i < dim; ++i)
        {
            min_ind = i;

            for (unsigned long j = i + 1; j < dim; ++j)
            {
                if (arr[min_ind] <= arr[j])
                    continue;

                min_ind = j;
            }

            _swap_(arr, i, min_ind);
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
        type_t aux;

        for (unsigned long i = 1; i < dim; ++i)
        {
            aux = arr[i];

            for (j = i - 1; j >= 0 && arr[j] > aux; --j)
                arr[j + 1] = arr[j];

            arr[j + 1] = aux;
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