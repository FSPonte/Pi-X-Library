#ifndef _TYPE_INFO_IPP_
#define _TYPE_INFO_IPP_

#ifndef _IS_SAME_
#define _IS_SAME_

template <typename type_t_1, typename type_t_2>
struct is_same
{ static constexpr bool value = false; };

template <typename type_t>
struct is_same<type_t, type_t>
{ static constexpr bool value = true; };

#endif // _IS_SAME_

#ifndef _IS_NUMBER_
#define _IS_NUMBER_

template <typename type_t>
struct is_number
{ static constexpr bool value = false; };

template <>
struct is_number<short>
{ static constexpr bool value = true; };

template <>
struct is_number<unsigned short>
{ static constexpr bool value = true; };

template <>
struct is_number<int>
{ static constexpr bool value = true; };

template <>
struct is_number<unsigned int>
{ static constexpr bool value = true; };

template <>
struct is_number<long>
{ static constexpr bool value = true; };

template <>
struct is_number<unsigned long>
{ static constexpr bool value = true; };

template <>
struct is_number<long long>
{ static constexpr bool value = true; };

template <>
struct is_number<unsigned long long>
{ static constexpr bool value = true; };

template <>
struct is_number<float>
{ static constexpr bool value = true; };

template <>
struct is_number<double>
{ static constexpr bool value = true; };

template <>
struct is_number<long double>
{ static constexpr bool value = true; };

#endif // _IS_NUMBER_

#ifndef _IS_FLOATING_POINT_
#define _IS_FLOATING_POINT_

template <typename type_t>
struct is_floating_point
{ static constexpr bool value = false; };

template <>
struct is_floating_point<float>
{ static constexpr bool value = true; };

template <>
struct is_floating_point<double>
{ static constexpr bool value = true; };

template <>
struct is_floating_point<long double>
{ static constexpr bool value = true; };

#endif // _IS_FLOATING_POINT_

namespace pix
{
    template <typename type_t>
    type_info<type_t>::type_info(void) {}

    template <typename type_t>
    type_info<type_t>::type_info(const type_t val) {}

    template <typename type_t>
    constexpr const bool type_info<type_t>::operator == (const type_info<type_t>& t_inf) const
    { return true; }

    template <typename type_t>
    template <typename _type_t>
    constexpr const bool type_info<type_t>::operator == (const type_info<_type_t>& t_inf) const
    { return false; }

    template <typename type_t>
    constexpr const bool type_info<type_t>::operator != (const type_info<type_t>& t_inf) const
    { return false; }

    template <typename type_t>
    template <typename _type_t>
    constexpr const bool type_info<type_t>::operator != (const type_info<_type_t>& t_inf) const
    { return true; }
}

#endif // _TYPE_INFO_IPP_