#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

// Dependencies
#include <types.hpp>

using namespace pix::types;

namespace pix
{
    // Hashing functions
    namespace hash_func
    {}

    namespace adt
    {
        /**
         * @brief Hash item
         * @tparam type_t Data type
         * @tparam BUFFER_SIZE Number of characters in the keys
        */
        template <typename type_t, size_t BUFFER_SIZE = D_BUFFER_SIZE>
        struct hash_item
        {
            string<BUFFER_SIZE> key;
            size_t hash;
            type_t val;
        };

        /**
         * @brief Hash table
         * @tparam type Data type
         * @tparam MAX_SIZE Maximum number of elements
         * @tparam BUFFER_SIZE Maximum number of characters for the keys
        */
        template <typename type_t, size_t MAX_SIZE, size_t BUFFER_SIZE = D_BUFFER_SIZE>
        class hash_table
        {
        private:

            hash_item<type_t, BUFFER_SIZE> arr[MAX_SIZE];
            hash_func_ptr_t f_ptr;
            size_t dim;

        public:

            /**
             * @brief Constructor
             * @param f_ptr Hashing function pointer
            */
            hash_table(const hash_func_ptr_t);

            /**
             * @brief Insert a element
             * @param key Key
             * @param val Value
             * @return true if key-value pair was successfully inserted
            */
            const bool insert(const char*, const type_t&);

            /**
             * @brief Remove a element
             * @param ind Index
             * @return Removed element
            */
            type_t remove(size_t);

            /**
             * @brief Remove a element
             * @param key Key
             * @return Removed element
            */
            type_t remove(const char*);

            /**
             * @brief Get value
             * @param ind Index
             * @return Reference to value
             * @note Index is congruent to the maximum size
            */
            type_t& operator [] (size_t);

            /**
             * @brief Get value
             * @param key Key
             * @return Reference to value
            */
            type_t operator [] (const char*) const;

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
             * @return true if hash table is empty
            */
            const bool is_empty(void) const;

            /**
             * @brief Is Full
             * @return true if hash table is full
            */
            const bool is_full(void) const;
        };
    }
}

// Implementation files
#include "hash_func.ipp"
#include "hash_table.ipp"

#endif // _HASH_TABLE_HPP_