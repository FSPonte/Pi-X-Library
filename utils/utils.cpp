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

	bool should_use_utf8(std::ostream& stream)
	{
		int fd = -1;

		// 1. Identify the file descriptor
		if (&stream == &std::cout)
			fd = STDOUT_FILENO;
		else if (&stream == &std::cerr || &stream == &std::clog)
			fd = STDERR_FILENO;

		// 2. If it's not a standard stream (like a file or stringstream), 
		// fd remains -1. isatty(-1) will return false.
		if (fd == -1 || !isatty(fd))
			return true; 

		// 3. It is a terminal; check environment/capabilities
		return terminal_supports_utf8();
	}

	bool should_use_color(std::ostream& stream)
	{
		// 1. Check NO_COLOR (Standard: https://no-color.org)
		const char* no_color = std::getenv("NO_COLOR");
		if (no_color && no_color[0] != '\0')
			return false;

		// 2. Check CLICOLOR_FORCE
		const char* force_color = std::getenv("CLICOLOR_FORCE");

		if (force_color && std::strcmp(force_color, "0") != 0)
			return true;

		// 3. Map C++ stream to file descriptor
		int fd = -1;

		if (&stream == &std::cout)
			fd = 1; // STDOUT_FILENO
		else if (&stream == &std::cerr || &stream == &std::clog)
			fd = 2; // STDERR_FILENO

		// If it's not a standard stream or not a TTY (e.g. redirected to file), no color
		if (fd == -1 || !ISATTY(fd))
			return false;

		// 4. Check TERM variable for "dumb" terminals
		const char* term = std::getenv("TERM");

		if (term && std::strcmp(term, "dumb") == 0)
			return false;

		// 5. Windows Specific: Enable Virtual Terminal Processing (ANSI support)
	#ifdef _WIN32
		HANDLE hOut = GET_OS_HANDLE(fd);

		if (hOut == INVALID_HANDLE_VALUE)
			return false;

		DWORD dwMode = 0;
		
		if (!GetConsoleMode(hOut, &dwMode))
			return false;

		#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
		#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
		#endif

		if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		{
			if (!SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
				return false; 
		}
	#endif

		return true;
	}

	int get_terminal_width(std::ostream& stream)
	{
		// 1. Map C++ stream to a File Descriptor
		int fd = -1;
	
		if (&stream == &std::cout) fd = 1;      // STDOUT_FILENO
		else if (&stream == &std::cerr) fd = 2; // STDERR_FILENO
		else if (&stream == &std::clog) fd = 2; // STDERR_FILENO

		// If it's a file, stringstream, or null stream, return default
		if (fd == -1) return TERMINAL_WIDTH_DEFAULT;

		// 2. Query the OS for terminal dimensions
	#ifdef _WIN32
		HANDLE hFile = reinterpret_cast<HANDLE>(_get_osfhandle(fd));
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		
		if (hFile != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hFile, &csbi))
			return csbi.srWindow.Right - csbi.srWindow.Left + 1;
	#else
		struct winsize w;

		if (ioctl(fd, TIOCGWINSZ, &w) != -1 && w.ws_col > 0)
			return w.ws_col;
	#endif

		// 3. Fallback to Environment Variable (useful for some CI/CD environments)
		const char* env_cols = std::getenv("COLUMNS");

		if (env_cols)
		{
			int cols = std::atoi(env_cols);
		
			if (cols > 0)
				return cols;
		}

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