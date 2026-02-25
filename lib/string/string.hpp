#ifndef _STRING_HPP_
#define _STRING_HPP_

// Abstract data types
namespace pix
{
	/**
	 * @brief String
	*/
	class string
	{
	public:

		/**
		 * @brief Default constructor
		*/
		string(void);

		/**
		 * @brief Parameterized constructor
		 * @param c_str C styled string
		 * @throw Pointer to C styled string is null
		*/
		string(const char[]) noexcept(false);

		/**
		 * @brief Copy constructor
		 * @param str String
		 * @throw Pointer to C styled string is null
		*/
		string(const string&) noexcept(false);

		/**
		 * @brief Get data
		 * @return Pointer to array of characters
		*/
		const char* data(void) const;

		/**
		 * @brief Get operator
		 * @param ind Index
		 * @return Indexed characters
		 * @throw Index is out of bounds
		*/
		char operator [] (unsigned long) noexcept(false);

		/**
		 * @brief Get length
		 * @return Number of characters
		*/
		unsigned long length(void) const;

		/**
		 * @brief Invert order of the characters
		*/
		void invert(void) noexcept(true);

		/**
		 * @brief Copy operator
		 * @param c_str C styled string
		 * @throw Pointer to C styled string is null
		*/
		void operator = (const char[]) noexcept(false);

		/**
		 * @brief Copy operator
		 * @param str String
		 * @throw Pointer to C styled string is null
		*/
		void operator = (const string&) noexcept(false);

		/**
		 * @brief Append operator
		 * @param ch Character
		*/
		void operator += (char) noexcept(true);

		/**
		 * @brief Append operator
		 * @param c_str C styled string
		 * @throw Pointer to C styled string is null
		*/
		void operator += (const char[]) noexcept(false);

		/**
		 * @brief Append operator
		 * @param str String
		 * @throw Pointer to C styled string is null
		*/
		void operator += (const string&) noexcept(false);

		/**
		 * @brief Comparisson operator
		 * @param c_str C styled string
		 * @return True if characters are equal
		 * @throw Pointer to C styled string is null
		*/
		bool operator == (const char[]) const noexcept(false);

		/**
		 * @brief Comparisson operator
		 * @param str String
		 * @return True if characters are equal
		 * @throw Pointer to C styled string is null
		*/
		bool operator == (const string&) const noexcept(false);

		/**
		 * @brief Comparisson operator
		 * @param c_str C styled string
		 * @return True if characters are different
		 * @throw Pointer to C styled string is null
		*/
		bool operator != (const char[]) const noexcept(false);

		/**
		 * @brief Comparisson operator
		 * @param str String
		 * @return True if characters are different
		 * @throw Pointer to C styled string is null
		*/
		bool operator != (const string&) const noexcept(false);

		/**
		 * @brief Type casting operator
		 * @return Pointer to array of characters
		*/
		operator const char*() const;

	private:

		char* _data;
		unsigned long _length;
	};

	/**
	 * @brief Convert to string
	 * @param 
	*/
	template <typename type_t>
	pix::string to_string(type_t) noexcept(true);
}

// Template file
#include "string.tpp"

#endif // _STRING_HPP_
