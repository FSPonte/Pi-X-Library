// Header file
#include "tests.hpp"

// Test target
#include <type_info.hpp>

static tester __tester__;

static void operator_equality(void) noexcept(false);
static void operator_inequality(void) noexcept(false);

tester test__type_info(void) noexcept(false)
{
	__tester__.init(__FUNCTION__);
	fn_unit_test tests[] = {
		&operator_equality,
		&operator_inequality
	};
	const unsigned long NUM_TESTS = sizeof(tests) / sizeof(*tests);
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
			std::cout << e.what() << std::endl;
		}
	}

	pgb.finish();

	return __tester__;
}

static void operator_equality(void) noexcept(false)
{
	__tester__.start(__FUNCTION__, __FILE__);

	char var_1 = 'a';
	pix::type_info obj(var_1);
	int var_2 = 6;

	// Positive test
	{
		if (obj == var_1)
			__tester__.pass(__LINE__);
		else
			__tester__.fail(__LINE__);
	}

	// Negative test
	{
		if (obj == var_2)
			__tester__.fail(__LINE__);
		else
			__tester__.pass(__LINE__);
	}
}

static void operator_inequality(void) noexcept(false)
{
	__tester__.start(__FUNCTION__, __FILE__);

	char var_1 = 'a';
	pix::type_info obj(var_1);
	int var_2 = 5;

	// Negative test
	{
		if (obj != var_1)
			__tester__.fail(__LINE__);
		else
			__tester__.pass(__LINE__);
	}

	// Positive test
	{
		if (obj != var_2)
			__tester__.pass(__LINE__);
		else
			__tester__.fail(__LINE__);
	}
}
