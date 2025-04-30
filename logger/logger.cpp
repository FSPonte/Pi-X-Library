// Header file
#include "logger.hpp"

// Dependencies
#include <iostream>

logger::logger(const std::string& file_path) noexcept(false)
{
    this->_file.open(file_path, std::ios::out);

	if (!this->_file.is_open())
        throw std::ios_base::failure("Logger error: Failed to open file: " + file_path);
}

logger::~logger(void)
{
    if (this->_file.is_open())
        this->_file.close();
}

void logger::log(const std::string& msg)
{
    std::lock_guard<std::mutex> lock(this->_mutex);

    if (this->_file.is_open())
        this->_file << msg << std::endl;
    else
        std::cerr << "Logger error: File is not open" << std::endl;
}
