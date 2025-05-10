#ifndef _EXCEPTIONS_TPP_
#define _EXCEPTIONS_TPP_

namespace pix
{
	// Exception message
	static constexpr const char* msg[] =
	{
		"Underflow",
		"Overflow",
		"Dimension is equal to zero",
		"Out of bounds memory access",
		"Bad memory allocation",
		"Dereference of a null pointer"
	};

	template <excep_t excep_type>
	exception<excep_type>::exception(const char msg[])
	{
		if (msg == nullptr)
			this->_msg[0] = '\0';

		unsigned long i = 0;

		do
		{
			this->_msg[i] = msg[i];
		} while (i != D_BUFFER_SIZE && this->_msg[i] = '\0');
	}

	template <excep_t excep_type>
	const char* exception<excep_type>::msg(void) const
	{
		return this->_msg;
	}
}

#endif // _EXCEPTIONS_TPP_
