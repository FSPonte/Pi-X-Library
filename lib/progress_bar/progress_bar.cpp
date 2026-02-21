// Header file
#include "progress_bar.hpp"

// Dependencies
#include <utils.hpp>
#include <iostream>
#include <cstring>

progress_bar::progress_bar(const char* description, long int start, long int total)
{
	std::strncpy(this->_description, description, sizeof(this->_description) - 1);
	this->_description[sizeof(this->_description) - 1] = '\0';
	
	this->_min_refresh_time = 0.1;
	this->_timer_remaining_time_recent_weight = 0.3;

	this->_internal.timer_freq_inv = utils::get_timer_freq_inv();

	this->_start = start;
	this->_total = total;
	this->_current = start;

	this->_is_started = false;
	this->_is_finished = false;

	this->_internal.updates_count = -1;
	this->_internal.time_start = 0;
	this->_internal.timer_time_last_update = 0;
	this->_internal.timer_percentage_last_update = 0;
	
	for (unsigned long i = 0; i < TIMER_DATA_POINTS; ++i)
	{
		this->_internal.timer_time_diffs[i] = 0;
		this->_internal.timer_percentage_diffs[i] = 0;
	}
}

void progress_bar::start(void)
{
	this->_is_started = true;

	if (this->update_timer_data())
		this->print_progress_bar();
}

void progress_bar::update(long int current)
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
		this->_internal.timer_time_last_update = this->get_monotonic_time();
		this->_internal.timer_percentage_last_update = 100;

		return true;
	}

	if (this->_internal.updates_count < 0)
	{
		const double current_time = this->get_monotonic_time();

		this->_internal.time_start = current_time;
		this->_internal.timer_time_last_update = current_time;
		this->_internal.timer_percentage_last_update = this->calculate_percentage();
		this->_internal.updates_count = 0;

		return true;
	}

	const double current_time = this->get_monotonic_time();
	const double diff_time = current_time - this->_internal.timer_time_last_update;

	if (diff_time < this->_min_refresh_time)
		return false;

	const double current_percentage = this->calculate_percentage();
	const double diff_percentage = current_percentage - this->_internal.timer_percentage_last_update;

	this->_internal.timer_time_diffs[this->_internal.updates_count % TIMER_DATA_POINTS] = diff_time;
	this->_internal.timer_percentage_diffs[this->_internal.updates_count % TIMER_DATA_POINTS] = diff_percentage;
	this->_internal.timer_time_last_update = current_time;
	this->_internal.timer_percentage_last_update = current_percentage;
	++this->_internal.updates_count;

	return true;
}

void progress_bar::print_elapsed_time(void)
{
	const double elapsed_time = (this->_internal.timer_time_last_update - this->_internal.time_start);

	const int
		hours = static_cast<int>(elapsed_time) / 3600,
		minutes = static_cast<int>(elapsed_time) % 3600 / 60,
		seconds = static_cast<int>(elapsed_time) % 60;

	if (hours < 0 || minutes < 0 || seconds < 0)
		std::cout << "--:--:--";
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
			(1 - this->_timer_remaining_time_recent_weight) * overall_rate;

	if (blended_rate <= 0)
	{
		std::cout << "--:--:--";
	
		return;
	}

	const double
		remaining_percentage = 100 - this->_internal.timer_percentage_last_update,
		estimated_remaining_time = remaining_percentage / blended_rate;

	// Calculate remaining hours, minutes and seconds
	const int
		hours = static_cast<int>(estimated_remaining_time) / 3600,
		minutes = static_cast<int>(estimated_remaining_time) % 3600 / 60,
		seconds = static_cast<int>(estimated_remaining_time) % 60;

	if (hours < 0 || minutes < 0 || seconds < 0)
		std::cout << "--:--:--";
	else
		std::printf("%02d:%02d:%02d", hours, minutes, seconds);
}

UTF8_codes progress_bar::get_utf8_codes(void)
{
	if (utils::should_use_utf8(std::cout) && utils::should_use_color(std::cout))
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
	std::cout << "\r";

	if (utf8_codes.is_utf8)
	{
		std::cout << utf8_codes.reset;
		std::cout << utf8_codes.disable_cursor;
		std::cout << utf8_codes.erase_current_line;
	}

	const double percentage = this->_internal.timer_percentage_last_update;
	const double clamped = percentage < 0 ? 0 : (percentage > 100 ? 100 : percentage);

	const int
		total_half_cells = PROGRESS_BAR_WIDTH_DEFAULT * 2,
		filled_half_cells = static_cast<int>(clamped / 100 * total_half_cells),
		full_cells = filled_half_cells / 2,
		empty_cells = PROGRESS_BAR_WIDTH_DEFAULT - full_cells;
	const bool
		has_left_half_cell = filled_half_cells % 2 > 0,
		has_right_half_cell = !has_left_half_cell && empty_cells > 0;

	const char* fill_color = this->_is_finished ? utf8_codes.color_fill_after_ended : utf8_codes.color_fill;

	// Spinner
	if (utf8_codes.spinner_animation_length > 0)
	{
		const int spinner_index = this->_internal.updates_count % utf8_codes.spinner_animation_length;
			
		std::cout << utf8_codes.color_spinner;
		std::cout << utf8_codes.spinner[spinner_index];
		std::cout << utf8_codes.reset;
		std::cout << " ";
	}

	// Description
	std::string description = this->_description;
	
	if (description[0] != '\0')
		std::cout << description << " ";

	// Filled cells
	std::cout << utf8_codes.bar_prefix;

	if (filled_half_cells > 0)
	{
		std::cout << fill_color;
		
		for (int i = 0; i < full_cells; i++)
			std::cout << utf8_codes.bar_fill;

		if (has_left_half_cell)
			std::cout << utf8_codes.bar_fill_head;

		std::cout << utf8_codes.reset;
	}

	// Unfilled cells
	if (empty_cells > 0)
	{
		std::cout << utf8_codes.color_empty;

		if (has_right_half_cell)
			std::cout << utf8_codes.bar_empty_head;

		int i = (has_left_half_cell || has_right_half_cell) ? 1 : 0;
		
		for (; i < empty_cells; ++i)
			std::cout << utf8_codes.bar_empty;
	}
	
	std::cout << utf8_codes.reset;
	std::cout << utf8_codes.bar_suffix;

	// Extra Info
	std::printf(
		" %s%3d%%%s %s ",
		utf8_codes.color_percentage,
		static_cast<int>(clamped),
		utf8_codes.reset,
		utf8_codes.separator
	);
	
	std::cout << utf8_codes.color_elapsed_time;
	this->print_elapsed_time();
	std::cout << utf8_codes.reset;
	std::cout << " ";
	std::cout << utf8_codes.separator;
	std::cout << " ";
	std::cout << utf8_codes.color_remaining_time;
	this->print_remaining_time();
	std::cout << utf8_codes.reset;

	// Reset cursor
	if (this->_is_finished)
	{
		std::cout << utf8_codes.enable_cursor;
		std::cout << "\n";
	}

	std::cout << std::flush;
}

double progress_bar::calculate_percentage(void)
{
	const long int
		start = this->_start,
		total = this->_total - start,
		current = this->_current - start;
		
	if (total <= 0 || current <= 0)
		return 0;

	if (current >= total)
		return 100;

	return static_cast<double>(current) / static_cast<double>(total) * 100;
}

double progress_bar::calculate_overall_rate(void)
{
	const double elapsed_time = this->_internal.timer_time_last_update - this->_internal.time_start;

	if (elapsed_time <= 0)
		return 0;

	return static_cast<double>(this->_internal.timer_percentage_last_update) / elapsed_time;
}

double progress_bar::calculate_recent_rate(void)
{
	// We don't need recent rate anyways if we only have a few data points
	if (this->_internal.updates_count <= TIMER_DATA_POINTS)
		return this->calculate_overall_rate();

	double
		sum_time = 0,
		sum_percent = 0;

	for (unsigned long i = 0; i < TIMER_DATA_POINTS; ++i)
	{
		sum_time += this->_internal.timer_time_diffs[i];
		sum_percent += this->_internal.timer_percentage_diffs[i];
	}

	if (sum_time <= 1E-9)
		return this->calculate_overall_rate();

	return sum_percent / sum_time;
}

double progress_bar::get_monotonic_time(void)
{
#if defined(_WIN32) || defined(_WIN64)
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	
	return static_cast<double>(now.QuadPart) * this->_internal.timer_freq_inv;
#else
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
		return 0.0;

	return static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec / 1E9);
#endif
}