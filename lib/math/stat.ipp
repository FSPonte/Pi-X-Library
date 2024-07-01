#ifndef _STAT_IPP_
#define _STAT_IPP_

namespace pix::math::stat
{
    template <typename type_t>
    type_t sum(const type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "sum: arr == nullptr";

        if (dim == 0)
            throw "sum: dim == 0";

        type_t result = 0;

        for (unsigned long i = 0; i < dim; ++i)
            result += arr[i];

        return result;
    }

    template <typename type_t>
    type_t mean(const type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "mean: arr == nullptr";

        if (dim == 0)
            throw "mean: dim == 0";

        return stat::sum(arr, dim) / dim;
    }

    template <typename type_t>
    type_t median(const type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "std_dev: arr == nullptr";

        if (dim == 0)
            throw "std_dev: dim == 0";

        if (dim % 2 == 0)
            return (arr[dim / 2] + arr[(dim / 2) - 1]) / 2;

        return arr[(dim + 1) / 2];
    }

    template <typename type_t>
    type_t std_dev(const type_t arr[], const unsigned long dim) noexcept(false)
    {
        is_number_static_assert(type_t);

        if (arr == nullptr)
            throw "std_dev: arr == nullptr";

        if (dim == 0)
            throw "std_dev: dim == 0";

        const type_t average = stat::mean(arr, dim);
        type_t result = 0;

        for (unsigned long i = 0; i < dim; ++i)
            result += (arr[i] - average) * (arr[i] - average);

        return math::root(result / dim, 2);
    }
}

#endif // _STAT_IPP_