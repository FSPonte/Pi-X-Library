#ifndef _SMART_POINTER_HPP_
#define _SMART_POINTER_HPP_

namespace
{
	template <typename type_t>
	class smart_pointer
	{
	protected:

		type_t* ptr;

	public:

		virtual type_t& operator * (void) = 0;
	};
}

#ifndef _AUTO_POINTER_
#define _AUTO_POINTER_

namespace pix::smart_pointer
{
	template <typename type_t>
	class auto_pointer : public smart_pointer<type_t>
	{
	public:
		/**
		 * @brief Default constructor
		*/
		auto_pointer(void);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		auto_pointer(type_t);

		/**
		 * @brief Destructor
		*/
		~auto_pointer(void);

		/**
		 * @brief Dereference operator
		 * @return Reference to member pointer
		*/
		type_t& operator * (void) override;
	};
}

// Template file
#include "auto_pointer.tpp"

#endif // _AUTO_POINTER_

#ifndef _UNIQUE_POINTER_
#define _UNIQUE_POINTER_

namespace pix::smart_pointer
{
	template <typename type_t>
	class unique_pointer : public smart_pointer<type_t>
	{
	public:

		/**
		 * @brief Default constructor
		*/
		unique_pointer(void);

		/**
		 * @brief Parameterized constructor
		 * @param val Value
		*/
		unique_pointer(type_t);

		/**
		 * @brief Destructor
		*/
		~unique_pointer(void);

		/**
		 * @brief Dereference operator
		 * @return Reference to member pointer
		*/
		type_t& operator * (void) override;

		/**
		 * @brief Left shift operator
		 * @param u_ptr Unique pointer
		 * @note Moves pointer between objects
		*/
		void operator << (unique_pointer<type_t>&);
	};
}

// Template file
#include "unique_pointer.tpp"

#endif // _UNIQUE_POINTER_

#endif // _SMART_POINTER_HPP_