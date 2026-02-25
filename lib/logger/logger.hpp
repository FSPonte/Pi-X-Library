#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#if __has_include(<fstream>)

// Dependencies
#include <fstream>

/**
 * @brief Logger class
*/
class logger
{
public:

	/**
	 * @brief Constructor
	 * @param file_path Path to the log file
	 * @throw Failed to open file
	*/
	explicit logger(const char[]) noexcept(false);

	// Disable copy constructor
	logger(const logger&) = delete;

	/**
	 * @brief Destructor
	*/
	~logger(void) noexcept(true);

	/**
	 * @brief Open a logging session
	*/
	void open_session(void) noexcept(true);

	/**
	 * @brief Log a message
	 * @param msg Message to log
	*/
	void log_msg(const char[]) noexcept(true);

	/**
	 * @brief Log an array as a list
	 * @tparam type_t Data type
	 * @param arr Array to log
	 * @param dim Number of elements
	*/
	template <typename type_t>
	void log_lst(const type_t[], unsigned long) noexcept(true);

	/**
	 * @brief Log an array as a list
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long DIM>
	void log_lst(const type_t (&)[DIM]) noexcept(true);

	/**
	 * @brief Log an array
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long DIM>
	void log_arr(const type_t (&)[DIM]) noexcept(true);

	/**
	 * @brief Log an array
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL]) noexcept(true);

	/**
	 * @brief Log two arrays
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr_1 Array 1 to log
	 * @param arr_2 Array 2 to log
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL], const type_t (&)[N_LIN]) noexcept(true);

	// Disable assignment operator
	logger& operator = (const logger&) = delete;

private:

	unsigned long _session_id; // Session id number
	std::string _file_path; // File path
	std::ofstream _file; // Logging file
	std::streambuf* _buffer; // Logging buffer
};

// Template file
#include "logger.tpp"

#else

class logger
{
public:

	explicit logger(const char[]) noexcept(false) {}
	logger(const logger&) = delete;
	~logger(void) noexcept(true) {}
	void open_session(void) noexcept(true) {}
	void log_msg(const char[]) noexcept(true) {}

	template <typename type_t>
	void log_lst(const type_t[], unsigned long) noexcept(true) {}

	template <typename type_t, unsigned long DIM>
	void log_lst(const type_t (&)[DIM]) noexcept(true) {}

	template <typename type_t, unsigned long DIM>
	void log_arr(const type_t (&)[DIM]) noexcept(true) {}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL]) noexcept(true) {}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL], const type_t (&)[N_LIN]) noexcept(true) {}

	logger& operator = (const logger&) = delete;
};

#endif

#endif // _LOGGER_HPP_
