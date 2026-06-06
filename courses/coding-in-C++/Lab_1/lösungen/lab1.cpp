#include <iostream>
#include <limits>
#include <cstdint>

namespace validation
{
    std::uint8_t adultAge = 18;
    std::uint8_t seniorAge = 65;

    bool isAdult(std::uint8_t age)
    {
        return age >= adultAge;
    }

    bool isSenior(std::uint8_t age)
    {
        return age >= seniorAge;
    }
}

int main()
{
    int inputAge = 0;
    std::uint8_t age = 0;

    const int minAge = 0;
    const int maxAge = 150;

    while (true)
    {
        std::cout << "Please enter your age: ";

        if (!(std::cin >> inputAge))
        {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (inputAge < minAge || inputAge > maxAge)
        {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
        }
        else
        {
            age = static_cast<std::uint8_t>(inputAge);
            break;
        }
    }

    std::cout << "You are " << static_cast<int>(age) << " years old." << std::endl;

    if (validation::isSenior(age))
    {
        std::cout << "That means that you are a senior citizen." << std::endl;
    }
    else if (validation::isAdult(age))
    {
        std::cout << "That means that you are an adult." << std::endl;
    }
    else
    {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    // Problem with uint8_t:
    // uint8_t is often treated like an unsigned char.
    // Therefore std::cin may read a character instead of a normal number.
    // Also std::cout may print it as a character.
    //
    // Fix:
    // Read the user input into an int first.
    // After validation, convert it with static_cast<std::uint8_t>.
    //
    // Other useful portable types:
    // std::uint16_t, std::uint32_t or std::int16_t.

    return 0;
}