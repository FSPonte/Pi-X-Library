// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

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

	using type_t = long double;
	constexpr const unsigned long SIZE = 1E3;
	constexpr const type_t
		MIN = 0,
		MAX = 10,
		ERROR = 0.8;
	type_t
		var,
		input[SIZE],
		output[SIZE];

	try
	{
		for (unsigned long i = 0; i < SIZE; ++i)
			input[i] = pix::random::drand(MIN, MAX);

		pix::sort::quick_sort(input, SIZE);

		for (unsigned long i = 0; i < SIZE; ++i)
		{
			output[i] = 5 * pix::math::log(input[i]) - 2.5;

			var = ERROR * pix::math::abs(output[i]);
			output[i] += pix::random::drand(output[i] - var, output[i] + var);
		}

		// Write data to file 1
		{
			std::ofstream file("files/data.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << output[i] << '\n';

			file.close();
		}

		type_t
			input_log[SIZE],
			sum_input = 0,
			sum_output = 0,
			sum_input_squared = 0,
			sum_input_output = 0;

		for (unsigned long i = 0; i < SIZE; ++i)
		{
			input_log[i] = pix::math::log(input[i]);
			sum_input += input_log[i];
			sum_output += output[i];
			sum_input_squared += input_log[i] * input_log[i];
			sum_input_output += input_log[i] * output[i];
		}

		type_t
			m = (SIZE * sum_input_output - sum_input * sum_output) / (SIZE * sum_input_squared - sum_input * sum_input),
			b = (sum_output - m * sum_input) / SIZE;

		std::cout
			<< "m = " << m << '\n'
			<< "b = " << b << '\n';

		type_t model[SIZE];

		for (unsigned long i = 0; i < SIZE; ++i)
			model[i] = m * pix::math::log(input[i]) + b;

		std::cout
			<< "Mean = " << pix::math::stat::mean(output, SIZE) << '\n'
			<< "Variance = " << pix::math::stat::var(output, SIZE) << '\n'
			<< "Std_dev = " << pix::math::stat::std_dev(output, SIZE) << '\n'
			<< "Covariance = " << pix::math::stat::cov(input, output, SIZE) << '\n'
			<< "R^2 = " << pix::math::stat::coeff_det(output, model, SIZE) << '\n';

		// Write data to file 1
		{
			std::ofstream file("files/aprox.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << m * pix::math::log(input[i]) + b << '\n';

			file.close();
		}
	}
	catch (const char msg[])
	{ std::cout << "Exception: " << msg << '\n'; }

	std::system("gnuplot scripts/plot.gp");

	return EXIT_SUCCESS;
}
