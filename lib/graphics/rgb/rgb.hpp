#ifndef _RGB_HPP_
#define _RGB_HPP_

namespace pix::graphics
{
	// Maximum value for color
	const unsigned int MAX_VALUE = 255;

	/**
	 * @brief RGB color
	*/
	class rgb
	{
	public:

		unsigned int
			_red,
			_green,
			_blue;

		void operator = (const rgb&);
		bool operator == (const rgb&) const;
		bool operator != (const rgb&) const;
	};
}

// Template file
#include "rgb.tpp"

#endif // _RGB_HPP_
