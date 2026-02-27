#ifndef _TRACEBACK_HPP_
#define _TRACEBACK_HPP_

// Dependencies
#include <fstream>
#include <vector>

namespace pix
{
	/**
	 * @brief Traceback class
	*/
	template <bool ENABLED = false>
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
		 * @brief Initialize
		 * @param file_name Name of the file
		 * @param fn_name Name of the function
		*/
		void init(const std::string&, const std::string&) noexcept(true);

		/**
		 * @brief Trigger the traceback
		 * @param line_number Number of the line
		*/
		void trigger(unsigned long) noexcept(true);

		/**
		 * @brief Get route
		 * @return Route
		*/
		std::string get(void) const noexcept(true);

		/**
		 * @brief Display the traceback
		*/
		void display(void) const noexcept(true);

		/**
		 * @brief Copy operator
		 * @param rt Traceback route
		*/
		void operator = (const traceback&) noexcept(true);

	private:

		std::string
			_file_path,
			_fn_name;
		unsigned long _line_number;
	};

	template <>
	class traceback<false>
	{
	public:

		traceback(void) noexcept(true) {}
		void init(const std::string&, const std::string&) noexcept(true) {}
		void trigger(unsigned long) noexcept(true) {}
		std::string get(void) const noexcept(true) { return ""; }
		void display(void) const noexcept(true) {}
		void operator = (const traceback&) noexcept(true) {}
	};
}

#endif // _TRACEBACK_HPP_
