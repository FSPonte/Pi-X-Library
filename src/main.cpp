// C/C++ standard libraries
#include <iostream>
#include <fstream>

// Pi-X library
#include <pix_lib.hpp>

// Utilities
#include <utils.hpp>

int main(int argc, char* argv[])
{
	utils::clear();
	utils::parse(argc, argv);
	utils::pause();
	utils::clear();

	for (unsigned long i = 1; i < argc; ++i)
	{
		std::cout << "File: " << argv[i] << "\n\n";

		utils::print_file(argv[i]);
		utils::pause();
		utils::clear();
	}

	return EXIT_SUCCESS;
}
