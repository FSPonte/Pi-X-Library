#ifndef _UTILS_HPP_
#define _UTILS_HPP_

// Dependencies
#include <ostream>

// Terminal width when it cannot be determined
#define TERMINAL_WIDTH_DEFAULT 80

// Default output width when printing to file
#define FILE_WIDTH_DEFAULT 120

#if defined(_WIN32) || defined(_WIN64)
#include <io.h>
#define ISATTY _isatty
#else
#include <unistd.h>
#define ISATTY isatty
#endif

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
	 * @brief Check if we should use UTF-8 encoding
	 * @param stream The output stream
	 * @return true if UTF-8 encoding should be used
	*/
	bool should_use_utf8(std::ostream&) noexcept(true);

	/**
	 * @brief Check if ANSI color codes should be used
	 * @param stream The output stream
	 * @return true if ANSI color codes should be used
	*/
	bool should_use_color(std::ostream&) noexcept(true);

	/**
	 * @brief Get the width of the terminal
	 * @param stream The output stream
	 * @return The width of the terminal in characters
	*/
	int get_terminal_width(std::ostream&) noexcept(true);

	/**
	 * @brief Get the inverse of the timer frequency
	 * @return The inverse of the timer frequency
	 * @note For Windows OS
	*/
	double get_timer_freq_inv(void) noexcept(true);

	/**
	 * @brief Check if C-string contains UTF-8 characters
	 * @param str C-string
	 * @return true if C-string contains UTF-8 characters
	 * @throw Null pointer
	*/
	bool contains_utf8_case_insensitive(const char[]) noexcept(false);

	/**
	 * @brief Checks if the terminal supports UTF-8
	 * @return true if terminal supports UTF-8
	*/
	bool terminal_supports_utf8(void) noexcept(true);
}

// Template file
#include "utils.tpp"

#endif // _UTILS_HPP_