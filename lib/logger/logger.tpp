#ifndef _LOGGER_TPP_
#define _LOGGER_TPP_

template <typename type_t>
void logger::log_lst(const type_t arr[], const unsigned long DIM) noexcept(false)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	if (!this->_file.is_open())
		throw "[Logger] File is not open";

	for (unsigned long i = 0; i < DIM; ++i)
		this->_file << i << " : " << arr[i] << '\n';
}

template <typename type_t, unsigned long DIM>
void logger::log_lst(const type_t (&arr)[DIM]) noexcept(false)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	this->log_lst(arr, DIM);
}

template <typename type_t, unsigned long DIM>
void logger::log_arr(const type_t (&arr)[DIM]) noexcept(false)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	if (!this->_file.is_open())
		throw "[Logger] File is not open";

	for (unsigned long i = 0; i < DIM; ++i)
		this->_file << arr[i] << ' ';

	this->_file << '\n';
}

template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
void logger::log_arr(const type_t (&arr)[N_LIN][N_COL]) noexcept(false)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	if (!this->_file.is_open())
		throw "[Logger] File is not open";

	for (unsigned long i = 0; i < N_LIN; ++i)
	{
		for (unsigned long j = 0; j < N_COL; ++j)
			this->_file << arr[i][j] << ' ';

		this->_file << '\n';
	}
}

template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
void logger::log_arr(const type_t (&mtx)[N_LIN][N_COL], const type_t (&vec)[N_LIN]) noexcept(false)
{
	std::lock_guard<std::mutex> lock(this->_mutex);

	if (!this->_file.is_open())
		throw "[Logger] File is not open";

	for (unsigned long i = 0; i < N_LIN; ++i)
	{
		for (unsigned long j = 0; j < N_COL; ++j)
			this->_file << mtx[i][j] << ' ';

		this->_file << "| " << vec[i] << '\n';
	}
}

#endif // _LOGGER_TPP_