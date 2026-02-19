// Header file
#include "utils.hpp"

// Dependencies
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

// Terminal width when it cannot be determined
#define TERMINAL_WIDTH_DEFAULT 80

// Default output width when printing to file
#define FILE_WIDTH_DEFAULT 120

#ifdef _WIN32
#include <io.h>
#include <windows.h>
#define ISATTY _isatty
#define FILENO _fileno
#else
#include <langinfo.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#define ISATTY isatty
#define FILENO fileno
#endif

namespace utils
{
	void pause(const char msg[]) noexcept(true)
	{
		if (msg == nullptr)
			std::cout << "Press RETURN to continue...";
		else
			std::cout << msg << "...";
		
		std::cin.get();
	}

	void clear(void) noexcept(true)
	{
		#if  defined(__linux__)

			std::system("clear");
		
		#elif defined(_Win32) || defined(_Win64)

			std::system("cls");

		#endif
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

		if (file.is_open() == false)
		{
			std::cout << "File " << file_name << " is not open\n";
			
			return;
		}

		if (file.good() == false)
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

		if (file.is_open() == false)
		{
			std::cout << "File " << file_name << " is not open\n";
			
			return;
		}

		if (file.good() == false)
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

	bool should_use_utf8(FILE* stream)
	{
		if (!ISATTY(FILENO(stream)))
			return true;

		return terminal_supports_utf8();
	}

	bool should_use_color(FILE* stream)
	{
		// NO_COLOR set
		// Don’t output ANSI color escape codes, see no-color.org
		const char* no_color = std::getenv("NO_COLOR");
		
		if (no_color && no_color[0] != '\0')
			return false;

		// CLICOLOR_FORCE set, but NO_COLOR unset
		// ANSI colors should be enabled no matter what
		const char* force_color = std::getenv("CLICOLOR_FORCE");
		
		if (force_color && std::strcmp(force_color, "0") != 0)
			return true;

		// Check if the stream is a terminal
		int fd = FILENO(stream);

		if (!ISATTY(fd))
			return false;

		// Check TERM variable for "dumb" terminals
		const char* term = std::getenv("TERM");
		
		if (term && std::strcmp(term, "dumb") == 0)
			return false;

	// Windows Specific: Enable Virtual Terminal Processing (ANSI support)
	#ifdef _WIN32
		HANDLE hOut = static_cast<HANDLE>(_get_osfhandle(fd));

		if (hOut == INVALID_HANDLE_VALUE)
			return false;

		DWORD dwMode = 0;

		if (!GetConsoleMode(hOut, &dwMode))
			return false;

	// ENABLE_VIRTUAL_TERMINAL_PROCESSING might not be defined in older SDKs
	#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
	#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
	#endif

		if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		{
			if (!SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
				return false; // Failed to enable ANSI support on this Windows console
		}
	#endif // _WIN32

		return true;
	}

	int get_terminal_width(FILE* stream)
	{
		if (!stream)
			return FILE_WIDTH_DEFAULT;

	#ifdef _WIN32
		const int fd = FILENO(stream);
		HANDLE hFile = static_cast<HANDLE>(_get_osfhandle(fd));
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		if (hFile != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hFile, &csbi))
			return csbi.srWindow.Right - csbi.srWindow.Left + 1;
	#else
		struct winsize w;
		const int fd = FILENO(stream);

		if (ioctl(fd, TIOCGWINSZ, &w) != -1)
			return w.ws_col;
	#endif // _WIN32
		// Check COLUMNS environment variable
		const char* env_cols = std::getenv("COLUMNS");

		if (env_cols)
			return std::atoi(env_cols);

		return TERMINAL_WIDTH_DEFAULT;
	}

	double get_timer_freq_inv(void)
	{
	#ifdef _WIN32
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);

		return 1 / static_cast<double>(freq.QuadPart);
	#else
		return 1;
	#endif // _WIN32
	}

	bool contains_utf8_case_insensitive(const char* str)
	{
		if (!str)
			return false;

		while (*str)
		{
			if (tolower((unsigned char)str[0]) == 'u' &&
				tolower((unsigned char)str[1]) == 't' &&
				tolower((unsigned char)str[2]) == 'f')
			{
				// Check for "utf8" or "utf-8"
				if (str[3] == '8')
					return true;

				if (str[3] == '-' && str[4] == '8')
					return true;
			}

			++str;
		}

		return false;
	}

	bool terminal_supports_utf8(void)
	{
	#ifdef _WIN32
		return GetConsoleOutputCP() == CP_UTF8;
	#else
		const char* codeset = nl_langinfo(CODESET);
		
		if (codeset && contains_utf8_case_insensitive(codeset))
			return true;

		const char* env_vars[] = {"LC_ALL", "LC_CTYPE", "LANG"};
		
		for (unsigned long i = 0; i < 3; ++i)
		{
			const char* val = std::getenv(env_vars[i]);
			
			if (val && val[0])
			{
				if (contains_utf8_case_insensitive(val))
					return true;

				if (i == 0)
					return false;
			}
		}

		return false;
	#endif // _WIN32
	}
}
