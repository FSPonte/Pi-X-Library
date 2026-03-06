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
static void binary_approx(void) noexcept(false);
static void strlen(void) noexcept(false);

void test__c_array(void) noexcept(false)
{
	DEBUG_TESTER_INIT;
	fn_test tests[] = {
		&swap,
		&invert,
		&copy,
		&move,
		&left_shift,
		&right_shift,
		&bit_rev,
		&binary_search,
		&binary_approx,
		&strlen
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
	DEBUG_TESTER_START;

	// Reference arguments
	{
		char
			var_1 = 'a',
			var_2 = 'b';
		pix::c_array::swap(var_1, var_2);

		if (var_1 == 'b' && var_2 == 'a')
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Pointer arguments
	{
		char
			var_1,
			var_2;
		char
			*ptr_1 = &var_1,
			*ptr_2 = &var_2;
		pix::c_array::swap(ptr_1, ptr_2);

		if (ptr_1 == &var_2 && ptr_2 == &var_1)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		char
			*ptr_1 = nullptr,
			*ptr_2 = nullptr;

		try
		{
			pix::c_array::swap(ptr_1, ptr_2);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void invert(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {5, 4, 3, 2, 1};
		constexpr unsigned long DIM = array_size(arr);
		pix::c_array::invert(arr, DIM);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != target[i])
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::invert(static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char var;
		char* ptr = &var;

		try
		{
			pix::c_array::invert(ptr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void copy(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {0, 0, 0, 0, 0},
			target[] = {1, 2, 3, 4, 5};

		pix::c_array::copy(target, arr);
		constexpr unsigned long DIM = array_size(arr);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != target[i])
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::copy(static_cast<char*>(nullptr), static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char arr[] = {0, 0, 0, 0, 0};

		try
		{
			pix::c_array::copy(arr, arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void move(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {0, 0, 0, 0, 0};

		pix::c_array::move(arr, target);
		constexpr unsigned long DIM = array_size(arr);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != 0 || target[i] != static_cast<char>(i + 1))
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::move(static_cast<char*>(nullptr), static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char arr[] = {0, 0, 0, 0, 0};

		try
		{
			pix::c_array::move(arr, arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void left_shift(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {2, 3, 4, 5, char()};

		pix::c_array::left_shift(arr);
		constexpr unsigned long DIM = array_size(arr);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != target[i])
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::left_shift(static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char arr[] = {0, 0, 0, 0, 0};

		try
		{
			pix::c_array::left_shift(arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void right_shift(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {1, 2, 3, 4, 5},
			target[] = {char(), 1, 2, 3, 4};

		pix::c_array::right_shift(arr);
		constexpr unsigned long DIM = array_size(arr);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != target[i])
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::right_shift(static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char arr[] = {0, 0, 0, 0, 0};

		try
		{
			pix::c_array::right_shift(arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void bit_rev(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char
			arr[] = {1, 2, 3, 4, 5, 6, 7, 8},
			target[] = {1, 5, 3, 7, 2, 6, 4, 8};

		pix::c_array::bit_rev(arr);
		constexpr unsigned long DIM = array_size(arr);
		bool pass = true;

		for (unsigned long i = 0; i < DIM; ++i)
		{
			if (arr[i] != target[i])
				pass = false;
		}

		if (pass)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::bit_rev(static_cast<char*>(nullptr), 3);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		char arr[] = {0, 0};

		try
		{
			pix::c_array::bit_rev(arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an power of 2 exception
	{
		char arr[] = {0, 0, 0};

		try
		{
			pix::c_array::bit_rev(arr, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_PASS;
		}
	}
}

static void binary_search(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		constexpr unsigned long index = 2;
		int
			arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
			target = arr[index];

		if (pix::c_array::binary_search(arr, target) == index)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::binary_search(static_cast<int*>(nullptr), 3, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		int arr[] = {0, 0};

		try
		{
			pix::c_array::binary_search(arr, 0, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
	
	// Trigger an element not found exception
	{
		int
			arr[] = {1, 2, 3, 4, 5, 6, 0, 8, 9, 10},
			target = 7;

		try
		{
			pix::c_array::binary_search(arr, target);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_PASS;
		}
	}
}

static void binary_approx(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		constexpr unsigned long index = 2;
		int
			arr[] = {0, 1, 2, 6, 7, 8, 9, 0, 10, 11},
			target = 3;

		if (pix::c_array::binary_approx(arr, target) == index)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::binary_approx(static_cast<int*>(nullptr), 3, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}

	// Trigger an null_dim exception
	{
		int arr[] = {0, 0};

		try
		{
			pix::c_array::binary_approx(arr, 0, 0);
			DEBUG_TESTER_FAIL;
		}
		catch (const pix::exception::null_dim& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep& e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}

static void strlen(void) noexcept(false)
{
	DEBUG_TESTER_START;

	// Normal
	{
		char str[] = "Hello world";
		constexpr unsigned long LEN = array_size(str);

		if (pix::c_array::strlen(str) == LEN)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Zero elements
	{
		char str[] = "";
		constexpr unsigned long LEN = array_size(str);

		if (pix::c_array::strlen(str) == LEN)
			DEBUG_TESTER_PASS;
		else
			DEBUG_TESTER_FAIL;
	}

	// Trigger an null_ptr exception
	{
		try
		{
			pix::c_array::strlen(static_cast<char*>(nullptr));
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::null_ptr& e)
		{
			DEBUG_TESTER_PASS;
		}
		catch (const pix::exception::excep e)
		{
			DEBUG_TESTER_FAIL;
		}
	}
}
