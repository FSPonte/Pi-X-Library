#ifndef _RAND_TPP_
#define _RAND_TPP_

// Dependencies
#include <sys_vars.hpp>

constexpr static const char SEED_BYTE = '\0';

static const unsigned long
	SEED = reinterpret_cast<unsigned long>(&SEED_BYTE), // Initial value
	MULT = reinterpret_cast<unsigned long>(&SEED_BYTE + 1), // Multiplier
	INC = reinterpret_cast<unsigned long>(&SEED_BYTE - 1); // Increment

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
		if (min > max)
			throw "Invalid minimum and maximum values (min > max)";
		
		if (min == max)
			return min;

		return rand() % (max - min) + min;
	}

	long double drand(void) noexcept(true)
	{ return static_cast<long double>(rand()) / static_cast<long double>(INT32_MAX); }

	long double drand(const long double min, const long double max) noexcept(false)
	{
		if (min > max)
			throw "Invalid minimum and maximum values (min > max)";

		if (min == max)
			return min;

		return (max - min) * drand() + min;
	}

	char crand(void) noexcept(true)
	{ return static_cast<char>(rand() % 26 + 97); }
}

#endif // _RAND_TPP_
