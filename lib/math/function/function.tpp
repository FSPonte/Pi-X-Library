#ifndef _FUNCTION_TPP_
#define _FUNCTION_TPP_

// Dependencies
#include <macros.hpp>
#include <type_info.hpp>

namespace pix::math
{
	template <typename type_in, typename type_out, typename callable>
	function<type_in, type_out, callable>::function(const callable& FUNC, const double TOL, const unsigned long MAX_ITER) noexcept(false) : _callable(FUNC)
	{
		is_float_static_assert(type_in);
		is_float_static_assert(type_out);

		if (TOL <= 0) throw "Invalid tolerance (TOL <= 0)";
		if (MAX_ITER == 0) throw "Invalid maximum number of iterations (MAX_ITER == 0)";
		
		this->_TOL = TOL;
		this->_MAX_ITER = MAX_ITER;
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::operator () (const type_in& INPUT) const
	{
		return this->_callable(INPUT);
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::bissection(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";

		type_in x; // Mid point of the interval
		type_out
			y_a = this->_callable(a), // Image of a
			y_b = this->_callable(b), // Image of b
			y; // Image of x

		if (y_a * y_b >= 0) throw "Invalid convergence condition (f(a) * f(b) >= 0)";

		// Logger
		LOGGER_INIT("logs/bissection.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTOL = " + std::to_string(this->_TOL));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(this->_MAX_ITER));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
			LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
		}

		for (unsigned long i = 1; i <= this->_MAX_ITER; ++i)
		{
			x = a + 0.5 * (b - a);
			y = this->_callable(x);

			if (y_a * y < 0)
			{
				b = x;
				y_b = this->_callable(b);
			}
			else if (y * y_b < 0)
			{
				a = x;
				y_a = this->_callable(a);
			}

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
				LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
			}

			if (pix::math::abs(y) < this->_TOL || a == b)
				break;
		}

		return x;
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::newton(type_in x) const noexcept(false)
	{
		type_out
			y = this->_callable(x), // Image of x
			m; // Slope

		// Logger
		LOGGER_INIT("logs/newton.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTOL = " + std::to_string(this->_TOL));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(this->_MAX_ITER));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\tx = " + std::to_string(x) + " | f(x) = " + std::to_string(y));
		}

		for (unsigned long i = 1; i <= this->_MAX_ITER; ++i)
		{
			m = this->derivative(x);

			if (m == 0) throw "Null derivative (f'(x) == 0)";

			x -= this->_callable(x) / m;
			y = this->_callable(x);

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\tm = " + std::to_string(m));
				LOGGER_LOG_MSG("\tx = " + std::to_string(x) + " | f(x) = " + std::to_string(y));
			}
			
			if (pix::math::abs(y) < this->_TOL)
				break;
		}
		
		return x;
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::secant(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";

		type_in x;
		type_out
			y_a = this->_callable(a),
			y_b = this->_callable(b),
			y = y_b;

		// Logger
		LOGGER_INIT("logs/secant.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTOL = " + std::to_string(this->_TOL));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(this->_MAX_ITER));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
			LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
		}

		for (unsigned long i = 1; i <= this->_MAX_ITER; ++i)
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

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
				LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
			}

			if (pix::math::abs(y) < this->_TOL || a == b)
				break;
		}

		return b;
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::golden_root(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw "Invalid interval (a >= b)";

		type_out
			y_a = this->_callable(a),
			y_b = this->_callable(b);

		if (y_a * y_b > 0) throw "Invalid convergence condition (f(a) * f(b) >= 0)";

		constexpr const auto INVPHI = static_cast<type_in>(1.0 / pix::constants::mathematics::GOLDEN_RATIO); // Inverse of the golden ratio
		type_in c, d;

		// Logger
		LOGGER_INIT("logs/golden_root.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTOL = " + std::to_string(this->_TOL));
			LOGGER_LOG_MSG("\tMAX_ITER = " + std::to_string(this->_MAX_ITER));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
			LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
		}

		for (unsigned long i = 1; i <= this->_MAX_ITER; ++i)
		{
			c = b - (b - a) * INVPHI;
			d = a + (b - a) * INVPHI;
			
			if (this->_callable(c) < this->_callable(d))
			{
				b = d;
				y_b = this->_callable(b);
			}
			else
			{
				a = c;
				y_a = this->_callable(a);
			}

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\ta = " + std::to_string(a) + " | f(a) = " + std::to_string(y_a));
				LOGGER_LOG_MSG("\tb = " + std::to_string(b) + " | f(b) = " + std::to_string(y_b));
			}

			if (b - a < this->_TOL)
				break;
		}

		return (y_a < y_b) ? a : b;
	}

	template <typename type_in, typename type_out, typename callable>
	type_out function<type_in, type_out, callable>::derivative(const type_in INPUT) const
	{
		static const auto h = static_cast<type_in>(this->_TOL);

		return static_cast<type_out>((this->_callable(INPUT + h) - this->_callable(INPUT)) / h);
	}
}

#endif // _FUNCTION_TPP_
