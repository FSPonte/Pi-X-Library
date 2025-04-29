#ifndef _NODE_HPP_
#define _NODE_HPP_

namespace pix::adt
{
	/**
	 * @brief Node
	 * @tparam type_t Data type
	*/
	template <typename type_t>
	class node
	{
	private:

		type_t* _value;
		node<type_t>** _edges;
		unsigned long _size;

	public:

		/**
		 * @brief Default constructor
		*/
		node(void);

		/**
		 * @brief Parameterized constructor
		 * @param val Pointer to value
		*/
		node(type_t*);

		/**
		 * @brief Destructor
		*/
		~node(void);

		/**
		 * @brief Set value
		 * @param val Pointer to value
		*/
		void set_value(type_t*);

		/**
		 * @brief Get value
		 * @return Pointer to value
		*/
		type_t* get_value(void) const;

		/**
		 * @brief Add a edge
		 * @param edg Edge
		*/
		void append(node<type_t>*);

		/**
		 * @brief Eliminate a edge
		 * @param ind Index
		 * @throw Index is out of bounds
		*/
		void pop(unsigned long) noexcept(false);

		/**
		 * @brief Get edge
		 * @param ind Index
		 * @return Pointer to edge
		 * @throw Index is out of bounds
		*/
		node<type_t>* operator [] (unsigned long) const noexcept(false);

		/**
		 * @brief Set edge
		 * @param edg Pointer to edge
		 * @note Deals with the first element
		*/
		void set_edge(node<type_t>*);

		/**
		 * @brief Get edge
		 * @return Pointer to edge
		 * @note Deals with the first element
		*/
		node<type_t>* get_edge(void) const;

		/**
		 * @brief Get size
		 * @return Number of edges
		*/
		unsigned long size(void) const;
	};
}

// Template file
#include "node.tpp"

#endif // _NODE_HPP_
