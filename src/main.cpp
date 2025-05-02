// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

using type_t = long double;

constexpr const unsigned long
	SIZE = 1E3,
	NUM_FREQS = 1E3;
constexpr const type_t
	TIME_INITIAL = 0,
	TIME_FINAL = 2 * pix::constants::mathematics::PI,
	AMP_MIN = 0,
	AMP_MAX = 10,
	OFFSET_MIN = -10,
	OFFSET_MAX = 10,
	FREQ_MIN = 0,
	FREQ_MAX = 5,
	PHASE_MIN = -pix::constants::mathematics::PI,
	PHASE_MAX = pix::constants::mathematics::PI;

/**
 * @brief Write file
 * @param in Array of input data
 * @param out Array of output data
 * @param dim Number of data entries
 * @param f_nam File name
*/
void write_file(const type_t[], const type_t[], unsigned long, const char[]);

type_t f(type_t);

int main(int argc, char* argv[])
{
	// Parse arguments
	utils::parse(argc, argv);

	// Transform
	{
		// Log constraints
		{
			std::cout
				<< "Constraints:\n"
				<< "\tTime = [" << TIME_INITIAL << ", " << TIME_FINAL << "]\n"
				<< "\tAmplitude = [" << AMP_MIN << ", " << AMP_MAX << "]\n"
				<< "\tOffset = [" << OFFSET_MIN << ", " << OFFSET_MAX << "]\n"
				<< "\tFrequency = [" << FREQ_MIN << ", " << FREQ_MAX << "]\n"
				<< "\tPhase = [" << PHASE_MIN << ", " << PHASE_MAX << "]\n\n";
		}

		type_t
			amp = pix::random::drand<type_t>(AMP_MIN, AMP_MAX),
			offset = pix::random::drand<type_t>(OFFSET_MIN, OFFSET_MAX),
			freq = pix::random::drand<type_t>(FREQ_MIN, FREQ_MAX),
			phase = pix::random::drand<type_t>(PHASE_MIN, PHASE_MAX);

		// Log parameters
		{
			std::cout
				<< "Parameters:\n"
				<< "\tAmplitude = " << amp
				<< "\n\tOffset = " << offset
				<< "\n\tFreq = " << freq
				<< "\n\tPhase = " << phase << "\n\n";
		}

		type_t
			time[SIZE],
			signal[SIZE];

		// Create dataset
		{
			for (unsigned long i = 0; i < SIZE; ++i)
				time[i] = pix::random::drand<type_t>(TIME_INITIAL, TIME_FINAL);

			pix::sort::quick_sort(time, SIZE);
			type_t ang_freq = 2 * pix::constants::mathematics::PI * freq;

			for (unsigned long i = 0; i < SIZE; ++i)
				signal[i] = amp * pix::math::trig::sin(ang_freq * time[i] + phase) + offset;

			write_file(time, signal, SIZE, "files/signal.txt");
		}

		// Adjust the signal
		{
			pix::math::signal::mean_sub(signal, SIZE);
			pix::math::signal::norm(signal, SIZE);
			pix::math::signal::window::blackman(signal, SIZE);

			write_file(time, signal, SIZE, "files/adjust.txt");
		}

		type_t freq_domain[NUM_FREQS];

		// Create frequency domain
		{
			type_t step = (FREQ_MAX - FREQ_MIN) / NUM_FREQS;
			
			for (unsigned long i = 0; i < NUM_FREQS; ++i)
				freq_domain[i] = step * i + FREQ_MIN;
		}

		type_t transform[NUM_FREQS];

		// Create transform
		{
			pix::math::signal::transform::dft(time, signal, freq_domain, transform, SIZE, NUM_FREQS);
			write_file(freq_domain, transform, NUM_FREQS, "files/fourier.txt");
		}
	}

	// Function
	{
		auto func = pix::math::function<type_t, type_t, decltype(&f)>(f, 1E-6, 1E3);
		type_t zero = 0.25 * pix::constants::mathematics::PI;

		std::cout
			<< "f(" << zero << ") = " << func(zero) << '\n'
			<< "bissection = " << func.bissection(-10, 6) << '\n'
			<< "newton = " << func.newton(-2) << '\n'
			<< "secant = " << func.secant(-10, 6) << '\n'
			<< "golden = " << func.golden_root(-10, 6) << "\n\n";
	}

	// System of linear equations
	{
		constexpr const unsigned long DIM = 4;
		type_t
			mtx[DIM][DIM] =
			{
				{1, 2, 3, 5},
				{3, 2, 1, -2},
				{-1, 3, 5, 0},
				{2, 1, 3, 4}
			},
			vec[DIM] = {1, 3, 4, -1};

		std::cout << "Matrix:\n";
		utils::print(mtx);
		std::cout << "\nVector:\n";
		utils::print(vec);

		// Gaussian elimination
		{
			type_t sol[DIM]; // Solution vector

			pix::c_array::swap(vec, sol);
			pix::c_array::swap(vec, sol);

			pix::math::sys_lin_equ::gauss_elim(mtx, vec, sol);

			// Print solution
			std::cout << "\nSolution:\n";
			utils::print(sol);
		}

		// LU decomposition
		{
			type_t
				L[DIM][DIM], // Lower triangular matrix
				U[DIM][DIM]; // Upper triangular matrix

			pix::math::sys_lin_equ::lu_decomp(mtx, L, U);

			std::cout << "\nLower:\n";
			utils::print(L);
			std::cout << "\nUpper:\n";
			utils::print(U);
		}
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}

void write_file(const type_t input[], const type_t output[], const unsigned long SIZE, const char file_name[])
{
	std::ofstream file(file_name);

	for (unsigned long i = 0; i < SIZE; ++i)
		file << input[i] << ' ' << output[i] << '\n';

	file.close();
}

type_t f(const type_t x)
{
	return pix::math::trig::sin(x);
}
