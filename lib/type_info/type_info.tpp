#ifndef _TYPE_INFO_TPP_
#define _TYPE_INFO_TPP_

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

namespace pix
{
	template <typename type_t>
	type_info<type_t>::type_info(void) {}

	template <typename type_t>
	type_info<type_t>::type_info(const type_t VAL) {}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<_type_t>& T_INF) const
	{
		return false;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<type_t>& T_INF) const
	{
		return true;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<_type_t>& T_INF) const
	{
		return true;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<type_t>& T_INF) const
	{
		return false;
	}
}

#endif // _TYPE_INFO_TPP_
