#ifndef _NODE_IPP_
#define _NODE_IPP_

namespace pix::adt
{
    template <typename type_t>
    node<type_t>::node(void)
    {
        this->value = nullptr;
        this->edge = nullptr;
    }

    template <typename type_t>
    node<type_t>::node(type_t element)
    {
        this->value = new type_t;
        *(this->value) = element;
        this->edge = nullptr;
    }

    template <typename type_t>
    node<type_t>::~node(void)
    {
        delete this->value;
        delete this->edge;
    }
}

#endif // _NODE_IPP_