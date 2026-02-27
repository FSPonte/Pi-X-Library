// Header file
#include "rgb.hpp"

namespace pix::graphics
{
	void rgb::operator = (const rgb& color)
	{
		this->_red = color._red;
		this->_green = color._green;
		this->_blue = color._blue;
	}

	bool rgb::operator == (const rgb& color) const
	{
		return
			this->_red == color._red
			&&
			this->_green == color._green
			&&
			this->_blue == color._blue;
	}

	bool rgb::operator != (const rgb& color) const
	{
		return
			this->_red != color._red
			||
			this->_green != color._green
			||
			this->_blue != color._blue;
	}
}
