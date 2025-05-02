#ifndef _UTILS_HPP_
#define _UTILS_HPP_

// Utilities
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

	/**
	 * @brief Print file content in hexadecimal
	 * @param f_nam File name
	*/
	void print_file_hex(char[]) noexcept(true);

	/**
	 * @brief Print vector
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array
	*/
	template <typename type_t, unsigned long DIM>
	void print(type_t (&)[DIM]) noexcept(true);

	/**
	 * @brief Print matrix
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr Array
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void print(type_t (&)[N_LIN][N_COL]) noexcept(true);
}

// Template file
#include "utils.tpp"

#endif // _UTILS_HPP_
