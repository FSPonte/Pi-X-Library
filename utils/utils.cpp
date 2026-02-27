// Header file
#include "utils.hpp"

// Dependencies
#include <iostream>
#include <fstream>

namespace utils
{
	void pause(const char msg[]) noexcept(true)
	{
		if (!msg)
			std::cout << "Press RETURN to continue...";
		else
			std::cout << msg << "...";
		
		std::cin.get();
	}

	void clear(void) noexcept(false)
	{
		int ret;

	#if LINUX_DEFINED
		ret = std::system("clear");
	#elif WIN_DEFINED
		ret = std::system("cls");
	#else
		throw "OS not supported";
	#endif

		if (ret != 0)
			throw "Shell command failed";
	}

	void parse(const int argc, char* argv[]) noexcept(true)
	{
		std::cout << "Arguments:" << '\n';

		for (int i = 0; i < argc; ++i)
			std::cout << '\t' << argv[i] << '\n';

		std::cout << '\n';
	}

	void print_file(char file_name[]) noexcept(true)
	{
		std::ifstream file(file_name, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "File " << file_name << " is not open\n";
			
			return;
		}

		if (!file.good())
		{
			std::cout << "File " << file_name << " is not good\n";

			return;
		}

		while (file.peek() != EOF)
			std::cout << static_cast<char>(file.get());

		file.close();
		std::cout << '\n';
	}

	void print_file_hex(char file_name[]) noexcept(true)
	{
		std::ifstream file(file_name, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "File " << file_name << " is not open\n";
			
			return;
		}

		if (!file.good())
		{
			std::cout << "File " << file_name << " is not good\n";

			return;
		}

		std::cout << std::hex;

		for (unsigned long i = 0; file.eof() == false; ++i)
		{
			if (i % 16 == 0)
				std::cout << i << " : ";

			std::cout << file.get() << ' ';

			if (i % 16 == 15)
				std::cout << '\n';
		}

		file.close();
		std::cout << std::dec << "\n\n";
	}
}
