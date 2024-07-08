#ifndef _DEQUE_IPP_
#define _DEQUE_IPP_

namespace pix::adt
{
    template <typename type_t, unsigned long MAX_SIZE>
    deque<type_t, MAX_SIZE>::deque(void)
    {
        static_assert
        (
            MAX_SIZE != 0,
            "Deque object cannot have a maximum of zero elements"
        );

        this->arr[0] = type_t();
        this->ind = 0;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool deque<type_t, MAX_SIZE>::push_back(const type_t& ele)
    {
        if (this->ind == MAX_SIZE)
            return false;

        this->arr[this->ind++] = ele;

        return true;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& deque<type_t, MAX_SIZE>::pop_back(void)
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[--this->ind];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool deque<type_t, MAX_SIZE>::push_front(const type_t& ele)
    {
        if (this->ind == MAX_SIZE)
            return false;

        for (unsigned long i = 0; i < this->ind; ++i)
            this->arr[i + 1] = this->arr[i];

        ++this->ind;
        this->arr[0] = ele;

        return true;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& deque<type_t, MAX_SIZE>::pop_front(void)
    {
        if (this->ind == 0)
            return type_t();

        type_t temp = this->arr[0];
        --this->ind;

        for (unsigned long i = 0; i < this->ind; ++i)
            this->arr[i] = this->arr[i + 1];

        return temp;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& deque<type_t, MAX_SIZE>::back(void) const
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[this->ind - 1];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& deque<type_t, MAX_SIZE>::front(void) const
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[0];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const unsigned long deque<type_t, MAX_SIZE>::size(void) const
    { return this->ind; }

    template <typename type_t, unsigned long MAX_SIZE>
    constexpr const unsigned long deque<type_t, MAX_SIZE>::max_size(void) const
    { return MAX_SIZE; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool deque<type_t, MAX_SIZE>::is_empty(void) const
    { return this->ind == 0; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool deque<type_t, MAX_SIZE>::is_full(void) const
    { return this->ind == MAX_SIZE; }
}

#endif // _DEQUE_IPP_