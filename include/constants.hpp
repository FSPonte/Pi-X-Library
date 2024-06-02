#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

namespace pix::constants
{
    namespace mathematics
    {
        const double pi = 3.141592653589793;  // Ratio of a circle's circumference to its diameter
        const double e =  2.718281828459045;  // Euler's number
        const double phi = 1.618033988749895; // Golden ratio
    }

    namespace physics
    {
        const double h = 6.62607015E-34;             // Planck constant
        const double epsilon_0 = 8.854187812813E-12; // Vacuum electric permittivity
        const double mu_0 = 1.2566370621219E-6;      // Vacuum magnetic permeability
        const double c = 299792458;                  // Speed of light in vacuum
        const double e = 1.602176634E-19;            // Elementary charge
        const double G = 6.6743E-11;                 // Newtonian constant of gravitation
    }
}

#endif // _CONSTANTS_HPP_