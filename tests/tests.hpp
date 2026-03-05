#ifndef __TESTS_HPP__
#define __TESTS_HPP__

// Dependencies
#include <macros.hpp>
#include <traceback.hpp>
#include <exception.hpp>
#include <logger.hpp>
#include <progress_bar.hpp>
#include <tester.hpp>

typedef void (*fn_test)(void) noexcept(false);

void test__type_info(void) noexcept(false);
void test__c_array(void) noexcept(false);
void test__memory(void) noexcept(false);

#endif // __TESTS_HPP__
