#ifndef _TUPLE_HPP_
#define _TUPLE_HPP_

// Dependencies
#include <macros.hpp>

// Abstract data types
namespace pix::adt
{
	/**
	 * @brief Tuple
	 * @tparam type_t Data type
	 * @tparam DIM Number of elements
	*/
	template <typename type_t, unsigned long DIM = D_BUFFER_SIZE>
	class tuple
	{
	private:
		
		type_t _data[DIM];
		unsigned long _index;

		/**
		 * @brief Assign a single element
		 * @tparam type_t Data type
		 * @param ele Element
		*/
		void assign(type_t);

		/**
		 * @brief Assign variadic elements
		 * @tparam args_t Variadic type
		 * @param ele Element
		 * @param args Variadic arguments
		*/
		template <typename... args_t>
		void assign(type_t, args_t...);

	public:
		
		/**
		 * @brief Default constructor
		*/
		tuple(void);

		/**
		 * @brief Parameterized constructor
		 * @tparam args_t Variadic type
		 * @param args Variadic arguments
		*/
		template<typename... args_t>
		tuple(args_t...);

		/**
		 * @brief Get operator
		 * @param ind Index
		 * @return Reference to element
		 * @throw Index is out of bounds
		*/
		const type_t& operator [] (unsigned long) const noexcept(false);
	};
}

// Template file
#include "tuple.tpp"

#endif // _TUPLE_HPP_
