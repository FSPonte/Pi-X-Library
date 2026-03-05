#ifndef __TYPE_INFO_TPP__
#define __TYPE_INFO_TPP__

#include <iostream>

namespace pix
{
	template <typename type_t>
	type_info<type_t>::type_info(void) noexcept(true) {}

	template <typename type_t>
	type_info<type_t>::type_info(const type_t) noexcept(true) {}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator == (const type_t&) const noexcept(true)
	{
		return true;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator == (const _type_t&) const noexcept(true)
	{
		return false;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<type_t>&) const noexcept(true)
	{
		return true;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator == (const type_info<_type_t>&) const noexcept(true)
	{
		return false;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator != (const type_t&) const noexcept(true)
	{
		return false;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator != (const _type_t&) const noexcept(true)
	{
		return true;
	}

	template <typename type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<type_t>&) const noexcept(true)
	{
		return false;
	}

	template <typename type_t>
	template <typename _type_t>
	constexpr bool type_info<type_t>::operator != (const type_info<_type_t>&) const noexcept(true)
	{
		return true;
	}
}

#endif // __TYPE_INFO_TPP__
