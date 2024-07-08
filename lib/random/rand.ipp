#ifndef _RAND_IPP_
#define _RAND_IPP_

// Dependencies
#include <sys_vars.hpp>

static unsigned long
    _seed = 1607, // Initial value
    _mult = 806, // Multiplier
    _inc = 103, // Increment
    _mod = INT32_MAX; // Modulus

namespace pix::random
{
    void set_seed(unsigned int seed)
    { _seed = seed; }

    void set_mult(unsigned int mult)
    { _mult = mult; }

    void set_inc(unsigned int inc)
    { _inc = inc; }

    void set_mod(unsigned int mod)
    { _mod = mod; }

    unsigned long rand(void)
    {
        static unsigned long value = _seed;
        
        value = (_mult * value + _inc) % _mod;

        return value;
    }

    long double drand(void)
    { return static_cast<long double>(rand()) / static_cast<long double>(_mod);}
}

#endif // _RAND_IPP_