#include <iostream>
#include <utils.hpp> // Utilities
#include <pix_lib.hpp> // Pi-X library
#include <tests.hpp> // Tests

int main(int argc, char* argv[])
{
	// Parse arguments
	utils::parse(argc, argv);

	fn_test tests[] = {
		&test__type_info,
		&test__c_array,
		&test__memory
	};
	const unsigned long NUM_TESTS = array_size(tests);

	for (unsigned long i = 0; i < NUM_TESTS; ++i)
		tests[i]();

	debugger::__tester__.print();

	return EXIT_SUCCESS;
}
