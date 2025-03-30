// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

using type_t = double;

constexpr const unsigned long
	DIM = 1E3,
	MAX_ITER = 1E3;
constexpr const type_t
	AMP_MAX = 5,
	OFFSET_MAX = 10,
	FREQ_MAX = 5,
	PHASE_MAX = pix::constants::mathematics::PI,
	ERROR = 1,
	THRESHOLD = 1E-3,
	LEARN_RATE = 1E-6,
	STEP = 1E-2;

struct parameters
{
	type_t
		amp,
		offset,
		freq,
		phase;
};

type_t function(parameters, type_t);
type_t function_der_amp(parameters, type_t);
type_t function_der_offset(parameters, type_t);
type_t function_der_freq(parameters, type_t);
type_t function_der_phase(parameters, type_t);

int main(int argc, char* argv[])
{
	type_t
		input[DIM],
		output[DIM],
		aprox[DIM];
	std::ofstream file;

	// Manage dataset
	{
		parameters dataset =
		{
			pix::random::drand<type_t>(0, AMP_MAX),
			pix::random::drand(-OFFSET_MAX, OFFSET_MAX),
			pix::random::drand<type_t>(0, FREQ_MAX),
			pix::random::drand(-PHASE_MAX, PHASE_MAX)
		};

		// Log dataset parameters
		{
			std::cout
				<< "Dataset:\n"
				<< "\tAmplitude = " << dataset.amp << '\n'
				<< "\tOffset = " << dataset.offset << '\n'
				<< "\tFrequency = " << dataset.freq << '\n'
				<< "\tPhase = " << dataset.phase << "\n\n";
		}

		for (unsigned long i = 0; i < DIM; ++i)
			input[i] = pix::random::drand<type_t>(0, 2 * pix::constants::mathematics::PI);

		pix::sort::quick_sort(input, DIM);

		for (unsigned long i = 0; i < DIM; ++i)
		{
			output[i] = function(dataset, input[i]);
			output[i] += pix::random::drand(-ERROR, ERROR);
		}

		// Write dataset.txt
		{
			file.open("files/dataset.txt");

			for (unsigned long i = 0; i < DIM; ++i)
				file << input[i] << ' ' << output[i] << '\n';

			file.close();
		}
	}

	// Manage model
	{
		std::cout << "Model:" << '\n';

		unsigned long iter;
		type_t coeff_det; // Coefficient of determination (R^2)
		parameters model;

		// Initial model paramters
		{
			model = parameters
			{
				0.5 * pix::math::stat::amp(output, DIM),
				pix::math::stat::mean(output, DIM),
				1,
				0
			};

			// Log initial model parameters
			{
				std::cout
					<< "\tInitial values:\n"
					<< "\t\tAmp = " << model.amp << '\n'
					<< "\t\tOffset = " << model.offset << '\n'
					<< "\t\tFreq = " << model.freq << '\n'
					<< "\t\tPhase = " << model.phase << "\n\n";
			}
		}

		// Training model
		{
			std::cout << std::setprecision(3) << std::fixed;

			type_t coeff = 2.0 / DIM;
			parameters sum, grad;

			for (iter = 0; iter < MAX_ITER; ++iter)
			{
				sum.amp = 0;
				sum.offset = 0;
				sum.freq = 0;
				sum.phase = 0;

				for (unsigned long i = 0; i < DIM; ++i)
				{
					sum.amp += (function(model, input[i]) - output[i]) * function_der_amp(model, input[i]);
					sum.offset += (function(model, input[i]) - output[i]) * function_der_offset(model, input[i]);
					sum.freq += (function(model, input[i]) - output[i]) * function_der_freq(model, input[i]);
					sum.phase += (function(model, input[i]) - output[i]) * function_der_phase(model, input[i]);
				}

				grad.amp = coeff * sum.amp;
				grad.offset = coeff * sum.offset;
				grad.freq = coeff * sum.freq;
				grad.phase = coeff * sum.phase;

				if
				(
					grad.amp < THRESHOLD &&
					grad.offset < THRESHOLD &&
					grad.freq < THRESHOLD &&
					grad.phase < THRESHOLD
				) break;

				model.amp -= LEARN_RATE * grad.amp;
				model.offset -= LEARN_RATE * grad.offset;
				model.freq -= LEARN_RATE * grad.freq;
				model.phase -= LEARN_RATE * grad.phase;

				for (unsigned long i = 0; i < DIM; ++i)
					aprox[i] = function(model, input[i]);

				coeff_det = pix::math::stat::coeff_det(output, aprox, DIM);

				// Log progress
				{
					std::cout
						<< "> Progress... "
						<< 100.0 * iter / pix::math::MAX_ITER << " %"
						<< " | R^2 = " << coeff_det
						<< "                    \r"
						<< std::flush;
				}
			}

			std::cout << "\r                                                  \r" << std::flush;
			std::cout.precision();

			// Write aprox.txt
			{
				file.open("files/aprox.txt");

				for (unsigned long i = 0; i < DIM; ++i)
					file << input[i] << ' ' << aprox[i] << '\n';

				file.close();
			}
		}

		// Fourier transform
		{
			constexpr const unsigned long FREQ_DIM = 5 / STEP;
			type_t freq[FREQ_DIM], transform[DIM];

			freq[0] = 0;

			for (unsigned long i = 1; i < FREQ_DIM; ++i)
				freq[i] = freq[i - 1] + STEP;

			pix::math::signal::mean_sub(aprox, DIM);
			pix::math::signal::norm(aprox, DIM);
			pix::math::signal::window::blackman(aprox, DIM);
			pix::math::signal::transform::ndft(input, aprox, freq, transform, DIM, FREQ_DIM);
			
			// Write fourier.txt
			{
				file.open("files/fourier.txt");

				for (unsigned long i = 0; i < FREQ_DIM; ++i)
					file << freq[i] << ' ' << transform[i] << '\n';

				file.close();
			}
		}

		// Log model parameters
		{
			std::cout
				<< "\tTrained values:\n"
				<< "\t\tAmp = " << model.amp << '\n'
				<< "\t\tOffset = " << model.offset << '\n'
				<< "\t\tFreq = " << model.freq << '\n'
				<< "\t\tPhase = " << model.phase<< "\n\n"
				<< "Iter = " << iter << '\n'
				<< "R^2 = " << coeff_det << "\n\n";
		}
	}

	return EXIT_SUCCESS;
}

type_t function(const parameters params, const type_t input)
{ return params.amp * pix::math::trig::sin(2 * pix::constants::mathematics::PI * params.freq * input + params.phase) + params.offset; }

type_t function_der_amp(const parameters params, const type_t input)
{ return pix::math::trig::sin(2 * pix::constants::mathematics::PI * params.freq * input + params.phase); }

type_t function_der_offset(const parameters params, const type_t input)
{ return 1; }

type_t function_der_freq(const parameters params, const type_t input)
{ return params.amp * pix::math::trig::cos(2 * pix::constants::mathematics::PI * params.freq * input + params.phase) * input; }

type_t function_der_phase(const parameters params, const type_t input)
{ return params.amp * pix::math::trig::cos(2 * pix::constants::mathematics::PI * params.freq * input + params.phase); }
