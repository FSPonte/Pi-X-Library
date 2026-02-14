#ifndef _INTEGRATION_TPP_
#define _INTEGRATION_TPP_

namespace pix::math::integration
{
	template <typename function, typename type_t>
	type_t trapezoid(const function f, const type_t a, const type_t b, const type_t TOL) noexcept(false)
	{
		assert_is_float(type_t);

		if (a >= b) throw "Invalid interval for integration (a >= b)";
		if (TOL >= 1) throw "Invalid value for tolerance (TOL >= 1)";

		type_t
			step = TOL * (b - a), // Step value
			x_1 = a,
			x_2 = x_1 + step,
			y_1,
			y_2,
			ret = 0; // Return value

		while (x_2 < b)
		{
			y_1 = f(x_1);
			y_2 = f(x_2);
			ret += y_1 + y_2;
			x_1 = x_2;
			x_2 += step;
		}

		return 0.5 * step * ret;
	}

	template <typename function, typename type_t>
	type_t romberg(const function f, const type_t a, const type_t b, const type_t TOL, const unsigned long MAX_STEPS) noexcept(false)
	{
		assert_is_float(type_t);

		if (a >= b) throw "Invalid interval for integration (a >= b)";
		if (TOL >= 1) throw "Invalid value for tolerance (TOL >= 1)";
		if (MAX_STEPS == 0) throw "Invalid number of steps (MAX_STEPS == 0)";

		type_t
			*R1 = new type_t[MAX_STEPS],
			*R2 = new type_t[MAX_STEPS],
			*Rp = &R1[0],
			*Rc = &R2[0], // Rp is previous row, Rc is current row
			h = b - a; //step size

		Rp[0] = 0.5 * h * (f(a) + f(b)); // first trapezoidal step

		unsigned long ep;
		type_t c, n_k, *rt;

		for (unsigned long i = 1; i < MAX_STEPS; ++i)
		{
			h /= 2.0;
			c = 0;
			ep = 1 << (i - 1); //2^(n-1)

			for (unsigned long j = 1; j <= ep; ++j)
				c += f(a + (2 * j - 1) * h);
			
			Rc[0] = h * c + 0.5 * Rp[0]; // R(i,0)

			for (unsigned long j = 1; j <= i; ++j)
			{
				n_k = pix::math::pow(static_cast<type_t>(4), static_cast<type_t>(j));
				Rc[j] = (n_k * Rc[j - 1] - Rp[j - 1]) / (n_k - 1); // compute R(i,j)
			}

			if (i > 1 && pix::math::abs(Rp[i - 1] - Rc[i]) < TOL)
			{
				Rp[MAX_STEPS - 1] = Rc[i];

				break;
			}

			// swap Rn and Rc as we only need the last row
			rt = Rp;
			Rp = Rc;
			Rc = rt;
		}

		delete[] R1;
		delete[] R2;

		return Rp[MAX_STEPS - 1]; // return our best guess
	}
}

#endif // _INTEGRATION_TPP_
