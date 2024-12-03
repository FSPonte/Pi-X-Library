#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace utils
{
	/**
	 * @brief Pause the process
	 * @param msg Message
	 * @note Adds the "..." string at the end
	*/
	void pause(const char[] = nullptr) noexcept(true);

	/**
	 * @brief Clear the terminal
	*/
	void clear(void) noexcept(true);

	/**
	 * @brief Parse program arguments
	 * @param argc Number of arguments
	 * @param argv Array of arguments
	*/
	void parse(int, char*[]) noexcept(true);

	/**
	 * @brief Print file content
	 * @param f_nam File name
	*/
	void print_file(char[]) noexcept(true);
}

// Template file
#include "utils.tpp"

#endif // _UTILS_HPP_
