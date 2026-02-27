#ifndef _RAND_HPP_
#define _RAND_HPP_

// Dependencies
#include <pix_lib.hpp>

// Random number generator
namespace pix::random
{
	/**
	 * @brief Linear congruential generator
	 * @tparam type_t Data type
	 * @return Random integer number between 0 and INT32_MAX
	*/
	template <typename type_t = unsigned long>
	type_t rand(void) noexcept(true);

	/**
	 * @brief Linear congruential generator
	 * @tparam type_t Data type
	 * @param min Minimum value
	 * @param max Maximum value
	 * @return Random integer number between min and max
	 * @throw Invalid minimum and maximum values (min >= max)
	*/
	template <typename type_t = long>
	type_t rand(type_t, type_t) noexcept(false);

	/**
	 * @brief Linear congruential generator
	 * @tparam type_t Data type
	 * @return Random decimal number between min and max
	*/
	template <typename type_t = long double>
	type_t drand(void) noexcept(true);

	/**
	 * @brief Linear congruential generator
	 * @tparam type_t Data type
	 * @param min Minimum value
	 * @param max Maximum value
	 * @return Random decimal number between 0 and 1
	 * @throw Invalid minimum and maximum values (min >= max)
	*/
	template <typename type_t = long double>
	type_t drand(type_t, type_t) noexcept(false);

	/**
	 * @brief Linear congruential generator
	 * @return Random character in ASCII
	 * @note Can only return lower case letters
	*/
	char crand(void) noexcept(true);
}

// Template file
#include "rand.tpp"

#endif // _RAND_HPP_
