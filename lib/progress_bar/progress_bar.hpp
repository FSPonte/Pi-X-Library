#ifndef _PROGRESS_BAR_HPP_
#define _PROGRESS_BAR_HPP_

// Dependencies
#include <string>

namespace pix
{
	constexpr long TIMER_DATA_POINTS = 5; // Number of data points to keep for timer calculations

	struct _utf8_codes_;
	typedef struct _utf8_codes_ utf8_codes;

	class progress_bar
	{
	public:

		/**
		 * @brief Constructor
		 * @param desc Description C-string
		 * @param start Starting point
		 * @param total Total amount
		*/
		progress_bar(const std::string&, long int, long int);

		/**
		 * @brief Start a progress bar
		*/
		void start(void);

		/**
		 * @brief Update a progress bar
		 * @param current The current value of the progress bar
		*/
		void update(long int);

		/**
		 * @brief Finish a progress bar
		*/
		void finish(void);

	private:

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

		bool update_timer_data(void);
		void print_elapsed_time(void);
		void print_remaining_time(void);
		void print_progress_bar(void);

		long int
			_start,
			_total,
			_current;

		bool
			_is_started,
			_is_finished;

		std::string _description;
		double
			_min_refresh_time,
			_timer_remaining_time_recent_weight;

		struct
		{
			long updates_count;
			double
				time_start,
				timer_time_last_update,
				timer_percentage_last_update,
				timer_time_diffs[TIMER_DATA_POINTS],
				timer_percentage_diffs[TIMER_DATA_POINTS],
				timer_freq_inv; // For monotonic time calculation on Windows
		} _internal;
	};
}

#endif // _PROGRESS_BAR_HPP_
