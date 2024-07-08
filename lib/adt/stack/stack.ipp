#ifndef _STACK_IPP_
#define _STACK_IPP_

namespace pix::adt
{
    template <typename type_t, unsigned long MAX_SIZE>
    stack<type_t, MAX_SIZE>::stack(void)
    {
        static_assert
        (
            MAX_SIZE != 0,
            "Stack object cannot have a maximum of zero elements"
        );

        this->arr[0] = type_t();
        this->ind = 0;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool stack<type_t, MAX_SIZE>::add(const type_t& element)
    {
        if (this->ind == MAX_SIZE)
            return false;

        this->arr[this->ind++] = element;

        return true;
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& stack<type_t, MAX_SIZE>::pop(void)
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[--this->ind];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const type_t& stack<type_t, MAX_SIZE>::top(void) const
    {
        if (this->ind == 0)
            return type_t();

        return this->arr[this->ind - 1];
    }

    template <typename type_t, unsigned long MAX_SIZE>
    const unsigned long stack<type_t, MAX_SIZE>::size(void) const
    { return this->ind; }

    template <typename type_t, unsigned long MAX_SIZE>
    constexpr const unsigned long stack<type_t, MAX_SIZE>::max_size(void) const
    { return MAX_SIZE; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool stack<type_t, MAX_SIZE>::is_empty(void) const
    { return this->ind == 0; }

    template <typename type_t, unsigned long MAX_SIZE>
    const bool stack<type_t, MAX_SIZE>::is_full(void) const
    { return this->ind == MAX_SIZE; }
}

#endif // _STACK_IPP_