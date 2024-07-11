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
            this->head = new node<type_t>(element);
        else
        {
            node<type_t>* iter_ptr = this->head; // Iterator pointer

            while (iter_ptr->edge != nullptr)
                iter_ptr = iter_ptr->edge;

            iter_ptr->edge = new node<type_t>(element);
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
            ret_val = *(this->head->value);
            node<type_t>* _head = this->head->edge; // New head
            this->head->edge = nullptr;
            delete this->head;
            this->head = _head;
        }
        else
        {
            node<type_t>* iter_ptr = this->head; // Iterator pointer
            --index;

            for (unsigned long i = 0; i < index; ++i)
                iter_ptr = iter_ptr->edge;

            node<type_t>* nd_prev = iter_ptr; // Previous node
            iter_ptr = iter_ptr->edge;
            ret_val = *(iter_ptr->value);
            nd_prev->edge = iter_ptr->edge;
            iter_ptr->edge = nullptr;
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
            iter_ptr = iter_ptr->edge;

        return *(iter_ptr->value);
    }

    template <typename type_t>
    const unsigned long list<type_t>::size(void) const
    { return this->dim; }
}

#endif // _LIST_IPP_