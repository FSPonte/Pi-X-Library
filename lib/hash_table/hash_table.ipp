#ifndef _HASH_TABLE_IPP_
#define _HASH_TABLE_IPP_

// Dependencies
#include <string.hpp>

namespace pix::adt
{
    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::hash_table(const types::hash_func_ptr_t f_ptr)
    {
        static_assert
        (
            MAX_SIZE > 2,
            "Minimum size permited is 2"
        );

        for (unsigned long i = 0; i < MAX_SIZE; ++i)
            this->arr[i] = hash_item<type_t>{type_t(), string<BUFFER_SIZE>(), 0};

        this->f_ptr = f_ptr;
        this->siz = 0;
    }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    const bool hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::insert(const char* const key, const type_t& val)
    {
        if (this->siz == MAX_SIZE || key == nullptr)
            return false;

        const unsigned long hash = this->f_ptr(key);
        const unsigned long ind = hash % MAX_SIZE;

        if (this->arr[ind].hash == 0)
        {
            this->arr[ind] = hash_item<type_t>{val, string<BUFFER_SIZE>(key), hash};
            ++this->siz;

            return true;
        }

        for (unsigned long i = ind + 1; i != ind; i = (i + 1) % MAX_SIZE)
        {
            if (this->arr[i].hash == 0)
            {
                this->arr[i] = hash_item<type_t>{val, string<BUFFER_SIZE>(key), hash};
                ++this->siz;

                return true;
            }
        }

        return false;
    }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    type_t hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::remove(const unsigned long ind)
    {
        type_t val = this->arr[ind].val;
        this->arr[ind] = hash_item<type_t>{type_t(), string<BUFFER_SIZE>(), 0};

        return val;
    }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    type_t hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::remove(const char* key)
    {
        if (key == nullptr)
            return 0;

        const unsigned long hash = this->f_ptr(key);
        const unsigned long ind = hash % MAX_SIZE;

        type_t val = type_t();

        for (unsigned long i = ind + 1; i != ind; i = (i + 1) % MAX_SIZE)
        {
            if (this->arr[i].hash == hash)
            {
                val = this->arr[i].val;
                this->arr[i] = hash_item<type_t>{type_t(), string<BUFFER_SIZE>(), 0};
            }
        }

        return val;
    }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    type_t& hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::operator [] (const unsigned long ind)
    { return this->arr[ind].val; }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    type_t hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::operator [] (const char* key) const
    {
        if (key == nullptr)
            return type_t();

        unsigned long hash = this->f_ptr(key);
        unsigned long ind = hash % MAX_SIZE;

        if (this->arr[ind].hash == hash)
            return this->arr[ind].val;

        for (unsigned long i = ind + 1; i != ind; i = (i + 1) % MAX_SIZE)
        {
            if (this->arr[i].hash == hash)
                return this->arr[i].val;
        }

        return type_t();
    }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    const unsigned long hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::size(void) const
    { return this->siz; }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    const unsigned long hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::max_size(void) const
    { return MAX_SIZE; }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    const bool hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::is_empty(void) const
    { return this->siz == 0; }

    template <typename type_t, unsigned long MAX_SIZE, unsigned long BUFFER_SIZE>
    const bool hash_table<type_t, MAX_SIZE, BUFFER_SIZE>::is_full(void) const
    { return this->siz == MAX_SIZE; }
}

#endif // _HASH_TABLE_IPP_