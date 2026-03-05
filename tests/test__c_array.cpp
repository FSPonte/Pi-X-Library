// Header file
#include "tests.hpp"

// Debugger
#include <debugger.hpp>

// Test target
#include <c_array.hpp>

static void swap(void) noexcept(false);
static void invert(void) noexcept(false);
static void copy(void) noexcept(false);
static void move(void) noexcept(false);
static void left_shift(void) noexcept(false);
static void right_shift(void) noexcept(false);
static void bit_rev(void) noexcept(false);
static void binary_search(void) noexcept(false);
static void strlen(void) noexcept(false);

void test__c_array(void) noexcept(false)
{
	debugger::__tester__.init(__FUNCTION__);
	fn_test tests[] = {
		&swap,
		&invert
	};
	const unsigned long NUM_TESTS = array_size(tests);
	pix::progress_bar pgb(__FUNCTION__, 0, NUM_TESTS);

	for (unsigned long i = 0; i < NUM_TESTS; ++i)
	{
		try
		{
			tests[i]();
			pgb.update(i);
		}
		catch (const pix::exception::excep& e)
		{
			std::cout << ' ';
			e.print();
		}
	}

	pgb.finish();
}

static void swap(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	// Reference test
	{
		char
			var_1 = 'a',
			var_2 = 'b';
		pix::c_array::swap(var_1, var_2);

		if (var_1 == 'b' && var_2 == 'a')
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}

	// Pointer test
	{
		char
			var_1 = 'a',
			var_2 = 'b';
		char
			*ptr_1 = &var_1,
			*ptr_2 = &var_2;
		pix::c_array::swap(ptr_1, ptr_2);

		if (ptr_1 == &var_2 && ptr_2 == &var_1)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}
}

static void invert(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	// Test #1
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {5, 4, 3, 2, 1};
		const unsigned long DIM = array_size(arr);
		pix::c_array::invert(arr, DIM);
		bool result = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] == target[i])
				continue;
			
			result = false;
		}

		if (result)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}

	// Test #2
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {5, 4, 3, 2, 1};
		const unsigned long DIM = array_size(arr);
		pix::c_array::invert(arr);
		bool result = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] == target[i])
				continue;
			
			result = false;
		}

		if (result)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}
}

static void copy(void) noexcept(false);
static void move(void) noexcept(false);
static void left_shift(void) noexcept(false);
static void right_shift(void) noexcept(false);
static void bit_rev(void) noexcept(false);
static void binary_search(void) noexcept(false);
static void strlen(void) noexcept(false);