#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#if LOGGER_ENABLED && __has_include(<fstream>)

// Dependencies
#include <fstream>

namespace pix
{
	/**
	 * @brief Logger class
	*/
	class logger
	{
	public:

		// Constructor
		logger(void) = default;

		// Copy constructor
		logger(const logger&) = delete;

		/**
		 * @brief Destructor
		*/
		~logger(void) noexcept(true);

		/**
		 * @brief Initialize the logger
		 * @param path Path to file
		 * @throw Failed to open file
		*/
		void init(const std::string&) noexcept(false);

		/**
		 * @brief Open a logging session
		 * @throw File not open
		*/
		void open_session(void) noexcept(false);

		/**
		 * @brief Log a message
		 * @param msg Message to log
		 * @throw File not open
		*/
		void log_message(const std::string&) noexcept(false);

		/**
		 * @brief Log an array as a list
		 * @tparam type_t Data type
		 * @param arr Array to log
		 * @param dim Number of elements
		 * @throw File not open
		*/
		template <typename type_t, unsigned long DIM>
		void log_list(const type_t (&)[DIM]) noexcept(false);

		/**
		 * @brief Log an array
		 * @tparam type_t Data type
		 * @tparam DIM Number of elements
		 * @param arr Array to log
		 * @throw File not open
		*/
		template <typename type_t, unsigned long DIM>
		void log_array(const type_t (&)[DIM]) noexcept(false);

		/**
		 * @brief Log an array
		 * @tparam type_t Data type
		 * @tparam N_LIN Number of lines
		 * @tparam N_COL Number of columns
		 * @param arr Array to log
		 * @throw File not open
		*/
		template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
		void log_array(const type_t (&)[N_LIN][N_COL]) noexcept(false);

		// Disable assignment operator
		void operator = (const logger&) = delete;

	private:

		unsigned long _session_id; // Session id number
		std::string _file_path; // Path for the file
		std::ofstream _file; // Logging file
		std::streambuf* _buffer; // Logging buffer
	};
}

// Template file
#include "logger.tpp"

#else

namespace pix
{
	class logger
	{
	public:

		logger(void) = default;
		logger(const logger&) = delete;
		~logger(void) noexcept(true) {}

		void init(const char[]) noexcept(true);
		void open_session(void) noexcept(true) {}

		void log_message(const char[]) noexcept(true) {}

		template <typename type_t, unsigned long DIM>
		void log_array(const type_t (&)[DIM]) noexcept(true) {}

		template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
		void log_array(const type_t (&)[N_LIN][N_COL]) noexcept(true) {}

		void operator = (const logger&) = delete;
	};
}

#endif

#endif // _LOGGER_HPP_
