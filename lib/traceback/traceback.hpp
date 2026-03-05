#ifndef __TRACEBACK_HPP__
#define __TRACEBACK_HPP__

// Dependencies
#include <macros.hpp>
#include <string>
#include <vector>

namespace pix
{
	struct trace_point
	{
		std::string
			_fn_name,
			_file_path;
		unsigned long _line_number;

		bool operator == (const trace_point&) const noexcept(true);
	};

	/**
	 * @brief Traceback class
	*/
	template <bool ENABLED = TRACEBACK_ENABLED>
	class traceback;

	template <>
	class traceback<true>
	{
	public:

		/**
		 * @brief Constructor
		*/
		traceback(void) noexcept(true) = default;

		/**
		 * @brief Copy constructor
		 * @param rt Route
		*/
		traceback(const traceback&) noexcept(true);

		/**
		 * @brief Initialize
		 * @param fn_name Name of the function
		 * @param file_name Name of the file
		 * @param lin Line number
		*/
		void init(const std::string&, const std::string&, unsigned long) noexcept(true);

		/**
		 * @brief Trigger the traceback
		 * @param line_number Number of the line
		*/
		void trigger(unsigned long) noexcept(true);

		/**
		 * @brief Print the traceback
		*/
		void print(void) const noexcept(true);

		/**
		 * @brief Copy operator
		 * @param rt Traceback route
		*/
		void operator = (const traceback&) noexcept(true);

	private:

		std::vector<trace_point> _data;
	};

	template <>
	class traceback<false>
	{
	public:

		traceback(void) noexcept(true) {}
		traceback(const std::string&, const std::string&) noexcept(true) {}
		traceback(const traceback&) noexcept(true) {}
		void init(const std::string&, const std::string&) noexcept(true) {}
		void trigger(unsigned long) noexcept(true) {}
		std::string get(void) const noexcept(true) { return ""; }
		void print(void) const noexcept(true) {}
		void operator = (const traceback&) noexcept(true) {}
	};
}

#endif // __TRACEBACK_HPP__
