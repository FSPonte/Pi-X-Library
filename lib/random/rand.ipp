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
    void set_seed(const unsigned int seed) noexcept(true)
    { _seed = seed; }

    void set_mult(const unsigned int mult) noexcept(true)
    { _mult = mult; }

    void set_inc(const unsigned int inc) noexcept(true)
    { _inc = inc; }

    void set_mod(const unsigned int mod) noexcept(true)
    { _mod = mod; }

    unsigned long rand(void) noexcept(true)
    {
        static unsigned long value = _seed;
        
        value = (_mult * value + _inc) % _mod;

        return value;
    }

    long rand(const long min, const long max) noexcept(false)
    {
        if (min >= max)
            throw "Invalid minimum and maximum values (min >= max)";

        return (max - min) * rand() + min;
    }

    long double drand(void) noexcept(true)
    { return static_cast<long double>(rand()) / static_cast<long double>(_mod); }

    long double drand(const long double min, const long double max) noexcept(false)
    {
        if (min >= max)
            throw "Invalid minimum and maximum values (min >= max)";

        return (max - min) * drand() + min;
    }

    char crand(void) noexcept(true)
    { return static_cast<char>(rand() % 26 + 97); }
}

#endif // _RAND_IPP_