#ifndef _RGB_TPP_
#define _RGB_TPP_

namespace pix::graphics
{
	void rgb::operator = (const rgb& COLOR)
	{
		this->_red = COLOR._red;
		this->_green = COLOR._green;
		this->_blue = COLOR._blue;
	}

	bool rgb::operator == (const rgb& COLOR) const
	{
		return
			this->_red == COLOR._red
			&&
			this->_green == COLOR._green
			&&
			this->_blue == COLOR._blue;
	}

	bool rgb::operator != (const rgb& COLOR) const
	{
		return
			this->_red != COLOR._red
			||
			this->_green != COLOR._green
			||
			this->_blue != COLOR._blue;
	}
}

#endif // _RGB_TPP_