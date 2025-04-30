#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

// Dependencies
#include <fstream>
#include <string>
#include <mutex>

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
	void log(const std::string&);

	// Disable assignment operator
	logger& operator = (const logger&) = delete;
};

#endif // _LOGGER_HPP_
