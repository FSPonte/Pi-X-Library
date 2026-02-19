#ifndef _SIGNAL_HPP_
#define _SIGNAL_HPP_

// Signal processing
namespace pix::math::signal
{
	/**
	 * @brief Mean subtraction
	 * @tparam type_t Data type
	 * @param arr Array of elements
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void mean_sub(type_t[], unsigned long) noexcept(false);

	/**
	 * @brief Normalizing signal
	 * @tparam type_t Data type
	 * @param arr Pointer to array
	 * @param dim Number of elements
	 * @throw Pointer to array is null
	 * @throw Dimension is null
	*/
	template <typename type_t>
	void norm(type_t[], unsigned long) noexcept(false);

	// Window functions
	namespace window
	{
		/**
		 * @brief Hann window function
		 * @tparam type_t Data type
		 * @param arr Array of elements
		 * @param dim Number of elements
		 * @throw Pointer to array is null
		 * @throw Dimension is null
		*/
		template <typename type_t>
		void hann(type_t[], unsigned long) noexcept(false);

		/**
		 * @brief Hamming window function
		 * @tparam type_t Data type
		 * @param arr Array of elements
		 * @param dim Number of elements
		 * @throw Pointer to array is null
		 * @throw Dimension is null
		*/
		template <typename type_t>
		void hamming(type_t[], unsigned long) noexcept(false);

		/**
		 * @brief Blackman window function
		 * @tparam type_t Data type
		 * @param arr Array of elements
		 * @param dim Number of elements
		 * @throw Pointer to array is null
		 * @throw Dimension is null
		*/
		template <typename type_t>
		void blackman(type_t[], unsigned long) noexcept(false);
	}

	// Transform functions
	namespace transform
	{
		/**
		 * @brief Discrete Fourier transform
		 * @tparam type_t Data type
		 * @param t Array of time instants
		 * @param s Array of signal values
		 * @param f Array of frequencies
		 * @param u Array of transform values
		 * @param d_dim Number of elements of time and signal arrays
		 * @param u_dim Number of elements of frequencies and transform arrays
		 * @throw Pointer to time array is null
		 * @throw Pointer to signal array is null
		 * @throw Pointer to frequencies array is null
		 * @throw Pointer to transform array is null
		 * @throw Domain dimension is null
		 * @throw Transform dimension is null
		*/
		template <typename type_t>
		void dft(const type_t[], const type_t[], const type_t[], type_t[], unsigned long, unsigned long) noexcept(false);
	}
}

// Template file
#include "signal.tpp"

#endif // _SIGNAL_HPP_