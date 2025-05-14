#ifndef _LIST_TPP_
#define _LIST_TPP_

namespace pix::adt
{
	template <typename type_t>
	list<type_t>::list(void)
	{
		this->_head = nullptr;
		this->_size = 0;
	}

	template <typename type_t>
	list<type_t>::~list(void)
	{
		delete this->_head;
	}

	template <typename type_t>
	void list<type_t>::append(type_t element)
	{
		if (this->_head == nullptr)
			this->_head = new node<type_t>(new type_t(element));
		else
		{
			node<type_t>* iter_ptr = this->_head; // Iterator pointer

			while (iter_ptr->get_edge() != nullptr)
				iter_ptr = iter_ptr->get_edge();

			iter_ptr->set_edge(new node<type_t>(new type_t(element)));
		}

		++this->_size;
	}

	template <typename type_t>
	type_t list<type_t>::pop(unsigned long index) noexcept(false)
	{
		if (index >= this->_size) throw pix::exceptions::out_of_bounds;

		type_t ret_val; // Return value

		if (index == 0)
		{
			ret_val = *(this->_head->get_value());
			node<type_t>* _head = this->_head->get_edge(); // New head
			this->_head->set_edge(nullptr);
			delete this->_head;
			this->_head = _head;
		}
		else
		{
			node<type_t>* iter_ptr = this->_head; // Iterator pointer
			--index;

			for (unsigned long i = 0; i < index; ++i)
				iter_ptr = iter_ptr->get_edge();

			node<type_t>* nd_prev = iter_ptr; // Previous node
			iter_ptr = iter_ptr->get_edge();
			ret_val = *(iter_ptr->get_value());
			nd_prev->set_edge(iter_ptr->get_edge());
			iter_ptr->set_edge(nullptr);
			delete iter_ptr;
		}

		--this->_size;

		return ret_val;
	}

	template <typename type_t>
	type_t& list<type_t>::operator [] (const unsigned long INDEX) noexcept(false)
	{
		if (INDEX >= this->_size) throw pix::exceptions::out_of_bounds;

		node<type_t>* iter_ptr = this->_head; // Iterator pointer

		for (unsigned long i = 0; i < INDEX; ++i)
			iter_ptr = iter_ptr->get_edge();

		return *(iter_ptr->get_value());
	}

	template <typename type_t>
	unsigned long list<type_t>::size(void) const
	{
		return this->_size;
	}
}

#endif // _LIST_TPP_
