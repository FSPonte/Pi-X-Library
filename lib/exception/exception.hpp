#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

// Dependencies
#include <traceback.hpp>
#include <string>

namespace pix::exception
{	
	class excep
	{
	public:

		excep(const std::string&) noexcept(true);
		excep(const std::string&, traceback<TRACEBACK_ENABLED>) noexcept(true);
		std::string what(void) const noexcept(true);
		void print(void) const noexcept(true);

	protected:

		const std::string _name;
		const traceback<TRACEBACK_ENABLED> _route;
	};

	class null_dim : public excep
	{
	public:

		null_dim(void) noexcept(true);
		null_dim(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};

	class null_ptr : public excep
	{
	public:
		
		null_ptr(void) noexcept(true);
		null_ptr(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};

	class bad_alloc : public excep
	{
	public:
		
		bad_alloc(void) noexcept(true);
		bad_alloc(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};
	
	class underflow : public excep
	{
	public:
		
		underflow(void) noexcept(true);
		underflow(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};

	class overflow : public excep
	{
	public:
		
		overflow(void) noexcept(true);
		overflow(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};

	class bad_range : public excep
	{
	public:
		
		bad_range(void) noexcept(true);
		bad_range(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};
	
	class div_zero : public excep
	{
	public:
		
		div_zero(void) noexcept(true);
		div_zero(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};

	class invalid_argument : public excep
	{
	public:
		
		invalid_argument(void) noexcept(true);
		invalid_argument(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};
	
	class out_of_bounds : public excep
	{
	public:
		
		out_of_bounds(void) noexcept(true);
		out_of_bounds(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};
	
	class os_not_supported : public excep
	{
	public:
		
		os_not_supported(void) noexcept(true);
		os_not_supported(traceback<TRACEBACK_ENABLED>) noexcept(true);
	};
}

#endif // __EXCEPTION_HPP__
