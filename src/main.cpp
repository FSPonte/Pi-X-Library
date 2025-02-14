// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

#define function_dataset(arg) pix::math::trig::cos(arg)
#define function_model(arg) pix::math::trig::sin(arg)
#define function_model_inv(arg) pix::math::trig::arcsin(arg)

using type_t = long double;

int main(int argc, char* argv[])
{
	/*
	utils::clear();
	utils::parse(argc, argv);
	utils::pause();
	utils::clear();

	for (unsigned long i = 1; i < argc; ++i)
	{
		std::cout << "File: " << argv[i] << "\n\n";

		utils::print_file(argv[i]);
		utils::pause();
		utils::clear();

		std::cout << "File: " << argv[i] << "\n\n";

		utils::print_file_hex(argv[i]);
		utils::pause();
		utils::clear();
	}
	*/

	constexpr const unsigned long SIZE = 1E3;
	constexpr const type_t
		INPUT_MIN = 1,
		INPUT_MAX = 10;
	const type_t
		amplitude = pix::random::drand(-5, 5),
		y_inter = pix::random::drand(-3, 3),
		ERROR = pix::random::drand(0, 0.75);
	type_t
		input[SIZE],
		output[SIZE],
		model[SIZE],
		model_amplitude,
		model_y_inter,
		model_phase;
	std::ofstream file;

	// Manage dataset
	{
		for (unsigned long i = 0; i < SIZE; ++i)
			input[i] = pix::random::drand(INPUT_MIN, INPUT_MAX);

		pix::sort::quick_sort(input, SIZE);

		for (unsigned long i = 0; i < SIZE; ++i)
			output[i] = (amplitude * function_dataset(input[i]) + y_inter) * (1 + pix::random::drand(-ERROR, ERROR));

		file.open("files/dataset.txt");

		for (unsigned long i = 0; i < SIZE; ++i)
			file << input[i] << ' ' << output[i] << '\n';

		file.close();
	}

	// Manage model
	{
		type_t
			sum_in = 0,
			sum_out = 0,
			sum_in_out = 0,
			sum_in_sq = 0;

		for (unsigned long i = 0; i < SIZE; ++i)
		{
			sum_in += function_dataset(input[i]);
			sum_out += output[i];
			sum_in_out += function_dataset(input[i]) * output[i];
			sum_in_sq += pix::math::pow(function_dataset(input[i]), 2);
		}

		model_amplitude = (SIZE * sum_in_out - sum_in * sum_out) / (SIZE * sum_in_sq - pix::math::pow(sum_in, 2));
		model_y_inter = (sum_out - model_amplitude * sum_in) / SIZE;
		model_phase = 0;

		for (unsigned long i = 0; i < SIZE; ++i)
			model_phase += function_model_inv((output[i] - y_inter) / amplitude);

		model_phase = (model_phase - sum_in) / SIZE;

		for (unsigned long i = 0; i < SIZE; ++i)
			model[i] = model_amplitude * function_model(input[i] - model_phase) + model_y_inter;

		file.open("files/model.txt");

		for (unsigned long i = 0; i < SIZE; ++i)
			file << input[i] << ' ' << model[i] << '\n';

		file.close();
	}

	std::system("gnuplot scripts/plot.gp");

	std::cout
		<< "Parameters:" << '\n'
		<< '\t' << "Size = " << SIZE << '\n'
		<< '\t' << "Input min = " << INPUT_MIN << '\n'
		<< '\t' << "Input max = " << INPUT_MAX << '\n'
		<< '\t' << "Error = " << ERROR << "\n\n"
		<< "Dataset:" << '\n'
		<< '\t' << "Amplitude = " << amplitude << '\n'
		<< '\t' << "Y-Inter = " << y_inter << "\n\n"
		<< "Model:" << '\n'
		<< '\t' << "Amplitude = " << model_amplitude << '\n'
		<< '\t' << "Y-Inter = " << model_y_inter << '\n'
		<< '\t' << "Phase = " << model_phase << '\n'
		<< '\t' << "R^2 = " << pix::math::stat::coeff_det(output, model, SIZE) << '\n';

	return EXIT_SUCCESS;
}
