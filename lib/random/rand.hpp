#ifndef _RAND_HPP_
#define _RAND_HPP_

namespace pix::random
{
    /**
     * @brief Set seed
     * @param seed Initial value
    */
    void set_seed(unsigned long) noexcept(true);

    /**
     * @brief Set multiplier
     * @param mult Multiplier
    */
    void set_mult(unsigned long) noexcept(true);

    /**
     * @brief Set increment
     * @param inc Increment
    */
    void set_inc(unsigned long) noexcept(true);

    /**
     * @brief Set modulus
     * @param mod Modulus
    */
    void set_mod(unsigned long) noexcept(true);

    /**
     * @brief Linear congruential generator
     * @return Random integer number between 0 and INT32_MAX
    */
    unsigned long rand(void) noexcept(true);

    /**
     * @brief Linear congruential generator
     * @param min Minimum value
     * @param max Maximum value
     * @return Random integer number between min and max
     * @throw Invalid minimum and maximum values (min >= max)
    */
    long rand(long, long) noexcept(false);

    /**
     * @brief Linear congruential generator
     * @return Random decimal number between min and max
    */
    long double drand(void) noexcept(true);

    /**
     * @brief Linear congruential generator
     * @param min Minimum value
     * @param max Maximum value
     * @return Random decimal number between 0 and 1
     * @throw Invalid minimum and maximum values (min >= max)
    */
    long double drand(long double, long double) noexcept(false);

    /**
     * @brief Linear congruential generator
     * @return Random character in ASCII
     * @note Can only return lower case letters
    */
    char crand(void) noexcept(true);
}

// Implementation file
#include "rand.ipp"

#endif // _RAND_HPP_