#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

// Constant values
namespace pix::constants
{
	// Mathematical constants
	namespace mathematics
	{
		constexpr const long double PI = 3.141592653589793; // Ratio of a circle's circumference to its diameter
		constexpr const long double EULER_NUM =  2.718281828459045; // Euler's number
		constexpr const long double GOLDEN_RATIO = 1.618033988749895; // Golden ratio
	}

	// Physics constants
	namespace physics
	{
		constexpr const long double PLANCK_CONST = 6.62607015E-34; // Planck constant
		constexpr const long double EPSILON_0 = 8.854187812813E-12; // Vacuum electric permittivity
		constexpr const long double MU_0 = 1.2566370621219E-6; // Vacuum magnetic permeability
		constexpr const long double SPEED_LIGHT = 299792458; // Speed of light in vacuum
		constexpr const long double ELE_CHARGE = 1.602176634E-19; // Elementary charge
		constexpr const long double GRAV_CONST = 6.6743E-11; // Newtonian constant of gravitation
	}
}

#endif // _CONSTANTS_HPP_
