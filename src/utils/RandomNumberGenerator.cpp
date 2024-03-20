#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {}

RandomNumberGenerator::RandomNumberGenerator(size_t min, size_t max)
{
    /*
        The constructor of the RandomNumberGenerator class. Initializes the random number generator.
    */
    std::random_device rd;
    gen = std::mt19937(rd());
    dist = std::uniform_int_distribution<unsigned>(min, max);
}

size_t RandomNumberGenerator::operator()()
{
    /*
        Overloads the function call operator to return a random number.
    */
    return dist(gen);
}