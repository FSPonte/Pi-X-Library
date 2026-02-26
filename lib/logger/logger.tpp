#ifndef _LOGGER_TPP_
#define _LOGGER_TPP_

namespace pix
{
	logger::~logger(void) noexcept(true)
	{
		this->_file.close();
		std::clog.rdbuf(this->_buffer);
	}
	
	void logger::init(const std::string& file_path) noexcept(false)
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

	void logger::open_session(void) noexcept(false)
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

	void logger::log_message(const std::string& msg) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";
		
		std::clog << msg << std::endl;
	}

	template <typename type_t, unsigned long DIM>
	void logger::log_list(const type_t (&arr)[DIM]) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";

		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << i << " : " << arr[i] << '\n';
	}

	template <typename type_t, unsigned long DIM>
	void logger::log_array(const type_t (&arr)[DIM]) noexcept(false)
	{
		if (!this->_file.is_open())
			throw "[Logger] File not open";
		
		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << arr[i] << ' ';

		std::clog << '\n';
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void logger::log_array(const type_t (&arr)[N_LIN][N_COL]) noexcept(false)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
			this->log_array(arr[i]);
	}
}

#endif // _LOGGER_TPP_
