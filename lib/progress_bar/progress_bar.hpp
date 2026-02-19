#ifndef _PROGRESS_BAR_HPP_
#define _PROGRESS_BAR_HPP_

// Dependencies
#include <sys_vars.hpp>

// Number of data points to keep for timer calculations
#define TIMER_DATA_POINTS 5

// Progress bar default width
#define PROGRESS_BAR_WIDTH_DEFAULT 40

typedef struct
{
	const bool is_utf8;

	const char
		*reset,
		*erase_current_line,
		*disable_cursor,
		*enable_cursor,

		*bar_prefix,
		*bar_suffix,
		*bar_fill,
		*bar_empty,
		*bar_fill_head,
		*bar_empty_head,
		*separator,

		*color_spinner,
		*color_fill,
		*color_fill_after_ended,
		*color_empty,
		*color_percentage,
		*color_remaining_time,
		*color_elapsed_time,
	
		*spinner[9];

	const int spinner_animation_length;
} UTF8_codes;

class progress_bar
{
public:

	progress_bar(const char[], long int, long int);

	/**
	 * @brief Start a progress bar.
	*/
	void start(void);

	/**
	 * @brief Update a progress bar.
	 * @param progress_bar The progress bar to update.
	 * @param current The current value of the progress bar.
	*/
	void update(long int);

	/**
	 * @brief Finish a progress bar.
	 * @param progress_bar The progress bar to finish.
	*/
	void finish(void);

private:

	long int
		_start,
		_total,
		_current;

	bool
		_is_started,
		_is_finished;

	char _description[D_BUFFER_SIZE];
	double
		_min_refresh_time,
		_timer_remaining_time_recent_weight;

	struct
	{
		long int updates_count;
		double
			time_start,
			timer_time_last_update,
			timer_percentage_last_update,
			timer_time_diffs[TIMER_DATA_POINTS],
			timer_percentage_diffs[TIMER_DATA_POINTS],
			_timer_freq_inv; // For monotonic time calculation on Windows
	} internal;

	bool update_timer_data(void);
	void print_elapsed_time(void);
	void print_remaining_time(void);
	UTF8_codes get_utf8_codes(void);
	void print_progress_bar(void);

	/**
	 * @brief Calculate the percentage of completion.
	 * @return The percentage of completion.
	*/
	double calculate_percentage(void);

	/**
	 * @brief Calculate the overall rate of progress (percentage per second).
	 * @return The overall rate of progress.
	*/
	double calculate_overall_rate(void);

	/**
	 * @brief Calculate the recent rate of progress (percentage per second) based on recent updates.
	 * @return The recent rate of progress.
	*/
	double calculate_recent_rate(void);

	double get_monotonic_time(void);
};

#endif // _PROGRESS_BAR_HPP_