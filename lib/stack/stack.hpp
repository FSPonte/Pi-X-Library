#ifndef _STACK_HPP_
#define _STACK_HPP_

namespace pix::adt
{
    /**
     * @brief Stack
     * @tparam type_t Data type
     * @tparam MAX_SIZE Maximum number of elements
    */
    template <typename type_t, unsigned long MAX_SIZE>
    class stack
    {
    private:

        type_t arr[MAX_SIZE];
        unsigned long ind;

    public:

        /**
         * @brief Constructor
        */
        stack(void);

        /**
         * @brief Add a element
         * @param ele Element
         * @return true - Success | false - Failure
        */
        const bool add(const type_t&);

        /**
         * @brief Pop a element
         * @return Eliminated element
        */
        const type_t& pop(void);

        /**
         * @brief Top element
         * @return See the top element
        */
        const type_t& top(void) const;

        /**
         * @brief Size of stack
         * @return Number of elements
        */
        const unsigned long size(void) const;

        /**
         * @brief Maximum size
         * @return Maximum number of elements
        */
        const unsigned long max_size(void) const;

        /**
         * @brief Is empty
         * @return true if stack is empty
        */
        const bool is_empty(void) const;

        /**
         * @brief Is Full
         * @return true if stack is full
        */
        const bool is_full(void) const;
    };
}

// Implementation file
#include "stack.ipp"

#endif // _STACK_HPP_