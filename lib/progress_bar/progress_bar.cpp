// Header file
#include "progress_bar.hpp"

// Dependencies
#include <iostream>
#include <cstring>

/**
 * @brief Determine if we should use UTF-8 encoding for the given output stream.
 * @param stream The output stream (e.g., stdout, stderr).
 * @return true if UTF-8 encoding should be used, false otherwise.
*/
bool should_use_utf8(FILE* stream);

/**
 * @brief Determine if ANSI color codes should be used for the given output stream.
 * @param stream The output stream (e.g., stdout, stderr).
 * @return true if ANSI color codes should be used, false otherwise.
*/
bool should_use_color(FILE* stream);

/**
 * @brief Get the width of the terminal for the given output stream.
 * @param stream The output stream (e.g., stdout, stderr), or NULL for files.
 * @return The width of the terminal in characters.
*/
int get_terminal_width(FILE* stream);

/**
 * @brief Get the inverse of the timer frequency (for Windows).
 * @return The inverse of the timer frequency.
*/
double get_timer_freq_inv(void);

progress_bar::progress_bar(const char description[], pix::types::int64_t start, pix::types::int64_t total)
{
	std::strncpy(this->_description, description, D_BUFFER_SIZE);
	this->_min_refresh_time = 0.1;
	this->_timer_remaining_time_recent_weight = 0.3;

	this->internal._timer_freq_inv = get_timer_freq_inv();

	this->_start = start;
	this->_total = total;
	this->_current = start;

	this->_is_started = false;
	this->_is_finished = false;

	this->internal.updates_count = -1;
	this->internal.time_start = 0;
	this->internal.timer_time_last_update = 0;
	this->internal.timer_percentage_last_update = 0;
	
	for (unsigned long i = 0; i < TIMER_DATA_POINTS; ++i)
	{
		this->internal.timer_time_diffs[i] = 0;
		this->internal.timer_percentage_diffs[i] = 0;
	}
}

void progress_bar::start(void)
{
	this->_is_started = true;

	if (this->update_timer_data())
		this->print_progress_bar();
}

void progress_bar::update(pix::types::int64_t current)
{
	this->_current = current;

	if (!this->update_timer_data())
		return;

	this->print_progress_bar();
}

void progress_bar::finish(void)
{
	this->_is_finished = true;

	if (this->update_timer_data())
		this->print_progress_bar();
}

bool progress_bar::update_timer_data(void)
{
	if (this->_is_finished)
	{
		this->internal.timer_time_last_update = this->get_monotonic_time();
		this->internal.timer_percentage_last_update = 100;

		return true;
	}

	if (this->internal.updates_count < 0)
	{
		const double current_time = this->get_monotonic_time();

		this->internal.time_start = current_time;
		this->internal.timer_time_last_update = current_time;
		this->internal.timer_percentage_last_update = this->calculate_percentage();
		this->internal.updates_count = 0;

		return true;
	}

	const double current_time = this->get_monotonic_time();
	const double diff_time = current_time - this->internal.timer_time_last_update;

	if (diff_time < this->_min_refresh_time)
		return false;

	const double current_percentage = this->calculate_percentage();
	const double diff_percentage = current_percentage - this->internal.timer_percentage_last_update;

	this->internal.timer_time_diffs[this->internal.updates_count % TIMER_DATA_POINTS] = diff_time;
	this->internal.timer_percentage_diffs[this->internal.updates_count % TIMER_DATA_POINTS] = diff_percentage;
	this->internal.timer_time_last_update = current_time;
	this->internal.timer_percentage_last_update = current_percentage;
	this->internal.updates_count++;

	return true;
}

void progress_bar::print_elapsed_time(void)
{
	const double elapsed_time = (this->internal.timer_time_last_update - this->internal.time_start);

	// Calculate elapsed hours, minutes and seconds
	const int
		hours = static_cast<int>(elapsed_time) / 3600,
		minutes = static_cast<int>(elapsed_time) % 3600 / 60,
		seconds = static_cast<int>(elapsed_time) % 60;

	if (hours < 0 || minutes < 0 || seconds < 0)
		std::fputs("--:--:--", stdout);
	else
		std::printf("%02d:%02d:%02d", hours, minutes, seconds);
}

void progress_bar::print_remaining_time(void)
{
	const double
		overall_rate = this->calculate_overall_rate(),
		recent_rate = this->calculate_recent_rate(),
		blended_rate =
			this->_timer_remaining_time_recent_weight * recent_rate +
			(1.0 - this->_timer_remaining_time_recent_weight) * overall_rate;

	if (blended_rate <= 0.0)
	{
		std::fputs("--:--:--", stdout);
	
		return;
	}

	const double
		remaining_percentage = 100.0 - this->internal.timer_percentage_last_update,
		estimated_remaining_time = remaining_percentage / blended_rate;

	// Calculate remaining hours, minutes and seconds
	const int
		hours = static_cast<int>(estimated_remaining_time) / 3600,
		minutes = static_cast<int>(estimated_remaining_time) % 3600 / 60,
		seconds = static_cast<int>(estimated_remaining_time) % 60;

	if (hours < 0 || minutes < 0 || seconds < 0)
		std::fputs("--:--:--", stdout);
	else
		std::printf("%02d:%02d:%02d", hours, minutes, seconds);
}

UTF8_codes progress_bar::get_utf8_codes(void)
{
	if (should_use_utf8(stdout) && should_use_color(stdout))
	{
		return UTF8_codes{
			.is_utf8 = true,

			.reset = "\033[0m",
			.erase_current_line = "\033[2K",
			.disable_cursor = "\033[?25l",
			.enable_cursor = "\033[?25h",

			.bar_prefix = "",
			.bar_suffix = "",
			.bar_fill = "\u2501",
			.bar_empty = "\u2501",
			.bar_fill_head = "\u2578",
			.bar_empty_head = "\u257A",
			.separator = "\u2022",

			.color_spinner = "\033[0;32m",
			.color_fill = "\033[38;5;197m",
			.color_fill_after_ended = "\033[38;5;106m",
			.color_empty = "\033[0;90m",
			.color_percentage = "\033[0;35m",
			.color_remaining_time = "\033[0;36m",
			.color_elapsed_time = "\033[0;33m",

			.spinner =
				{
					"\u280B",
					"\u2819",
					"\u2839",
					"\u2838",
					"\u283C",
					"\u2834",
					"\u2826",
					"\u2827",
					"\u2807",
				},

			.spinner_animation_length = 9
		};
	}
	
	return UTF8_codes{
		.is_utf8 = false,

		.reset = "",
		.erase_current_line = "",
		.disable_cursor = "",
		.enable_cursor = "",

		.bar_prefix = "[",
		.bar_suffix = "]",
		.bar_fill = "=",
		.bar_empty = " ",
		.bar_fill_head = ">",
		.bar_empty_head = ">",
		.separator = "*",

		.color_spinner = "",
		.color_fill = "",
		.color_fill_after_ended = "",
		.color_empty = "",
		.color_percentage = "",
		.color_remaining_time = "",
		.color_elapsed_time = "",

		.spinner = {NULL},
		.spinner_animation_length = -1
	};
}

void progress_bar::print_progress_bar(void)
{
	const UTF8_codes utf8_codes = this->get_utf8_codes();
	std::fputs("\r", stdout);

	if (utf8_codes.is_utf8)
	{
		std::fputs(utf8_codes.reset, stdout);
		std::fputs(utf8_codes.disable_cursor, stdout);
		std::fputs(utf8_codes.erase_current_line, stdout);
	}

	const double percentage = this->internal.timer_percentage_last_update;
	const double clamped = percentage < 0.0 ? 0.0 : (percentage > 100.0 ? 100.0 : percentage);

	const int total_half_cells = PROGRESS_BAR_WIDTH_DEFAULT * 2;
	const int filled_half_cells = static_cast<int>(clamped / 100.0 * total_half_cells);
	const int full_cells = filled_half_cells / 2;
	const bool has_left_half_cell = filled_half_cells % 2 > 0;
	const int empty_cells = PROGRESS_BAR_WIDTH_DEFAULT - full_cells;
	const bool has_right_half_cell = !has_left_half_cell && empty_cells > 0;

	const char* fill_color = this->_is_finished ? utf8_codes.color_fill_after_ended : utf8_codes.color_fill;

	// Spinner
	if (utf8_codes.spinner_animation_length > 0)
	{
		const int spinner_index = this->internal.updates_count % utf8_codes.spinner_animation_length;
			
		std::fputs(utf8_codes.color_spinner, stdout);
		std::fputs(utf8_codes.spinner[spinner_index], stdout);
		std::fputs(utf8_codes.reset, stdout);
		std::fputs(" ", stdout);
	}

	// Description
	std::string description = this->_description;
	
	if (description[0] != '\0')
		std::cout << description << " ";

	// Filled cells
	std::fputs(utf8_codes.bar_prefix, stdout);

	if (filled_half_cells > 0)
	{
		std::fputs(fill_color, stdout);
		
		for (int i = 0; i < full_cells; i++)
			std::fputs(utf8_codes.bar_fill, stdout);

		if (has_left_half_cell)
			std::fputs(utf8_codes.bar_fill_head, stdout);

		std::fputs(utf8_codes.reset, stdout);
	}

	// Unfilled cells
	if (empty_cells > 0)
	{
		std::fputs(utf8_codes.color_empty, stdout);

		if (has_right_half_cell)
			std::fputs(utf8_codes.bar_empty_head, stdout);

		int i = (has_left_half_cell || has_right_half_cell) ? 1 : 0;
		
		for (; i < empty_cells; i++)
			std::fputs(utf8_codes.bar_empty, stdout);
	}
	
	std::fputs(utf8_codes.reset, stdout);
	std::fputs(utf8_codes.bar_suffix, stdout);

	// Extra Info
	std::printf(
		" %s%3d%%%s %s ",
		utf8_codes.color_percentage,
		(int)clamped,
		utf8_codes.reset,
		utf8_codes.separator
	);
	
	std::fputs(utf8_codes.color_elapsed_time, stdout);
	this->print_elapsed_time();
	std::fputs(utf8_codes.reset, stdout);
	std::fputs(" ", stdout);
	std::fputs(utf8_codes.separator, stdout);
	std::fputs(" ", stdout);
	std::fputs(utf8_codes.color_remaining_time, stdout);
	this->print_remaining_time();
	std::fputs(utf8_codes.reset, stdout);

	// Reset cursor
	if (this->_is_finished)
	{
		std::fputs(utf8_codes.enable_cursor, stdout);
		std::fputs("\n", stdout);
	}

	std::fflush(stdout);
}

double progress_bar::calculate_percentage(void)
{
	const int64_t
		start = this->_start,
		total = this->_total - start,
		current = this->_current - start;
		
	if (total <= 0 || current <= 0)
		return 0.0;

	if (current >= total)
		return 100.0;

	return static_cast<double>(current) / static_cast<double>(total) * 100;
}

double progress_bar::calculate_overall_rate(void)
{
	const double elapsed_time = this->internal.timer_time_last_update - this->internal.time_start;

	if (elapsed_time <= 0)
		return 0;

	return static_cast<double>(this->internal.timer_percentage_last_update) / elapsed_time;
}

double progress_bar::calculate_recent_rate(void)
{
	// We don't need recent rate anyways if we only have a few data points
	if (this->internal.updates_count <= TIMER_DATA_POINTS)
		return this->calculate_overall_rate();

	double
		sum_time = 0,
		sum_percent = 0;

	for (unsigned long i = 0; i < TIMER_DATA_POINTS; ++i)
	{
		sum_time += this->internal.timer_time_diffs[i];
		sum_percent += this->internal.timer_percentage_diffs[i];
	}

	if (sum_time <= 1E-9)
		return this->calculate_overall_rate();

	return sum_percent / sum_time;
}

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

static bool contains_utf8_case_insensitive(const char* str)
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

static bool terminal_supports_utf8(void)
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

double progress_bar::get_monotonic_time(void)
{
#ifdef _WIN32
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	
	return static_cast<double>(now.QuadPart) * this->internal._timer_freq_inv;
#else
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
		return 0.0;

	return static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec / 1E9);
#endif // _WIN32
}