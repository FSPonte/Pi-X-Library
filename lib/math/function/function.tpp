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
		is_number_static_assert(type_in);
		is_number_static_assert(type_out);
	}

	template<typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::operator () (const type_in& x) const
	{
		return this->_callable(x);
	}

	template<typename type_in, typename type_out, typename callable>
	template <typename type_t>
	type_out function<type_in, type_out, callable>::bissection(type_in a, type_in b) const noexcept(false)
	{
		is_float_static_assert(type_t);

		if (a > b) throw "Invalid range (a > b)";
		
		if (a == b) return this->_callable(a);

		if (this->_callable(a) * this->_callable(b) >= 0)
			return type_out();

		type_in x; // Mid point of the interval
		type_out y; // Image of the mid point

		do
		{
			x = a + 0.5 * (b - a);
			y = this->_callable(x);

			if (this->_callable(a) * y < 0)
				b = x;
			else if (y * this->_callable(b) < 0)
				a = x;

			if (y < 0) // Turn the value of y into it's own absolute value
				y *= -1;
		}
		while (a < b && y > pix::math::PR_THRESHOLD);

		return x;
	}

	template<typename type_in, typename type_out, typename callable>
	template <typename type_t>
	type_out function<type_in, type_out, callable>::newton(type_in x) const noexcept(false)
	{
		is_float_static_assert(type_t);

		type_out y; // Image of the mid point

		do
		{
			x -= this->_callable(x) / this->derivative(x);
			y = this->_callable(x);
			
			if (y < 0) // Turn the value of y into it's own absolute value
				y *= -1;
		}
		while (y > pix::math::PR_THRESHOLD);
		
		return x;
	}

	template<typename type_in, typename type_out, typename callable>
	template <typename type_t>
	type_out function<type_in, type_out, callable>::secant(type_in x_0, type_in x_1) const noexcept(false)
	{
		is_float_static_assert(type_t);

		type_in x;
		type_out
			y_0 = this->_callable(x_0),
			y_1 = this->_callable(x_1),
			y = y_1;

		do
		{
			if (y_0 == y_1) throw "Division by zero (y_0 == y_1)";
			
			// Secant step
			x = x_1 - y_1 * (x_1 - x_0) / (y_1 - y_0);

			// Update for next iteration
			x_0 = x_1;
			y_0 = y_1;
			x_1 = x;
			y_1 = this->_callable(x_1);
			
			y = y_1;

			if (y < 0) // Turn the value of y into it's own absolute value
				y *= -1;
		}
		while (y > pix::math::PR_THRESHOLD);

		return x_1;
	}

	template<typename type_in, typename type_out, typename callable>
	template <typename type_t>
	type_out function<type_in, type_out, callable>::golden_root(type_in a, type_in b) const noexcept(false)
	{
		is_float_static_assert(type_t);

		if (a >= b) throw "Invalid interval (a >= b)";

		type_out
			y_a = this->_callable(a),
			y_b = this->_callable(b);

		if (y_a * y_b > 0)
			throw "The function must have opposite signs at the interval endpoints";

		const type_t phi = static_cast<type_t>(0.5 * (3.0 - pix::math::root(5.0, 2))); // ~0.381966

		type_in x_1, x_2;
		type_out y_1, y_2;

		while ((b - a) > pix::math::PR_THRESHOLD)
		{
			x_1 = b - phi * (b - a);
			x_2 = a + phi * (b - a);

			y_1 = this->_callable(x_1);
			y_2 = this->_callable(x_2);

			// Check for sign changes to bracket root
			if (y_a * y_1 < 0)
			{
				b = x_1;
				y_b = y_1;
			}
			else if (y_1 * y_2 < 0)
			{
				a = x_1;
				y_a = y_1;
				b = x_2;
				y_b = y_2;
			}
			else // f2 * fb < 0
			{
				a = x_2;
				y_a = y_2;
			}
		}

		// Return midpoint of final interval as estimated root
		return static_cast<type_out>(0.5 * (a + b));
	}

	template <typename type_in, typename type_out, typename callable>
	template <typename type_t>
	type_out function<type_in, type_out, callable>::derivative(const type_in arg) const noexcept(false)
	{
		is_float_static_assert(type_t);

		return static_cast<type_out>((this->_callable(arg + pix::math::PR_THRESHOLD) - this->_callable(arg)) / pix::math::PR_THRESHOLD);
	}
}

#endif // _FUNCTION_TPP_
