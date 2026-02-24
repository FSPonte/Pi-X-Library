#ifndef _SMART_POINTER_HPP_
#define _SMART_POINTER_HPP_

namespace
{
	template <typename type_t>
	class smart_pointer
	{
	protected:

		type_t* _ptr;

	public:

		virtual type_t& operator * (void) = 0;
	};
}

// Smart pointers
namespace pix::smart_pointer
{
	template <typename type_t>
	class auto_pointer : public smart_pointer<type_t>
	{
	public:
	
		/**
		 * @brief Default constructor
		*/
		auto_pointer(void) noexcept(true);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		auto_pointer(type_t) noexcept(true);

		/**
		 * @brief Destructor
		*/
		~auto_pointer(void) noexcept(true);

		/**
		 * @brief Dereference operator
		 * @return Reference to member pointer
		*/
		type_t& operator * (void) noexcept(true) override;
	};

	template <typename type_t>
	class unique_pointer : public smart_pointer<type_t>
	{
	public:

		/**
		 * @brief Default constructor
		*/
		unique_pointer(void) noexcept(true);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		unique_pointer(type_t) noexcept(true);

		/**
		 * @brief Destructor
		*/
		~unique_pointer(void) noexcept(true);

		/**
		 * @brief Dereference operator
		 * @return Reference to member pointer
		*/
		type_t& operator * (void) noexcept(true) override;

		/**
		 * @brief Left shift operator
		 * @param u_ptr Unique pointer
		 * @note Moves pointer between objects
		*/
		void operator << (unique_pointer<type_t>&) noexcept(true);
	};
}

// Template file
#include "auto_pointer.tpp"
#include "unique_pointer.tpp"

#endif // _SMART_POINTER_HPP_
