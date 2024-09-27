// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Pi-X library
#include <pix_lib.hpp>

#include <cmath>

/**
 * @brief Pause the process
 * @param msg Message
 * @note Adds the "..." string at the end
*/
void pause(const char[] = nullptr);

int main(int argc, char* argv[])
{
    auto PI = pix::constants::mathematics::PI;

    // Print arguments
    {
        std::cout << "Arguments:" << '\n';

        for (unsigned long i = 0; i < argc; ++i)
            std::cout << '\t' << argv[i] << '\n';

        std::cout << '\n';
    }

    long double arg;

    try
    {
        for (unsigned long i = 0; i < 1E3; ++i)
        {
            arg = pix::random::drand(- 20 * PI, 20 * PI);

            std::cout
                << "arg = " << arg << '\n'
                << "tan = " << pix::math::trig::tan(arg) << '\n';
            
            arg = pix::math::trig::arctan(pix::math::trig::tan(arg));

            std::cout
                << "arg = " << arg << '\n'
                << "tan = " << pix::math::trig::tan(arg) << '\n';

            std::cout << '\n';
        }
    }
    catch (const char err_msg[])
    { std::cout << err_msg << '\n'; }

    return EXIT_SUCCESS;
}

void pause(const char msg[])
{
    if (msg == nullptr)
        std::cout << "Press RETURN to continue...";
    else
        std::cout << msg << "...";
    
    std::cin.get();
}