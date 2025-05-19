#ifndef _FUNCTION_TPP_
#define _FUNCTION_TPP_

namespace pix::math
{
	template <typename callable, typename type_in, typename type_out>
	function<callable, type_in, type_out>::function(const callable& FUNC, const type_in TOL, const unsigned long MAX_ITER) noexcept(false) : _callable(FUNC)
	{
		assert_is_float(type_in);
		assert_is_float(type_out);

		if (TOL <= 0) throw "Invalid tolerance (TOL <= 0)";
		if (MAX_ITER == 0) throw "Invalid maximum number of iterations (MAX_ITER == 0)";
		
		this->_TOL = TOL;
		this->_MAX_ITER = MAX_ITER;
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::operator () (const type_in& INPUT) const
	{
		return static_cast<type_out>(this->_callable(INPUT));
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::bissection(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw pix::exceptions::bad_range;

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

		return static_cast<type_out>(x);
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::newton(type_in x) const noexcept(false)
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
		
		return static_cast<type_out>(x);
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::secant(type_in a, type_in b) const noexcept(false)
	{
		if (a >= b) throw pix::exceptions::bad_range;

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

		return static_cast<type_out>(b);
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::derivative(const type_in INPUT) const
	{
		return static_cast<type_out>((this->_callable(INPUT + this->_TOL) - this->_callable(INPUT)) / this->_TOL);
	}

	template <typename callable, typename type_in, typename type_out>
	type_out function<callable, type_in, type_out>::integral(const type_in a, const type_in b) const noexcept(false)
	{
		if (a >= b) throw pix::exceptions::bad_range;

		type_in
			step = this->_TOL * (b - a), // Step value
			x_1 = a,
			x_2;
		type_out
			y_1 = this->_callable(x_1),
			y_2,
			ret = static_cast<type_out>(0); // Return value

		// Logger
		LOGGER_INIT("logs/integral.log");
		{
			LOGGER_LOG_MSG("Parameters:");
			LOGGER_LOG_MSG("\tTOL = " + std::to_string(this->_TOL));
			LOGGER_LOG_MSG("Initial values:");
			LOGGER_LOG_MSG("\ta = " + std::to_string(a));
			LOGGER_LOG_MSG("\tb = " + std::to_string(b));
			LOGGER_LOG_MSG("\tstep = " + std::to_string(step));
		}

		for (unsigned long i = 1; x_1 < b; ++i)
		{
			x_2 = x_1 + step;
			y_2 = this->_callable(x_2);
			ret += y_1 + y_2;

			// Logger
			{
				LOGGER_LOG_MSG("\nIteration: " + std::to_string(i));
				LOGGER_LOG_MSG("\tx_1 = " + std::to_string(x_1) + " | f(x_1) = " + std::to_string(y_1));
				LOGGER_LOG_MSG("\tx_2 = " + std::to_string(x_2) + " | f(x_2) = " + std::to_string(y_2));
				LOGGER_LOG_MSG("\tResult = " + std::to_string(ret));
			}

			x_1 = x_2;
			y_1 = this->_callable(x_1);
		}

		return 0.5 * step * ret;
	}
}

#endif // _FUNCTION_TPP_
