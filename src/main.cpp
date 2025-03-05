// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

#define MAX_ITER 1E3
#define THRESHOLD 1E-1
#define LEARN_RATE 1E-6

using type_t = long double;

constexpr const unsigned long SIZE = 1E3;
constexpr const type_t
	INPUT_MIN = -2 * pix::constants::mathematics::PI,
	INPUT_MAX = 2 * pix::constants::mathematics::PI,
	ERROR_MAX = 1;
const type_t ERROR = pix::random::drand(0, ERROR_MAX);

struct container
{
	type_t
		amp, // Amplitude
		offset, // Y Intercept
		freq, // Frequency
		phase; // Phase shift
};

type_t function(container, type_t);
type_t function_der_amp(container, type_t);
type_t function_der_offset(container, type_t);
type_t function_der_freq(container, type_t);
type_t function_der_phase(container, type_t);

int main(int argc, char* argv[])
{
	// Log parameters
	{
		std::cout
			<< "Parameters:\n"
			<< "\tSize = " << SIZE << '\n'
			<< "\tRange = [" << INPUT_MIN << ", " << INPUT_MAX << "]\n"
			<< "\tError = " << ERROR << '\n'
			<< "\tMAX_ITER = " << MAX_ITER << '\n'
			<< "\tThreshold = " << THRESHOLD << '\n'
			<< "\tLearning rate = " << LEARN_RATE << "\n\n";
	}

	unsigned long iter = 0;
	type_t
		input[SIZE],
		output[SIZE],
		aprox[SIZE],
		derivative[SIZE - 1];
	container
		dataset,
		model;
	std::ofstream file;

	// Manage dataset
	{
		// Initial values
		{
			dataset = container
			{
				pix::random::drand(0, 10),
				pix::random::drand(-5, 5),
				pix::random::drand(0, 5),
				pix::random::drand(- pix::constants::mathematics::PI, pix::constants::mathematics::PI)
			};
		}

		// Log dataset
		{
			std::cout
				<< "Dataset:\n"
				<< "\tAmp = " << dataset.amp << '\n'
				<< "\tOffset = " << dataset.offset << '\n'
				<< "\tFreq = " << dataset.freq << '\n'
				<< "\tPhase = " << dataset.phase << "\n\n";
		}

		// Create dataset
		{
			for (unsigned long i = 0; i < SIZE; ++i)
				input[i] = pix::random::drand(INPUT_MIN, INPUT_MAX);

			pix::sort::quick_sort(input, SIZE);

			for (unsigned long i = 0; i < SIZE; ++i)
			{
				output[i] = function(dataset, input[i]);
				output[i] += pix::random::drand(-ERROR, ERROR);
			}
		}

		// Write data.txt
		{
			file.open("files/data.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << output[i] << '\n';

			file.close();
		}
	}

	// Manage model
	{
		std::cout << "Model:" << '\n';

		type_t coeff_det; // Coefficient of determination (R^2)

		// Initial values
		{
			type_t
				min_val = output[0], // Minimum value
				max_val = output[0], // Maximum value
				sum = output[0], // Sum of all elements
				num_zeros = 0; // Number of zero crossings

			for (unsigned long i = 1; i < SIZE; ++i)
			{
				if (output[i] < min_val)
					min_val = output[i];

				if (output[i] > max_val)
					max_val = output[i];

				sum += output[i];
			}

			model = container
			{
				0.5 * (max_val - min_val),
				sum / SIZE,
				1,
				0
			};

			// Log
			{
				std::cout
					<< '\t' << "Initial values:" << '\n'
					<< "\t\t" << "Amp = " << model.amp << '\n'
					<< "\t\t" << "Offset = " << model.offset << '\n'
					<< "\t\t" << "Freq = " << model.freq << '\n'
					<< "\t\t" << "Phase = " << model.phase << "\n\n";
			}
		}

		// Training
		{
			std::cout << std::setprecision(3) << std::fixed;

			type_t coeff = 2.0 / SIZE;
			container sum, grad;

			for (iter; iter < MAX_ITER; ++iter)
			{
				sum.amp = 0;
				sum.offset = 0;
				sum.freq = 0;
				sum.phase = 0;

				for (unsigned long i = 0; i < SIZE; ++i)
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

				if (grad.amp < THRESHOLD && grad.offset < THRESHOLD && grad.freq < THRESHOLD && grad.phase < THRESHOLD)
					break;

				model.amp -= LEARN_RATE * grad.amp;
				model.offset -= LEARN_RATE * grad.offset;
				model.freq -= LEARN_RATE * grad.freq;
				model.phase -= LEARN_RATE * grad.phase;

				for (unsigned long i = 0; i < SIZE; ++i)
					aprox[i] = function(model, input[i]);

				coeff_det = pix::math::stat::coeff_det(output, aprox, SIZE);

				// Log
				{
					std::cout
						<< "> Progress... "
						<< 100.0 * iter / MAX_ITER << " %"
						<< " | R^2 = " << coeff_det
						<< "                    \r"
						<< std::flush;
				}
			}

			std::cout << "\r                                                  \r" << std::flush;
			std::cout.precision();
		}

		// Log model
		{
			std::cout
				<< "\tModel:\n"
				<< "\t\tAmp = " << model.amp << '\n'
				<< "\t\tOffset = " << model.offset << '\n'
				<< "\t\tFreq = " << model.freq << '\n'
				<< "\t\tPhase = " << model.phase<< "\n\n"
				<< "Number of iterations: " << iter << '\n'
				<< "R^2 = " << coeff_det << "\n\n";
		}

		// Write aprox.txt
		{
			file.open("files/aprox.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << aprox[i] << '\n';

			file.close();
		}

		// Calculate derivative
		{
			for (unsigned long i = 0; i < SIZE - 1; ++i)
				derivative[i] = (aprox[i + 1] - aprox[i]) / (input[i + 1] - input[i]);
		}

		// Write der.txt
		{
			file.open("files/der.txt");

			for (unsigned long i = 0; i < SIZE - 1; ++i)
				file << input[i] << ' ' << derivative[i] << '\n';

			file.close();
		}
	}

	std::system("gnuplot scripts/plot.gp");

	return EXIT_SUCCESS;
}

type_t function(const container params, const type_t input)
{ return params.amp * pix::math::trig::sin(params.freq * input + params.phase) + params.offset; }

type_t function_der_amp(const container params, const type_t input)
{ return pix::math::trig::sin(params.freq * input + params.phase); }

type_t function_der_offset(const container params, const type_t input)
{ return 1; }

type_t function_der_freq(const container params, const type_t input)
{ return params.amp * pix::math::trig::cos(params.freq * input + params.phase) * input; }

type_t function_der_phase(const container params, const type_t input)
{ return params.amp * pix::math::trig::cos(params.freq * input + params.phase); }
