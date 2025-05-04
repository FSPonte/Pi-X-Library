#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

// Dependencies
#include <fstream>
#include <string>
#include <mutex>

constexpr const unsigned long MAX_SESSION_ID = 1E3; // Maximum number of sessions

/**
 * @brief Logger class
*/
class logger
{
private:

	unsigned long _session_id; // Session id number
	std::ofstream _file; // File
	std::mutex _mutex;

public:

	/**
	 * @brief Constructor
	 * @param file_path Path to the log file
	 * @throw Failed to open file
	*/
	explicit logger(const std::string&) noexcept(false);

	// Disable copy constructor
	logger(const logger&) = delete;

	/**
	 * @brief Destructor
	*/
	~logger(void);

	/**
	 * @brief Open a logging session
	 * @throw File is not open
	*/
	void open_session(void) noexcept(false);

	/**
	 * @brief Log a message
	 * @param msg Message to log
	 * @throw File is not open
	*/
	void log_msg(const std::string&) noexcept(false);

	/**
	 * @brief Log an array as a list
	 * @tparam type_t Data type
	 * @param arr Array to log
	 * @param dim Number of elements
	 * @throw File is not open
	*/
	template <typename type_t>
	void log_lst(const type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Log an array as a list
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array to log
	 * @throw File is not open
	*/
	template <typename type_t, unsigned long DIM>
	void log_lst(const type_t (&)[DIM]) noexcept(false);

	/**
	 * @brief Log an array
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array to log
	 * @throw File is not open
	*/
	template <typename type_t, unsigned long DIM>
	void log_arr(const type_t (&)[DIM]) noexcept(false);

	/**
	 * @brief Log an array
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr Array to log
	 * @throw File is not open
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL]) noexcept(false);

	/**
	 * @brief Log two arrays
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr_1 Array 1 to log
	 * @param arr_2 Array 2 to log
	 * @throw File is not open
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL], const type_t (&)[N_LIN]) noexcept(false);

	// Disable assignment operator
	logger& operator = (const logger&) = delete;
};

// Template file
#include "logger.tpp"

#endif // _LOGGER_HPP_
