#ifndef _GEO_HPP_
#define _GEO_HPP_

namespace pix::math::geo
{
    /**
     * @brief Point
     * @tparam type_t Data type
     * @tparam DIM Number of coordinates
    */
    template <typename type_t, unsigned long DIM>
    class point
    {
    private:

        type_t data[DIM];

    public:

        /**
         * @brief Constructor
        */
        point(void);

        /**
         * @brief Parameterized constructor
         * @param arr Array of coordinates
        */
        point(const type_t[]);

        /**
         * @brief Get coordinate
         * @param ind Index
         * @return Coordinate
         * @throw Index is out of bounds
        */
        type_t& operator [] (unsigned long) noexcept(false);

        /**
         * @brief Calculate the distance to a point
         * @param p Point
         * @return Distance
        */
        const type_t dist(point<type_t, DIM>&) const;

        /**
         * @brief Calculate the midpoint
         * @param p Point
         * @return Midpoint
        */
        const point<type_t, DIM> midp(point<type_t, DIM>&) const;
    };
}

// Implementation file
#include "geo.ipp"

#endif // _GEO_HPP_