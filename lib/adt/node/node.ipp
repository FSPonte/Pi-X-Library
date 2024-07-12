#ifndef _NODE_IPP_
#define _NODE_IPP_

namespace pix::adt
{
    template <typename type_t>
    node<type_t>::node(void)
    {
        this->_value = nullptr;
        this->_edges = nullptr;
        this->_size = 0;
    }

    template <typename type_t>
    node<type_t>::node(type_t* value)
    {
        this->_value = value;
        this->_edges = nullptr;
    }

    template <typename type_t>
    node<type_t>::~node(void)
    {
        delete this->_value;

        for (unsigned long i = 0; i < this->_size; ++i)
            delete this->_edges[i];
        
        delete[] this->_edges;
    }

    template <typename type_t>
    void node<type_t>::set_value(type_t* value)
    { this->_value = value; }

    template <typename type_t>
    type_t* node<type_t>::get_value(void) const
    { return this->_value; }

    template <typename type_t>
    void node<type_t>::append(node<type_t>* edge)
    {
        if (this->_edges == nullptr)
        {
            this->_edges = new node<type_t>*;
            *(this->_edges) = edge;

            return;
        }

        auto** edges_new = new node<type_t>*[this->_size + 1];

        for (unsigned long i = 0; i < this->_size; ++i)
            edges_new[i] = this->_edges[i];

        edges_new[this->_size] = edge;
        ++this->_size;
    }

    template <typename type_t>
    void node<type_t>::pop(const unsigned long index) noexcept(false)
    {
        if (index >= this->_size)
            throw "Index is out of bounds";

        if (this->_size == 1)
        {
            delete *(this->_edges);
            delete this->_edges;
            this->_size = 0;

            return;
        }

        auto** edges_new = new node<type_t>*[this->_size - 1];
        unsigned long j = 0; // Auxiliar index

        for (unsigned long i = 0; i < this->_size; ++i)
        {
            if (i == index)
                continue;

            edges_new[j] = this->_edges[i];
            ++j;
            this->_edges[i] = nullptr;
        }

        delete this->_edges[index];
        delete[] this->_edges;
        this->_edges = edges_new;
        --this->_size;
    }

    template <typename type_t>
    void node<type_t>::set_edge(node<type_t>* edge)
    {
        if (this->_edges == nullptr)
            this->_edges = new node<type_t>*;

        *(this->_edges) = edge;
    }

    template <typename type_t>
    node<type_t>* node<type_t>::get_edge(void) const
    {
        if (this->_edges == nullptr)
            return nullptr;
        
        return *(this->_edges);
    }

    template <typename type_t>
    const unsigned long node<type_t>::size(void) const
    { return this->_size; }
}

#endif // _NODE_IPP_