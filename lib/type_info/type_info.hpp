#ifndef _TYPE_INFO_HPP_
#define _TYPE_INFO_HPP_

/**
 * @brief Comparison between two data types
 * @param type_1 Data type 1
 * @param type_2 Data type 2
 * @return True if arguments have the same data type
*/
#define is_same(type_1, type_2) is_same<type_1, type_2>::value

/**
 * @brief Static assertion for is_same
 * @param type_1 Data type 1
 * @param type_2 Data type 2
*/
#define is_same_static_assert(type_1, type_2) \
static_assert                                 \
(                                             \
	is_same(type_1, type_2),                  \
	"Not the same data type"                  \
)

/**
 * @brief Checks type for primitive numerical data type
 * @param type Data type
 * @return True if is a primitive numerical data type
*/
#define is_number(type) is_number<type>::value

/**
 * @brief Static assertion for is_number
 * @param type Data type
*/
#define is_number_static_assert(type)   \
static_assert                           \
(                                       \
	is_number(type),                    \
	"Non primitive numerical data type" \
)

/**
 * @brief Checks type for primitive integer numerical data type
 * @param type Data type
 * @return True if is a primitive integer numerical data type
*/
#define is_integer(type) is_integer<type>::value

/**
 * @brief Static assertion for is_integer
 * @param type Data type
*/
#define is_integer_static_assert(type) \
static_assert                          \
(                                      \
	is_integer(type),                  \
	"Non primitive integer data type"  \
)

/**
 * @brief Checks type for primitive floating point numerical data type
 * @param type Data type
 * @return True if is a primitive floating point numerical data type
*/
#define is_float(type) is_float<type>::value

/**
 * @brief Static assertion for is_float
 * @param type Data type
*/
#define is_float_static_assert(type) \
static_assert                        \
(                                    \
	is_float(type),                  \
	"Non primitive float data type"  \
)

namespace pix
{
	/**
	 * @brief Information of data types
	 * @tparam type Data type
	 * @note Template parameter meant to be implicit
	*/
	template <typename type_t>
	class type_info
	{
	public:

		/**
		 * @brief Default constructor
		*/
		type_info(void);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		type_info(type_t);

		/**
		 * @brief Equality operator
		 * @tparam _type_t Data type
		 * @param t_inf Object
		 * @return True if types are equal
		*/
		template <typename _type_t>
		constexpr bool operator == (const type_info<_type_t>&) const;

		/**
		 * @brief Equality operator
		 * @param t_inf Object
		 * @return True if types are equal
		*/
		constexpr bool operator == (const type_info<type_t>&) const;

		/**
		 * @brief Inequality operator
		 * @tparam _type_t Data type
		 * @param t_inf Object
		 * @return True if types are different
		*/
		template <typename _type_t>
		constexpr bool operator != (const type_info<_type_t>&) const;

		/**
		 * @brief Inequality operator
		 * @param t_inf Object
		 * @return True if types are different
		*/
		constexpr bool operator != (const type_info<type_t>&) const;
	};
}

// Template file
#include "type_info.tpp"

#endif // _TYPE_INFO_HPP_
