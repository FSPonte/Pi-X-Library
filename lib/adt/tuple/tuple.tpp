#ifndef _TUPLE_TPP_
#define _TUPLE_TPP_

namespace pix::adt
{
	template <typename type_t, unsigned long DIM>
	tuple<type_t, DIM>::tuple(void)
	{
		static_assert
		(
			DIM != 0,
			"Tuple object cannot have zero elements"
		);

		this->_index = 0;
	}

	template <typename type_t, unsigned long DIM>
	template<typename... arg_t>
	tuple<type_t, DIM>::tuple(arg_t... args) : tuple<type_t, DIM>::tuple()
	{
		static_assert
		(
			sizeof...(args) == DIM,
			"Dimension doesn't equal the number of arguments"
		);
		
		this->assign(args...);
	}

	template <typename type_t, unsigned long DIM>
	void tuple<type_t, DIM>::assign(type_t element)
	{
		this->_data[this->_index] = element;
	}

	template <typename type_t, unsigned long DIM>
	template <typename... args_t>
	void tuple<type_t, DIM>::assign(type_t element, args_t... args)
	{
		this->_data[this->_index] = element;
		++this->_index;
		this->assign(args...);
	}

	template <typename type_t, unsigned long DIM>
	const type_t& tuple<type_t, DIM>::operator [] (const unsigned long index) const noexcept(false)
	{
		if (index >= DIM)
			throw "Index out of bounds";
		
		return this->_data[index];
	}
}

#endif // _TUPLE_TPP_
