#ifndef _TYPE_INFO_IPP_
#define _TYPE_INFO_IPP_

// Dependencies
#include <types.hpp>

using namespace pix;
using namespace pix::types;

template <typename type_t_1, typename type_t_2>
struct is_same
{ static constexpr bool value = false; };

template <typename type_t>
struct is_same<type_t, type_t>
{ static constexpr bool value = true; };

template <typename type_t>
struct is_number
{ static constexpr bool value = false; };

template <>
struct is_number<int>
{ static constexpr bool value = true; };

template <>
struct is_number<unsigned int>
{ static constexpr bool value = true; };

template <>
struct is_number<float>
{ static constexpr bool value = true; };

template <>
struct is_number<double>
{ static constexpr bool value = true; };

template <>
struct is_number<double_t>
{ static constexpr bool value = true; };

template <typename type_t>
type_info<type_t>::type_info(void) {}

template <typename type_t>
type_info<type_t>::type_info(const type_t val) {}

template <typename type_t>
bool type_info<type_t>::operator == (const type_info<type_t>& t_inf)
{ return true; }

template <typename type_t>
template <typename _type_t>
bool type_info<type_t>::operator == (const type_info<_type_t>& t_inf)
{ return false; }

template <typename type_t>
bool type_info<type_t>::operator != (const type_info<type_t>& t_inf)
{ return false; }

template <typename type_t>
template <typename _type_t>
bool type_info<type_t>::operator != (const type_info<_type_t>& t_inf)
{ return true; }

#endif // _TYPE_INFO_IPP_