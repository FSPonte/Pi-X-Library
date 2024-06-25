#ifndef _RAND_HPP_
#define _RAND_HPP_

namespace pix::random
{
    /**
     * @brief Set seed
     * @param seed Initial value
    */
    void set_seed(unsigned int);

    /**
     * @brief Set multiplier
     * @param mult Multiplier
    */
    void set_mult(unsigned int);

    /**
     * @brief Set increment
     * @param inc Increment
    */
    void set_inc(unsigned int);

    /**
     * @brief Set modulus
     * @param mod Modulus
    */
    void set_mod(unsigned int);

    /**
     * @brief Linear congruential generator
     * @return Random number between 0 and INT32_MAX
    */
    int rand(void);

    /**
     * @brief Line congruential generator
     * @return Random number between 0 and 1
    */
    double drand(void);
}

// Implementation file
#include "rand.ipp"

#endif // _RAND_HPP_