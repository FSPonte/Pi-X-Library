// Header file
#include "logger.hpp"

// Dependencies
#include <iostream>

logger::logger(const std::string& file_path) noexcept(false)
{
	this->_file.open(file_path, std::ios::out | std::ios::trunc);

	if (!this->_file.is_open())
		throw "[Logger] Failed to open file: " + file_path;

	this->_session_id = 0;
}

logger::~logger(void)
{
	this->_file.close();
}

void logger::open_session(void)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	if (!this->_file.is_open())
		throw "[Logger] File is not open";

	if (this->_session_id != 0)
		this->_file << '\n';
	
	this->_file
		<< "====================\n"
		<< "[LOGGER] Session ID: " << ++this->_session_id << '\n'
		<< "====================\n\n";
}

void logger::log_msg(const std::string& msg) noexcept(false)
{
    std::lock_guard<std::mutex> lock(this->_mutex);

    if (!this->_file.is_open())
		throw "[Logger] File is not open";

	this->_file << msg << std::endl;
}
