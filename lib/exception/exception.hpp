#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

// Dependencies
#include <traceback.hpp>
#include <string>

namespace pix::exception
{	
	class excep
	{
	public:

		excep(const std::string&, traceback<true>* = nullptr) noexcept(true);
		std::string what(void) const noexcept(true);

	protected:

		const std::string _name;
		traceback<true>* _route;
	};

	class null_dim : public excep
	{
	public:

		null_dim(traceback<true>* = nullptr) noexcept(true);
	};

	class null_ptr : public excep
	{
	public:
		
		null_ptr(traceback<true>* = nullptr) noexcept(true);
	};

	class bad_alloc : public excep
	{
	public:
		
		bad_alloc(traceback<true>* = nullptr) noexcept(true);
	};
	
	class underflow : public excep
	{
	public:
		
		underflow(traceback<true>* = nullptr) noexcept(true);
	};

	class overflow : public excep
	{
	public:
		
		overflow(traceback<true>* = nullptr) noexcept(true);
	};

	class bad_range : public excep
	{
	public:
		
		bad_range(traceback<true>* = nullptr) noexcept(true);
	};
	
	class div_zero : public excep
	{
	public:
		
		div_zero(traceback<true>* = nullptr) noexcept(true);
	};

	class invalid_argument : public excep
	{
	public:
		
		invalid_argument(traceback<true>* = nullptr) noexcept(true);
	};
	
	class out_of_bounds : public excep
	{
	public:
		
		out_of_bounds(traceback<true>* = nullptr) noexcept(true);
	};
	
	class os_not_supported : public excep
	{
	public:
		
		os_not_supported(traceback<true>* = nullptr) noexcept(true);
	};
}

#endif // _EXCEPTION_HPP_
