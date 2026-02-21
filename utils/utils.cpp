// Header file
#include "utils.hpp"

// Dependencies
#include <sys_vars.hpp>
#include <exceptions.hpp>
#include <cstring>
#include <fstream>

#if LINUX_DEFINED
#include <langinfo.h>
#include <sys/ioctl.h>
#elif WINDOWS_DEFINED
#include <windows.h>
#endif

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

	bool should_use_utf8(std::ostream& stream) noexcept(true)
	{
		int fd = -1; // File descriptor

		if (&stream == &std::cout)
			fd = STDOUT;
		else if (&stream == &std::cerr || &stream == &std::clog)
			fd = STDERR;

		if (!ISATTY(fd))
			return true; 

		return terminal_supports_utf8();
	}

	bool should_use_color(std::ostream& stream) noexcept(true)
	{
		const char* no_color = std::getenv("NO_COLOR");

		if (no_color && no_color[0] != '\0')
			return false;

		const char* force_color = std::getenv("CLICOLOR_FORCE");

		if (force_color && std::strcmp(force_color, "0") != 0)
			return true;

		int fd = -1; // File descriptor

		if (&stream == &std::cout)
			fd = STDOUT;
		else if (&stream == &std::cerr || &stream == &std::clog)
			fd = STDERR;

		// If it's not a standard stream or not a TTY (e.g. redirected to file), no color
		if (!ISATTY(fd))
			return false;

		// Check TERM variable for "dumb" terminals
		const char* term = std::getenv("TERM");

		if (term && std::strcmp(term, "dumb") == 0)
			return false;

		// Windows Specific: Enable Virtual Terminal Processing (ANSI support)
	#if WIN_DEFINED
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

	int get_terminal_width(std::ostream& stream) noexcept(true)
	{
		// Map C++ stream to a File Descriptor
		int fd = -1;
	
		if (&stream == &std::cout)
			fd = STDOUT;
		else if (&stream == &std::cerr || &stream == &std::clog)
			fd = STDERR;

		// If it's a file, stringstream, or null stream, return default
		if (fd == -1)
			return TERMINAL_WIDTH_DEFAULT;

		// Query the OS for terminal dimensions
	#if WIN_DEFINED
		HANDLE hFile = reinterpret_cast<HANDLE>(_get_osfhandle(fd));
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		
		if (hFile != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hFile, &csbi))
			return csbi.srWindow.Right - csbi.srWindow.Left + 1;
	#else
		struct winsize w;

		if (ioctl(fd, TIOCGWINSZ, &w) != -1 && w.ws_col > 0)
			return w.ws_col;
	#endif

		// Fallback to Environment Variable (useful for some CI/CD environments)
		const char* env_cols = std::getenv("COLUMNS");

		if (env_cols)
		{
			int cols = std::atoi(env_cols);
		
			if (cols > 0)
				return cols;
		}

		return TERMINAL_WIDTH_DEFAULT;
	}

	double get_timer_freq_inv(void) noexcept(true)
	{
	#if WIN_DEFINED
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);

		return 1 / static_cast<double>(freq.QuadPart);
	#else
		return 1;
	#endif
	}

	bool contains_utf8_case_insensitive(const char str[]) noexcept(false)
	{
		if (!str)
			throw pix::exceptions::null_ptr;

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

	bool terminal_supports_utf8(void) noexcept(true)
	{
	#if WIN_DEFINED
		return GetConsoleOutputCP() == CP_UTF8;
	#else
		const char* codeset = nl_langinfo(CODESET);
		
		if (codeset && contains_utf8_case_insensitive(codeset))
			return true;

		const char* env_vars[] = {"LC_ALL", "LC_CTYPE", "LANG"};
		
		for (unsigned long i = 0; i < sizeof(env_vars); ++i)
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
	#endif
	}
}
