#ifndef _RAND_TPP_
#define _RAND_TPP_

// Dependencies
#include <type_info.hpp>

constexpr static const char SEED_BYTE = '\0';
static const unsigned long
	SEED = reinterpret_cast<unsigned long>(&SEED_BYTE), // Initial value
	MULT = reinterpret_cast<unsigned long>(&SEED_BYTE + 1), // Multiplier
	INC = reinterpret_cast<unsigned long>(&SEED_BYTE - 1); // Increment

namespace pix::random
{
	template <typename type_t>
	type_t rand(void) noexcept(true)
	{
		is_integer_static_assert(type_t);

		static type_t value = SEED;
		
		value = (MULT * value + INC) % INT32_MAX;

		return value;
	}

	template <typename type_t>
	type_t rand(const type_t MIN, const type_t MAX) noexcept(false)
	{
		is_integer_static_assert(type_t);

		if (MIN > MAX) throw "Invalid minimum and maximum values (min > max)";
		
		if (MIN == MAX)
			return MIN;

		return rand<type_t>() % (MAX - MIN) + MIN;
	}

	template <typename type_t>
	type_t drand(void) noexcept(true)
	{
		is_float_static_assert(type_t);

		return static_cast<type_t>(rand()) / static_cast<type_t>(INT32_MAX);
	}

	template <typename type_t>
	type_t drand(const type_t MIN, const type_t MAX) noexcept(false)
	{
		is_float_static_assert(type_t);

		if (MIN > MAX) throw "Invalid minimum and maximum values (min > max)";

		if (MIN == MAX)
			return MIN;

		return (MAX - MIN) * drand<type_t>() + MIN;
	}

	char crand(void) noexcept(true)
	{
		return static_cast<char>(rand() % 26 + 97);
	}
}

#endif // _RAND_TPP_
