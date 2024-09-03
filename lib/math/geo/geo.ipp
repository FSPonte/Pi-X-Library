#ifndef _GEO_IPP_
#define _GEO_IPP_

// Dependencies
#include <type_info.hpp>
#include <math.hpp>

namespace pix::math::geo
{
    template <typename type_t, unsigned long DIM>
    point<type_t, DIM>::point(void)
    {
        is_number_static_assert(type_t);

        static_assert
        (
            DIM != 0,
            "Geometric point cannot have zero coordinates"
        );
    }

    template <typename type_t, unsigned long DIM>
    point<type_t, DIM>::point(const type_t data[]) : point<type_t, DIM>()
    {
        for (unsigned long i = 0; i < DIM; ++i)
            this->data[i] = data[i];
    }

    template <typename type_t, unsigned long DIM>
    type_t& point<type_t, DIM>::operator [] (const unsigned long index) noexcept(false)
    {
        if (index >= DIM)
            throw "Index is out of bounds";

        return this->data[index];
    }

    template <typename type_t, unsigned long DIM>
    const type_t point<type_t, DIM>::dist(point<type_t, DIM>& p) const
    {
        type_t distance = 0;

        for (unsigned long i = 0; i < DIM; ++i)
            distance += (this->data[i] - p[i]) * (this->data[i] - p[i]);

        return pix::math::root(distance, 2);
    }

    template <typename type_t, unsigned long DIM>
    const point<type_t, DIM> point<type_t, DIM>::midp(point<type_t, DIM>& p) const
    {
        type_t arr[DIM];

        for (unsigned long i = 0; i < DIM; ++i)
            arr[i] = 0.5 * (p[i] - this->data[i]) + this->data[i];

        return point<type_t, DIM>(arr);
    }
}

#endif // _GEO_IPP_