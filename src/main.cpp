// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Utilities
#include <utils.hpp>

// Pi-X library
#include <pix_lib.hpp>

using type_t = long double;

type_t function(type_t);
type_t model_function(type_t);

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
		INPUT_MIN = -2 * pix::constants::mathematics::PI,
		INPUT_MAX = 2 * pix::constants::mathematics::PI;

	while (true)
	{
		utils::clear();

		try
		{
			const type_t
				ERROR = pix::random::drand(0, 1),
				slope = pix::random::drand(-5, 5),
				y_inter = pix::random::drand(-3, 3);
			type_t input[SIZE];

			for (unsigned long i = 0; i < SIZE; ++i)
				input[i] = pix::random::drand(INPUT_MIN, INPUT_MAX);

			pix::sort::quick_sort(input, SIZE);
			type_t output[SIZE];

			for (unsigned long i = 0; i < SIZE; ++i)
				output[i] = (slope * function(input[i]) + y_inter) * (1 + pix::random::drand(-ERROR, ERROR));

			std::ofstream file("files/data.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << output[i] << '\n';

			file.close();

			type_t
				sum_in = 0,
				sum_out = 0,
				sum_in_out = 0,
				sum_in_sq = 0;

			for (unsigned long i = 0; i < SIZE; ++i)
			{
				sum_in += function(input[i]);
				sum_out += output[i];
				sum_in_out += function(input[i]) * output[i];
				sum_in_sq += pix::math::pow(function(input[i]), 2);
			}

			type_t
				model_slope = (SIZE * sum_in_out - sum_in * sum_out) / (SIZE * sum_in_sq - sum_in * sum_in),
				model_y_inter = (sum_out - slope * sum_in) / SIZE;

			std::cout
				<< "Slope = " << model_slope << '\n'
				<< "Y-Inter = " << model_y_inter << '\n';
			
			type_t model[SIZE];

			for (unsigned long i = 0; i < SIZE; ++i)
				model[i] = model_slope * model_function(input[i]) + model_y_inter;

			std::cout << "R^2 = " << pix::math::stat::coeff_det(output, model, SIZE) << '\n';
			file.open("files/aprox.txt");

			for (unsigned long i = 0; i < SIZE; ++i)
				file << input[i] << ' ' << model[i] << '\n';

			file.close();
			std::system("gnuplot scripts/plot.gp");
		}
		catch (const char ex_msg[])
		{ std::cout << "Exception: " << ex_msg << '\n'; }

		utils::pause();
	}

	return EXIT_SUCCESS;
}

type_t function(const type_t x)
{
	type_t ret;

	try
	{
		ret = pix::math::trig::sin(x);
	}
	catch (const char ex_msg[])
	{
		std::cout
			<< "Exception: " << ex_msg << '\n'
			<< "Input = " << x << '\n';
	}

	return ret;
}

type_t model_function(const type_t x)
{
	type_t ret;

	try
	{
		ret = pix::math::trig::cos(x - 0.5 * pix::constants::mathematics::PI);
	}
	catch (const char ex_msg[])
	{
		std::cout
			<< "Exception: " << ex_msg << '\n'
			<< "Input = " << x << '\n';
	}

	return ret;
}
