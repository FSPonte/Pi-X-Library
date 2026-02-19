#ifndef _UTILS_HPP_
#define _UTILS_HPP_

// Dependencies
#include <cstdio>

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

	/**
	 * @brief Determine if we should use UTF-8 encoding for the given output stream.
	 * @param stream The output stream (e.g., stdout, stderr).
	 * @return true if UTF-8 encoding should be used, false otherwise.
	*/
	bool should_use_utf8(FILE* stream);

	/**
	 * @brief Determine if ANSI color codes should be used for the given output stream.
	 * @param stream The output stream (e.g., stdout, stderr).
	 * @return true if ANSI color codes should be used, false otherwise.
	*/
	bool should_use_color(FILE* stream);

	/**
	 * @brief Get the width of the terminal for the given output stream.
	 * @param stream The output stream (e.g., stdout, stderr), or NULL for files.
	 * @return The width of the terminal in characters.
	*/
	int get_terminal_width(FILE* stream);

	/**
	 * @brief Get the inverse of the timer frequency (for Windows).
	 * @return The inverse of the timer frequency.
	*/
	double get_timer_freq_inv(void);

	bool contains_utf8_case_insensitive(const char[]);

	bool terminal_supports_utf8(void);
}

// Template file
#include "utils.tpp"

#endif // _UTILS_HPP_
