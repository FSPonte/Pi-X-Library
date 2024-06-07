#ifndef _QUEUE_IPP_
#define _QUEUE_IPP_

namespace pix::adt
{
    template <typename type_t, unsigned long MAX_SIZE>
    queue<type_t, MAX_SIZE>::queue(void)
    {
        static_assert
        (
            MAX_SIZE != 0,
            "Queue object cannot have a maximum of zero elements"
        );

        this->arr[0] = type_t();
        this->ind = 0;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool queue<type_t, MAX_SIZE>::queue_up(const type_t& ele)
    {
        if (this->ind == MAX_SIZE)
            return false;

        this->arr[this->ind++] = ele;

        return true;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& queue<type_t, MAX_SIZE>::unqueue(void)
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
    const type_t& queue<type_t, MAX_SIZE>::last(void) const
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[this->ind - 1];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& queue<type_t, MAX_SIZE>::first(void) const
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[0];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const unsigned long queue<type_t, MAX_SIZE>::size(void) const
    { return this->ind; }

    template <typename type_t, unsigned long MAX_SIZE>
    constexpr const unsigned long queue<type_t, MAX_SIZE>::max_size(void) const
    { return MAX_SIZE; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool queue<type_t, MAX_SIZE>::is_empty(void) const
    { return this->ind == 0; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool queue<type_t, MAX_SIZE>::is_full(void) const
    { return this->ind == MAX_SIZE; }
}

#endif // _QUEUE_IPP_