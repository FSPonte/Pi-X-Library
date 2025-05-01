// Header file
#include "logger.hpp"

// Dependencies
#include <iostream>

logger::logger(const std::string& file_path) noexcept(false)
{
    this->_file.open(file_path, std::ios::out);

	if (!this->_file.is_open())
		throw "[Logger] Failed to open file: " + file_path;
}

logger::~logger(void)
{
    if (this->_file.is_open())
        this->_file.close();
}

void logger::log_msg(const std::string& msg) noexcept(false)
{
    std::lock_guard<std::mutex> lock(this->_mutex);

    if (!this->_file.is_open())
		throw "[Logger] File is not open";

	this->_file << msg << std::endl;
}
