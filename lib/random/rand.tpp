#ifndef _RAND_TPP_
#define _RAND_TPP_

// Dependencies
#include <sys_vars.hpp>

constexpr static const char
	seed_byte = '\0',
	mult_byte = '\0',
	inc_byte = '\0';

static const unsigned long
	SEED = reinterpret_cast<unsigned long>(&seed_byte), // Initial value
	MULT = reinterpret_cast<unsigned long>(&mult_byte), // Multiplier
	INC = reinterpret_cast<unsigned long>(&inc_byte); // Increment

namespace pix::random
{
	unsigned long rand(void) noexcept(true)
	{
		static unsigned long value = SEED;
		
		value = (MULT * value + INC) % INT32_MAX;

		return value;
	}

	long rand(const long min, const long max) noexcept(false)
	{
		if (min >= max)
			throw "Invalid minimum and maximum values (min >= max)";

		return rand() % (max - min) + min;
	}

	long double drand(void) noexcept(true)
	{ return static_cast<long double>(rand()) / static_cast<long double>(INT32_MAX); }

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
