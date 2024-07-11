#ifndef _NODE_IPP_
#define _NODE_IPP_

namespace pix::adt
{
    template <typename type_t>
    node<type_t>::node(void)
    {
        this->value = nullptr;
        this->edges = nullptr;
        this->dim = 0;
    }

    template <typename type_t>
    node<type_t>::node(type_t* value)
    {
        this->value = value;
        this->edges = nullptr;
    }

    template <typename type_t>
    node<type_t>::~node(void)
    {
        delete this->value;

        for (unsigned long i = 0; i < this->dim; ++i)
            delete this->edges[i];
        
        delete[] this->edges;
    }

    template <typename type_t>
    void node<type_t>::set_value(type_t* value)
    { this->value = value; }

    template <typename type_t>
    type_t* node<type_t>::get_value(void) const
    { return this->value; }

    template <typename type_t>
    void node<type_t>::append(node<type_t>* edge)
    {
        if (this->edges == nullptr)
        {
            this->edges = new node<type_t>*;
            *(this->edges) = edge;

            return;
        }

        auto** edges_new = new node<type_t>*[this->dim + 1];

        for (unsigned long i = 0; i < this->dim; ++i)
            edges_new[i] = this->edges[i];

        edges_new[this->dim] = edge;
        ++this->dim;
    }

    template <typename type_t>
    void node<type_t>::pop(const unsigned long index) noexcept(false)
    {
        if (index >= this->dim)
            throw "pix::adt::node.pop : Index is out of bounds";

        if (this->dim == 1)
        {
            delete *(this->edges);
            delete this->edges;
            this->dim = 0;

            return;
        }

        auto** edges_new = new node<type_t>*[this->dim - 1];
        unsigned long j = 0; // Auxiliar index

        for (unsigned long i = 0; i < this->dim; ++i)
        {
            if (i == index)
                continue;

            edges_new[j] = this->edges[i];
            ++j;
            this->edges[i] = nullptr;
        }

        delete this->edges[index];
        delete[] this->edges;
        this->edges = edges_new;
        --this->dim;
    }

    template <typename type_t>
    void node<type_t>::set_edge(node<type_t>* edge)
    {
        if (this->edges == nullptr)
            this->edges = new node<type_t>*;

        *(this->edges) = edge;
    }

    template <typename type_t>
    node<type_t>* node<type_t>::get_edge(void) const
    {
        if (this->edges == nullptr)
            return nullptr;
        
        return *(this->edges);
    }

    template <typename type_t>
    const unsigned long node<type_t>::size(void) const
    { return this->dim; }
}

#endif // _NODE_IPP_