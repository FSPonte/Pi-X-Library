#ifndef _NODE_HPP_
#define _NODE_HPP_

namespace pix::adt
{
    /**
     * @brief Node
     * @tparam type_t Data type
    */
    template <typename type_t>
    struct node
    {
        type_t* value;
        node<type_t>* edge;

        /**
         * @brief Default constructor
        */
        node(void);

        /**
         * @brief Parameterized constructor
         * @param ele Element
        */
        node(type_t);

        /**
         * @brief Destructor
        */
        ~node(void);
    };
}

// Implementation file
#include "node.ipp"

#endif // _NODE_HPP_