#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

namespace pix::adt
{
    /**
     * @brief Queue
     * @tparam type_t Data type
     * @tparam MAX_SIZE Maximum number of elements
    */
    template <typename type_t, unsigned long MAX_SIZE>
    class queue
    {
    private:

        type_t arr[MAX_SIZE];
        unsigned long ind;

    public:

        /**
         * @brief Constructor
        */
        queue(void);

        /**
         * @brief Queue up a element
         * @param ele Element
         * @return true - Success | false - Failure
        */
        const bool queue_up(const type_t&);

        /**
         * @brief Unqueue a element
         * @return Eliminated element
        */
        const type_t& unqueue(void);

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
        const unsigned long size(void) const;

        /**
         * @brief Maximum size
         * @return Maximum number of elements
        */
        const unsigned long max_size(void) const;

        /**
         * @brief Is empty
         * @return true if queue is empty
        */
        const bool is_empty(void) const;

        /**
         * @brief Is Full
         * @return true if queue is full
        */
        const bool is_full(void) const;
    };
}

// Implementation file
#include "queue.ipp"

#endif // _QUEUE_HPP_