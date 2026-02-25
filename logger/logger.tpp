#ifndef _LOGGER_TPP_
#define _LOGGER_TPP_

namespace pix
{
	logger::logger(const char file_path[]) noexcept(false)
	{
		this->_file.open(file_path, std::ios::out | std::ios::trunc);

		if (!this->_file.is_open())
			throw "[Logger] Failed to open file";

		this->_session_id = 0;
		this->_buffer = std::clog.rdbuf();
		std::clog.rdbuf(this->_file.rdbuf());
	}

	logger::~logger(void) noexcept(true)
	{
		this->_file.close();
		std::clog.rdbuf(this->_buffer);
	}

	void logger::open_session(void) noexcept(true)
	{
		if (this->_session_id != 0)
			std::clog << '\n';
		
		std::clog
			<< "====================\n"
			<< "[LOGGER] Session ID: " << ++this->_session_id << '\n'
			<< "====================\n\n";
	}

	void logger::log_msg(const char msg[]) noexcept(true)
	{
		std::clog << msg << std::endl;
	}

	template <typename type_t>
	void logger::log_lst(const type_t arr[], const unsigned long DIM) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << i << " : " << arr[i] << '\n';
	}

	template <typename type_t, unsigned long DIM>
	void logger::log_lst(const type_t (&arr)[DIM]) noexcept(true)
	{
		this->log_lst(arr, DIM);
	}

	template <typename type_t, unsigned long DIM>
	void logger::log_arr(const type_t (&arr)[DIM]) noexcept(true)
	{
		for (unsigned long i = 0; i < DIM; ++i)
			std::clog << arr[i] << ' ';

		std::clog << '\n';
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void logger::log_arr(const type_t (&arr)[N_LIN][N_COL]) noexcept(true)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
				std::clog << arr[i][j] << ' ';

			std::clog << '\n';
		}
	}

	template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
	void logger::log_arr(const type_t (&mtx)[N_LIN][N_COL], const type_t (&vec)[N_LIN]) noexcept(true)
	{
		for (unsigned long i = 0; i < N_LIN; ++i)
		{
			for (unsigned long j = 0; j < N_COL; ++j)
				std::clog << mtx[i][j] << ' ';

			std::clog << "| " << vec[i] << '\n';
		}
	}
}

#endif // _LOGGER_TPP_
