#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

namespace pix::constants
{
    namespace mathematics
    {
        const long double pi = 3.141592653589793;  // Ratio of a circle's circumference to its diameter
        const long double e =  2.718281828459045;  // Euler's number
        const long double phi = 1.618033988749895; // Golden ratio
    }

    namespace physics
    {
        const long double h = 6.62607015E-34;             // Planck constant
        const long double epsilon_0 = 8.854187812813E-12; // Vacuum electric permittivity
        const long double mu_0 = 1.2566370621219E-6;      // Vacuum magnetic permeability
        const long double c = 299792458;                  // Speed of light in vacuum
        const long double e = 1.602176634E-19;            // Elementary charge
        const long double G = 6.6743E-11;                 // Newtonian constant of gravitation
    }
}

#endif // _CONSTANTS_HPP_