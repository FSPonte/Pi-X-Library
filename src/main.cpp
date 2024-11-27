// C/C++ standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>

// Pi-X library
#include <pix_lib.hpp>

/**
 * @brief Pause the process
 * @param msg Message
 * @note Adds the "..." string at the end
*/
void pause(const char[] = nullptr);

int main(int argc, char* argv[])
{
    // Print arguments
    {
        std::cout << "Arguments:" << '\n';

        for (pix::types::size_t i = 0; i < argc; ++i)
            std::cout << '\t' << argv[i] << '\n';

        std::cout << '\n';
    }

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
