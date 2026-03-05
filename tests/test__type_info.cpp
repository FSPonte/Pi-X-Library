// Header file
#include "tests.hpp"

// Debugger
#include <debugger.hpp>

// Test target
#include <type_info.hpp>

static void operator_equality(void) noexcept(false);
static void operator_inequality(void) noexcept(false);

void test__type_info(void) noexcept(false)
{
	DEBUG_TESTER_INIT;
	fn_test tests[] = {
		&operator_equality,
		&operator_inequality
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

static void operator_equality(void) noexcept(false)
{
	DEBUG_TESTER_START;

	{
		char var;
		pix::type_info obj(var);

		if (obj == var)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	{
		char var_1 = 'a';
		int var_2;
		pix::type_info obj(var_1);

		if (obj == var_2)
			DEBUG_TESTER_FAIL;
		else
			DEBUG_TESTER_PASS;
	}

	{
		char var;
		pix::type_info<char> obj;

		if (obj == var)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	{
		char var;
		pix::type_info<int> obj;

		if (obj == var)
			DEBUG_TESTER_FAIL;
		else
			DEBUG_TESTER_PASS;
	}
}

static void operator_inequality(void) noexcept(false)
{
	DEBUG_TESTER_START;

	{
		char var;
		pix::type_info obj(var);

		if (obj != var)
			DEBUG_TESTER_FAIL;
		else
			DEBUG_TESTER_PASS;
	}

	{
		char var_1 = 'a';
		int var_2;
		pix::type_info obj(var_1);

		if (obj != var_2)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	{
		char var;
		pix::type_info<char> obj;

		if (obj != var)
			DEBUG_TESTER_FAIL;
		else
			DEBUG_TESTER_PASS;
	}

	{
		char var;
		pix::type_info<int> obj;

		if (obj != var)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}
}
