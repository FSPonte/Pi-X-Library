#ifndef _RAND_HPP_
#define _RAND_HPP_

namespace pix::random
{
    const unsigned long
        SEED = 1607, // Initial value
        MULT = 806, // Multiplier
        INC = 103, // Increment
        MOD = INT32_MAX; // Modulus

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