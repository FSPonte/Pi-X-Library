#ifndef _RAND_HPP_
#define _RAND_HPP_

namespace pix::random
{
    /**
     * @brief Set seed
     * @param seed Initial value
    */
    void set_seed(unsigned long);

    /**
     * @brief Set multiplier
     * @param mult Multiplier
    */
    void set_mult(unsigned long);

    /**
     * @brief Set increment
     * @param inc Increment
    */
    void set_inc(unsigned long);

    /**
     * @brief Set modulus
     * @param mod Modulus
    */
    void set_mod(unsigned long);

    /**
     * @brief Linear congruential generator
     * @return Random number between 0 and INT32_MAX
    */
    unsigned long rand(void);

    /**
     * @brief Line congruential generator
     * @return Random number between 0 and 1
    */
    long double drand(void);
}

// Implementation file
#include "rand.ipp"

#endif // _RAND_HPP_