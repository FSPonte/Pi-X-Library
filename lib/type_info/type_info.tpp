#ifndef _TYPE_INFO_TPP_
#define _TYPE_INFO_TPP_

namespace pix
{
	template <typename type_t>
	type_info<type_t>::type_info(void) noexcept(true) {}

	template <typename type_t>
	type_info<type_t>::type_info(const type_t val) noexcept(true) {}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<_type_t>& t_inf) const noexcept(true)
	{
		return false;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<type_t>& t_inf) const noexcept(true)
	{
		return true;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<_type_t>& t_inf) const noexcept(true)
	{
		return true;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<type_t>& t_inf) const noexcept(true)
	{
		return false;
	}
}

#endif // _TYPE_INFO_TPP_
