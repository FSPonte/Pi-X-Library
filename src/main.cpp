// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// OS dependent libraries
#include <utils.hpp>
#include <progress_bar.hpp>

// Pi-X library
#include <pix_lib.hpp>

int main(int argc, char* argv[])
{
	// Parse arguments
	utils::parse(argc, argv);

	constexpr pix::types::int64_t N = 1E9;

	progress_bar pgb("Processing", 0, N);

	for (pix::types::int64_t i = 0; i <= N; i++)
	{
		if (i % 100 == 0)
			pgb.update(i);
	}
	
	pgb.finish();

	return EXIT_SUCCESS;
}
