#ifndef _RGB_IPP_
#define _RGB_IPP_

namespace pix::graphics
{
    void rgb::operator = (const rgb& color)
    {
        this->red = color.red;
        this->green = color.green;
        this->blue = color.blue;
    }

    const bool rgb::operator == (const rgb& color) const
    {
        return
            this->red == color.red
            &&
            this->green == color.green
            &&
            this->blue == color.blue;
    }

    const bool rgb::operator != (const rgb& color) const
    {
        return
            this->red != color.red
            ||
            this->green != color.green
            ||
            this->blue != color.blue;
    }
}

#endif // _RGB_IPP_