#ifndef _TRACEBACK_HPP_
#define _TRACEBACK_HPP_

#if __has_include(<fstream>) && __has_include(<vector>)

// Dependencies
#include <fstream>
#include <vector>

namespace pix
{
	struct traceback_item;

	/**
	 * @brief Traceback class
	*/
	class traceback
	{
	public:

		traceback(const traceback&) = delete; // Copy constructor
		void operator=(const traceback&) = delete; // Copy operator

		/**
		 * @brief Add traceback
		 * @param file_name Name of the file
		 * @param fn_name Name of the function
		*/
		static void add(const std::string&, const std::string&, int = -1) noexcept(true);

		/**
		 * @brief Display the traceback
		*/
		static void display(void) noexcept(true);

	private:

		traceback(void) = default; // Default constructor
		~traceback(void) = default; // Destructor

		static std::vector<traceback_item> _data; // Member variable, not static
	};
}

// Template file
#include "traceback.tpp"

#else

namespace pix
{
	class traceback
	{
	public:

		traceback(const traceback&) = delete; // Copy constructor
		void operator=(const traceback&) = delete; // Copy operator
		static traceback& get_instance(void) noexcept(true) {}
		void add(const std::string&, const std::string&) noexcept(true) {}
		void display(void) const noexcept(true) {}
	};
}

#endif

#endif // _TRACEBACK_HPP_
