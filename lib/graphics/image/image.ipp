#ifndef _IMAGE_IPP_
#define _IMAGE_IPP_

namespace pix::graphics
{
    template <unsigned long W_DIM, unsigned long H_DIM>
    image<W_DIM, H_DIM>::image(void)
    {
        this->_data = new rgb*[H_DIM];

        for (unsigned long i = 0; i < H_DIM; ++i)
            this->_data[i] = new rgb[W_DIM];
    }

    template <unsigned long W_DIM, unsigned long H_DIM>
    image<W_DIM, H_DIM>::~image(void)
    {
        for (unsigned long i = 0; i < H_DIM; ++i)
            delete[] this->_data[i];

        delete[] this->_data;
    }

    template <unsigned long W_DIM, unsigned long H_DIM>
    rgb** image<W_DIM, H_DIM>::data(void)
    { return this->_data; }

    template <unsigned long W_DIM, unsigned long H_DIM>
    rgb& image<W_DIM, H_DIM>::get(const unsigned long y, const unsigned long x) noexcept(false)
    {
        if (y >= H_DIM)
            throw "Y coordinate is out of bounds";

        if (x >= W_DIM)
            throw "X coordinate is out of bounds";

        return this->_data[y][x];
    }

    template <unsigned long W_DIM, unsigned long H_DIM>
    constexpr const unsigned long image<W_DIM, H_DIM>::width(void) const
    { return W_DIM; }

    template <unsigned long W_DIM, unsigned long H_DIM>
    constexpr const unsigned long image<W_DIM, H_DIM>::height(void) const
    { return H_DIM; }

    template <unsigned long W_DIM, unsigned long H_DIM>
    constexpr const unsigned long image<W_DIM, H_DIM>::resolution(void) const
    { return W_DIM * H_DIM; }

    template <unsigned long W_DIM, unsigned long H_DIM>
    constexpr const unsigned long image<W_DIM, H_DIM>::size(void) const
    { return W_DIM * H_DIM * sizeof(rgb); }

    template <unsigned long W_DIM, unsigned long H_DIM>
    void image<W_DIM, H_DIM>::operator = (const image<W_DIM, H_DIM>& img)
    {
        rgb** _data = img.data();

        if (_data == nullptr)
            return;

        for (unsigned long y = 0; y < H_DIM; ++y)
        {
            if (_data[y] == nullptr)
                return;

            for (unsigned long x = 0; x < W_DIM; ++x)
                this->_data[y][x] = _data[y][x];
        }
    }
}

#endif // _IMAGE_IPP_