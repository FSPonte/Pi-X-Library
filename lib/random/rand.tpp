#ifndef _RAND_TPP_
#define _RAND_TPP_

// Dependencies
#include <sys_vars.hpp>

namespace pix::random
{
	unsigned long rand(void) noexcept(true)
	{
		static unsigned long value = SEED;
		
		value = (MULT * value + INC) % MOD;

		return value;
	}

	long rand(const long min, const long max) noexcept(false)
	{
		if (min >= max)
			throw "Invalid minimum and maximum values (min >= max)";

		return (max - min) * rand() + min;
	}

	long double drand(void) noexcept(true)
	{ return static_cast<long double>(rand()) / static_cast<long double>(MOD); }

	long double drand(const long double min, const long double max) noexcept(false)
	{
		if (min >= max)
			throw "Invalid minimum and maximum values (min >= max)";

		return (max - min) * drand() + min;
	}

	char crand(void) noexcept(true)
	{ return static_cast<char>(rand() % 26 + 97); }
}

#endif // _RAND_TPP_
