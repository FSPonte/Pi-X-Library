#ifndef _TESTS_HPP_
#define _TESTS_HPP_

// Dependencies
#include <traceback.hpp>
#include <exception.hpp>
#include <logger.hpp>
#include <progress_bar.hpp>
#include <tester.hpp>

typedef void (*fn_unit_test)(void) noexcept(false);
typedef tester (*fn_test)(void) noexcept(false);

tester test__type_info(void) noexcept(false);

#endif // _TESTS_HPP_
