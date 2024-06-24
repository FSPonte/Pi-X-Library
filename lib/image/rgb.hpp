#ifndef _RGB_HPP_
#define _RGB_HPP_

namespace pix::graphics
{
    // Maximum value for color
    const unsigned int max_val = 255;

    /**
     * @brief RGB color
    */
    class rgb
    {
    public:

        unsigned int
            red,
            green,
            blue;

        void operator = (const rgb&);
        const bool operator == (const rgb&) const;
        const bool operator != (const rgb&) const;
    };
}

// Implementation file
#include "rgb.ipp"

#endif // _RGB_HPP_