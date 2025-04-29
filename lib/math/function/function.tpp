#ifndef _FUNCTION_TPP_
#define _FUNCTION_TPP_

// Dependencies
#include <type_info.hpp>
#include <math.hpp>

namespace pix::math
{
	template<typename type_in, typename type_out, typename callable>
	function<type_in, type_out, callable>::function(const callable& func) : _callable(func)
	{
		is_float_static_assert(type_in);
		is_float_static_assert(type_out);
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::operator () (const type_in& x) const
	{
		return this->_callable(x);
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::bissection(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";
		if (this->_callable(a) * this->_callable(b) >= 0) throw "Invalid convergence condition (f(a) * f(b) >= 0)";

		type_in x; // Mid point of the interval
		type_out y; // Image of the mid point

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			x = a + 0.5 * (b - a);
			y = this->_callable(x);

			if (this->_callable(a) * y < 0)
				b = x;
			else if (y * this->_callable(b) < 0)
				a = x;

			if (a >= b || pix::math::abs(y) < pix::math::PR_THRESHOLD)
				break;
		}

		return x;
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::newton(type_in x) const noexcept(false)
	{
		type_out
			der, // Derivative
			y; // Image of the mid point

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			der = this->derivative(x);

			if (der == 0) throw "Null derivative (f'(x) == 0)";

			x -= this->_callable(x) / der;
			y = this->_callable(x);
			
			if (pix::math::abs(y) < pix::math::PR_THRESHOLD)
				break;
		}
		
		return x;
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::secant(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";

		type_in x;
		type_out
			y_a = this->_callable(a),
			y_b = this->_callable(b),
			y = y_b;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			if (y_a == y_b) throw "Division by zero (f(a) == f(b))";
			
			// Secant step
			x = b - y_b * (b - a) / (y_b - y_a);

			// Update for next iteration
			a = b;
			y_a = y_b;
			b = x;
			y_b = this->_callable(b);
			
			y = y_b;

			if (pix::math::abs(y) < pix::math::PR_THRESHOLD)
				break;
		}

		return b;
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::golden_root(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";

		type_out
			y_a = this->_callable(a),
			y_b = this->_callable(b);

		if (y_a * y_b > 0) throw "Invalid convergence condition (f(a) * f(b) >= 0)";

		const auto invphi = static_cast<type_in>(0.5 * (pix::math::root(5.0, 2) - 1)); // Inverse of the golden ratio
		type_in c, d;

		for (unsigned long i = 0; i < pix::math::MAX_ITER; ++i)
		{
			c = b - (b - a) * invphi;
			d = a + (b - a) * invphi;
			
			if (this->_callable(c) < this->_callable(d))
				b = d;
			else
				a = c;

			if (b - a > pix::math::PR_THRESHOLD)
				break;
		}

		return 0.5 * (b + a);
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::derivative(const type_in x) const
	{
		return static_cast<type_out>((this->_callable(x + pix::math::PR_THRESHOLD) - this->_callable(x)) / pix::math::PR_THRESHOLD);
	}
}

#endif // _FUNCTION_TPP_
