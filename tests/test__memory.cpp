// Header file
#include "tests.hpp"

// Debugger
#include <debugger.hpp>

// Test target
#include <memory.hpp>

static void memcpy(void) noexcept(false);
static void realloc(void) noexcept(false);
static void extend(void) noexcept(false);
static void mmap__add(void) noexcept(false);
static void mmap__rm(void) noexcept(false);
static void mmap__operator_subscript(void) noexcept(false);
static void mmap__size(void) noexcept(false);

void test__memory(void) noexcept(false)
{
	debugger::__tester__.init(__FUNCTION__);
	fn_test tests[] = {
		&memcpy,
		&realloc,
		&extend
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

static void memcpy(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	const unsigned long SIZE = 5;
	char
		arr[SIZE] = {1, 2, 3, 4, 5},
		target[SIZE] = {0, 0, 0, 0, 0};
	pix::memory::memcpy(arr, target, SIZE);
	bool result = true;

	for (unsigned long i = 0; i < SIZE; ++i)
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

static void realloc(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	const unsigned long SIZE = 5;
	char
		arr[SIZE] = {1, 2, 3, 4, 5},
		target[SIZE] = {0, 0, 0, 0, 0};
	pix::memory::memcpy(arr, target, SIZE);
	bool result = true;

	for (unsigned long i = 0; i < SIZE; ++i)
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

static void extend(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	const unsigned long SIZE = 5;
	char
		arr[SIZE] = {1, 2, 3, 4, 5},
		target[SIZE] = {0, 0, 0, 0, 0};
	pix::memory::memcpy(arr, target, SIZE);
	bool result = true;

	for (unsigned long i = 0; i < SIZE; ++i)
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

static void mmap__add(void) noexcept(false);
static void mmap__rm(void) noexcept(false);
static void mmap__operator_subscript(void) noexcept(false);
static void mmap__size(void) noexcept(false);
