#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

// Dependencies
#include <fstream>
#include <string>
#include <mutex>

/**
 * @brief Logger class
*/
class logger
{
private:

	std::ofstream _file;
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
	 * @brief Log a message
	 * @param msg Message to log
	*/
	void log_msg(const std::string&);

	/**
	 * @brief Log a message
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long DIM>
	void log_arr(const type_t (&)[DIM]);

	/**
	 * @brief Log a message
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL]);

	/**
	 * @brief Log a message
	 * @tparam type_t Data type
	 * @tparam N_LIN Number of lines
	 * @tparam N_COL Number of columns
	 * @param arr Array to log
	*/
	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void log_arr(const type_t (&)[N_LIN][N_COL], const type_t (&)[N_LIN]);

	// Disable assignment operator
	logger& operator = (const logger&) = delete;
};

// Template file
#include "logger.tpp"

#endif // _LOGGER_HPP_
