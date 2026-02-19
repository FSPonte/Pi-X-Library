#ifndef _INTERPOLATION_TPP_
#define _INTERPOLATION_TPP_

namespace pix::math::interpolation
{
	template <typename type_t, unsigned long DIM>
	type_t linear(type_t (&input)[DIM], type_t (&output)[DIM], const type_t TARGET) noexcept(false)
	{
		assert_is_float(type_t);

		if (TARGET < input[0] || input[DIM - 1] < TARGET)
			throw pix::exceptions::out_of_bounds;
		
		unsigned long
			left = pix::c_array::binary_approx(input, TARGET), // Left index
			right; // Right index

		if (TARGET < input[left] || left == DIM - 1)
			--left;

		right = left + 1;

		type_t den = input[right] - input[left]; // Denominator

		if (den == 0)
			throw pix::exceptions::div_zero;

		type_t
			slope = (output[right] - output[left]) / den,
			offset = 0.5 * (output[left] + output[right] - slope * (input[left] + input[right]));

		return slope * TARGET + offset;
	}

	template <typename type_t, unsigned long DIM>
	type_t newton(type_t (&input)[DIM], type_t (&output)[DIM], const type_t TARGET) noexcept(false)
	{
		assert_is_float(type_t);
		assert_not_nulldim(DIM);

		if (TARGET < input[0] || input[DIM - 1] < TARGET)
			throw pix::exceptions::out_of_bounds;

		type_t
			den, // Denominator
			table[DIM][DIM]; // Table of divided differences

		for (unsigned long i = 0; i < DIM; ++i)
			table[i][0] = output[i];

		for (unsigned long i = 1; i < DIM; ++i)
		{
			for (unsigned long j = 0; j < DIM - i; ++j)
			{
				den = input[i + j] - input[j];

				if (den == 0)
					throw pix::exceptions::div_zero;

				table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]) / den;
			}
		}

		type_t
			term = 1,
			ret = table[0][0]; // Return value

		for (unsigned long i = 1; i < DIM; ++i)
		{
			term *= (TARGET - input[i - 1]);
			ret += table[0][i] * term;
		}

		return ret;
	}

	template <typename type_t, unsigned long DIM>
	type_t spline(type_t (&input)[DIM], type_t (&output)[DIM], const type_t TARGET) noexcept(false)
	{
		assert_is_float(type_t);
		assert_not_nulldim(DIM);

		if (TARGET < input[0] || input[DIM - 1] < TARGET)
			throw pix::exceptions::out_of_bounds;

		type_t h[DIM - 1], alpha[DIM - 1];
		type_t l[DIM], mu[DIM], z[DIM];
		type_t a[DIM], b[DIM - 1], c[DIM], d[DIM - 1];

		for (unsigned long i = 0; i < DIM; ++i)
			a[i] = output[i];

		for (unsigned long i = 0; i < DIM - 1; ++i)
			h[i] = input[i + 1] - input[i];

		for (unsigned long i = 1; i < DIM - 1; ++i)
			alpha[i] = (3.0 * (a[i + 1] - a[i]) / h[i]) - (3.0 * (a[i] - a[i - 1]) / h[i - 1]);

		l[0] = 1.0;
		mu[0] = z[0] = 0.0;

		for (unsigned long i = 1; i < DIM - 1; ++i)
		{
			l[i] = 2.0 * (input[i + 1] - input[i - 1]) - h[i - 1] * mu[i - 1];
			mu[i] = h[i] / l[i];
			z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
		}

		l[DIM - 1] = 1.0;
		z[DIM - 1] = c[DIM - 1] = 0.0;

		for (long j = DIM - 2; j >= 0; --j)
		{
			c[j] = z[j] - mu[j] * c[j + 1];
			b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
			d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
		}

		unsigned long i = 0;
		for (; i < DIM - 2; ++i)
		{
			if (TARGET < input[i + 1])
				break;
		}

		type_t dx = TARGET - input[i];
		
		return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
	}

	template <typename type_t, unsigned long DIM>
	type_t lagrange(type_t (&input)[DIM], type_t (&output)[DIM], const type_t TARGET, unsigned long order) noexcept(false)
	{
		assert_is_float(type_t);
		assert_not_nulldim(DIM);

		if (TARGET < input[0] || TARGET > input[DIM - 1])
			throw pix::exceptions::out_of_bounds;

		if (order == 0)
			throw "Invalid order value";

		unsigned long
			index = pix::c_array::binary_approx(input, TARGET), // Aproximated index
			start = 0, // Start index
			end = DIM - 1; // End index

		if (index == 0)
			end = index + order;
		else if (index == DIM - 1)
			start = index - order;
		else if (index - 0.5 * order > index) // Check for underflow
		{
			order += index - 0.5 * order;
			index = 0;
		}
		else
		{
			start = index;
			end = index + order;
		}

		type_t
			term,
			sum = 0;

		for (unsigned long i = start; i <= end; ++i)
		{
			term = 1;

			for (unsigned long j = start; j <= end; ++j)
			{
				if (j != i)
				{
					term *= (TARGET - input[j]) / (input[i] - input[j]);
				}
			}

			sum += term * output[i];
		}

		return sum;
	}
}

#endif // _INTERPOLATION_TPP_