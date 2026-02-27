// Header file
#include "logger.hpp"

namespace pix
{
	logger<true>::~logger(void) noexcept(true)
	{
		this->_file.close();
		std::clog.rdbuf(this->_buffer);
	}
	
	void logger<true>::init(const std::string& file_path) noexcept(false)
	{
		if (this->_file.is_open())
			this->_file.close();
		
		this->_file_path = file_path;
		this->_file.open(this->_file_path, std::ios::out | std::ios::trunc);

		if (!this->_file.is_open())
			throw "[Logger] Failed to open file";

		this->_session_id = 0;
		this->_buffer = std::clog.rdbuf();
		std::clog.rdbuf(this->_file.rdbuf());
	}

	void logger<true>::open_session(void) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";

		if (this->_session_id != 0)
			std::clog << '\n';

		std::string line_1, line_2;

		line_1 = "[LOGGER] Session ID: " + std::to_string(++this->_session_id);
		line_2 = "file_path: " + this->_file_path;

		const unsigned long
			line_1_length = line_1.length(),
			line_2_length = line_2.length();

		const unsigned long LINE_WIDTH = (line_1_length > line_2_length) ? line_1_length : line_2_length;
		
		std::clog
			<< std::string(LINE_WIDTH, '=') << '\n'
			<< line_1 << '\n'
			<< line_2 << '\n'
			<< std::string(LINE_WIDTH, '=') << "\n\n";
	}

	void logger<true>::log_message(const std::string& msg) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";
		
		std::clog << msg << std::endl;
	}
}
