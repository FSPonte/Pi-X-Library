#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

// Dependencies
#include <types.hpp>

using namespace pix::types;

namespace pix::adt
{
    /**
     * @brief Deque
     * @tparam type_t Data type
     * @tparam MAX_SIZE Maximum number of elements
    */
    template <typename type_t, size_t MAX_SIZE>
    class deque
    {
    private:

        type_t arr[MAX_SIZE];
        size_t ind;

    public:

        /**
         * @brief Constructor
        */
        deque(void);

        /**
         * @brief Queue up a element in the back
         * @param ele Element
         * @return true if push was successfull
        */
        const bool push_back(const type_t&);

        /**
         * @brief Queue up a element in the front
         * @param ele Element
         * @return true if push was successfull
        */
        const bool push_front(const type_t&);

        /**
         * @brief Unqueue the back element
         * @return Eliminated element
        */
        const type_t& pop_back(void);

        /**
         * @brief Unqueue the front element
         * @return Eliminated element
        */
        const type_t& pop_front(void);

        /**
         * @brief Back element
         * @return See the back element
        */
        const type_t& back(void) const;

        /**
         * @brief Front element
         * @return See the front element
        */
        const type_t& front(void) const;

        /**
         * @brief Size of queue
         * @return Number of elements
        */
        const size_t size(void) const;

        /**
         * @brief Maximum size
         * @return Maximum number of elements
        */
        const size_t max_size(void) const;

        /**
         * @brief Is empty
         * @return true if deque is empty
        */
        const bool is_empty(void) const;

        /**
         * @brief Is Full
         * @return true if deque is full
        */
        const bool is_full(void) const;
    };
}

// Implementation file
#include "queue.ipp"

#endif // _DEQUE_HPP_