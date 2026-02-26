// C/C++ standard libraries
#include <iostream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

int main(int argc, char* argv[])
{
	// Parse arguments
	utils::parse(argc, argv);

	constexpr unsigned long DIM = 1E9;
	pix::progress_bar pgb("Processing", 0, DIM);

	for (unsigned long i = 0; i <= DIM; ++i)
	{
		if (i % 100 == 0)
			pgb.update(i);
	}

	pgb.finish();

	return EXIT_SUCCESS;
}
