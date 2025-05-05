#ifndef _IMAGE_TPP_
#define _IMAGE_TPP_

// Dependencies
#include <asserts.hpp>

namespace pix::graphics
{
	template <unsigned long W_DIM, unsigned long H_DIM>
	image<W_DIM, H_DIM>::image(void)
	{
		assert_not_nulldim(W_DIM);
		assert_not_nulldim(H_DIM);

		this->_data = new rgb*[W_DIM];

		for (unsigned long i = 0; i < W_DIM; ++i)
			this->_data[i] = new rgb[H_DIM];
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
	rgb& image<W_DIM, H_DIM>::get(const unsigned long X, const unsigned long Y) noexcept(false)
	{
		if (X >= W_DIM) throw "X coordinate is out of bounds";
		if (Y >= H_DIM) throw "Y coordinate is out of bounds";

		return this->_data[X][Y];
	}

	template <unsigned long W_DIM, unsigned long H_DIM>
	constexpr unsigned long image<W_DIM, H_DIM>::width(void) const
	{
		return W_DIM;
	}

	template <unsigned long W_DIM, unsigned long H_DIM>
	constexpr unsigned long image<W_DIM, H_DIM>::height(void) const
	{
		return H_DIM;
	}

	template <unsigned long W_DIM, unsigned long H_DIM>
	constexpr unsigned long image<W_DIM, H_DIM>::resolution(void) const
	{
		return W_DIM * H_DIM;
	}

	template <unsigned long W_DIM, unsigned long H_DIM>
	constexpr unsigned long image<W_DIM, H_DIM>::size(void) const
	{
		return W_DIM * H_DIM * sizeof(rgb);
	}

	template <unsigned long W_DIM, unsigned long H_DIM>
	void image<W_DIM, H_DIM>::operator = (const image<W_DIM, H_DIM>& IMG)
	{
		rgb** data = IMG.data();

		if (data == nullptr)
			return;

		for (unsigned long x = 0; x < W_DIM; ++x)
		{
			if (data[x] == nullptr)
				return;

			for (unsigned long y = 0; y < H_DIM; ++y)
				this->_data[x][y] = data[x][y];
		}
	}
}

#endif // _IMAGE_TPP_
