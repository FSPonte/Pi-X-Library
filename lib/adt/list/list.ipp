#ifndef _LIST_IPP_
#define _LIST_IPP_

namespace pix::adt
{
    template <typename type_t>
    list<type_t>::list(void)
    {
        this->head = nullptr;
        this->dim = 0;
    }

    template <typename type_t>
    list<type_t>::~list(void)
    { delete this->head; }

    template <typename type_t>
    void list<type_t>::append(type_t element)
    {
        if (this->head == nullptr)
            this->head = new node<type_t>(new type_t(element));
        else
        {
            node<type_t>* iter_ptr = this->head; // Iterator pointer

            while (iter_ptr->get_edge() != nullptr)
                iter_ptr = iter_ptr->get_edge();

            iter_ptr->set_edge(new node<type_t>(new type_t(element)));
        }

        ++this->dim;
    }

    template <typename type_t>
    type_t list<type_t>::pop(unsigned long index) noexcept(false)
    {
        if (index >= this->dim)
            throw "pix::adt::list.pop : Index is out of bounds";

        type_t ret_val; // Return value

        if (index == 0)
        {
            ret_val = *(this->head->get_value());
            node<type_t>* _head = this->head->get_edge(); // New head
            this->head->set_edge(nullptr);
            delete this->head;
            this->head = _head;
        }
        else
        {
            node<type_t>* iter_ptr = this->head; // Iterator pointer
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

        --this->dim;

        return ret_val;
    }

    template <typename type_t>
    type_t& list<type_t>::operator [] (const unsigned long index) noexcept(false)
    {
        if (index >= this->dim)
            throw "pix::adt::list.operator [] : Index is out of bounds";

        node<type_t>* iter_ptr = this->head; // Iterator pointer

        for (unsigned long i = 0; i < index; ++i)
            iter_ptr = iter_ptr->get_edge();

        return *(iter_ptr->get_value());
    }

    template <typename type_t>
    const unsigned long list<type_t>::size(void) const
    { return this->dim; }
}

#endif // _LIST_IPP_