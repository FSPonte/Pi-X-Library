#ifndef _ASSERTS_HPP_
#define _ASSERTS_HPP_

// Dependencies
#include <types.hpp>

/**
 * @brief Assert pointer is not null
 * @param ptr Pointer
*/
#define assert_not_nullptr(ptr) \
static_assert					\
(								\
	ptr != nullptr,				\
	"Pointer is null"			\
)

/**
 * @brief Assert dimension is not null
 * @param dim Dimension
*/
#define assert_not_nulldim(dim)	\
static_assert					\
(								\
	dim != 0,					\
	"Dimension is null"			\
)

/**
 * @brief Assert data types are the same
 * @param type_1 Data type 1
 * @param type_2 Data type 2
*/
#define assert_is_same(type_1, type_2)	\
static_assert							\
(										\
	is_same(type_1, type_2),			\
	"Not the same data type"			\
)

/**
 * @brief Assert data type is a number
 * @param type Data type
*/
#define assert_is_number(type)			\
static_assert							\
(										\
	is_number(type),					\
	"Non primitive numerical data type"	\
)

/**
 * @brief Assert data type is an integer
 * @param type Data type
*/
#define assert_is_integer(type)			\
static_assert							\
(										\
	is_integer(type),					\
	"Non primitive integer data type"	\
)

/**
 * @brief Assert data type is an float
 * @param type Data type
*/
#define assert_is_float(type)		\
static_assert						\
(									\
	is_float(type),					\
	"Non primitive float data type"	\
)

#endif // _ASSERTS_HPP_
