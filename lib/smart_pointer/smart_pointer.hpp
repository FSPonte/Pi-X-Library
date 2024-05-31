#ifndef _SMART_POINTER_HPP_
#define _SMART_POINTER_HPP_

// Dependencies
#include <types.hpp>

using namespace pix::types;

namespace
{
    template <typename type_t>
    class smart_pointer
    {
    protected:

        type_t* ptr;

    public:

        virtual type_t& operator * (void) = 0;
        virtual type_t* operator -> (void) = 0;
        virtual type_t& operator [] (size_t) = 0;
    };
}

#endif // _SMART_POINTER_HPP_

#ifndef _AUTO_POINTER_HPP_
#define _AUTO_POINTER_HPP_

namespace pix::adt
{
    template <typename type_t>
    class auto_pointer : public smart_pointer<type_t>
    {
    public:

        /**
         * @brief Default constructor
        */
        auto_pointer(void);

        /**
         * @brief Parameterized constructor
         * @param val Value
        */
        auto_pointer(type_t);

        /**
         * @brief Destructor
        */
        ~auto_pointer(void);

        /**
         * @brief Dereference operator
         * @return Reference to member pointer
        */
        type_t& operator * (void) override;

        /**
         * @brief Arrow operator
         * @return Member pointer
        */
        type_t* operator -> (void) override;

        /**
         * @brief Get operator
         * @param ind Index
         * @return Reference to element
        */
        type_t& operator [] (size_t) override;
    };
}

// Implementation file
#include "auto_pointer.ipp"

#endif // _AUTO_POINTER_HPP_

#ifndef _UNIQUE_POINTER_HPP_
#define _UNIQUE_POINTER_HPP_

namespace pix::adt
{
    template <typename type_t>
    class unique_pointer : public smart_pointer<type_t>
    {
    public:

        /**
         * @brief Default constructor
        */
        unique_pointer(void);

        /**
         * @brief Parameterized constructor
         * @param val Value
        */
        unique_pointer(type_t);

        /**
         * @brief Destructor
        */
        ~unique_pointer(void);

        /**
         * @brief Dereference operator
         * @return Reference to member pointer
        */
        type_t& operator * (void) override;

        /**
         * @brief Arrow operator
         * @return Member pointer
        */
        type_t* operator -> (void) override;

        /**
         * @brief Get operator
         * @param ind Index
         * @return Reference to element
        */
        type_t& operator [] (size_t) override;

        /**
         * @brief Left shift operator
         * @param u_ptr Unique pointer
         * @note Moves pointer between objects
        */
        void operator << (unique_pointer<type_t>&);
    };
}

// Implementation file
#include "unique_pointer.ipp"

#endif // _UNIQUE_POINTER_HPP_