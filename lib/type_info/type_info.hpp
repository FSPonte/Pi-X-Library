#ifndef _TYPE_INFO_HPP_
#define _TYPE_INFO_HPP_

namespace pix
{
	/**
	 * @brief Information of data types
	 * @tparam type_t Data type
	 * @note Template parameter meant to be implicit
	*/
	template <typename type_t>
	class type_info
	{
	public:

		/**
		 * @brief Default constructor
		*/
		type_info(void) noexcept(true);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		type_info(type_t) noexcept(true);

		/**
		 * @brief Equality operator
		 * @tparam _type_t Data type
		 * @param t_inf Object
		 * @return False
		*/
		template <typename _type_t>
		constexpr bool operator == (const type_info<_type_t>&) const noexcept(true);

		/**
		 * @brief Equality operator
		 * @param t_inf Object
		 * @return True
		*/
		constexpr bool operator == (const type_info<type_t>&) const noexcept(true);

		/**
		 * @brief Inequality operator
		 * @tparam _type_t Data type
		 * @param t_inf Object
		 * @return True
		*/
		template <typename _type_t>
		constexpr bool operator != (const type_info<_type_t>&) const noexcept(true);

		/**
		 * @brief Inequality operator
		 * @param t_inf Object
		 * @return False
		*/
		constexpr bool operator != (const type_info<type_t>&) const noexcept(true);
	};
}

// Template file
#include "type_info.tpp"

#endif // _TYPE_INFO_HPP_
