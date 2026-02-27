// Header file
#include "rand.hpp"

namespace pix::random
{
	char crand(void) noexcept(true)
	{
		return static_cast<char>(pix::random::rand() % 26 + 97);
	}
}
