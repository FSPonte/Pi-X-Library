#ifndef _TYPES_HPP_
#define _TYPES_HPP_

/**
 * @brief Comparison between two data types
 * @param type_1 Data type 1
 * @param type_2 Data type 2
 * @return True if arguments have the same data type
*/
#define is_same(type_1, type_2) pix::types::is_same<type_1, type_2>::VALUE

/**
 * @brief Checks type for primitive numerical data type
 * @param type Data type
 * @return True if is a primitive numerical data type
*/
#define is_number(type) pix::types::is_number<type>::VALUE

/**
 * @brief Checks type for primitive integer numerical data type
 * @param type Data type
 * @return True if is a primitive integer numerical data type
*/
#define is_integer(type) pix::types::is_integer<type>::VALUE

/**
 * @brief Checks type for primitive floating point numerical data type
 * @param type Data type
 * @return True if is a primitive floating point numerical data type
*/
#define is_float(type) pix::types::is_float<type>::VALUE

// Data types
namespace pix::types
{
	typedef unsigned char byte_t;
	typedef const char* c_str_t;
	typedef unsigned long int size_t;
	typedef signed char int8_t;
	typedef unsigned char uint8_t;
	typedef short int16_t;
	typedef unsigned short uint16_t;
	typedef int int32_t;
	typedef unsigned int uint32_t;
	typedef long int int64_t;
	typedef unsigned long int uint64_t;
	typedef long double double_t;

	template <typename type_t_1, typename type_t_2>
	struct is_same
	{
		static constexpr const bool VALUE = false;
	};

	template <typename type_t>
	struct is_same<type_t, type_t>
	{
		static constexpr const bool VALUE = true;
	};

	template <typename type_t>
	struct is_number
	{
		static constexpr const bool VALUE = false;
	};

	template <>
	struct is_number<short>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<unsigned short>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<int>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<unsigned int>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<long>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<unsigned long>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<long long>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<unsigned long long>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<float>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<double>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_number<long double>
	{
		static constexpr const bool VALUE = true;
	};

	template <typename type_t>
	struct is_integer
	{
		static constexpr const bool VALUE = false;
	};

	template <>
	struct is_integer<short>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_integer<unsigned short>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_integer<int>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_integer<unsigned int>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_integer<long>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_integer<unsigned long>
	{
		static constexpr const bool VALUE = true;
	};

	template <typename type_t>
	struct is_float
	{
		static constexpr const bool VALUE = false;
	};

	template <>
	struct is_float<float>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_float<double>
	{
		static constexpr const bool VALUE = true;
	};

	template <>
	struct is_float<long double>
	{
		static constexpr const bool VALUE = true;
	};
}

#endif // _TYPES_HPP_
