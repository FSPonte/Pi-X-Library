#ifndef _ROOT_FINDING_TPP_
#define _ROOT_FINDING_TPP_

namespace pix::math::root_finding
{
	template <typename function, typename type_t>
	type_t bissection(const function fn, type_t a, type_t b, const type_t TOL, const unsigned long MAX_ITER) noexcept(false)
	{
		assert_is_float(type_t);

		if (a >= b) throw "Invalid interval (a >= b)";
		if (TOL >= 1) throw "Invalid value for tolerance (TOL >= 1)";
		if (MAX_ITER == 0) throw "Invalid maximum number of iteration (MAX_ITER == 0)";

		type_t
			x, // Mid point of the interval
			y_a = fn(a), // Image of a
			y_b = fn(b), // Image of b
			y; // Image of x

		if (y_a * y_b >= 0) throw "Invalid convergence condition (f(a) * f(b) >= 0)";

		for (unsigned long i = 1; i <= MAX_ITER; ++i)
		{
			x = a + 0.5 * (b - a);
			y = fn(x);

			if (y_a * y < 0)
			{
				b = x;
				y_b = fn(b);
			}
			else if (y * y_b < 0)
			{
				a = x;
				y_a = fn(a);
			}

			if (pix::math::abs(y) < TOL || a == b)
				break;
		}

		return x;
	}

	template <typename function, typename type_t>
	type_t newton(const function fn, type_t x, const type_t TOL, const unsigned long MAX_ITER) noexcept(false)
	{
		assert_is_float(type_t);

		if (TOL >= 1) throw "Invalid value for tolerance (TOL >= 1)";
		if (MAX_ITER == 0) throw "Invalid maximum number of iteration (MAX_ITER == 0)";

		type_t
			y = fn(x), // Image of x
			m; // Slope

		for (unsigned long i = 1; i <= MAX_ITER; ++i)
		{
			m = (fn(x + TOL) - fn(x)) / TOL;

			if (m == 0) throw "Null derivative (f'(x) == 0)";

			x -= fn(x) / m;
			y = fn(x);
			
			if (pix::math::abs(y) < TOL)
				break;
		}
		
		return x;
	}

	template <typename function, typename type_t>
	type_t secant(const function fn, type_t a, type_t b, const type_t TOL, const unsigned long MAX_ITER) noexcept(false)
	{
		assert_is_float(type_t);

		if (a >= b) throw "Invalid interval (a >= b)";
		if (TOL >= 1) throw "Invalid value for tolerance (TOL >= 1)";
		if (MAX_ITER == 0) throw "Invalid maximum number of iteration (MAX_ITER == 0)";

		type_t
			x,
			y_a = fn(a),
			y_b = fn(b),
			y = y_b;

		for (unsigned long i = 1; i <= MAX_ITER; ++i)
		{
			if (y_a == y_b) throw "Division by zero (f(a) == f(b))";
			
			// Secant step
			x = b - y_b * (b - a) / (y_b - y_a);

			// Update for next iteration
			a = b;
			y_a = y_b;
			b = x;
			y_b = fn(b);
			
			y = y_b;

			if (pix::math::abs(y) < TOL || a == b)
				break;
		}

		return b;
	}
}

#endif // _ROOT_FINDING_TPP_
