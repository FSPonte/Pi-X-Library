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
	debugger::__tester__.init(__FUNCTION__);
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
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	{
		char var;
		pix::type_info obj(var);

		if (obj == var)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}

	{
		char var_1 = 'a';
		int var_2;
		pix::type_info obj(var_1);

		if (obj == var_2)
			debugger::__tester__.fail(__LINE__);
		else
			debugger::__tester__.pass(__LINE__);
	}

	{
		char var;
		pix::type_info<char> obj;

		if (obj == var)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}

	{
		char var;
		pix::type_info<int> obj;

		if (obj == var)
			debugger::__tester__.fail(__LINE__);
		else
			debugger::__tester__.pass(__LINE__);
	}
}

static void operator_inequality(void) noexcept(false)
{
	debugger::__tester__.start(__FUNCTION__, __FILE__);

	{
		char var;
		pix::type_info obj(var);

		if (obj != var)
			debugger::__tester__.fail(__LINE__);
		else
			debugger::__tester__.pass(__LINE__);
	}

	{
		char var_1 = 'a';
		int var_2;
		pix::type_info obj(var_1);

		if (obj != var_2)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}

	{
		char var;
		pix::type_info<char> obj;

		if (obj != var)
			debugger::__tester__.fail(__LINE__);
		else
			debugger::__tester__.pass(__LINE__);
	}

	{
		char var;
		pix::type_info<int> obj;

		if (obj != var)
			debugger::__tester__.pass(__LINE__);
		else
			debugger::__tester__.fail(__LINE__);
	}
}
