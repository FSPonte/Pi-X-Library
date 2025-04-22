#ifndef _ASSERTS_HPP_
#define _ASSERTS_HPP_

/**
 * @brief Assert pointer is not null
 * @param ptr Pointer
*/
#define assert_not_nullptr(ptr) \
	static_assert(ptr != nullptr, "Pointer is null")

/**
 * @brief Assert dimension is not null
 * @param dim Dimension
*/
#define assert_not_nulldim(dim) \
	static_assert(dim != 0, "Dimension is null")

#endif // _ASSERTS_HPP_
