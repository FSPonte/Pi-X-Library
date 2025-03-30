#ifndef _RAND_TPP_
#define _RAND_TPP_

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
	type_t rand(const type_t min, const type_t max) noexcept(false)
	{
		is_integer_static_assert(type_t);

		if (min > max)
			throw "Invalid minimum and maximum values (min > max)";
		
		if (min == max)
			return min;

		return rand<type_t>() % (max - min) + min;
	}

	template <typename type_t>
	type_t drand(void) noexcept(true)
	{
		is_float_static_assert(type_t);

		return static_cast<type_t>(rand()) / static_cast<type_t>(INT32_MAX);
	}

	template <typename type_t>
	type_t drand(const type_t min, const type_t max) noexcept(false)
	{
		is_float_static_assert(type_t);

		if (min > max)
			throw "Invalid minimum and maximum values (min > max)";

		if (min == max)
			return min;

		return (max - min) * drand<type_t>() + min;
	}

	char crand(void) noexcept(true)
	{ return static_cast<char>(rand() % 26 + 97); }
}

#endif // _RAND_TPP_
