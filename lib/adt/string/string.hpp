#ifndef _STRING_HPP_
#define _STRING_HPP_

namespace pix::adt
{
	/**
	 * @brief String
	 * @tparam MAX_LENGTH Maximum number of characters
	*/
	template <unsigned long MAX_LENGTH>
	class string
	{
	private:

		char _data[MAX_LENGTH];
		unsigned long _length;

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
		string(const string<MAX_LENGTH>&) noexcept(false);

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
		 * @brief Get maximum length
		 * @return Maximum number of characters
		*/
		constexpr unsigned long max_length(void) const;

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
		void operator = (const string<MAX_LENGTH>&) noexcept(false);

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
		void operator += (const string<MAX_LENGTH>&) noexcept(false);

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
		bool operator == (const string<MAX_LENGTH>&) const noexcept(false);

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
		bool operator != (const string<MAX_LENGTH>&) const noexcept(false);

		/**
		 * @brief Type casting operator
		 * @return Pointer to array of characters
		*/
		operator const char*() const;
	};
}

// Template file
#include "string.tpp"

#endif // _STRING_HPP_
