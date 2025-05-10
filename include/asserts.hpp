#ifndef _ASSERTS_HPP_
#define _ASSERTS_HPP_

// Dependencies
#include <types.hpp>

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
 * @brief Static assertion for is_float
 * @param type Data type
*/
#define is_float_static_assert(type) \
static_assert                        \
(                                    \
	is_float(type),                  \
	"Non primitive float data type"  \
)

#endif // _ASSERTS_HPP_
